class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0 || s.size() == 1)
            return s.size();
        unordered_map<char, int> mp;
        int i = 0, maxl=0;
        int left=0;
        for(i=0; i < s.size(); i++) {
            mp[s[i]]++;
            maxl = max(i - left, maxl);
            while(mp[s[i]] > 1 && left <= i) {
                mp[s[left]]--;
                left++;
            }
        }
        maxl = max(i - left, maxl);
        return maxl;
    }
};  
