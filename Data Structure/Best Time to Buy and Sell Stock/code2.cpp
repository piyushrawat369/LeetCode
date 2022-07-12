// Time Complexity: O(N)
// Space Complexity: O(1)


int maxProfit(vector<int> &prices)
{
   int answer = 0;
   int mi = INT_MAX;
   for (auto ele : prices)
   {
       answer = max(answer, ele - mi);
       mi = min(mi, ele);
   }
   return answer;
}
