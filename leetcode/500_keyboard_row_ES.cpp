const int keyboard[26]={2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3};
class Solution {

    public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        for (auto a : words){
            int first =0;
            bool flag= true;
            for (int i=0; i<a.size(); i++){
                if (!flag)
                    break;
                if (i==0){
                    if (a[i]-'A'<26)
                        first = keyboard[a[i]-'A'];
                    else
                        first = keyboard[a[i]-'a'];
                }
                else{
                    if (a[i]-'A'<26)
                        flag = (first == keyboard[a[i]-'A']) ? true: false; 
                    else
                        flag = (first == keyboard[a[i]-'a']) ? true: false; 
                }
            }
            if (flag)
                ans.push_back(a);
        }
        return ans;
    }
};