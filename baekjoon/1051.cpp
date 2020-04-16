#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >>N>>M; 
    vector<string> v;
    for (int i=0; i<N; i++){
        string s;
        cin >>s;
        v.push_back(s);
    }
    int ans =1;
    int big = (N > M) ? M : N;
    for (int i =big-1; i>0; i--){
        for (int j=0; j+i<N; j++){
            for (int k=0; k+i<M; k++){
                if (v[j][k] == v[j+i][k] && v[j][k] == v[j][k+i] && v[j][k] == v[j+i][k+i]){
                    cout << (i+1)*(i+1)<<"\n";
                    return 0;
                }
            }
        }
    }
    cout <<ans<<"\n";
    return 0;
    
}