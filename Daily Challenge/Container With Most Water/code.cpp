int maxArea(vector<int>& h) {
        int n = h.size();
        
        int area = 0;
        int l = 0;
        int r = n-1;
        
        while(l < r){
            area = max(area, min(h[l], h[r]) * (r-l));
            
            if(h[l] < h[r]){
                l += 1;
            }
            else{
                r -= 1; 
            }
        }
        return area;
    }
