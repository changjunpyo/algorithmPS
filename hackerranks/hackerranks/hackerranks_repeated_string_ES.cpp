#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long long int ret =0;
    long long int a_count =0;
    for (int i=0; i<s.size(); i++){
        if (s[i] =='a')
            a_count++;
    }
    ret += a_count*(n/s.size());
    for (int i=0; i<(n%s.size()); i++){
        if (s[i] =='a')
            ret++;
    }

    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
