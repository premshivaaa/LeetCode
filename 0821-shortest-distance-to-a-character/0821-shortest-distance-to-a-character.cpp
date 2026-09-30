class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> ans(n, INT_MIN);
        int prev = INT_MAX;

        for(int i=0; i<n; i++){
            if(s[i] == c) prev = i;
            ans[i] = abs(prev - i);
        }
        int next = INT_MAX;
        for(int j=n-1; j>=0; j--){
            if(s[j] == c) next = j;
            ans[j] = min(abs(next-j), ans[j]);
        }
        return ans;
    }
};