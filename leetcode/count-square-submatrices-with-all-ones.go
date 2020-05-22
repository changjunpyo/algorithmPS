func countSquares(matrix [][]int) int {
    ret :=0
    row := len(matrix)
    col := len(matrix[0])
    for x:=row-1; x>=0; x--{
        for y:=col-1; y>=0; y--{
            if matrix[x][y] >0 && x< row-1 && y <col-1 {
                matrix[x][y] += min(matrix[x+1][y], min(matrix[x][y+1], matrix[x+1][y+1]))
            }        
            ret += matrix[x][y]
        }
    }
    return ret
}

func min(a,b int) int{
    if a > b {
        return b
    }else{
        return a
    }
}
