class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int ans = 0;

        for(int i=0; i<n;){
            char curr = chars[i];
            int cnt = 0;

            while(i < n && chars[i] == curr){
                ++i;
                ++cnt;
            }

            chars[ans++] = curr;

            if(cnt > 1){
                for(auto it: to_string(cnt)){
                    chars[ans++] = it;
                }
            }
        }
        return ans;
    }
};


