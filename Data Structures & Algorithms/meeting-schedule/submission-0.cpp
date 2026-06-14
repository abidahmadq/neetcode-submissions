/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& x, auto& y) {
            return x.start < y.start;
        });
        int start = intervals[0].start;
        int end = intervals[0].end;
        for(int i=1; i < intervals.size(); i++) {
            if(intervals[i].start < end) {
                cout << intervals[i].start << " " << end << endl;
                return false;
            } else {
                end = intervals[i].end;
            }
        }
        return true;
    }
};
