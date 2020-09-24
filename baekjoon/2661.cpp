#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N;
bool check(string s){
	reverse(s.begin(), s.end());
	for (int i=1; i<=s.size()/2; i++){
		if (s.substr(0, i) == s.substr(i, i)) return false;
	}
	return true;
}

string make_string(int now, string &s){
	if (now == N) return s;
	string ans="";
	for (int i=0; i<3; i++){
		s += '1' + i;
		if (check(s)){
			ans = make_string(now+1, s);
			if (ans.size() == N) return ans;
		}
		s.pop_back(); 
	}
	return ans;
}


int main(){
	cin >> N;
	string s = "";
	cout <<make_string(0,s)<<"\n";

}