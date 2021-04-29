#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // loop thr to map between nums and index
        int tmp_index = 0;
        for (int i = 0; i < nums.size(); i++) {
            tmp_index = abs(nums[i]) - 1;
            if (nums[tmp_index] > 0) {
                nums[tmp_index] = -nums[tmp_index];
            }
        }

        vector<int> ans;
        // find non-neg and append into ans
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};