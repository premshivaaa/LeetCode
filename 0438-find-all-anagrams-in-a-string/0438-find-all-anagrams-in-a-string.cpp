class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mp;
        for (char c : p)
            mp[c]++;

        int required = mp.size();
        int formed = 0;
        int left = 0;
        vector<int> ans;

        for (int right = 0; right < s.size(); right++) {
            mp[s[right]]--;
            if (mp[s[right]] == 0)
                formed++;

            if (right - left + 1 > p.size()) {
                if (mp[s[left]] == 0)
                    formed--;
                mp[s[left]]++;
                left++;
            }

            if (right - left + 1 == p.size() && formed == required)
                ans.push_back(left);
        }

        return ans;
    }
};