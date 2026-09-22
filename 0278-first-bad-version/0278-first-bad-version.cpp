// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
private:
    void solve(int left, int right, int& ans) {
        if (left > right) return;

        int mid = left + (right - left) / 2;

        if (isBadVersion(mid)) {
            ans = mid;                  // possible answer
            solve(left, mid - 1, ans);  // search for an earlier bad version
        }

        else solve(mid + 1, right, ans); // good version - search right
    }

public:
    int firstBadVersion(int n) {
        int ans = n;

        solve(1, n, ans);

        return ans;
    }
};