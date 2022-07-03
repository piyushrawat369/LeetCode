void combo(string &digits, int i, vector<string> &v, string s){
        if(i >= digits.size()){
            v.push_back(s);
            return;
        }
        
        int digit = digits[i] - '0';
        int k = 3;
        int base = 'a' + (digit-2)*3;
        
        if(digit == 7){
            k = 4;
            base = 'p';
        }
        else if(digit == 8){
            base = 't';
        }
        else if(digit == 9){
            k = 4;
            base = 'w';
        }
        
        for(int j = 0; j<k; ++j){
            combo(digits, i+1, v, s + (char)(base + j));
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        if(digits.size()){
            combo(digits, 0, v, "");
        }
        return v;
    }
