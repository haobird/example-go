package ac

// Policy consists of rules and constranits to validate Resource against.
// 策略由规则和约束来验证资源是否有权限访问。
type Policy struct {
	ID      string
	Version string
	Name    string
	Owner   string
	Rules   []Rule
	// Constraints represnet general constraints such as subject constraints
	// or temporal/spacial constraints related to the context of the execution.
	// 约束表示一般约束，例如主体约束或关于执行上下文的时间或空间约束。
	Constraints []Constraint
}

// ResourceID returns Policy ID.
// 资源ID返回策略ID。
func (p Policy) ResourceID() string {
	return p.ID
}

// Type returns Policy resource type.
// 资源类型返回策略资源类型。
func (p Policy) Type() string {
	return "policy"
}

// Attributes method returns Policy attributes.
// 属性方法返回策略属性。
func (p Policy) Attributes() map[string]string {
	return map[string]string{
		"version": p.Version,
		"name":    p.Name,
		"owner":   p.Owner,
	}
}

// Evaluate validates the access request against the Policy.
// 通过策略验证请求是否有权限访问。
func (p Policy) Evaluate(subject Resource, action Action, object Resource) bool {
	for _, c := range p.Constraints {
		// Constraints are only evaluated against subject.
		if !c.Validate(subject) {
			return false
		}
	}
	rt := object.Type()
	for _, rule := range p.Rules {
		if rule.ResourceType == rt {
			for _, a := range rule.Actions {
				if a == Any || a == action {
					// Matcher can be omitted.
					if rule.Matcher == nil || rule.Matcher.Match(subject, object) {
						return rule.Effect
					}
				}
			}
		}
	}
	return false
}

// PolicyRepository exposes Policy persistence API.
type PolicyRepository interface {
	// Save a single policy.
	Save(policy Policy) (string, error)

	// RetrieveByID retrieves the Policy by its ID.
	RetrieveByID(id string) (Policy, error)

	// List returns all the policies that belong to the owner.
	List(owner string) ([]Policy, error)

	// Remove an existing policy.
	Remove(id string) error

	// Attach adds policy to the resource.
	Attach(policyID, resourceID string) error

	// Detach removes policy from the resource.
	Detach(policyID, resourceID string) error
}
