// Brute Force Solution
// Time Complexity: O(N^2)
// Space Complexity: O(1)


int maxProfit(vector<int> &prices)
{
   int n = prices.size();
   int answer = 0;
   for (int i = 0; i < n; i++)
   {
       for (int j = i + 1; j < n; j++)
       {
           answer = max(answer, prices[j] - prices[i]);
       }
   }
   return answer;
}
