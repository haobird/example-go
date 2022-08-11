package session

import "crypto/x509"

type Client struct {
	ID       string
	Username string
	Password string
	Cert     x509.Certificate
}
