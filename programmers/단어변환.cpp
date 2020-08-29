#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int compStringCount(const string &s1, const string &s2){
     int count =0;
	     for (int i=0; i<s1.size(); i++){
		          if (s1[i] != s2[i]) count++;
				      }
		     return count;
}
int bfs_count (vector<int> begin_idx, int target_idx, vector<vector<int>> &graph, vector<bool> &visited){
     queue<int> q;
	     for (int i=0; i<begin_idx.size(); i++){
		          q.push(begin_idx[i]);
				          visited[begin_idx[i]] = true;
						          if (begin_idx[i] == target_idx) return 1;
								      }
		     int count =1;
			     while (!q.empty()){
				          int q_size = q.size();
						          count++;
								          for (int i=0; i<q_size; i++){
										               int x = q.front();
													               q.pop();
																               for (int j=0; j<graph.size(); j++){
																				                if (graph[x][j] && !visited[j]) {
																								                     if (j == target_idx) return count;
																													                     visited[j] = true;
																																		                     q.push(j);
																																							                 }
																								            }
																			           }
										      }
				     return 0;
}

int solution(string begin, string target, vector<string> words) {
     int answer = 0;
	     vector<vector<int>> graph(words.size(),vector<int> (words.size(), 0) );
		     vector<bool> visited(words.size());
			     int begin_idx =-1;
				     int target_idx =-1;
					     for (int i=0; i<words.size(); i++){
						          if (words[i] == target) target_idx =i;
								      }
						     if (target_idx == -1) return 0;
							     

							     vector<int> start_idxs;
								     for (int i=0; i<words.size(); i++){
									          if (compStringCount(begin, words[i]) == 1) start_idxs.push_back(i);
											      }
									     for (int i=0; i<words.size(); i++){
										          for (int j=i+1; j<words.size(); j++){
												               if (compStringCount(words[i], words[j]) == 1){
																                graph[i][j] = graph[j][i] = 1;
																				            }
															           }
												      }

										     return bfs_count(start_idxs, target_idx, graph, visited);
}
