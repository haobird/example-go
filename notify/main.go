package main

import (
	"context"
	"fmt"

	"github.com/nikoksr/notify"
	"github.com/nikoksr/notify/service/telegram"
)

func main() {
	fmt.Println("Hello, world!")
	// Create a telegram service. Ignoring error for demo simplicity.
	telegramService, _ := telegram.New("5336271636:AAGukDhGwROZv2fD9xeyzvkoV70C74fZQ6w")

	// Passing a telegram chat id as receiver for our messages.
	// Basically where should our message be sent?
	telegramService.AddReceivers(-5377069547)

	notify.UseServices(telegramService)

	// Send a test message.
	err := notify.Send(
		context.Background(),
		"Subject/Title",
		"The actual message - Hello, you awesome gophers! :)",
	)

	fmt.Println("Error:", err)
}
