package main

import (
	"flag"
	"fmt"
	"strconv"

	"github.com/360EntSecGroup-Skylar/excelize"
)

type SectionConf struct {
	itemIndex   int
	typeIndex   int
	marketIndex int
}

var (
	name        = flag.String("name", "", "go flag test")
	sheet       = "Sheet1"
	sectionConf = SectionConf{
		itemIndex:   16,
		typeIndex:   20,
		marketIndex: 13,
	}
)

func main() {
	// 解析命令行参数
	flag.Parse()
	if *name == "" {
		panic("文件名称不能为空")
	}

	// 获取数据源数据
	rows, err := fetchRows(*name)
	if err != nil {
		panic(err)
	}

	// 获取区块配置
	// 基于首列 搜索 AmazonOrderItemCode 关键字，以此为开启标记
	for i, name := range rows[0] {
		if name == "AmazonOrderItemCode" {
			sectionConf.itemIndex = i
		}
		if name == "Type" {
			sectionConf.typeIndex = i
		}
	}

	// 创建新的 excel rows
	newRows := make([][]string, 0)

	// 循环处理旧资源的数据，逐渐添加到新资源中
	flag := 0 // 0 代表未开启， 1 代表开启重置， 2 代表关闭
	n := 0

	section := make([][]string, 0)
	for i, row := range rows {
		// 前两行直接赋值
		// fmt.Printf("第%d行--13列:%s, 16列:%s,flag:%d\n", i, row[13], row[16], flag)

		// 如果 重置已经开启，出现 13列为空，则说明需要重置的区块已经没有了，后续直接复制即可
		if flag == 1 && row[sectionConf.marketIndex] == "" {
			flag = 2
		}

		// 如果 重置关闭状态，且 出现 16行有值，则开始重置区块功能
		if flag < 1 && row[sectionConf.itemIndex] != "" {
			flag = 1
		}

		if i < 2 {
			flag = 0
		}

		// 第三行开始，判断 16是否有值，有值则为本区块的初始行，直到下次出现，则该次区块结束
		if flag == 1 && row[sectionConf.itemIndex] != "" {
			if n > 0 {
				// 处理上一次的 重置区块，实现多行变一行
				newSection := dealSection2(section)
				newRows = append(newRows, newSection...)
				section = make([][]string, 0)
			}

			// if n > 2 {
			// 	break
			// }
			n++
		}

		// 如果关闭状态，则直接复制行即可，如果开启状态，说明处于重置区域
		if flag != 1 {
			newRows = append(newRows, row)
		} else {
			section = append(section, row)
		}
	}

	// 把新数据写入新文件中
	f1 := excelize.NewFile()
	for i, row := range newRows {
		// fmt.Printf("amout:%s, %s\n", row[20], row[21])
		f1.SetSheetRow(sheet, "A"+strconv.Itoa(i+1), &row)
	}

	// 保存文件

	newName := fmt.Sprintf("%s-修正.xlsx", *name)
	if err := f1.SaveAs(newName); err != nil {
		panic(err)
	}

}

func fetchRows(name string) (rows [][]string, err error) {
	path := fmt.Sprintf("%s.xlsx", name)
	// 读取 excel文件
	f, err := excelize.OpenFile(path)
	if err != nil {
		err = fmt.Errorf("打开文件【%s】失败", path)
		return
	}

	// 读取 sheet的所有数据
	// Get all the rows in the Sheet1.
	rows = f.GetRows(sheet)
	return
}

func dealSection2(section [][]string) [][]string {
	fmt.Printf("该区块的行数为:%d\n", len(section))
	commonRow := section[0]
	newSection := make([][]string, 0)
	flag := false
	// n := 0
	for _, row := range section {
		if !flag && row[sectionConf.typeIndex] != "" {
			flag = true
			fmt.Printf("开始处理 Type[%d]:%s ,数据：%v\n", sectionConf.typeIndex, row[sectionConf.typeIndex], commonRow[16:])
		}

		// 处理归并的行
		if !flag {
			// 在 16-19 之间，谁不为空，就顶上去谁
			for j := sectionConf.itemIndex; j <= sectionConf.typeIndex-1; j++ {
				if row[j] != "" {
					commonRow[j] = row[j]
				}
			}
		} else {
			for j := sectionConf.itemIndex; j <= sectionConf.typeIndex-1; j++ {
				row[j] = commonRow[j]
			}
			newSection = append(newSection, row)
		}
	}

	return newSection

}
