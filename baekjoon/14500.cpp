#include <cstdio>
using namespace std;

int map[500][500]={0,};

int ilza(int i,int j, int N, int M){ 
	int max = 0;
	if (j+3 < M){
		int sum = map[i][j] + map[i][j+1]+ map[i][j+2]+ map[i][j+3];
		if (max < sum)
			max = sum;
	}

	if (j-3 >= 0){
		int sum = map[i][j] + map[i][j-1]+ map[i][j-2]+ map[i][j-3];
		if (max < sum)
			max = sum;
	}

	if (i+3 <N){
		int sum = map[i][j] + map[i+1][j]+ map[i+2][j]+ map[i+3][j];
		if (max < sum)
			max = sum;
	}
	if (i-3 >= 0){
		int sum = map[i][j] + map[i-1][j]+ map[i-2][j]+ map[i-3][j];
		if (max < sum)
			max = sum;
	}

	return max;
}

int nemo(int i,int j, int N, int M){
	int max =0;
	if (i+1 <N && j+1 <M){
		int sum = map[i][j] + map[i][j+1]+ map[i+1][j]+ map[i+1][j+1];
		if (max < sum)
			max = sum;
	}
	if (i-1 >= 0 && j+1 <M){
		int sum = map[i][j] + map[i-1][j]+ map[i][j+1]+ map[i-1][j+1];
		if (max < sum)
			max = sum;
	}

	if (i-1 >=0 && j-1 >=0){
		int sum = map[i][j] + map[i][j-1]+ map[i-1][j]+ map[i-1][j-1];
		if (max < sum)
			max = sum;
	}

	if (i+1 <N && j-1 >=0){
		int sum = map[i][j] + map[i+1][j]+ map[i][j-1]+ map[i+1][j-1];
		if (max < sum)
			max = sum;
	}

	return max;
}

int fucu(int i,int j, int N, int M){
	int max =0;
	if (i+1 <N && j-1 >=0 && j+1<M){
		int sum = map[i][j] + map[i+1][j-1]+ map[i+1][j]+ map[i+1][j+1];
		if (max < sum)
			max = sum;
	}
	if (j+1 <M && i-1 >=0 && i+1<N){
		int sum = map[i][j] + map[i-1][j+1]+ map[i][j+1]+ map[i+1][j+1];
		if (max < sum)
			max = sum;
	}
	if (i-1 >= 0 && j-1 >=0 && j+1<M){
		int sum = map[i][j] + map[i-1][j-1]+ map[i-1][j]+ map[i-1][j+1];
		if (max < sum)
			max = sum;
	}
	if (j-1 >=0 && i-1 >=0 && i+1<N){
		int sum = map[i][j] + map[i-1][j-1]+ map[i][j-1]+ map[i+1][j-1];
		if (max < sum)
			max = sum;
	}

	return max;
}

int bungae(int i,int j, int N, int M){
	int max =0;

	if (i+2 <N && j+1 <M){
		int sum = map[i][j] + map[i+1][j]+ map[i+1][j+1]+ map[i+2][j+1];
		if (max < sum)
			max = sum;
	}
	if (i-1 >=0 && j+2 <M){
		int sum = map[i][j] + map[i][j+1]+ map[i-1][j+1]+ map[i-1][j+2];
		if (max < sum)
			max = sum;
	}

	if (i-2 >=0 && j-1 >=0){
		int sum = map[i][j] + map[i-1][j]+ map[i-1][j-1]+ map[i-2][j-1];
		if (max < sum)
			max = sum;
	}

	if (i+1 <N && j-2 >=0){
		int sum = map[i][j] + map[i][j-1]+ map[i+1][j-1]+ map[i+1][j-2];
		if (max < sum)
			max = sum;	
	}
	// 대칭

	if (i+2 <N && j-1 >=0){
		int sum = map[i][j] + map[i+1][j]+ map[i+1][j-1]+ map[i+2][j-1];
		if (max < sum)
			max = sum;
	}
	if (i+1 <N && j+2 <M){
		int sum = map[i][j] + map[i][j+1]+ map[i+1][j+1]+ map[i+1][j+2];
		if (max < sum)
			max = sum;
	}

	if (i-2 >=0 && j+1 <M){
		int sum = map[i][j] + map[i-1][j]+ map[i-1][j+1]+ map[i-2][j+1];
		if (max < sum)
			max = sum;
	}

	if (i-1 >=0 && j-2 >=0){
		int sum = map[i][j] + map[i][j-1]+ map[i-1][j-1]+ map[i-1][j-2];
		if (max < sum)
			max = sum;	
	}

	return max;
}
int lzza(int i,int j, int N, int M){
	int max =0;
	if (i+2 <N && j+1 <M){
		int sum = map[i][j] + map[i+1][j]+ map[i+2][j]+ map[i+2][j+1];
		if (max < sum)
			max = sum;
	}
	if (i-1 >=0 && j+2 <M){
		int sum = map[i][j] + map[i][j+1]+ map[i][j+2]+ map[i-1][j+2];
		if (max < sum)
			max = sum;
	}

	if (i+1 <N && j-2 >=0){
		int sum = map[i][j] + map[i][j-1]+ map[i][j-2]+ map[i+1][j-2];
		if (max < sum)
			max = sum;
	}
	if (i-2 >=0 && j-1 >=0){
		int sum = map[i][j] + map[i-1][j]+ map[i-2][j]+ map[i-2][j-1];
		if (max < sum)
			max = sum;
	}
	// 대칭
	if (i+2 <N && j-1 >=0){
		int sum = map[i][j] + map[i+1][j]+ map[i+2][j]+ map[i+2][j-1];
		if (max < sum)
			max = sum;
	}
	if (i+1 <N && j+2 <M){
		int sum = map[i][j] + map[i][j+1]+ map[i][j+2]+ map[i+1][j+2];
		if (max < sum)
			max = sum;
	}
	if (i-2 >=0 && j+1 <M){
		int sum = map[i][j] + map[i-1][j]+ map[i-2][j]+ map[i-2][j+1];
		if (max < sum)
			max = sum;
	}
	if (i-1 >=0 && j-2 >=0){
		int sum = map[i][j] + map[i][j-1]+ map[i][j-2]+ map[i-1][j-2];
		if (max < sum)
			max = sum;
	}

	return max;
}




int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++){
			scanf("%d",&map[i][j]);
		}
	}
	int max =0;
	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++){
			int sum;
			//일자
			sum = ilza(i,j,N,M);
			if (max < sum)
				max = sum;
			sum = nemo(i,j,N,M);
			if (max < sum)
				max = sum;
			sum = fucu(i,j,N,M);
			if (max < sum)
				max = sum;
			sum = lzza(i,j,N,M);
			if (max < sum)
				max = sum;
			sum = bungae(i,j,N,M);
			if (max < sum)
				max = sum;
			
		}
	}

	printf("%d\n", max);
}