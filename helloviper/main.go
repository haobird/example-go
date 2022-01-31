package main

import (
	"fmt"
	"os"
	"strings"

	"github.com/spf13/viper"
)

func main() {
	path := "config.yaml"
	viper.SetConfigFile(path)                    // 如果指定了配置文件，则解析指定的配置文件
	if err := viper.ReadInConfig(); err != nil { // viper解析配置文件
		panic(fmt.Errorf("Fatal error config file: %w \n", err))
	}
	rotate_date := viper.GetString("zk.group.tobprefix")
	fmt.Println(rotate_date)
}

//
func test() {
	err := os.Setenv("LOG_ROTATE_DATE", "50")
	fmt.Println(err)
	path := "config.yaml"
	LoadConfig(path)
	rotate_date := viper.GetString("zk.group.tobprefix")
	fmt.Println(rotate_date)
}

// 读取配置
func LoadConfig(path string) {
	if path != "" {
		viper.SetConfigFile(path) // 如果指定了配置文件，则解析指定的配置文件
	} else {
		viper.AddConfigPath(".") // 如果没有指定配置文件，则解析默认的配置文件
		viper.SetConfigName("config")
	}
	viper.SetConfigType("yaml") // 设置配置文件格式为YAML
	viper.AutomaticEnv()        // 读取匹配的环境变量
	// viper.SetEnvPrefix("APP")   // 读取环境变量的前缀为 APP
	replacer := strings.NewReplacer(".", "_")
	viper.SetEnvKeyReplacer(replacer)
	if err := viper.ReadInConfig(); err != nil { // viper解析配置文件
		panic(fmt.Errorf("Fatal error config file: %w \n", err))
	}
}
