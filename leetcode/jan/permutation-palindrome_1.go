func canPermutePalindrome(s string) bool {
    charCount := make(map[rune]int)
    oddCount := 0
    for _ , val := range s{
        charCount[val]++
        if (charCount[val] % 2 ==1){
            oddCount++;
        } else{
            oddCount--;
        }
    }
    if len(s) %2 == 0{
        if (oddCount == 0){
            return true;
        } else{
            return false;
        }
    } else{
        if (oddCount == 1){
            return true;
        } else{
            return false;
        }
    }
    
}