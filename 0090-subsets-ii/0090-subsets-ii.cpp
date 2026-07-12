class Solution {
    set<vector<int>> st;
    int n;
private:
    void recursion(int idx, vector<int>& nums, vector<int>& curr){
        if(idx >= n){
            if(st.find(curr) == st.end()){
                st.insert(curr);
            }
            return;
        }

        curr.push_back(nums[idx]);
        recursion(idx+1, nums, curr);
        curr.pop_back();
        recursion(idx+1, nums, curr);

        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        vector<int> curr;
        recursion(0, nums, curr);

        vector<vector<int>> ans;
        for(auto it : st){
            ans.push_back(it);
        }

        return ans;
    }
};