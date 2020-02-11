class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v(num+1);
        v[0] = 0;
        if (num ==0)
            return v;
        v[1] = 1;
        int m=2;
        while (m <= num){
            for (int i=m; i<2*m; i++){
                if (i > num)
                    break;
                if (i < m+ m/2)
                   v[i] = v[i-m/2]; 
                else 
                   v[i] = v[i-m/2]+1;
            }
            m *=2;
        }
        return v;
    }
};


//more clear answer...
/*
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v(num+1,0);
        for(int i=1; i<=num; i++)
            v[i] = v[i/2] + i%2;
        return v;
    }
};

*/