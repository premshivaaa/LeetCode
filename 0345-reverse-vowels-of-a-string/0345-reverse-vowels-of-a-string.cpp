class Solution {
private:
    bool isVowel(char ch) {
    // Returns true if ch is found in the vowels string
    return string("aeiouAEIOU").find(ch) != string::npos;
}
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size()-1;
        while(left < right){
            if(!isVowel(s[left])) left++;
            if(!isVowel(s[right])) right--;

            if(isVowel(s[left]) && isVowel(s[right])){
                swap(s[left], s[right]);
                left++;
                right--;
            } 
        }
        return s;
    }
};