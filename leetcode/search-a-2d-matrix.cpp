class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int x = -1;
        int l= 0;
        int h= matrix.size()-1;
        while (l <= h){
            int mid = (l+h)/2;
            if (matrix[mid][0] <= target && matrix[mid][matrix[mid].size() - 1] >= target){
                x = mid; 
                break;
            }
            if (matrix[mid][0] < target)
                l = mid+1;
            else
                h = mid-1;
        }
        if (x == -1) return false;
        int a = 0;
        int b =matrix[0].size()-1;
        while(a <=b){
            int mid = (a+b)/2;
            if (matrix[x][mid] < target)
                a = mid+1;
            else
                b= mid-1;
        }
        return matrix[x][a] == target;
    }
};