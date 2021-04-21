#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) {
            return {};
        }

        sort(nums.begin(), nums.end());

        int twoSum_target = 0, mv_index;
        vector<vector<int>> ans;
        int sum = -1;

        for(mv_index = 0; mv_index < nums.size() - 2; mv_index++) {
            if(mv_index != 0 && nums[mv_index] == nums[mv_index - 1]) {
                continue;
            } // remove duplicate

            int tail_index = nums.size() - 1, front_index = mv_index + 1;
            while(front_index < tail_index) {
                sum = nums[mv_index] + nums[front_index] + nums[tail_index];
                if(sum > 0) {
                    tail_index--;
                } else if(sum < 0) {
                    front_index++;
                } else {
                    ans.push_back(vector<int>{nums[mv_index], nums[front_index], nums[tail_index]});

                    while(front_index < tail_index && nums[front_index] == nums[front_index + 1]) {
                        front_index++;
                    }

                    while(front_index < tail_index && nums[tail_index] == nums[tail_index-1]) {
                        tail_index--;
                    }
                    front_index++;
                    tail_index--;
                }
            }
        }

        return ans;
    }
    
};
/*===Input===*/
/*
    * no duplicate triplets
    * -10^5 < nums[i] < 10 ^ 5
*/

/* Solution */
/*
    1. 3 for loops
    2. sort + two_sum
*/
