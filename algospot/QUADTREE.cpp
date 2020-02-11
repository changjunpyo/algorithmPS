#include <iostream>
#include <string>
using namespace std;

string reverse(string::iterator& it){
	char head = *it;
	it++;

	if (head == 'b' || head =='w')
		return string(1, head);

	string topLeft = reverse(it);
	string topRight = reverse(it);
	string bottomLeft = reverse(it);
	string bottomRight = reverse(it);

	return string("x") + bottomLeft+ bottomRight + topLeft + topRight;
}
	

int main(){
	int T;
	cin >> T;
	for (int i=0; i<T; i++){
		string s;
		cin >> s;
		string::iterator it = s.begin();
		cout <<reverse(it)<<"\n";
	}
}