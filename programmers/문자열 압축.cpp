#include <string>
#include <vector>
#include <iostream>
using namespace std;

int fin(int x){
    int count =0;
    while(x != 0){
        x /=10;
        count++;
    }
    return count;
}


int solution(string s) {
    int answer = s.size();
    for (int i=1; i<=s.size()/2; i++){
        int count =s.size();
        int comp =1;
        
        for(int j=0; j<s.size()-i; j+=i){
            if (s.substr(j,i) == s.substr(j+i,i))
                comp++;
            else{
                if (comp >1) 
                    count -= (comp-1)*i -fin(comp);
                comp =1;
            }
        }
        if (comp >1) 
            count -= (comp-1)*i -fin(comp);
        answer = min(answer, count);
    }
    return answer;
}