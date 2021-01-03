func canFormArray(arr []int, pieces [][]int) bool {
    for i:=0; i<len(arr);{
        find := false;
        idx := 0
        for j:=0; j<len(pieces); j++{
            if (arr[i] == pieces[j][0]) {
                find = true
                idx = j
                break;
            }
        }
        if (!find) {
            return false
        }
        for j:=0; j<len(pieces[idx]); j++{
            if (arr[i] != pieces[idx][j]){
                return false;
            }
            i++
        }
    }
    return true;
}

// binary & hashmap version add needed!