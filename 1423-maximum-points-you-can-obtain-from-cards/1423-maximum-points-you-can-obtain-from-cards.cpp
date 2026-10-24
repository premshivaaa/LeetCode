class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size()-1, maxScore = 0, score = 0;
        for(int i=0; i<k; i++){
            score += cardPoints[i];
        }
        maxScore = max(score, maxScore);
        
        for(int i=0; i<k; i++){
            score = score + cardPoints[n-i] - cardPoints[k-i-1];
            maxScore = max(score, maxScore);
        }
        return maxScore;
    }
};