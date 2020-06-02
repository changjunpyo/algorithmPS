#include <string>
#include <vector>

using namespace std;

bool check(const vector<int> &budgets, int t, int total){
    long long int sum=0;
    for (int i=0; i<budgets.size(); i++){
        if (budgets[i] <= t)
            sum+= budgets[i];
        else
            sum+= t;
    }
    if (sum <= total)
        return true;
    else
        return false;
}

int binary_search(int s, int e, const vector<int> &budgets, int total){
    while(s < e){
        int m = (e+s)/2;
        if (check(budgets, m, total))
            s = m+1;
        else
            e = m;   
    }
    return s-1;
}


int solution(vector<int> budgets, int M) {
    long long int answer = 0;
    int mx =0;
    for (int i=0; i<budgets.size(); i++){
        answer += budgets[i];
        if (mx < budgets[i]){
            mx = budgets[i];
        }
    }
    if (answer <= M)
        return mx;
    else
        return binary_search(M/budgets.size(),100000,budgets,M);
}