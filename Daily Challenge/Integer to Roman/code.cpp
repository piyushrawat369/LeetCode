string intToRoman(int num) {
        vector<string> roman ({"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"});
        vector<int> int_arr ({1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000});
        
        int i = 12, div;
        string ans = "";
        
        while(num > 0){
            div = num / int_arr[i];
            num = num % int_arr[i];
            while(div--){
                ans += roman[i];  
            }
            i--;
        }
        return ans;
    }
