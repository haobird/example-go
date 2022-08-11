package session

type Handler interface {
	AuthConnect(client *Client) error

	AuthPublish(client *Client, topic *string, payload *[]byte) error

	AuthSubscribe(client *Client, topics *[]string) error

	Connect(client *Client)

	Publish(client *Client, topic *string, payload *[]byte)

	Subscribe(client *Client, topics *[]string)

	Unsubscribe(client *Client, topics *[]string)

	Disconnect(client *Client)
}
