class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left = 0, right = 0, count = 0;
        unordered_map<char, int> mp;

        for(char c : s1)
            mp[c]++;

        int req = mp.size();

        while(right < s2.size()){
            mp[s2[right]]--;
            if(mp[s2[right]] == 0)
                count++;

            while(right - left + 1 > s1.size()){
                if(mp[s2[left]] == 0)
                    count--;
                mp[s2[left]]++;
                left++;
            }

            if(right - left + 1 == s1.size() && count == req)
                return true;

            right++;
        }

        return false;
    }
};