
class Solution {
    const int dx[8]={-1,-1,-1,0,0,1,1,1};
    const int dy[8]={-1,0,1,-1,1,-1,0,1};
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> v(board.size(), vector<int>(board[0].size()));
        for (int i=0; i<board.size(); i++){
            for (int j=0; j<board[i].size(); j++){
                int count =0;
                for (int k=0; k<8; k++){
                    int x = i+dx[k];
                    int y = j+dy[k];
                    if (x >=0 && y>=0 && x<board.size() && y<board[0].size())
                        if (board[x][y] == 1) count++;
                }
                if (board[i][j] ==1){
                    if (count < 2) v[i][j] = 0;
                    else if (count >3) v[i][j] = 0;
                    else v[i][j] = board[i][j];
                }
                else{
                    if (count == 3) v[i][j] = 1;
                    else v[i][j] = 0;
                }
            }
        }
        board.clear();
        board.assign(v.begin(), v.end());
        
    }
};