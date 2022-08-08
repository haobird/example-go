package helper

import (
	"fmt"
	"hellolog/logger"
	"os"
	"strings"

	"github.com/pkg/errors"
	"github.com/spf13/viper"
)

// 获取环境变量信息
func GetEnvDefault(key, defVal string) string {
	val, ex := os.LookupEnv(key)
	if !ex {
		return defVal
	}
	return val
}

// LoadConfig 读取yaml配置
func LoadConfig(confPath, envPrefix string) {
	// 加载日志文件
	viper.SetConfigFile(confPath) // 如果指定了配置文件，则解析指定的配置文件
	viper.AutomaticEnv()          // 读取匹配的环境变量
	viper.SetEnvPrefix(envPrefix) // 读取环境变量的前缀为 APP
	replacer := strings.NewReplacer(".", "_")
	viper.SetEnvKeyReplacer(replacer)
	if err := viper.ReadInConfig(); err != nil { // viper解析配置文件
		panic(fmt.Errorf("Fatal error config file: %w \n", err))
	}
}

//InitLog 加载log配置
func InitLog() {
	logger.Init(&logger.Cfg{
		Level:        viper.GetString("log.level"),
		File:         viper.GetString("log.file"),
		RotatePolicy: viper.GetString("log.rotatePolicy"),
		RotateTime:   viper.GetInt("log.rotate_time"),
		RotateSize:   viper.GetInt("log.rotate_size"),
		MaxBackup:    viper.GetInt("log.max_backup"),
		MaxAge:       viper.GetInt("log.max_age"),
		FormatText:   viper.GetBool("log.format_text"),
		FormatColor:  viper.GetBool("log.format_color"),
		FormatReport: viper.GetBool("log.format_report"),
	})
}

func WrapErr(err error, wrapper error) error {
	if wrapper == nil || err == nil {
		return wrapper
	}
	return errors.Wrap(err, wrapper.Error())
}
