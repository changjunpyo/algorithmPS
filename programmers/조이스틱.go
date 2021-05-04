package main

func min(a, b int) int {
	if a > b {
		return b
	} else {
		return a
	}
}
func solution(name string) int {
	ans := 0
	nextMove := len(name) - 1
	for i := 0; i < len(name); i++ {
		last := -1
		for j := i; j < len(name) && name[j] == 'A'; j++ {
			last = j
		}
		if last != -1 {
			nextMove = min(nextMove, 2*i-3+len(name)-last)
			i = last
		}
		charMoveCount := int(name[i] - 'A')
		ans += min(charMoveCount, 26-charMoveCount)

	}

	return ans + nextMove
}
