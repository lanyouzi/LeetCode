/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        // for (auto item : nums) {
        //     cout << item << " ";
        // }
        cout << endl;
        int n = nums.size();
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int left = j + 1, right = n - 1;
                long long sum = (long long) target - nums[i] - nums[j];
                while (left < right) {
                    if (nums[left] + nums[right] == sum) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        // cout << nums[i] << " " << nums[j] <<" " << nums[left] <<
                        // " " << nums[right] << endl;
                        while (left < n - 1 && nums[left + 1] == nums[left]) {  // avoid duplicated item
                            left++;
                        }
                        left++;
                        while (right > 0 && nums[right - 1] == nums[right]) {   // avoid duplicated item
                            right--;
                        }
                        right--;
                    } else if (nums[left] + nums[right] < sum) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

