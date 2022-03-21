package main

import (
	"hellokit_example/mystring"
	"log"
	"net/http"
)

func main() {
	svc := mystring.New()
	mystring.MakeHandler(svc)
	log.Fatal(http.ListenAndServe(":8083", nil))
}
