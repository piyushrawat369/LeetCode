class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());

        int n = tokens.size();
        int score = 0;
        int max_score = 0;
        int left = 0;
        int right = n - 1;

        while(left <= right){
            if(power >= tokens[left]){
                score += 1;
                power -= tokens[left];
                left += 1;
                max_score = max(max_score, score);
            }
            else if(score > 0){
                score -= 1;
                power += tokens[right];
                right -= 1;
            }
            else{
                break;
            }
        }
        return max_score;
    }
};
