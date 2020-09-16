type trie struct{
    child [2]*trie
}

func newChild() *trie{
    return &trie{child : [2]*trie{nil,nil}}
}

func (t *trie)updateTrie(num int) {
    node := t
    for i:=31 ; i>=0; i--{
        bitFlag := (num >> uint(i) )& 1
        if node.child[bitFlag] == nil{
            node.child[bitFlag] = newChild()   
        } 
        node = node.child[bitFlag]
    }
}

func (t *trie)findMax(num int) int{
    node := t
    ret := 0
    for i:=31; i>=0; i--{
        bitFlag := (num >> uint(i) )& 1
        if (bitFlag == 1 && node.child[0] != nil) ||( bitFlag == 0 && node.child[1] != nil) {
            node = node.child[1 ^ bitFlag]
            ret += (1<< uint(i) )
        } else{
            node = node.child[bitFlag]
        }
        
    }
    return ret
}



func findMaximumXOR(nums []int) int {
    t := newChild()
    ans := 0 
    for _, val := range nums {
        t.updateTrie(val)
    }
    
    for _, val := range nums {
        result := t.findMax(val)
        if ans < result{
            ans = result
        }
    }
    return ans
    
}

