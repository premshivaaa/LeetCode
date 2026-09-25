class Solution {
public:
    string reverseWords(string s) {
        int pointer = 0, index = 0;
        while(index <= s.size()){
            if(index == s.size() || s[index] == ' '){
                reverse(s.begin() + pointer, s.begin() + index);
                pointer = index + 1;
            }
            
            index++;
        }
        return s;
    }
};