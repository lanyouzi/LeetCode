/*
 * @lc app=leetcode.cn id=2383 lang=cpp
 *
 * [2383] 赢得比赛需要的最少训练时长
 */

// @lc code=start
class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int energy_time = 0, exp = initialExperience;
        for (int i = 0; i<energy.size(); i++) {
            energy_time+=energy[i];
        }
        int ans = initialEnergy>energy_time?0:energy_time+1-initialEnergy;
        for (int i = 0; i<experience.size(); i++) {
            if (exp<=experience[i]) {
                ans+=(experience[i]+1-exp);
                exp = experience[i]+1;
            }
            exp+=experience[i];
        }
        return ans;
    }
};
// @lc code=end

