func kthGrammar(N int, K int) int {
    if N == 1 {
        return 0
    }
    if N == 2{
        if K == 1{
            return 0
        } else{
            return 1
        }
    } 
    x := int(math.Pow(2,float64(N-2)))
    if x < K {
        rest := ((K-1) % x) +1 
        if rest % 2 == 0{
            return kthGrammar(N-1, rest-1)
        } else{
            return kthGrammar(N-1, rest+1)
        }
    } else{
        return kthGrammar(N-1, K)
    }
}