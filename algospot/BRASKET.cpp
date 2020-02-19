#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >>N;
	while(N--){
		string s;
		cin >>s;
		stack<char> stack;
		bool flag = true;
		for (int i=0; i<s.size(); i++){
			if (s[i] =='[' || s[i] =='(' || s[i] =='{')
				stack.push(s[i]);
			else if (s[i] ==']'){
				if (stack.empty()){
					flag = false;
					break;
				}
				if (stack.top() =='['){
					stack.pop();
				}
				else {
					flag = false;
					break;
				}
			}
			else if (s[i] ==')'){
				if (stack.empty()){
					flag = false;
					break;
				}
				if (stack.top() =='('){
					stack.pop();
				}
				else {
					flag = false;
					break;
				}
			}
			else if (s[i] =='}'){
				if (stack.empty()){
					flag = false;
					break;
				}
				if (stack.top() =='{'){
					stack.pop();
				}
				else {
					flag = false;
					break;
				}
			}
		}
		if (!stack.empty())
			flag = false;
		if (flag)
			cout <<"YES"<<"\n";
		else
			cout <<"NO\n";

	}
	return 0;
}