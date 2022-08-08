#!/usr/bin/env sh

thrift -r --gen "go:package_prefix=github.com/go-kit/examples/addsvc/thrift/gen-go/,thrift_import=github.com/apache/thrift/lib/go/thrift" addsvc.thrift