#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

bool checkRightChar(string s){
    stack<char> st;
    for (int i=0; i<s.size(); i++){
        if (s[i] =='(') st.push(s[i]);
        if (s[i] ==')'){
            if (st.empty()) return false;
            st.pop();
        }
    }
    if (!st.empty()) return false;
    return true;
}

string makeRightChar(string s){
    if (s.size() == 0) return s;
    int count1=0;
    int count2=0;
    int idx=0;
    for (int i=0; i<s.size(); i++){
        if (s[i] == '(') count1++;
        if (s[i] == ')') count2++;
        if (count1 >0 && count1 == count2) {
            idx =i;
            break;
        }
    }
    string str ="";
    string u = s.substr(0,idx+1);
    string v ;
    if (idx+1 == s.size())
        v = "";
    else
        v = s.substr(idx+1);
    if (checkRightChar(u))
        return u+ makeRightChar(v);
    else{
        str += "(";
        str += makeRightChar(v);
        str += ")";
        for (int i=1; i<u.size()-1; i++){
            if (u[i] =='(') str += ")";
            else str+="(";
        }
        return str;
    }
    
    
}   


string solution(string p) {
    string answer = "";
    if (p.size() == 0 )
        return p;
    // 올바른 문자열인지 체크
    if (checkRightChar(p)) return p;
    

    return makeRightChar(p);
}