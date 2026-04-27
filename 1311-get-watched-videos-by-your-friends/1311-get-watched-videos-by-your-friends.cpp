class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, 
                                          vector<vector<int>>& friends, 
                                          int id, int level) {
        
        int n = friends.size();
        vector<int> vis(n, 0);
        queue<int> q;
        
        q.push(id);
        vis[id] = 1;

        int currLevel = 0;

        // BFS to reach level
        while(!q.empty()){
            int size = q.size();

            if(currLevel == level) break;

            while(size--){
                int node = q.front(); q.pop();

                for(auto it : friends[node]){
                    if(!vis[it]){
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
            currLevel++;
        }

        // Count videos
        unordered_map<string, int> freq;

        while(!q.empty()){
            int node = q.front(); q.pop();

            for(auto &video : watchedVideos[node]){
                freq[video]++;
            }
        }

        // Sort result
        vector<pair<string, int>> temp(freq.begin(), freq.end());

        sort(temp.begin(), temp.end(), [](auto &a, auto &b){
            if(a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        });

        vector<string> ans;
        for(auto &it : temp){
            ans.push_back(it.first);
        }

        return ans;
    }
};