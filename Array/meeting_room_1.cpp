#include <iostream>
#include <vector>
using namespace std;

class Interval {
   public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
   public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    static bool cmpInterval(Interval i1, Interval i2) {
        int i = 0;
        cout << i << endl;
        i++;
        return (i1.start < i2.start);
    }

    bool canAttendMeetings(vector<Interval> &intervals) {
        // sort the vector first
        sort(intervals.begin(), intervals.end(), cmpInterval);
        // the start out of latter need to eqaul or great than previous
        int index = 0;
        for (index = 0; index < intervals.size() - 1; index++) {
            if (intervals[index + 1].start < intervals[index].end) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Interval a(0, 0);
    Interval b(0, 0);

    Solution s;

    s.cmpInterval(a, b);
    s.cmpInterval(a, b);
}