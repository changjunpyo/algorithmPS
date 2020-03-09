class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        vector<int> three_one;
        vector<int> three_two;
        vector<int> three_three;
        
        for (int i=0; i<digits.size(); i++){
            if (digits[i]%3 ==0)
                three_three.push_back(digits[i]);
            else if (digits[i]%3 ==1)
                three_one.push_back(digits[i]);
            else
                three_two.push_back(digits[i]);
        }
        
        sort(three_one.begin(), three_one.end(), greater<int>());
        sort(three_two.begin(), three_two.end(), greater<int>());
        sort(three_three.begin(), three_three.end(), greater<int>());
        int x =  (three_one.size()/3)*3;
        int y = (three_two.size()/3)*3;
        bool oneIsBigger= three_one.size() < three_two.size() ? false : true;
        int sz = three_one.size() < three_two.size() ?  three_one.size() : three_two.size();
        
        if (x+y >= sz*2){
            for (int i=0; i<x; i++){
                three_three.push_back(three_one[i]);
            }
            for (int i=0; i<y; i++){
                three_three.push_back(three_two[i]);
            }
        
            for (int i=0; i<3; i++){
                if (x == three_one.size() || y==three_two.size())
                    break;
                three_three.push_back(three_one[x++]);
                three_three.push_back(three_two[y++]);
            }
        }
        else {
            for (int i=0; i<sz; i++){
                three_three.push_back(three_one[i]);
                three_three.push_back(three_two[i]);
                int new_x = ((three_one.size()-i-1)/3)*3;
                int new_y = ((three_two.size()-i-1)/3)*3;
                if (new_x+new_y > (sz-i-1)*2){
                    for (int j=i+1;j<i+new_x+1; j++){
                        three_three.push_back(three_one[j]);
                    }
                    for (int j=i+1; j<i+new_y+1; j++){
                        three_three.push_back(three_two[j]);
                    }
                    break;
                }
            }
        }
        
        sort(three_three.begin(), three_three.end(), greater<int>());
        if (three_three.size() == 0)
            return "";
        else if (three_three[0] == 0)
            return "0";
        else{
            string ans;
            for (int i=0; i<three_three.size(); i++){
                ans.push_back(three_three[i]+'0');   
            }
            return ans;
        }
        
    }
};