class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> st;
        int zeros = 0;
        for(int ele : arr){
            st.insert(ele);
        }
        for(int ele : arr){
            if(ele == 0){
                zeros++;
                if(zeros >= 2) return true;
                else continue;
            }
            if(st.find(ele*2) != st.end() || (st.find(ele/2) != st.end() && ele%2 == 0)) return true;
        }
        return false;
    }
};