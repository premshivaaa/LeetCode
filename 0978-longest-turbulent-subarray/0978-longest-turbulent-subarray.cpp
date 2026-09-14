class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 1;

        int left = 0;
        int ans = 1;

        for (int right = 1; right < n; right++) {
            int cmp = (arr[right] > arr[right - 1]) ? 1 :
                      (arr[right] < arr[right - 1]) ? -1 : 0;

            if (cmp == 0) {
                left = right;
            } else if (right == n - 1 ||
                       cmp * ((arr[right + 1] > arr[right]) ? 1 :
                              (arr[right + 1] < arr[right]) ? -1 : 0) != -1) {
                ans = max(ans, right - left + 1);
                left = right;
            }
        }

        return ans;
    }
};