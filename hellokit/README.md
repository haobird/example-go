# 项目说明

## 项目分为三层

* transport
* endpoint
* service


### 1. service

service 是业务逻辑开始的地方。 定义一个 Service 接口。
接口将包含一个具体实现。

### 2. endpoint 

框架里的定义：
```
type Endpoint func(ctx context.Context, request interface{}) (response interface{}, err error)
```

每个端点代表服务接口中的单个方法。 编写简单的适配器来将服务中的每个方法转换为端点。每个 适配器接收一个 Service ,并返回一个对应于其中一个方法的端点。

端点的中间件
```
type Middleware func(Endpoint) Endpoint
```

### 3. transport

对外提供服务的入口。

kit 针对 各种协议分别提供包：
前缀路径： github.com/go-kit/kit/
* http :  transport/http
* thrift: 
* gRPC:  transport/grpc
* jsonrpc: transport/http/jsonrpc



### 4. middlewares 

中间件可以包装端点或服务来添加功能，如：日志记录，速率限制，负载均衡或分布式跟踪。
围绕一个端点或服务连接多个中间件是很常见的。

### 5. example

```
logger := log.NewLogger(...)

var service todo.Service    // interface
service = todo.NewService() // concrete struct
service = todo.NewLoggingMiddleware(logger)(service)

endpoints := todo.NewEndpoints(service)
transport := todo.NewHTTPTransport(endpoints)
```

### 可观察性分为

* logging 日志
* metrics 指标质量
* tracing 链路跟踪

各中间件的包
* tracing : github.com/uber/jaeger-client-go/config
* tracing : github.com/opentracing/opentracing-go
* metrics : github.com/go-kit/kit/metrics/prometheus
* metrics : github.com/prometheus/client_golang/prometheus

### 提供服务

```
type StringService interface {
	Uppercase(string) (string, error)
	Count(string) int
}
```

### service (业务流程)

```
type StringService
type stringService
func Uppercase
func Count
var ErrEmpty
```

### transport 

http

```http
// router
func MakeHandler

// decode request and encode response
func decodeUppercaseRequest
func decodeCountRequest
func encodeResponse

// handle error 
func encodeError
```

gRPC

```gRPC

// implement rpc interface
type grpcServer

// create grpc server use kitgrpc.NewServer
func NewServer

// decode request and encode response
func decodeUppercaseRequest
func decodeCountRequest
func encodeResponse
func encodeEmptyResponse

// handle error
func encodeError
```

thrift

```thrift
// implement thrif interface
type thriftServer

// create thrif server user 
func NewServer

// 如果 是原始参数，则不需要解析 对应的数据
```

```jsonrpc

// returns a JSON RPC Server/Handler that can be passed to http.Handle() 
func NewHandler

// makeEndpointCodecMap returns a codec map configured for the 
func makeEndpointCodecMap

// decode request and encode response
func decodeUppercaseRequest
func decodeCountRequest
func encodeResponse

```

### endpoint

注意：

```
type Endpoints struct {
    SumEndpoint      endpoint.Endpoint
    ConcatEndpoint   endpoint.Endpoint
}

func MakeEndpoints Endpoints

// request and response
type uppercaseRequest
type uppercaseResponse
type countRequest
type countResponse

// create endpoint
func makeUppercaseEndpoint
func makeCountEndpoint

// middleware
func InstrumentingMiddleware
func LoggingMiddleware
```

### 中间件

tracer 需要在 Server 中增加
logger 需要在 Service 的中间件
metrics 需要在 Service 的中间件

还有一部分 tracing 需要在 Repository 中间件中



### Server boot

#### http

```
errs <- http.ListenAndServe(p, api.NewHTTPHandler(svc, tracer))
```

#### gRPC

```
listener, err := net.Listen("tcp", p)

var server *grpc.Server
server = grpc.NewServer()
addsvc.RegisterAddServer(server, api.NewGRPCServer(svc, tracer))
errs <- server.Serve(listener)
```

#### thrift

```
processor = addthrift.NewAddServiceProcessor(api.NewThriftServer(svc, tracer))

thriftSocket, err := thrift.NewTServerSocket(*thriftAddr)
protocolFactory = thrift.NewTBinaryProtocolFactoryDefault()
transportFactory = thrift.NewTTransportFactory()
// transportFactory = thrift.NewTFramedTransportFactory(transportFactory)
server := thrift.NewTSimpleServer4(processor, serverTransport, transFactory, protoFactory)
server.SetLogger(RPCLogger)
errs <- server.Serve()
```

### kit提供的协议包使用

#### http
transport/http:
```
uppercaseHandler := httptransport.NewServer(
    makeUppercaseEndpoint(svc),
    decodeUppercaseRequest,
    encodeResponse,
)

countHandler := httptransport.NewServer(
    makeCountEndpoint(svc),
    decodeCountRequest,
    encodeResponse,
)

http.Handle("/uppercase", uppercaseHandler)
http.Handle("/count", countHandler)
log.Fatal(http.ListenAndServe(":8080", nil))
```

#### mux

```
opts := []kithttp.ServerOption{
    kithttp.ServerErrorEncoder(encodeError),
}
mux.Post("/keys", kithttp.NewServer(
    kitot.TraceServer(tracer, "issue")(issueEndpoint(svc)),
    decodeIssue,
    encodeResponse,
    opts...,
))

mux.Get("/keys/:id", kithttp.NewServer(
    kitot.TraceServer(tracer, "retrieve")(retrieveEndpoint(svc)),
    decodeKeyReq,
    encodeResponse,
    opts...,
))

mux.Delete("/keys/:id", kithttp.NewServer(
    kitot.TraceServer(tracer, "revoke")(revokeEndpoint(svc)),
    decodeKeyReq,
    encodeResponse,
    opts...,
))

return mux
```