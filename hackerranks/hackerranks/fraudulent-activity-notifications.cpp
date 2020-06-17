int activityNotifications(vector<int> expenditure, int d) {
    int ans =0;
    int count[201] ={0,};
    for (int i=0; i<d; i++){
        count[expenditure[i]]++;
        for (int j= expenditure[i]+1; j<200; j++){
            count[j]++;
        }
    }
    for (int i=d; i<expenditure.size(); i++){
        if ( d %2 == 0){
            int x,y;
            for (int j=0; j<= 200; j++){
                if (d/2 <= count[j]){
                    x = j;
                    break;
                }
            }
            for (int j=0; j<= 200; j++){
                if (d/2+1 <= count[j]){
                    y = j;
                    break;
                }
            }
            if (x+y <=  expenditure[i]) ans++;
        }
        else {
            for (int j=0; j<= 200; j++){
                if (d/2 +1 <= count[j]){
                    cout <<j << i<<"\n";
                    if (j*2 <=  expenditure[i]) ans++;
                    break;
                }
            }
        }
        
        count[expenditure[i]]++;
        for (int j= expenditure[i]+1; j<=200; j++){
            count[j]++;
        }
        count[expenditure[i-d]]--;
        for (int j= expenditure[i-d]+1; j<=200; j++){
            count[j]--;
        }
        
    }
    return ans;
}