class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int &n: nums) {
            st.insert(n);
        }
        int longest=0;
        int l=0;
        for(auto &n: st) {
            if(st.find(n-1) == st.end()) {
                l = 1;
                while(st.find(n+l) != st.end()) {
                        l++;
                }
                longest = max(l, longest);
            }
        }
        return longest;
    }
};
