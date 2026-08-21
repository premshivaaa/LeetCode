class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        // window for 1st k elements
        for(int i=0; i<k; i++){
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        for(int i=k; i<nums.size(); i++){
            ans.push_back(nums[dq.front()]);

            // check the condition
            while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }

            // push the max element of k-window after removing smaller ones
            while(!dq.empty() > 0 && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);

        return ans;
    }
};