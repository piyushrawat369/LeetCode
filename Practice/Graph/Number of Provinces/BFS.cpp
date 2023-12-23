class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>adj[n];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j]){
                adj[i].push_back(j);
                adj[j].push_back(i);
                }
            }
        }
        vector<bool>vis(n,0);
        int ans= 0;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                ans++;
                queue<int>q;
                q.push(i);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    vis[node] = 1;
                    for(auto child:adj[node]){
                        if(!vis[child]){
                            q.push(child);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
