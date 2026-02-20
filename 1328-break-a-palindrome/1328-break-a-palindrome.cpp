class Solution {
public:
    string breakPalindrome(string palindrome) {
        int size = palindrome.size();
        if(size == 1) return "";
        bool flag = true;

        vector<char> charArray(palindrome.begin(), palindrome.end());

        for(int i=0; i<size/2; i++){
            if(charArray[i] != 'a' ){
                charArray[i] = 'a';
                flag = false;
                break;
            }
        }
        if(flag){
            charArray[size-1] = 'b'  ;
        }

        string result(charArray.begin(), charArray.end());
        return result;
    }
};