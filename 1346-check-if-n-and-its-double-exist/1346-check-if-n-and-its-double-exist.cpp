class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> seen;
        for (int ele : arr) {
            
            if (seen.count(ele * 2) || (ele % 2 == 0 && seen.count(ele / 2))) {
                return true;
            }
            seen.insert(ele);
        }
        return false;
    }
};