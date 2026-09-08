class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(int i=0; i<t.size(); i++){
            mp[t[i]]++;
        }
        int left = 0, right = 0, count = 0, minlen = INT_MAX, sIndex = -1;
        while(right < s.size()){
            if(mp[s[right]] > 0) count++;
            
            mp[s[right]]--;
            while(count == t.size()){
                if((right-left+1) < minlen){
                    minlen = right-left+1;
                    sIndex = left;
                }
                mp[s[left]]++;
                if(mp[s[left]] > 0) count--;
                left++;
            }
            right++;
        }
        if(sIndex == -1) return "";
        return s.substr(sIndex, minlen);
    }
};