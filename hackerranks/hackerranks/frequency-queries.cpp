#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> queries) {
    map<int,int> m;
    map<int, int> fr;
    vector<int> ans;
    for (int i=0; i<queries.size(); i++){
        if (queries[i][0] == 1){
            if (m.find(queries[i][1]) == m.end()){
                m[queries[i][1]] = 1;
                fr[m[queries[i][1]]]++;
                continue;
            }
            fr[m[queries[i][1]]]--;
            m[queries[i][1]]++;
            fr[m[queries[i][1]]]++;
        } else if (queries[i][0] == 2){
            if (m.find(queries[i][1]) == m.end() || m[queries[i][1]] == 0){
                continue;
            }
            fr[m[queries[i][1]]]--;
            m[queries[i][1]]--;
            fr[m[queries[i][1]]]++;
        } else if (queries[i][0] == 3){
            if (fr.find(queries[i][1]) != fr.end() && fr[queries[i][1]] >0 )  ans.push_back(1);
            else ans.push_back(0);
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    vector<vector<int>> queries(q);

    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> ans = freqQuery(queries);

    for (int i = 0; i < ans.size(); i++) {
        fout << ans[i];

        if (i != ans.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
