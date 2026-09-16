class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0, right = 0, currCost = 0, maxlen = 0;
        while(right < s.size()){
            currCost += abs ( (s[right]-'a') - (t[right]-'a') );
            while(currCost > maxCost){
                currCost -= abs ( (s[left]-'a') - (t[left]-'a') );
                left++;
            }
            maxlen = max(maxlen, right - left + 1);
            right++;
        }
        return maxlen;
    }
};