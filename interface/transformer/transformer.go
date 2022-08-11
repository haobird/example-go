package transformer

type Message struct{}

type Transformer interface {
	Transform(Message) (interface{}, error)
}

type funcTransformer func(Message) (interface{}, error)

func (fh funcTransformer) Transform(msg Message) (interface{}, error) {
	return fh(msg)
}

func transformer(msg Message) (interface{}, error) {
	return msg, nil
}

func New() Transformer {
	return funcTransformer(transformer)
}
