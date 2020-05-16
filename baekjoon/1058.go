package main 

import "fmt"

func main(){
	var N int
	fmt.Scan(&N);
	var arr [50] string

	for i:=0; i<N; i++{
		fmt.Scan(&arr[i])
	}
	ans := 0
	for i:=0; i<N; i++{
		count := 0
		for j:=0; j<N; j++{
			if i==j{
				continue
			}
			if arr[i][j] == 'Y' && arr[j][i] =='Y'{
				count++
				continue
			}
			for k:=0; k<N; k++{
				if i==k || j==k{
					continue
				}
				if arr[i][k] == 'Y' && arr[j][k] == 'Y'{
					count++
					break
				}
			}
		}
		if ans < count{
			ans = count
		}
	}
	fmt.Println(ans)
}