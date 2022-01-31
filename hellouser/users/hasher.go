package users

// Hasher specifies an API for generating hashers of an arbitrary textual content.
type Hasher interface {
	Hash(string) (string, error)

	Compare(string, string) error
}
