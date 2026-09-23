class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1, maxCap = INT_MIN;
        while(left < right){
            int cap = (right-left) * min(height[left],height[right]);
            maxCap = max(maxCap, cap);

            if(height[left] < height[right]) left++;
            else right--;
        }
        return maxCap;
    }
};