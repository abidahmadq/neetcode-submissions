class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int ns = newInterval[0];
        int ne = newInterval[1];
        int i=0;
        for(i=0; i < intervals.size(); i++) {
            if(ns > intervals[i][1]) {
                ans.push_back({intervals[i][0], intervals[i][1]});
            } else {
                break;
            }
        }
        for(; i < intervals.size(); i++) {
            if(ne >= intervals[i][0]) {
                ns = min(intervals[i][0], ns);
                ne = max(intervals[i][1], ne);
            } else {
                break;
            }
        }
        ans.push_back({ns, ne});
        for(; i < intervals.size(); i++) {
            ans.push_back({intervals[i][0], intervals[i][1]});
        }
        return ans;
    }
};
