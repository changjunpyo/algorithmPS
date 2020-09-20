func check_visited(grid [][]int, visited[][]bool) bool {
    for i := range grid{
        for j:= range grid[i]{
            if grid[i][j] == 0 && !visited[i][j]{
                return false
            }
        }
    }
    return true
}
func dfs(x,y int, end_point [2]int , dx,dy []int,visited [][]bool , grid [][]int) int {
    if x == end_point[0] && y == end_point[1]{
        if check_visited(grid,visited){
            return 1
        }else{
            return 0
        }
    }
    visited[x][y] = true
    count :=0
    for i:=0; i<4; i++{
        new_x, new_y := x+dx[i],y+dy[i]
        if new_x >= 0 && new_x < len(grid) && new_y >=0 && new_y < len(grid[0]) &&grid[new_x][new_y] != -1  && !visited[new_x][new_y] {
            count += dfs(new_x,new_y, end_point, dx,dy, visited, grid)
        }
    }
    visited[x][y] = false
    return count
}


func uniquePathsIII(grid [][]int) int {
    dx := []int{1,0,-1,0}
    dy := []int{0,1, 0,-1}

    visited := make([][]bool, len(grid))
    var start_point [2]int
    var end_point [2]int
    for i:= range visited{
        visited[i]= make([]bool, len(grid[i]))
    }
    for i := range grid{
        for j:= range grid[i]{
            if grid[i][j] == 1{
                start_point[0],start_point[1] = i,j
            } else if grid[i][j] == 2{
                end_point[0], end_point[1] = i,j
            }
        }
    }

    
    return dfs(start_point[0],start_point[1], end_point,dx,dy , visited, grid)
    
}