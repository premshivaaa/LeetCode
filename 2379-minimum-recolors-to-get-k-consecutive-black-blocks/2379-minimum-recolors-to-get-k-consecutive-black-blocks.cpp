class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        unordered_map<char,int> mp;
        for(int i=0; i<k; i++){
            mp[blocks[i]]++;
        }
        int mini = INT_MAX;
        for(int i=k; i<blocks.size(); i++){
            mini = min(mini, mp['W']);
            mp[blocks[i]]++;
            mp[blocks[i-k]]--;
            
            if (mp[blocks[i-k]] == 0) mp.erase(blocks[i-k]);
        }
        mini = min(mini, mp['W']);
        return mini;
    }
};