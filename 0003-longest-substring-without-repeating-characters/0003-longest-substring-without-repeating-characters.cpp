class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0, left = 0, right = 0;
        vector<int> hash(256, -1);

        while(right < s.size()){
            if(hash[s[right]] != -1){ // duplicate element found senario
                if(left <= hash[s[right]]){
                    left = hash[s[right]] + 1;
                }
            }

            int len = right - left + 1;
            maxlen = max(maxlen, len);

            hash[s[right]] = right; // normal case (updation)
            right++;
        }
        return maxlen;
    }
};