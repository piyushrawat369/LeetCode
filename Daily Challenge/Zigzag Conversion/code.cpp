string convert(string s, int numRows) {
        
        if(numRows == 1){
            return s;
        }
        
        int size = s.size();
        string ans = "";
    
        for(int i=0; i<numRows; i++){
            int a = (numRows-1)*2;
        
            for(int j=i; j<size; j+=a){
                ans += s[j];
            
                if(i > 0 && i < numRows-1 && (j+a - 2*i) < size){
                    ans += s[j+a - 2*i];
                }
            }
        }
        return ans;
}
