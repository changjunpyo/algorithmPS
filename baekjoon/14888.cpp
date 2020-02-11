#include <iostream>
#include <vector>
using namespace std;

int mx =-1000000000;
int mn =1000000001;
void cal(int arr[], int depth, vector<int> v,int r){
	if (v[0] ==0 && v[1] == 0 && v[2]==0 && v[3] == 0){
		if (r > mx)
			mx = r;
		if (r <mn)
			mn = r;
		return ;
	}
	
	if (v[0] > 0){
		v[0] -=1;
		int s = r + arr[depth];
		cal(arr,depth+1, v, s);
		v[0] +=1;
		
	}

	if (v[1] >0){
		v[1] -=1;
		int s = r - arr[depth];
		cal(arr,depth+1, v, s);
		v[1] +=1;

	}

	if (v[2] >0){
		v[2] -=1;
		int s = r * arr[depth];
		cal(arr,depth+1, v, s);
		v[2] +=1;

	}

	if (v[3] >0){
		v[3] -=1;
		int s = r / arr[depth];
		cal(arr,depth+1, v, s);
		v[3] +=1;
	}
	
	return; 
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	int arr[11];
	cin >> N;
	vector<int> sacik(4);
	for (int i=0; i<N; i++ ){
		cin >>arr[i];
	}
	for (int i=0; i<4; i++){
		cin >> sacik[i];
	}
	cal(arr,1,sacik,arr[0]);
	cout <<mx <<"\n";
	cout <<mn <<"\n";




}