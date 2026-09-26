class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end());
        string ans = "";
        for(string each : dictionary){
            int i = 0, j = 0;
            while(i < s.size()){
                if(each[j] == s[i]) j++;
                i++;
            }
            if(j == each.size()){
                if(j > ans.size()) ans = each;
            }
        }
        return ans;
    }
};