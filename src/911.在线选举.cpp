/*
 * @lc app=leetcode.cn id=911 lang=cpp
 *
 * [911] 在线选举
 */

// @lc code=start
class TopVotedCandidate {
public:
    vector<int> persons;
    vector<int> times;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->persons = persons;
        this->times = times;
    }
    
    int q(int t) {
        vector<int> flag(5001);
        vector<int> latest_occur(5001);
        for (int i=0; i<this->times.size(); i++) {
            if (t>=this->times[i]) {
                flag[this->persons[i]]++;
                latest_occur[this->persons[i]] = i;
            }
            
        }
        int max_num = 0;
        vector<int> candidates;
        for (int i=0;i<5001; i++) {
            if (max_num<flag[i]) {
                max_num = flag[i];
                candidates.clear();
                candidates.emplace_back(i);
            } else if (max_num==flag[i]) {
                candidates.emplace_back(i);
            }
        }
        int ans = 0;
        int index = -1;
        for (auto &item : candidates){
            if (latest_occur[item]>index){
                index = latest_occur[item];
                ans = item;
            }
        }
        return ans;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
// @lc code=end

