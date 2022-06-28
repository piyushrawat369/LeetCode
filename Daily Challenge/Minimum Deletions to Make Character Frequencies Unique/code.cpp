int minDeletions(string s) {
        unordered_map<char, int> m;
        priority_queue<int> q;
        
        int count = 0;
        
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
        }
        for(auto i: m){
            q.push(i.second);
        }
        
        while(!q.empty()){
            int val = q.top();
            q.pop();
            
            if(q.empty()){
                return count;
            }
            
            if(q.top() == val){
                if(val > 1){
                    q.push(val - 1);
                }
                count++;
            }
        }
        return count;
    }
