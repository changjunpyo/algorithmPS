#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int searchParkingLot(const vector<int> & v){
	int idx=0;
	for (auto a : v){
		if (a== -1)
			break;
		idx++;
	}
	return idx;
}

int main(){
	int T;

	scanf("%d",&T);

	for (int i=0; i<T; i++){
		int n,m;
		int sum=0;
		scanf("%d %d",&n,&m);
		vector<int> location(n,-1); // -1 if not parked
		vector<int> car_parked(m,-1);
		queue<int> waiting;
		vector<int> R(n);
		vector<int> W(m);

		for (int j=0; j<n; j++){
			scanf("%d",&R[j]);
		}

		for (int j=0; j<m; j++){
			scanf("%d",&W[j]);
		}

		for (int j=0; j<2*m; j++){
			int car;
			scanf("%d", &car);

			if (car <0){
				car *= -1;
				sum += R[car_parked[car-1]] * W[car-1];
				
				if (!waiting.empty()){
					car_parked[waiting.front()]= car_parked[car-1];
					location[car_parked[car-1]] = waiting.front();
					waiting.pop();
				}
				else
					location[car_parked[car-1]] = -1;
			}
			else {
				int min_num = searchParkingLot(location);
				if (min_num == n)
					waiting.push(car-1);
				else{
				car_parked[car-1] = min_num;
				location[min_num] = car-1;
				}
			}
		}

		printf("#%d %d\n",T+1, sum);

	}
}