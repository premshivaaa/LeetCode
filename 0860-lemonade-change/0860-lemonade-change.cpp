class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0;

        for(int i : bills){
            if(i == 5){
                fives++;
            }
            else if(i == 10){
                if(fives >= 1){
                    tens++;
                    fives--;
                } else{
                    return false;
                }
            }
            else{
                if(tens >=1 && fives>=1){
                    tens--;
                    fives--;
                } else if(fives >= 3) {
                    fives -= 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};