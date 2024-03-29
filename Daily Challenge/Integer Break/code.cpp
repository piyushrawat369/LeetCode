class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;

        int count_of_3 = n/3;
        int rem = n%3;

        if(rem == 0){
            return pow(3, count_of_3);
        } else if(rem == 1){
            return pow(3, count_of_3 - 1) * 4;
        } else{
            return pow(3, count_of_3) * 2;
        }
    }
};


