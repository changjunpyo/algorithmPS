#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int ret =-987654321;

    for (int i=0; i<arr.size(); i++){
        for (int j=0; j<arr[i].size(); j++){
            if (i+2 >= arr.size() || j+2 >=arr[i].size())
                continue;
            int h_class = arr[i][j] + arr[i][j+1]+ arr[i][j+2]+ arr[i+1][j+1]+arr[i+2][j]                 +arr[i+2][j+1]+arr[i+2][j+2];
            ret = max(h_class,ret);
        }
    }
    return ret;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
