package main

import "strconv"

func solution(s string) []int {
	cnt := 0
	total := 0
	for len(s) != 1 {
		now := 0
		for i := 0; i < len(s); i++ {
			if s[i] == '1' {
				now++
			}
		}
		cnt++
		total += len(s) - now
		s = strconv.FormatInt(int64(now), 2)
	}

	return []int{cnt, total}
}
