#include <bits/stdc++.h>
using namespace std;

template< typename T, typename U>
pair<T,U> operator-(const pair<T,U> & l, const pair<T,U> &r){
	return make_pair(l.first - r.first, l.second- r.second);
}
template< typename T, typename U>
pair<T,U> operator+(const pair<T,U> & l,const pair<T,U> &r){
	return make_pair(l.first + r.first, l.second + r.second);
}

double dist(const pair<int,int> &p){
	return sqrt(p.first*p.first + p.second*p.second);
}

int main(){
	pair<int, int> arr[3];

	for (int i=0; i<3; i++){
		cin >>arr[i].first;
		cin >>arr[i].second; 
	}
	pair<int, int> check[2];
	check[0] = arr[1] - arr[0];
	check[1] = arr[2] - arr[1];
	if (check[0].first * check[1].second == check[0].second* check[1].first){
		printf("-1\n");
		return 0;
	}
	pair<int, int> p[3];
	double mx = 0;
	double mn = 987654321;
	p[0] = arr[1] + (arr[2] - arr[0]);
	mx = max(mx, 2*(dist(arr[2] - arr[0])+ dist(arr[1] - arr[0])));
	mn = min(mn, 2*(dist(arr[2] - arr[0])+dist(arr[1] - arr[0])));
	p[1] = arr[1] + (arr[0] - arr[2]);
	mx = max(mx, 2*(dist(p[1] - arr[0])+dist(arr[2] - arr[0])));
	mn = min(mn, 2*(dist(p[1] - arr[0])+dist(arr[2] - arr[0])));
	p[2] = arr[2] + (arr[0] - arr[1]);
	mx = max(mx, 2*(dist(p[2] - arr[0])+dist(arr[1] - arr[0])));
	mn = min(mn, 2*(dist(p[2] - arr[0])+dist(arr[1] - arr[0])));
	cout << fixed;
	cout.precision(10);
	cout <<mx-mn<<"\n";
}