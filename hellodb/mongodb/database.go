package mongodb

import (
	"context"

	"github.com/opentracing/opentracing-go"
)

const (
	layoutISO = "2006-01-02T15:04:05.000Z"
)

func getOrderQuery(order string) string {
	switch order {
	case "timestamp":
		return "timestamp"
	default:
		return "id"
	}
}

func getDirQuery(dir string) int8 {
	switch dir {
	case "asc":
		return 1
	default:
		return -1
	}
}

func getFilterQuery(filter map[string]interface{}) map[string]interface{} {
	// newFilter := bson.M{}
	return filter
}

func addSpanTags(ctx context.Context, query string) {
	span := opentracing.SpanFromContext(ctx)
	if span != nil {
		span.SetTag("sql.statement", query)
		span.SetTag("span.king", "client")
		span.SetTag("peer.service", "postgres")
		span.SetTag("db.type", "sql")
	}
}
