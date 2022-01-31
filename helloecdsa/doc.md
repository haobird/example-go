# 加密说明

## 比对流程

### 确定 puk 和 priker

```
pubker = `-----BEGIN PUBLIC KEY-----
MFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAE7mU/3m2URGywg1uYL9rUosMb/i54
4kzJ5xHg/cZ9oM9wC3V3+OMKw+4Tkxs8lMznwMHxxAbVcZUOeRpc8jgrjQ==
-----END PUBLIC KEY-----`
priker = `-----BEGIN PRIVATE KEY-----
MEECAQAwEwYHKoZIzj0CAQYIKoZIzj0DAQcEJzAlAgEBBCDL9833IX0JVALjoeB1
StEOUtTnLhHsQ3eds2Y47IEE+A==
-----END PRIVATE KEY-----`
publicKey  = "MFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAE7mU_3m2URGywg1uYL9rUosMb_i544kzJ5xHg_cZ9oM9wC3V3-OMKw-4Tkxs8lMznwMHxxAbVcZUOeRpc8jgrjQ"
privateKey = "MEECAQAwEwYHKoZIzj0CAQYIKoZIzj0DAQcEJzAlAgEBBCDL9833IX0JVALjoeB1StEOUtTnLhHsQ3eds2Y47IEE-A"
data       = "USER0001202004151958010871292app0001202004161020152918451test8888123456"
```

### Java自身验证

生成 新的签名
使用 publicKey 校验 签名 是否为 true

### Golang自身验证

生成 新的签名
使用 publicKey 校验 签名 是否为 true

### 比对校验

使用 Golang生成的签名，使用Java的PubKey校验



## Java



