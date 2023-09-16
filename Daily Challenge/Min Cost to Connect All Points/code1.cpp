// prims minimum spanning tree algorithm


int manhattan_distance(vector<int>& p1, vector<int>& p2){
  return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
}

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
      int n = points.size();
      unordered_map<int, int> dis_mp;    // distance 

      vector<bool> visited(n, false);

      for(int i=0; i<n; i++){
        dis_mp[i] = INT_MAX;
      }
      dis_mp[0] = 0;

      auto cmp = [](pair<int, int> left, pair<int, int> right) {   return left.first > right.first;   };
      priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> min_heap(cmp);

      min_heap.push({0, 0});
      int min_weight = 0;

      while(!min_heap.empty()){
        auto [w, u] = min_heap.top();
        min_heap.pop(); 

        if(visited[u] || dis_mp[u] < w)  continue;

        visited[u] = true;
        min_weight += w;

        for(int v=0; v<n; v++){
          if(!visited[v]){
            int new_distance = manhattan_distance(points[u], points[v]);
            if(new_distance < dis_mp[v]){
              dis_mp[v] = new_distance;
              min_heap.push({new_distance, v});
            }
          }
        }
      }
      return min_weight;
    }
};
