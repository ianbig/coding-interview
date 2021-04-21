#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int index = -1;
        for (int i = 0; i < nums.size(); i++) {
            index = abs(nums[i]) - 1;
            if (nums[index] < 0) {
                ans.push_back(abs(nums[index]));
            } else {
                nums[index] = 0 - nums[index];
            }
        }

        return ans;
    }
};

int main() {}

// thoughts: used hashmap to enable store (key, value)