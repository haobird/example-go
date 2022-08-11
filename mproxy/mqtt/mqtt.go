package mqtt

import (
	"crypto/tls"
	"errors"
	"log"
	"net"

	"hellomproxy/session"
)

var (
	errCreateListener = errors.New("failed to create listener")
)

type Proxy struct {
	address string
	target  string
	handler session.Handler
	dialer  net.Dialer
}

func New(address, target string, handler session.Handler) *Proxy {
	return &Proxy{
		address: address,
		target:  target,
		handler: handler,
	}
}

func (p Proxy) accept(l net.Listener) {
	for {
		conn, err := l.Accept()
		if err != nil {
			log.Println("Accept error:", err)
			continue
		}

		log.Println("Accepted connection:", conn.RemoteAddr())
		go p.handle(conn)
	}
}

func (p Proxy) handle(inbound net.Conn) {
	defer p.close(inbound)

	outbound, err := p.dialer.Dial("tcp", p.target)
	if err != nil {
		log.Println("Dial error:", err)
		return
	}

	defer p.close(outbound)
}

func (p Proxy) Listen() error {
	l, err := net.Listen("tcp", p.address)
	if err != nil {
		return err
	}

	defer l.Close()

	p.accept(l)

	log.Println("Server Exiting...")
	return nil
}

func (p Proxy) ListenTLS(tlsCfg *tls.Config) error {
	l, err := tls.Listen("tcp", p.address, tlsCfg)
	if err != nil {
		return err
	}
	defer l.Close()

	p.accept(l)

	log.Println("Server Exiting...")
	return nil
}

func (p Proxy) close(conn net.Conn) {
	if err := conn.Close(); err != nil {
		log.Println("Close error:", err)
	}
}
