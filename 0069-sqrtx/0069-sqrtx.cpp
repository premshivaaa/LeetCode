class Solution {
private:
    void solve(int left, int right, int x, int& num) {
        if (left > right) return;

        int mid = left + (right - left) / 2;

        long long square = 1LL * mid * mid;

        if (square == x) {
            num = mid;
            return;
        }

        if (square < x) {
            num = mid;
            solve(mid + 1, right, x, num);
        } 
        else {
            solve(left, mid - 1, x, num);
        }
    }

public:
    int mySqrt(int x) {
        int num = 0;
        solve(0, x, x, num);
        return num;
    }
};