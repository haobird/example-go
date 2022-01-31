package main

import (
	"fmt"
	"io/ioutil"

	pb "github.com/haobird/learngo/addressbook/message"
	"google.golang.org/protobuf/proto"
)

func writePerson() {
	p := pb.Person{
		Id:    1234,
		Name:  "john doe",
		Email: "jdoe@example.com",
		Phones: []*pb.Person_PhoneNumber{
			{Number: "555-1234", Type: pb.Person_HOME},
		},
	}

	out, err := proto.Marshal(&p)
	if err != nil {
		fmt.Println("failed to encode person:", err)
	}
	if err := ioutil.WriteFile("./address.txt", out, 0644); err != nil {
		fmt.Println("failed to write person:", err)
	}

}

func readPerson() {
	in, err := ioutil.ReadFile("./address.txt")
	if err != nil {
		fmt.Println("failed to read file:", err)
	}
	person := &pb.Person{}
	if err := proto.Unmarshal(in, person); err != nil {
		fmt.Println("failed to parse address book:", err)
	}
	fmt.Println(person)
}

func main() {
	// writePerson()
	readPerson()
}
