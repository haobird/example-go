package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strings"

	"github.com/davecgh/go-spew/spew"
	"github.com/spf13/viper"
	"gopkg.in/yaml.v2"
)

func main() {
	path := "config.yaml"

	LoadConfig(path)

	conf := loadConfig("dmapper.yaml")
	devices := conf.Dmapper.Devices
	spew.Dump(devices)

	// mapper := viper.GetStringMap("dmapper.mapper")
	// spew.Dump(mapper)

	rotate_date := viper.GetString("zk.group.tobprefix")
	spew.Dump(rotate_date)
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

type Config struct {
	Dmapper struct {
		Devices map[string]string `yaml:"devices"`
	}
}

func loadConfig(path string) Config {
	var config Config
	File, err := ioutil.ReadFile(path)
	if err != nil {
		panic(fmt.Errorf("Fatal error config file: %w \n", err))
	}
	err = yaml.Unmarshal(File, &config)
	if err != nil {
		panic(fmt.Errorf("failed to parse yaml: %v", err))
	}
	return config
}
