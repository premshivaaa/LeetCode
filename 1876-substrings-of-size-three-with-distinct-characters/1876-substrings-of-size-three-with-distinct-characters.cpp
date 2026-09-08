class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.size() < 3) return 0;

        int count = 0;
        unordered_map<char,int> mp;
        for(int j=0; j<3; j++){
            mp[s[j]]++;
        }
        for(int i=3; i<s.size(); i++){
            if(mp.size() == 3) count++;
            mp[s[i]]++;
            mp[s[i-3]]--;
            if(mp[s[i-3]] == 0) mp.erase(s[i-3]);
        }
        if(mp.size() == 3) count++;
        
        return count;
    }
};