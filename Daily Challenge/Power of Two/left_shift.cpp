class Solution {
public:
    bool isPowerOfTwo(int n) {
        int x =1;
        while(x<=n){
            if(x==n)return true;
            if(x > INT_MAX /2)break;
            x = x<<1;
        }
        return false;
    }
};
