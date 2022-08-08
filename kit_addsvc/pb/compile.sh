#!/usr/bin/env sh

# 生成普通代码
# protoc addsvc.proto --go_out=.

# 生成grpc代码
protoc addsvc.proto --go-grpc_out=.