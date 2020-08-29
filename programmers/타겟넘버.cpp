#include <string>
#include <vector>

using namespace std;
int brute_force(int idx, int total, vector<int> &numbers, int target){
		    
	int plus_total = total + numbers[idx];
	int minus_total = total - numbers[idx];
	int ret =0;
	if (idx == numbers.size()-1){
		if (plus_total == target) ret += 1;
		if (minus_total == target) ret +=1;
		return ret;
	} else{
	    ret += brute_force(idx+1,plus_total, numbers, target);
		ret += brute_force(idx+1,minus_total, numbers, target);
		return ret;
	}
}
int solution(vector<int> numbers, int target) {
	    int answer = brute_force(0, 0, numbers,target);
		return answer;
}
