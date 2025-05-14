// Maximum Sum of Non-Adjacent Elements (LeetCode House Robber - #198)
// Time: O(n), Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prev2 = nums[0];                        // max sum up to i - 2
        int prev1 = max(nums[0], nums[1]);          // max sum up to i - 1

        for (int i = 2; i < n; ++i) {
            int curr = max(prev1, prev2 + nums[i]); // max of skipping or picking current
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << "Maximum sum of non-adjacent elements: " << sol.rob(nums) << endl;
    return 0;
}
