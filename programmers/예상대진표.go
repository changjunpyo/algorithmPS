package main

func solution(n int, a int, b int) int {
	answer := -1
	for i := 1; i < 21; i++ {
		a = (a + 1) / 2
		b = (b + 1) / 2
		if a == b {
			return i
		}
	}
	return answer
}
