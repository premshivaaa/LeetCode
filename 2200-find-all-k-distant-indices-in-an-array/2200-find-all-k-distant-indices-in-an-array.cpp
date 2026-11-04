class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> st;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i] == key){
                st.insert(i);
                for(int j=1; j<=k; j++){
                    if(i-j >= 0) st.insert(i-j);
                    if(i+j < n) st.insert(i+j);
                }
            }
        }
        vector<int> ans;
        for(int ele : st){
            ans.push_back(ele);
        }
        return ans;
    }
};