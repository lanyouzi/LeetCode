/*
 * @Author: mrk-lyz mrk_lanyouzi@yeah.net
 * @Date: 2022-07-16 10:19:09
 * @LastEditTime: 2022-07-16 10:21:05
 * @FilePath: /LeetCode/src/剑指 Offer II 041. 滑动窗口的平均值.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by mrk-lyz mrk_lanyouzi@yeah.net, All Rights Reserved. 
 */
class MovingAverage {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    int max_size;
    int csum;
    MovingAverage(int size) {
        max_size = size;
        csum = 0;
    }
    
    double next(int val) {
        if (q.size()==max_size) {
            csum -= q.front();
            q.pop();
        }
        csum+=val;
        q.push(val);
        return 1.0 * csum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */