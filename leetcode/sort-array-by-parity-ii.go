func sortArrayByParityII(A []int) []int {

    // time complexity :O(n) 
    // space complexty : O(n)
    /*
    even := 0
    odd := 1
    B := make([]int,len(A))
    for i:=0; i<len(A); i++{
        if A[i]%2 ==0{
            B[even] = A[i]
            even += 2
        } else{
            B[odd] = A[i]
            odd += 2
        }
    }
    return B
    */
    
    // time complexity :O(n) 
    // space complexty : O(1)
    odd :=1
    for i:=0; i<len(A); i+=2{
        if A[i] %2 == 1{
            
            for ;A[odd]%2 ==1;{
                odd+=2
            }
            
            temp := A[i]
            A[i] = A[odd]
            A[odd] = temp
        }
    }
    return A
}