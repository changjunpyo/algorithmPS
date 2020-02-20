#include <bits/stdc++.h>
using namespace std;



string move(string chr,string cmd){
	string mvd = chr;
	if (cmd.find("R") != string::npos)
		mvd[0]++;
	if (cmd.find("L") != string::npos)
		mvd[0]--;
	if (cmd.find("B") != string::npos)
		mvd[1]--;
	if (cmd.find("T") != string::npos)
		mvd[1]++;

	if ((mvd[0] >= 'A' && mvd[0]<='H') && ( mvd[1]>='1' && mvd[1]<='8')) {
		return mvd;
	}
	else
		return chr;

}

int main(){
	int N;
	string king,stone;
	string a_king, a_stone;
	cin >>king >> stone >> N;
	while(N--){
		string command;
		cin >> command;

		a_king = move(king,command);
		if (a_king == stone)
			a_stone = move(stone,command);
		if (a_king == a_stone){
			continue;
		}
		king = a_king;
		if (a_stone.size() !=0)
			stone= a_stone;
	}

	cout <<king <<"\n" <<stone<<"\n";
}