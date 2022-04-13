/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start

class NumArray {
   public:
    vector<int> tree;
    vector<int> nums;
    int lowbit(int x) { return x & -x; }
    int query(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += tree[i];
        }
        return ans;
    }
    void add(int x, int u) {
        for (int i = x; i <= nums.size(); i += lowbit(i)) {
            tree[i] += u;
        }
    }
    NumArray(vector<int>& nums) {
        int n = nums.size();
        this->nums = nums;
        tree.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            add(i + 1, nums[i]);
        }
    }

    void update(int index, int val) {
        add(index + 1, val - nums[index]);
        nums[index] = val;
    }

    int sumRange(int left, int right) {
        return query(right + 1) - query(left);
    };
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end
