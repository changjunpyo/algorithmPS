#include <iostream>
using namespace std;

int main(){
	int t;
	cin >>t;
	while(t--){
		int n,m;
		cin >>n >> m;
		int mint=0;
		int s=m,e=m;
		bool flag = true;
		for (int i=0; i<n; i++){
			int a,b,q;

			cin >>q >>a >>b;
			if (!flag)
				continue;
			int diff = q-mint;
			mint = q;
			s-=diff;
			e+=diff;

			if (e < a || b <s){
				flag =false;
			}
			else{
				if (s<=a && b <= e){
					s = a;
					e = b;
				}
				else if (a <= s && b <=e){
					e= b;
				}
				else if (s <=a && e<=b)
					s= a;
			}
		}

		if (!flag)
			cout <<"NO\n";
		else
			cout <<"YES\n";
	}
}