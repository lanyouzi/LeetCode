/*
 * @lc app=leetcode.cn id=2043 lang=cpp
 *
 * [2043] 简易银行系统
 */

// @lc code=start
class Bank {
   public:
    vector<long long> balance;
    Bank(vector<long long>& balance) { this->balance = balance; }

    bool transfer(int account1, int account2, long long money) {
        if (account1 < 1 || account1 > this->balance.size() || account2 < 1 ||
            account2 > this->balance.size()) {
            return false;
        }
        if (this->balance[account1 - 1] >= money) {
            this->balance[account1 - 1] -= money;
            this->balance[account2 - 1] += money;
            return true;
        } else {
            return false;
        }
    }
    bool deposit(int account, long long money) {
        if (account < 1 || account > this->balance.size()) {
            return false;
        }
        this->balance[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (account < 1 || account > this->balance.size() ||
            this->balance[account - 1] < money) {
            return false;
        }
        this->balance[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
// @lc code=end
