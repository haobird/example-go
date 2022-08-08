package cmd

import (
	"fmt"
	"os"

	"github.com/spf13/cobra"
)

var (
	rootCmd = &cobra.Command{
		Use:   "hugo",
		Short: "修正导出数据的excel格式",
		Long:  "无",
		Run: func(cmd *cobra.Command, args []string) {
			// Do some thing
		},
	}
)

func Execute() {
	if err := rootCmd.Execute(); err != nil {
		fmt.Fprintln(os.Stderr, err)
		os.Exit(1)
	}
}
