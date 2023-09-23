class Solution {
public:
    using int2 = pair<int, int>;
    int v;

    int L1(vector<int>& P, vector<int>& Q){
      return abs(P[0]-Q[0]) + abs(P[1]-Q[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points){
      v = points.size();
      priority_queue<int2, vector<int2>, greater<int2>> pq;
      pq.push({0, 0});
      vector<bool> visited(v, 0);
      vector<int> minWt(v, INT_MAX);

      int ans = 0;
      int n = 0;
      while(!pq.empty()){
        auto [w, i] = pq.top();
        pq.pop();

        if(visited[i])  continue;
        visited[i] = 1;
        ans += w;
        n++;

        if(n == v)  return ans;
        for(int j=0; j<v; j++){
          if(visited[j])  continue;
          int&& wt = L1(points[i], points[j]);
          if(wt < minWt[j]){
            minWt[j] = wt;
            pq.push({wt, j});
          }
        }
      }
      return -1;
    }
};
