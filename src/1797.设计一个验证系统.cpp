/*** 
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-02-09 09:45:31
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-02-09 09:45:44
 * @FilePath: \LeetCode\src\1797.设计一个验证系统.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
/*
 * @lc app=leetcode.cn id=1797 lang=cpp
 *
 * [1797] 设计一个验证系统
 */

// @lc code=start
class AuthenticationManager {
public:
    int validity;
    unordered_map<string, int> tokens;
    
    AuthenticationManager(int timeToLive) {
        validity = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        tokens[tokenId] = currentTime+validity;
    }
    
    void renew(string tokenId, int currentTime) {
        auto cur = tokens.find(tokenId);
        if (cur != tokens.end() && currentTime<cur->second) {
            cur->second = currentTime+validity;
        }    
    }
    
    int countUnexpiredTokens(int currentTime) {
        int ans = 0;
        for (auto cur = tokens.begin(); cur!=tokens.end(); cur++) {
            if (currentTime<cur->second) {
                ans++;
            }
        }
        return ans;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
// @lc code=end

