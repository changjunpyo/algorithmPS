#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotate(const vector<vector<int>> &key){
    vector<vector<int>> rotated(key.size(), vector<int>(key.size()));
    for (int i=0; i<key.size(); i++){
        for (int j=0; j<key.size(); j++){
            rotated[i][j] = key[key.size()-1-j][i];
        }
    }
    return rotated;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int count=0;
    vector<vector<int>> key_rotated = key;
    int k_size = lock.size();
    for (int i=0; i<lock.size(); i++)
        for (int j=0; j<lock.size(); j++)
            if (lock[i][j] == 0) count++;
    for (int k=0; k<4; k++){
         key_rotated = rotate(key_rotated);
        for (int i = -k_size; i<=k_size; i++){
            for (int j=-k_size; j<= k_size; j++){
                int total =count;
                bool flag = true;
                for (int x =0; x<lock.size(); x++){
                    if (!flag) break;
                    for (int y=0; y<lock.size(); y++){
                        if (!flag) break;
                        int key_x = x-i;
                        int key_y = y-j;
                        if (key_x >=0 && key_y >=0 && key_x <key.size() && key_y <key.size()){
                            if (key_rotated[key_x][key_y] ==1 && lock[x][y]== 1) flag = false;
                            if (key_rotated[key_x][key_y] == 1 && lock[x][y] ==0) total--;
                        }
                    }
                }
                if (flag && total ==0) return true;
            }
        }
    }
    return false;
}