class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int n = heights.size(), diff = 0, i = 0;

        priority_queue<int> pq;

        for(i=0; i<n-1; i++){
            diff = heights[i+1] - heights[i];

            if(diff <= 0 )
                continue;

            pq.push(diff);
            bricks -= diff;

            if(bricks < 0){
                bricks += pq.top();
                pq.pop();
                ladders--;
            }

            if(ladders < 0)
                break;
        }
        return i;
    }
};
