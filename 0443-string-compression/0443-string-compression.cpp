class Solution {
public:
    int compress(vector<char>& chars) {
        int left = 0, right = 0, n = chars.size();
        string s;
        while(right < n){
            s += chars[left];
            int len = 0;
            while(right < n && chars[right] == chars[left]){
                len++;
                right++;
            }
            if(len > 1) s += to_string(len);
            left = right;
        }
        int j = 0;
        for(char c : s){
            chars[j] = c;
            j++;
        }
        return s.size();
    }
};