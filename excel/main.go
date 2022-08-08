package main

import (
	"fmt"
	"strconv"

	"github.com/360EntSecGroup-Skylar/excelize"
)

var (
	f1 = excelize.NewFile()
	n  = 1
)

func main() {

	// Get value from cell by given worksheet name and axis.
	cell := f.GetCellValue("Sheet1", "B1")
	fmt.Println(cell)

	sheets := f.GetSheetMap()
	fmt.Println(sheets)

	sheet := f.GetSheetName(1)
	fmt.Println(sheet)

	// 创建一个工作表
	index := f1.NewSheet("Sheet1")
	// 设置工作簿的默认工作表
	f1.SetActiveSheet(index)
	f1.SetCellValue("Sheet1", "A1", "string")

	// Get all the rows in the Sheet1.
	rows := f.GetRows(sheet)
	fmt.Println(len(rows))
	addline(rows[0])
	// fmt.Println(rows[5][20])
	// return
	section := [][]string{}
	flag := true
	for i, row := range rows {
		if i < 2 {
			continue
		}

		// 判断是否起始端, 则为起始端
		if flag && row[16] != "" {
			if len(section) > 0 {
				temp := section[0 : len(section)-3]
				for _, v := range temp {
					// 处理每一行的16 17都等于首行
					v[16] = temp[0][16]
					v[17] = temp[0][17]
					addline(v)
				}
				section = [][]string{}
			}
		}

		if flag && row[13] == "" {
			fmt.Println(i)
			if len(section) > 0 {
				temp := section[0 : len(section)-3]
				for _, v := range temp {
					v[16] = temp[0][16]
					v[17] = temp[0][17]
					addline(v)
				}
				section = [][]string{}
			}
			flag = false
		}

		if flag {
			tempRow := deal(i, row, rows)
			section = append(section, tempRow)
		} else {
			addline(row)
		}

	}

	fmt.Println("保存文件")

	// 根据指定路径保存文件
	if err := f1.SaveAs("2022.5.6-5.20结算报告.xlsx"); err != nil {
		fmt.Println(err)
	}
}

func deal(i int, row []string, rows [][]string) []string {
	if (i + 3) >= len(rows) {
		return row
	}
	// SKU
	row[17] = rows[i+1][17]
	// Quantity
	row[18] = rows[i+2][18]
	// Type
	row[19] = rows[i+3][19]
	// Amount
	row[20] = rows[i+3][20]
	// currency2
	row[21] = rows[i+3][21]
	// Type3
	row[22] = rows[i+3][22]
	// Amount4
	row[23] = rows[i+3][23]
	// currency5
	row[24] = rows[i+3][24]
	// MerchantPromotionID
	row[25] = rows[i+3][25]
	// Type6
	row[26] = rows[i+3][26]
	// Amount7
	row[27] = rows[i+3][27]
	// currency8
	row[28] = rows[i+3][28]
	return row
}

func addline(row []string) {
	f1.SetSheetRow("Sheet1", "A"+strconv.Itoa(n), &row)
	n++
}
