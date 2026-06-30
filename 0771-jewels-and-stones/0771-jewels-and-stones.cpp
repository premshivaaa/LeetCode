class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> st;
        for(char ch : jewels){
            st.insert(ch);
        }
        int result = 0;

        for(char it : stones){
            if(st.find(it) != st.end()) result++;
        }

        return result;
    }
};