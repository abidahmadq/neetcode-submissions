class Solution {
public:
    int robHelper(vector<int>& nums) {
        int r1, r2;
        r1 = r2 = 0;
        for(int i=0; i < nums.size(); i++) {
            int temp = max(nums[i] + r1, r2);
            r1 = r2;
            r2 = temp;
        }
        return max(r1, r2);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        vector<int> t1(nums.begin(), nums.end()-1);
        vector<int> t2(nums.begin()+1, nums.end());
        return max(robHelper(t1), robHelper(t2));
    }
};
