class Solution {
public:
    int magicalString(int n) {
        if(n <= 3) return 1;

        string s = "122";
        int left = 2, toggle = 1, ones = 1;
        while(left < n){
            int turn = s[left] - '0';
            for(int i=0; i<turn; i++){
                s += to_string(toggle);
                if(toggle == 1) ones++;
                if(s.size() == n) return ones;
            }
            if(toggle == 1) toggle = 2;
            else toggle = 1;
            left++;
        }
        return 0;
    }
};