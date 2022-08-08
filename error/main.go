package main

import (
	"fmt"

	"helloerror/xerrors"

	"github.com/pkg/errors"
)

var ErrConflict = errors.New("email already taken")

func fn() error {
	e1 := errors.New("error")
	e2 := errors.Wrap(e1, "inner")
	e3 := errors.Wrap(e2, "middle")
	return errors.Wrap(e3, "outer")
}

type customErr struct {
	msg string
}

func (c customErr) Error() string { return c.msg }

func main() {
	// e1 := errors.New("第一次错误")
	// e2 := xerrors.Wrap(e1, ErrConflict)
	// fmt.Printf("%+v \n", e2) // top two frames

	err0 := xerrors.New("0")
	err1 := xerrors.New("1")

	errWrap := xerrors.Wrap(err1, err0)
	fmt.Printf("%+v \n", errWrap)

	flag := xerrors.Contains(errWrap, ErrConflict)
	fmt.Println(flag)

	// testIs()
}

func testAs() {
	// var err = customErr{msg: "test message"}

}

// 是否
func testIs() {
	// err := errors.New("error that gets wrapped")
	// wrapped := errors.Wrap(err, "wrapped up")
	// err1 := errors.New("hhh")

	e1 := errors.New("第一次错误")
	fmt.Printf("%s\n", e1)
	e2 := errors.Wrap(e1, "email already taken")
	fmt.Printf("%s\n", e2)
	e3 := errors.Wrap(e2, "第三次错误")
	fmt.Printf("%s\n", e3)

	flag := errors.Is(e3, e1)
	fmt.Println(flag)
	fmt.Printf("%s\n", e3)

	e4 := errors.New("第一次错误")

	flag = errors.Is(e3, e4)
	fmt.Println(flag)

	flag = errors.Is(e3, ErrConflict)
	fmt.Println(flag)
}
