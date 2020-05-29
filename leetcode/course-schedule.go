
func checkCycle(visited, recCheck []bool, n, idx int, adj [][]int) bool{
    visited[idx] = true
    recCheck[idx] = true
    for i:=0; i<len(adj[idx]); i++{
        if !visited[adj[idx][i]] && checkCycle(visited,recCheck,n,adj[idx][i], adj){
            return true
        } else if recCheck[adj[idx][i]]{
            return true
        }
    }
    recCheck[idx] = false
    return false
}


func canFinish(numCourses int, prerequisites [][]int) bool {
    adj := make([][]int, numCourses)
    visited := make([]bool, numCourses)
    recCheck := make([]bool, numCourses)
    for i:=0; i<numCourses; i++{
        adj[i] = make([]int, 0)
    }
    
    for i:=0; i<len(prerequisites); i++{
        adj[prerequisites[i][1]] = append(adj[prerequisites[i][1]],  prerequisites[i][0])
    }
    for i:=0; i<numCourses; i++{
        if checkCycle(visited,recCheck,numCourses,i,adj) {
            return false;
        }
    }
    return true
}