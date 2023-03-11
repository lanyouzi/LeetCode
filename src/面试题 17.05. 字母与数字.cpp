class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int n = array.size();
        int prefix_digits = 0, prefix_alphas = 0;
        vector<int> differ(n, 0);
        for (int i=0; i<n; i++) {
            if (isdigit(array[i][0])) {
                prefix_digits += 1;
            } else {
                prefix_alphas += 1;
            }
            differ[i] = prefix_digits-prefix_alphas;
        }
        // find (i,j) that makes prefix_digits[i]-prefix_alphas[i]==prefix_digits[j]-prefix_alphas[j]
        // i.e. differ[i]==differ[j] with longest j-i and minimal i
        unordered_map<int, int> mp;
        mp[0] = -1;
        int start = n, length = 0;
        for (int i=0; i<n; i++) {
            if (mp.count(differ[i])) {
                if (i-mp[differ[i]]>length) {
                    length = i-mp[differ[i]];
                    start = mp[differ[i]];
                }
            } else {
                mp[differ[i]] = i;
            }
        }
        return vector<string>(array.begin()+start+1, array.begin()+start+length+1);
    }
};