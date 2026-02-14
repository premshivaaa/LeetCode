class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int l = 0, r = tokens.size() - 1;
        int score = 0, maxScore = 0;

        while(l<=r){
            if(tokens[l] <= power){
                score++;
                power -= tokens[l];
                maxScore = max(maxScore, score);
                l++;
            }
            else{
                if(score <= 0){
                    break;
                } else{
                    score--;
                    power += tokens[r];
                    r--;
                }
            }
        }

        return maxScore;
    }
};