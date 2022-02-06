package main

import (
	"fmt"

	"github.com/pkg/errors"
)

var ErrConflict = errors.New("email already taken")

func fn() error {
	e1 := errors.New("error")
	e2 := errors.Wrap(e1, "inner")
	e3 := errors.Wrap(e2, "middle")
	return errors.Wrap(e3, "outer")
}

func main() {
	e1 := errors.New("error")
	e2 := errors.Wrap(e1, "inner")
	e3 := errors.Wrap(e2, "middle")

	fmt.Printf("%+v\n", e3)

}
