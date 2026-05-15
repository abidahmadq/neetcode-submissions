class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int maxA = 0;
        int a = 0;
        while(l < r) {
            a = min(heights[l], heights[r]) * (r-l);
            maxA = max(a, maxA);
            if(heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxA;
    }
};
