#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
using namespace std;

set<int> s;

void findPossibleNumberUsingString(const string &str, int count,int num, vector<bool> &visited){
  if (count == visited.size()) return ;


  for (int i=0; i<visited.size(); i++){
    if (visited[i]) continue;
    visited[i] = true;
    int next = num + pow(10,count)*(str[i]-'0');
    if (s.find(next) == s.end()) s.insert(next);
    findPossibleNumberUsingString(str,count+1,next,visited);
    visited[i] = false;
  }
}

int solution(string number){
  vector<bool> isPrime(pow(10,number.size()),true);
  vector<bool> visited(number.size());
  isPrime[0] = isPrime[1] = false;
  
  for (int i=2; i*i<isPrime.size(); i++){
    if (!isPrime[i]) continue;
    for (int j=2; j*i<isPrime.size(); j++){
      isPrime[i*j] = false;
    }
  }  
  findPossibleNumberUsingString(number, 0, 0, visited);
  int ans =0;
  for (auto number : s) if (isPrime[number]) ans++;
  return ans;

}
