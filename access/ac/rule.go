package ac

// Action represents any action.
type Action int64

// Predefined list of actions.
const (
	Any Action = iota
	Create
	Update
	Delete
	Read
	Write
)

// Rule represents Policy rule.
// 规则表示策略规则
type Rule struct {
	Actions      []Action
	ResourceType string
	Effect       bool
	Matcher      Matcher
}

// Matcher represents Rule matcher.
// 匹配器表示规则匹配器
type Matcher interface {
	Match(subject, object Resource) bool
}
