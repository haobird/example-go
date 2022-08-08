package fooc

/*
#cgo CFLAGS: -I./dll
#include "foo.h"
*/
import "C"

func Hello() {
	C.SayHello(C.CString("dd"))
}
