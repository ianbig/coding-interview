#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int origi_sum = 0, given_arr = 0;
        // calculate the orignal value
        for (int i = 0; i <= nums.size(); i++) {
            origi_sum += i;
        }
        // calculate the given array value
        for (vector<int>::const_iterator it = nums.begin(); it != nums.end();
             it++) {
            given_arr += *it;
        }

        // return the (given_array_value - original_value)
        return (origi_sum - given_arr);
    }
};