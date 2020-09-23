#include <iostream>
#include <vector>
using namespace std;
const int acint[5]={1, 1<<('c'-'a'), 1<<('i'-'a'), 1<<('n'-'a'), 1<<('t'-'a')};
vector<int> words;
int all_case(int now,int next, int count, int K){
	if (count == K){
		int x = 0;
		for (int i=0; i<words.size(); i++){
			if ((now & words[i]) == words[i]) x++;
		}
		return x;
	}
	int ans = 0;
	for(int i=next; i<26; i++){
		if (now & 1<<i) continue;
		else{
			now |= (1<<i);
			ans = max(ans, all_case(now,i+1,count+1, K));
			now ^= (1<<i);
		}
	}
	return ans;
}

int main(){
	int N, K;
	cin >>N >>K;
	string s;
	for (int i=0; i<N; i++){
		string s;
		cin >>s;
		int x = 0;
		for (int j=0; j<s.size(); j++){
			x |= (1 << (s[j]-'a'));
		}
		words.push_back(x);
	}
	int now = 0;
	for(int i=0; i<5; i++){
		now |= acint[i];
	}
	if (K<5) 
		cout <<"0"<<"\n";
	else
		cout <<all_case(now,0,5,K)<<"\n";


}