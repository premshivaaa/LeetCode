class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, right = 0, maxlen = 0;
        unordered_map<int,int> mp;

        while(right < fruits.size()){
            mp[fruits[right]]++;

            if(mp.size() > 2){
                // while(mp.size() > 2){
                    mp[fruits[left]]--;
                    if(mp[fruits[left]] == 0) mp.erase(fruits[left]);
                    left++;
                // }
            }
            maxlen = max(maxlen, right-left+1);
            right++;
        }

        return maxlen;
    }
};