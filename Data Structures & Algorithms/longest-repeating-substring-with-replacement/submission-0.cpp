class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int left = 0; 
        int right = 0; 
        int maxl = 0;
        int ans = 0;
        for(right=0; right < s.size(); right++) {
            mp[s[right]]++;
            maxl = max(maxl, mp[s[right]]);
            while((right - left + 1) - maxl > k) {
                mp[s[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
