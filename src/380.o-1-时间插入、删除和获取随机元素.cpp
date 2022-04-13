/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */
/*
    变长数组：查询元素时间复杂度为O(1)
    哈希表：插入和删除时间复杂度为O(1)
    因此将二者结合起来，变长数组存放值，哈希表存放值在数组的下标
 */
// @lc code=start
class RandomizedSet {
   public:
    vector<int> nums;
    unordered_map<int, int> indices;

    RandomizedSet() { srand((unsigned)time(nullptr)); }

    bool insert(int val) {
        if (indices.count(val) > 0) {
            return false;
        }
        nums.emplace_back(val);
        indices[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (indices.count(val) == 0) {
            return false;
        }
        int index = indices[val];
        nums[index] = nums[nums.size() - 1];
        indices[nums[nums.size() - 1]] = index;
        nums.pop_back();
        indices.erase(val);
        return true;
    }

    int getRandom() {
        int random = rand() % nums.size();
        return nums[random];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
