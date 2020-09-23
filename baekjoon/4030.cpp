#include <iostream>
#include <vector>
using namespace std;

int main(){
	const int M = 1000000000;
	vector<int> x,y;
	int count =0;
	for (int i=1; ;i++){
		count += i;
		if (i*i>= M && count >= M)
			break;
		if (i*i <M) x.push_back(i*i);
		if (count <M) y.push_back(count);
	}
	int a, b;
	cin >> a >>b;
	int num=1;
	while(a != 0 && b!=0){
		int ans =0;
		int x_idx = 0;
		int y_idx = 0;
		while(x[x_idx] <= a)
			x_idx++;
		while(y[y_idx]< a)
			y_idx++;

		while(x_idx< x.size() && y_idx<y.size() && x[x_idx] < b && y[y_idx]+1 < b){
			if (x[x_idx] == y[y_idx]+1){
				x_idx++;
				y_idx++;
				ans++;
			} else if(x[x_idx] > y[y_idx]+1)
				y_idx++;
			  else {
			  	x_idx++;
			  }
		}
		cout <<"Case " << num++<<": " <<ans<<"\n";
		cin >>a >>b;
	}
}