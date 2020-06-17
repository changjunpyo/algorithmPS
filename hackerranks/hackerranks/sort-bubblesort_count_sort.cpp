void countSwaps(vector<int> a) {
    int count =0;
    for (int i = 0; i < a.size(); i++) {

    for (int j = 0; j < a.size()-i- 1; j++) {
        // Swap adjacent elements if they are in decreasing order
        if (a[j] > a[j + 1]) {
            swap(a[j], a[j + 1]);
            count++;
        }
    }
    
    }
    cout << "Array is sorted in "<< count<< " swaps.\n";
    cout << "First Element: "<< a[0]<<"\n";
    cout << "Last Element: " << a.back() <<"\n";
}