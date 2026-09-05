class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0, maxf = 0, maxlen = 0;
        unordered_map<char,int> mp;
        while(right < s.size()){
            mp[s[right]]++;
            maxf = max(maxf, mp[s[right]]);
            while((right-left+1) - maxf > k){
                mp[s[left]]--;
                left++;
            }
                maxlen = max(maxlen, right-left+1);
            right++;
        }
        return maxlen;
    }
};