class Solution {
public:
    int rob(vector<int>& nums) {
        int r1, r2;
        r1 = r2 = 0;
        for(int i=0; i < nums.size(); i++) {
            int temp = max(nums[i] + r1, r2);
            r1 = r2;
            r2 = temp;
        }
        return max(r1, r2);
    }
};
