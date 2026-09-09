class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int count = 0;
        for(int i=0; i<colors.size(); i++){
            int prev = (i - 1 + colors.size()) % colors.size();
            int next = (i + 1) % colors.size();
            if(colors[i] != colors[prev] && colors[i] != colors[next]) count++;
        }
        return count;
    }
};