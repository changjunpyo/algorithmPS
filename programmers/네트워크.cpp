#include <string>
#include <vector>

using namespace std;

int dfs(int idx, vector<vector<int>> &computers, vector<bool> &visited){
	    visited[idx] = true;
		    for (int j=0; j<computers.size(); j++){
				        if (computers[idx][j] && !visited[j]){
							          dfs(j, computers, visited);
									          } 
						    }
			    return 1;
}



int solution(int n, vector<vector<int>> computers) {
	    vector<bool> visited(n);
		    int ans =0;
			    for (int i=0; i<n; i++){
					        if (!visited[i]) ans += dfs(i, computers, visited);
							    }
				    return ans;
}
