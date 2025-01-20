package main

import (
	"fmt"
)

var matrix [][]int

var rmin []int
var rmin1 []int

func main() {

	var row, cols int
	var min = 1000000000000

	fmt.Scan(&row)
	fmt.Scan(&cols)
	matrix = make([][]int, row)
	for i := 0; i < row; i++ {
		matrix[i] = make([]int, cols)
		for j := 0; j < cols; j++ {
			var t int
			fmt.Scan(&t)
			if min > t && t%3 == 0 {
				min = t

			}

			matrix[i][j] = t
		}
	}
	if min == 1000000000000 {
		min = 10
	}
	for i := 0; i < row; i++ {
		for j := 0; j < cols; j++ {

			if matrix[i][j] == min {
				rmin = append(rmin, j)
				// } else if matrix[i][j]%min == 0 {
				//   for n, _ := range rmin {
				//     rmin[n] = -1
				//   }
				//   rmin1 = append(rmin, j)
			}

		}
	}

	for i := 0; i < row; i++ {
		for j := 0; j < cols; j++ {

			if matrix[i][j]%min == 0 && matrix[i][j] != min {

				for n, m := range rmin {
					if j == m {
						rmin1 = append(rmin1, j)
						rmin[n] = -1
					}

				}

			}

		}
	}
	for i := 0; i < row; i++ {
		for j := 0; j < cols; j++ {

			for _, n := range rmin {
				if j == n {
					matrix[i][j] = 0
				}

			}
			for _, n := range rmin1 {
				if j == n {
					matrix[i][j] = 1
				}

			}

		}
	}
	for i := 0; i < row; i++ {
		for j := 0; j < cols; j++ {

			fmt.Print(matrix[i][j])
			fmt.Print(" ")
		}
		fmt.Print("\n")
	}

}
