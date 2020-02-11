#include <iostream>
#include <string>
using namespace std;


int count_K_non_zero_digit(string s, int k){
	while(s[0]=='0'){
		s.erase(0,1);
	}
	int ret=0;
	int x = s.size();
	if (k==3 && x>2){
		if (x >3)
			ret+= ((x-1)*(x-2)*(x-3)/6)*9*9*9;
		ret += (s[0]-'0'-1)* ((x-1)*(x-2)/2)*9*9;
		ret += count_K_non_zero_digit(s.substr(1,x-1), k-1);
	}
	if (k==2 && x>1){
		if (x >2)
			ret+= (((x-1)*(x-2))/2)*9*9;
		ret += (s[0]-'0'-1)* (x-1) *9;
		ret += count_K_non_zero_digit(s.substr(1,x-1),k-1);
	}

	if (k==1 && x >0){
		ret += (x-1)*9;
		ret += (s[0]-'0');
	}
	return ret;
}

int main(){
	string n;
	int k;
	cin >>n;
	cin >>k;
	int ans =0;
	printf("%d\n",count_K_non_zero_digit(n,k));
}