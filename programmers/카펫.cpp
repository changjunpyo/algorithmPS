#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int max_n = (brown+4)/2;
    for (int i=3; i<= max_n; i++){
        for (int j=3; j<=i; j++){
            if (2*j + 2*i -4 == brown && (i-2) * (j-2) == yellow) {
                answer.push_back(i);
                answer.push_back(j);
                return answer;
            }
        }
    }
    return answer;
}
