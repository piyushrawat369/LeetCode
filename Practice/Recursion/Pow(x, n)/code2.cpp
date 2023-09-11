class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(n == 1)
            return x;

        if(n < 0)
            return (1 / myPow(x, -(n+1)) / x);

        double ans = myPow(x, n/2);

        if(n%2 == 0)
            return ans*ans;
        else 
            return ans*ans*x;
    }
};
