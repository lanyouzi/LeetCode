class Solution {
   public:
    bool oneEditAway(string first, string second) {
        // check replace
        if (first.size() == second.size()) {
            int differ = 0;
            for (int i = 0; i < first.size(); i++) {
                if (first[i] != second[i]) {
                    differ++;
                }
                if (differ > 1) {
                    return false;
                }
            }
            return true;
        }
        // check if add/delete
        //  regulate the first string is longer than the second
        if (first.size() < second.size()) {
            string tmp = second;
            second = first;
            first = tmp;
        }
        int pos = 0;
        for (pos = 0; pos < second.size(); pos++) {
            if (first[pos] != second[pos]) {
                first.erase(pos, 1);  // delete the first different char
                break;
            }
        }
        if (pos == second.size()) {
            return first.size() == second.size() + 1;  // tail different
        } else {
            return first == second;
        }
    }
};