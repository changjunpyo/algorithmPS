package main

func solution(absolutes []int, signs []bool) int {
	ans := 0
	for idx, val := range absolutes {
		if signs[idx] {
			ans += val
		} else {
			ans -= val
		}
	}
	return ans
}
