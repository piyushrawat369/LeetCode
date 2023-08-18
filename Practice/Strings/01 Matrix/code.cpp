class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        multiset<pair<int,pair<int,int>>> s;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!mat[i][j])
                    dist[i][j] = 0,s.insert({0,{i,j}});
            }
        }
        while(!s.empty()){ 
            int val = s.begin()->first;
            int x = s.begin()->second.first;
            int y = s.begin()->second.second;
            s.erase(s.begin());
            if(x+1<n and val+1<dist[x+1][y]){
                s.erase({dist[x+1][y],{x+1,y}});
                dist[x+1][y] = 1 + val;
                s.insert({dist[x+1][y],{x+1,y}});
            }
            if(x-1>=0 and val+1<dist[x-1][y]){
                s.erase({dist[x-1][y],{x-1,y}});
                dist[x-1][y] = 1 + val;
                s.insert({dist[x-1][y],{x-1,y}});
            }
            if(y+1<m and val+1<dist[x][y+1]){
                s.erase({dist[x][y+1],{x,y+1}});
                dist[x][y+1] = 1 + val;
                s.insert({dist[x][y+1],{x,y+1}});
            }
            if(y-1>=0 and val+1<dist[x][y-1]){
                s.erase({dist[x][y-1],{x,y-1}});
                dist[x][y-1] = 1 + val;
                s.insert({dist[x][y-1],{x,y-1}});
            }
        }
        return dist;
    }
};
