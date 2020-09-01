#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



int main(){
 int N, M;
 cin >>N >>M;
 vector<string> pocket;
 pocket.push_back("dummy");
 unordered_map<string,int> m;
 for (int i=0; i<N; i++){
  string s;
  cin >>s;
  pocket.push_back(s);
  m.insert(make_pair(s,i+1));
 }
 for (int i=0; i<M; i++){
  string s;
  cin >>s;
  if (isdigit(s[0])) cout << pocket[stoi(s)]  <<"\n"; 
  else cout << m[s]<<"\n";
 }
 return 0;
}
