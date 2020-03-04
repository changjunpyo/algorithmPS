class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> map(3,vector<char>(3,' '));
        bool turn =0;
        int count =0;
        for (auto x : moves){
            count ++;
            if (turn)
                map[x[0]][x[1]] = 'O';
            else
                map[x[0]][x[1]] = 'X';
            turn = !turn;
        }
        // check row
        for (int i=0; i<3; i++){
            if (map[i][0] != ' ' && map[i][0]==map[i][1] && map[i][1]==map[i][2]){
                if (map[i][0]=='X')
                    return "A";
                else
                    return "B";
            }
        }
        for (int i=0; i<3; i++){
            if (map[0][i] != ' ' && map[0][i]==map[1][i] && map[1][i]==map[2][i]){
                if (map[0][i]=='X')
                    return "A";
                else
                    return "B";
            }
        }
        
        if (map[0][0] != ' ' && map[0][0] == map[1][1] && map[1][1] == map[2][2]){
            if (map[0][0]=='X')
                    return "A";
                else
                    return "B";
        }
        if (map[1][1] != ' ' && map[2][0] == map[1][1] && map[1][1] == map[0][2]){
            if (map[1][1]=='X')
                    return "A";
                else
                    return "B";
        }
        
        if (count == 9)
            return "Draw";
        else
            return "Pending";
        
    }
};