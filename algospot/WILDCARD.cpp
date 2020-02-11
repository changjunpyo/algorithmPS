#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int cache[101][101];
string s;
string p;
int match_string(int a, int b){
    if (cache[a][b] != -1){
        return cache[a][b];
    }

    while(a <p.size() && b < s.size() && (p[a] == '?' || p[a] == s[b])){
        return cache[a][b] = match_string(a+1,b+1);
    }
    if (a == p.size())
        return cache[a][b] = (b == s.size());

    if (p[a] =='*'){
        cache[a][b] = match_string(a+1,b) ||( b <s.size() && match_string(a,b+1));
            return cache[a][b]; 
    }
    else 
       return  cache[a][b] = 0;

}


int main(){
    int T;
    cin >>T;
    for (int i=0; i<T; i++){
        int N;
        cin >>p;
        cin >>N;
        vector<string> v;
        for (int i=0; i<N; i++){
            memset(cache, -1, sizeof(cache));
            cin >> s;
            if (match_string(0,0)){
                v.push_back(s);
            }
        }
        sort(v.begin(),v.end());
        for (auto i : v)
        {
            cout << i <<"\n";
        }
        
    }
    return 0;
}