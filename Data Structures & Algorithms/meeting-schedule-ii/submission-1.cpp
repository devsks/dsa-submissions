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
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](Interval A, Interval B) { return A.start < B.start; });

        int minRoom = 0;
        priority_queue<int, vector<int>, greater<int>> scheduler;
        for (auto interval : intervals) {
            if (!scheduler.empty()) {
                int meetingEnd = scheduler.top();
                if (meetingEnd <= interval.start) {
                    scheduler.pop();
                }
            }

            scheduler.push(interval.end);
            minRoom = max(minRoom, (int)scheduler.size());
        }

        return minRoom;
    }
};
