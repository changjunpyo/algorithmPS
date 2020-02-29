class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //row
        for (int i=0; i<9; i++){
            bool visited[9]={false,};
            for (int j=0; j<9; j++){
                if (board[i][j] =='.')
                    continue;
                if (visited[board[i][j]-'1'])
                    return false;
                visited[board[i][j]-'1']=true;
            }
        }
        for (int i=0; i<9; i++){
            bool visited[9]={false,};
            for (int j=0; j<9; j++){
                if (board[j][i] =='.')
                    continue;
                if (visited[board[j][i]-'1'])
                    return false;
                visited[board[j][i]-'1']=true;
            }
        }
        for (int i=0; i<9; i+=3){
            for (int j=0; j<9; j+=3){
                bool visited[9]={false,};
                for (int x=0; x<3; x++){
                    for (int y=0; y<3; y++){
                        if (board[i+x][j+y] =='.')
                            continue;
                        if (visited[board[i+x][j+y]-'1'])
                            return false;
                        visited[board[i+x][j+y]-'1']=true;
                    }
                }
            }
        }
       return true; 
    }
};