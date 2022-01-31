package main

import (
	"encoding/base64"
	"fmt"

	"github.com/haobird/learngo/helloecdsa/ecdsa"
)

var (
	pubker1 = `-----BEGIN PUBLIC KEY-----
MFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAE7mU/3m2URGywg1uYL9rUosMb/i54
4kzJ5xHg/cZ9oM9wC3V3+OMKw+4Tkxs8lMznwMHxxAbVcZUOeRpc8jgrjQ==
-----END PUBLIC KEY-----`
	priker1 = `-----BEGIN PRIVATE KEY-----
MEECAQAwEwYHKoZIzj0CAQYIKoZIzj0DAQcEJzAlAgEBBCDL9833IX0JVALjoeB1
StEOUtTnLhHsQ3eds2Y47IEE+A==
-----END PRIVATE KEY-----`
)

func main() {

	ec, err := ecdsa.NewEcdsaR1Handle(pubker, priker)

	if err != nil {
		fmt.Println(err)
	}

	// str := `USER0001202004151958010871292app0001202004161020152918451test8888123456`
	//     USER0001202004161009309407413app0001202004161017141233920QU5oOUxvZW5JQS4uOXFkTTB8YzNLT3FBcc_app0001202004161017141233920_00set{"baseKey":"test20200421","baseValue":"this is string "}testtesttesttesttest
	str := `POST&/bridge/s2s/echo&abc&1636947572729`
	data := []byte(str)
	digest, _ := ec.Hash(data)
	// sign := "MEQCID1GWAsqfWt8/rDMKIIkg+xigE3GEfBb6AveYT2dKMSjAiAls4YaxNDBZ6K0vXgUvMWdcidnmdhbKCqw7NfM9JgFww=="
	// sign := "MEUCIQDxadoMNh6nW28SZ644TgJfUdoGJW9DW8mxZ9-jFV8gjAIgau_lHi_UDzRa10jPA7415aOsy0fExUjHitu2vRf2jqE"
	// sign := "MEQCIHSRjB_HqdLGalHAlfCK7Jqx_i1JPL7qxvL9GVYYHuiaAiAnd4pBldkkTjiNh3H3QDd7G7Ule-OFBN_9OIS7rI-KNg"
	// sign := "MEQCIG0koDIxSJiv6PL8tanMz_ue5eWjBJgWScUmfJi8y_3cAiBDGtqdDEve1hjtzZPJBskI3ERLt5QwGzx_AXXVnSi4Og"
	sign := "MEQCIDAz5ohY7Z0c8TmL9_zREk8paqcXAiuBBm1fCmZOmfKgAiB2Y6l1vPuCjkyhc-NeWZI9-Me3mTHmjukE-U2Q_VwXQg"
	si, _ := base64.RawURLEncoding.DecodeString(sign)

	// 生成 签名的二进制
	// si, _ := ec.Sign(digest)

	// sign := base64.RawURLEncoding.EncodeToString(si)

	fmt.Println("sign:", sign)
	// 校验 二进制签名 与 加密前数据
	b, err := ec.Verify(si, digest)

	if err != nil {
		fmt.Println(err)
	}

	fmt.Println(b)
}
