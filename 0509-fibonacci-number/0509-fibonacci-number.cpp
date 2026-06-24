class Solution {
private:
    int fibonnaci(int n){
        int prev1 = 0, prev2 = 1;

        for(int i=2; i<=n; i++){
            int curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }

        return prev2;
    }
public:
    int fib(int n) {
        if(n == 0) return 0;

        return fibonnaci(n);
    }
};