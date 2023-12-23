class Solution {
public:
    void sol(vector<int> adj[], int node, vector<bool> &vis){
        vis[node] = true;
        for(auto i: adj[node]){
            if(!vis[i]){
                sol(adj, i, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> vis(n, false);
        int count = 0;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                sol(adj, i, vis);
                count++;
            }
        }
        return count;
    }
};
