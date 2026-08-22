class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int l_sum = 0, r_sum = 0, maxSum = 0;
        for(int i=0; i<k; i++) l_sum += cardPoints[i];
        maxSum = l_sum;

        int right = n-1;
        for(int i=k-1; i>=0; i--){
            l_sum -= cardPoints[i];
            r_sum += cardPoints[right];
            right--;
            maxSum = max(maxSum, l_sum + r_sum);
        }

        return maxSum;
    }
};