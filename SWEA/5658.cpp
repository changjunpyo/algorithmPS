#include<iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int HexToInt(string s){
	int ret =0;
	int N= 1;
	for (int i=s.size()-1; i>=0; i--){
		if (s[i] >= '0' && s[i] <= '9'){
			ret += N*(s[i]-'0');
		}
		else
			ret += N*(s[i] -'A' +10);
		N*=16;
	}
	return ret;
}

int main(){
	int T;
	cin >>T;

	for (int t=1; t<=T; t++){
		unordered_set<string> num;
		vector<int> v;
		int N, K;
		cin >>N >>K;
		int line_count = N/4;
		string s;
		cin >>s;
		for (int i=0; i<line_count; i++){
			for (int j=i; j<s.size(); j++){
				string str = s.substr(j,line_count);
				j+= line_count-1;
				if (str.size() <line_count)
					str += s.substr(0,i);
				if (num.find(str) == num.end()){
					num.insert(str);
					v.push_back(HexToInt(str));
				}
				else
					continue;
			}

		}
		sort(v.begin(), v.end(), greater<int>());
		cout << "#"<<t<<" " <<v[K-1] <<"\n";
	}
}