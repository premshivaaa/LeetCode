class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size(), near = INT_MAX;
        vector<int> ans(n, INT_MAX);
        
        for(int i=0; i<n; i++){
            if(s[i] == c){
                near = i;
            }
            ans[i] = abs(near - i);
        }
        near = INT_MAX;
        for(int i=n-1; i>=0; i--){
            if(s[i] == c) near = i;
            ans[i] = min(ans[i], abs(near - i));
        }
        return ans;
    }
};