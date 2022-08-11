package ac

// Resource represents any resource in the system.
// All the actions are executed by Resource and against Resource.
// 资源表示系统中的任何资源。
// 所有的操作都由资源执行，并与资源进行比较。
type Resource interface {
	ResourceID() string
	Type() string
	Attributes() map[string]string
}

// Constraint is Policy constraint.
// 约束是策略的约束。
type Constraint interface {
	Validate(r Resource) bool
}
