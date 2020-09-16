package main

import (
	"fmt"
)

func check(s string) bool {
	if len(s) == 0{
		return true
	}
	if len(s) >= 2 && s[0] == '0' && s[1] == '1' {
		return check(s[2:])
	}

	if len(s) >= 3 && s[0] == '1' && s[1] == '0' && s[2] =='0' {
		i := 3
		for ; i < len(s); i++ {
			if s[i] == '1' {
				break
			}
		}
		if i >= len(s){
			return false
		}
		t := i
		for ; i < len(s); i++ {
			if s[i] == '0' {
				break
			}
		}
		if t+1 < i {
			return check(s[i-1:]) || check(s[i:])
		}
		return check(s[i:])
	}
	return false
}

func main() {

	var s string
	_, _ = fmt.Scanln(&s)

	if len(s) >= 2 && check(s[:]) {
		fmt.Println("SUBMARINE")
	} else {
		fmt.Println("NOISE")
	}
}
