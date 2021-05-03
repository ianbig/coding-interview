#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        // sort the nums
        sort(nums.begin(), nums.end());
        // loop through the array to find
        int i = 0;
        int cur_num = nums[0];
        for (i = 1; i < nums.size(); i++) {
            if (nums[i] == cur_num) {
                return nums[i];
            }
            cur_num = nums[i];
        }
        return -1;
    }
};

class OptSolution {
   public:
    int findDuplicate(vector<int>& nums) {}
}