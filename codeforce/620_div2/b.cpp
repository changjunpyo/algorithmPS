#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool check_pd(string s){
	for(int i=0; i<s.size()/2; i++){
		if (s[i] != s[s.size()-1-i])
			return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >>n >>m;
	vector<string> s(n);
	vector<string> r_s(n);
	vector<int> stack;
	vector<bool> flag(n,0);
	string pd;
	for (int i=0; i<n; i++){
		cin >> s[i];
		if (check_pd(s[i])){
			flag[i] = true;
			pd = s[i];
		}
		r_s[i] = s[i];
		reverse(r_s[i].begin(), r_s[i].end());
	}

	for (int i=0; i<n; i++){
		if (flag[i])
			continue;
		for (int j=0; j<n; j++){
			if(i==j || flag[j])
				continue;
			if (s[i] ==r_s[j]){
				stack.push_back(i);
				flag[i] = true;
				flag[j] = true;
			}
		}
	}
	if (stack.empty() && pd.empty())
		cout <<"0"<<"\n"<<""<<"\n";
	else{
		cout <<stack.size()*2*m + pd.size()<<"\n";
		for (int i=0; i<stack.size(); i++){
			cout <<s[stack[i]];
		}
		if (!pd.empty())
			cout << pd;

		for (int i=stack.size()-1; i>=0; i--){
			cout <<r_s[stack[i]];
		}
		cout <<"\n";
	}

}