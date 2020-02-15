#include <iostream>
using namespace std;
int main(){
	int t;
	cin >>t;
	while(t--){
		int x,y,a,b;
		cin >>x >>y >>a >>b;

		int sum = a+b;
		int dd = y-x;

		if (dd % sum == 0)
			cout <<dd/sum <<"\n";
		else
			cout <<"-1"<<"\n";
	}

}