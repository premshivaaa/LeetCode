class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boats = 0, left = 0, right = people.size() - 1;
        sort(people.begin(), people.end());

        while(left <= right){
            if((people[left] + people[right]) <= limit){
                //boats++;
                left++;
                right--;
            } else{
                right--;
                //boats++;
            }
            boats++;
        }

        return boats;
    }
};