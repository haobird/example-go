package helper

import (
	"fmt"
	"hellolog/logger"
)

func Print(str string) {
	fmt.Println("print", str)
	logger.Debug("ddd")
}
