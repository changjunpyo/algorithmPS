class Solution {
public:
    int mySqrt(int x) {
        long long int t=x;
        // newton's method
        while(t*t > x){
            t = (t+ x/t)/2;
        }
        return t;
    }
};