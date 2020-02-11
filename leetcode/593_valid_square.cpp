class Solution {
public:
    int distance_square(const vector<int> &a, const vector<int> &b){
        return (a[0]-b[0])*(a[0]-b[0]) +  (a[1]-b[1]) *  (a[1]-b[1]);
    }
    bool check_straight(const vector<int>& a, const vector<int>& b, const vector<int>& c){
        vector<int> v1({a[0]-b[0], a[1]-b[1]}); 
        vector<int> v2({a[0]-c[0], a[1]-c[1]});
        int t;
        // one point
        if (v1[0] == 0 && v1[1] == 0)
            return true;
        
        // check straight
        else if (v1[0] == 0){
            return v2[0] == 0;
        }
        else if (v1[1] == 0){
            return v2[1] == 0;
        }
        else 
            return v2[0]*v1[1] == v2[1]*v1[0];
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int a = distance_square(p1,p2);
        int b = distance_square(p1,p3);
        int c = distance_square(p1,p4);
        
        if (check_straight(p1,p2,p3) || check_straight(p1,p2,p4) || check_straight(p1,p3,p4) || check_straight(p2,p3,p4)){
            return false;
        }
        
        if (a== b){
            if (2*a == c){
                if (distance_square(p2,p4) == distance_square(p3,p4))
                    return true;
            }
        }
        else if (a== c){
            if (b == 2*a){
                if (distance_square(p3,p2) == distance_square(p3,p4))
                    return true;
            }
        }
        else if (b== c){
            if (a == 2*b){
                if (distance_square(p2,p3) == distance_square(p2,p4))
                    return true;
            }
        }
        return false;
    }
};

/* 
class Solution {
public:
int square_distance(vector<int>& a, vector<int>& b) {
    
    int x = a[0] - b[0], y = a[1] - b[1];
    
    return x * x + y * y;
    
}

bool valid_triangle(vector<int>& p1, vector<int>& p2, vector<int>& p3) {
    
    vector<int> v = { square_distance(p1, p2), square_distance(p1, p3), square_distance(p3, p2) };
    
    sort(v.begin(), v.end());
    
    return v[0] && v[0] == v[1] && v[0] + v[1] == v[2];
}

bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    
    return valid_triangle(p1, p2, p3) && valid_triangle(p4, p2, p3) && valid_triangle(p1, p2, p4);
}

};
*/