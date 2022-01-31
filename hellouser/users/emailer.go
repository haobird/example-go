package users

// Emailer wrapper around the email
type Emailer interface {
	SendPasswordReset(To []string, host, token string) error
}
