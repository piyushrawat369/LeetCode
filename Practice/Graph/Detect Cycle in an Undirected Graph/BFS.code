class Graph {
public:
    bool cycle(int a, vector<int> adj[], vector<int> &visi){
        visi[a] = true;
        queue<pair<int, int>> q;
        q.push({a, -1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto &it: adj[node]){
                if(!visi[it]){
                    visi[it] = 1;
                    q.push({it, node});
                }
                else if(parent != it){
                    return true;
                }
            }
        }
        return false;
    }

    bool detectCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, false);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(cycle(i, adj, vis))
                    return true;
            }
        }
        return false;
    }
};
