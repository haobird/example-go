package emailer

import "github.com/haobird/learngo/hellouser/users"

type emailer struct {
	resetURL string
}

func New(url string) (users.Emailer, error) {
	return &emailer{resetURL: url}, nil
}

func (e *emailer) SendPasswordReset(To []string, host string, token string) error {
	// url := fmt.Sprintf("%s%s?token=%s", host, e.resetURL, token)
	return nil
}
