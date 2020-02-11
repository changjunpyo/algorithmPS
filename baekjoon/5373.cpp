#include <cstdio>
using namespace std;
const int up[4]={3,5,2,4};
const int down[4] ={3,4,2,5};
const int front[4] ={0,5,1,4};
const int back[4] ={0,4,1,5};
const int left[4] ={0,3,1,2};
const int right[4] ={0,2,1,3};

// 한 면을 회전
void rotate_square(int location, bool clock_wise){
	if (clock_wise){
		cube[location][0] = copy_cube[location][6];
		cube[location][1] = copy_cube[location][3];
		cube[location][2] = copy_cube[location][0];
		cube[location][3] = copy_cube[location][7];
		cube[location][4] = copy_cube[location][4];
		cube[location][5] = copy_cube[location][1];
		cube[location][6] = copy_cube[location][8];
		cube[location][7] = copy_cube[location][5];
		cube[location][8] = copy_cube[location][2];
	}
	else {
		cube[location][0] = copy_cube[location][2];
		cube[location][1] = copy_cube[location][5];
		cube[location][2] = copy_cube[location][8];
		cube[location][3] = copy_cube[location][1];
		cube[location][4] = copy_cube[location][4];
		cube[location][5] = copy_cube[location][7];
		cube[location][6] = copy_cube[location][0];
		cube[location][7] = copy_cube[location][3];
		cube[location][8] = copy_cube[location][6];
	}
}

void rotate_cube(int location, bool clock_wise){
	if (location == 0){
		rotate_square(location,clock_wise);
		for (int i=0; i<4){
			for (int j=0; j<3; j++){

			}
		}
	}
	if (location == 1){
		rotate_square(location,clock_wise);
		
	}
	if (location == 2){
		rotate_square(location,clock_wise);
		
	}
	if (location == 3){
		rotate_square(location,clock_wise);
		
	}
	if (location == 4){
		rotate_square(location,clock_wise);
		
	}
	if (location == 5){
		rotate_square(location,clock_wise);
		
	}
}


int main(){
	int N;
	// 0: 위 1:아래, 2: 앞, 3:뒤 :4왼쪽, 5 오른쪽
	char cube[6][9] ={
		{'w','w','w','w','w','w','w','w','w'},
		{'y','y','y','y','y','y','y','y','y'},
		{'r','r','r','r','r','r','r','r','r'},
		{'o','o','o','o','o','o','o','o','o'},
		{'g','g','g','g','g','g','g','g','g'},
		{'b','b','b','b','b','b','b','b','b'}
	};
	char copy_cube[6][3][3];


}