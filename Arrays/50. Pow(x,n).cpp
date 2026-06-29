class Solution {
public:
    double myPow(double x, int n) {
        long long p = n;
        if(p < 0) {
            x = 1/x;
            p = -p;
        }

        double ans = 1;
        while(p > 0) {
            if(p % 2 == 1) {    // odd power
                ans *= x;
                p--;
            } else {             // even power
                x *= x;         // square base
                p /= 2;         // halve power
            }
        }
        return ans;
    }
};
