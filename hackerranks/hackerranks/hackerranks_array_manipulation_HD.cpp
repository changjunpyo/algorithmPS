long arrayManipulation(int n, vector<vector<int>> queries) {
    long ans = 0;
    vector<int> arr(n+1, 0);
    int sz = queries.size();
    for (int i=0; i<sz; i++){
        int a = queries[i][0];
        int b = queries[i][1];
        arr[a] += queries[i][2];
        if (b+1 <= n) arr[b+1] -= queries[i][2]; 
    }
    long sum =0;
    for (int i=1; i<=n; i++){
        sum += arr[i];
        if (sum > ans)
            ans = sum; 
    }
    return ans;
}
