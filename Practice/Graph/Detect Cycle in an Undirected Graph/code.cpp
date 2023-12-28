class Graph {

public:
    bool isCycleDFS(int node, int parent, vector<bool> &visited, vector<int> adj[]){
        visited[node] = true;

        for(auto &it: adj[node]){
            if(!visited[it]){
                if(isCycleDFS(it, node, visited, adj))
                    return true;
            }
            else if(it != parent)
                return true;
        }
        return false;
    }

    bool detectCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(isCycleDFS(i, -1, visited, adj))
                    return true;
            }
        }
        return false;
    }
};
