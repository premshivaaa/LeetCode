class Solution {
public:
    bool isSubsequence(string s, string t) {
        int left = 0, right = 0;
        while(right < t.size()){
            if(s[left] == t[right]){
                left++;
            }
            right++;
        }
        if(left == s.size()) return true;
        return false;
    }
};