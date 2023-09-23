// Adjacent List

class Solution {
public:
    using int2 = pair<int, int>;
    int v;

    int L1(vector<int>& p1, vector<int>& p2){
      return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);
    }

    vector<vector<int2>> adj;
    void build_graph(vector<vector<int>>& points){
      adj.resize(v);
      for(int i=0; i<v-1; i++){
        for(int j=i+1; j<v; j++){
          int&& wt = L1(points[i], points[j]);
          adj[i].push_back({wt, j});
          adj[j].push_back({wt, i});
        }
      }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
      v = points.size();
      build_graph(points);
      priority_queue<int2, vector<int2>, greater<int2>> pq;
      pq.push({0, 0});
      vector<bool> visited(v, 0);

      int ans = 0;
      int n = 0;
      while(!pq.empty()){
        auto [w, i] = pq.top();
        pq.pop();
        if(visited[i]) continue;
        visited[i] = 1;
        ans += w;
        n++;

        if(n == v)  return ans;
        for(auto& [wt, j]: adj[i]){
          if(!visited[j]) pq.push({wt, j});
        }
      }
      return -1;
    }
};
