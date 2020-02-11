#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(string a, string b){
	if (a.length() == b.length())
		return a < b;
	else 
		return a.length() < b.length();

}

int main(){
    int N;
    cin >>N;
    vector<string> v;
    while (N--){
        string s;
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(),compare);
    string pre ="";
    for (auto x: v){
    	if (pre != x)
    	cout << x<<"\n";
    	pre = x;
    }

    return 0;
}