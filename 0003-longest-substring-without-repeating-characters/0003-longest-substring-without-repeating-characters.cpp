class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int count = 0;
        int maxi = 0;
        for (int i = 0; i < s.size();i++){
            char current = s[i];
            if (mp.find(current) != mp.end() && mp[current] >= count) {               
                 count = mp[current] +1;
            }
            mp[current] = i;
            maxi = max(maxi, i - count + 1);
        }
        return maxi;
    }
};