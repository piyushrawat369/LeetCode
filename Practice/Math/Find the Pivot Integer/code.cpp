class Solution {
public:
    int pivotInteger(int n) {
        int x = n*(n+1)/2;
        for(int i=1; i<=n; i++){
            if((i*(i+1)/2) == (x - ((i-1)*(i)/2)))
                return i;
        }
        return -1;
    }
};


