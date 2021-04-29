#include <iostream>
#include <vector>

using namespace std;
// brute force: with division
class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul = 1;
        bool zero_alert = false;

        int i = 0;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (zero_alert == true) {
                    mul = 0;
                }
                zero_alert = true;
                continue;
            }
            mul = mul * nums[i];
        }

        vector<int> ans;
        // dealing zero situation
        if (zero_alert == true) {
            for (i = 0; i < nums.size(); i++) {
                if (nums[i] == 0) {
                    ans.push_back(mul);
                } else {
                    ans.push_back(0);
                }
            }
            return ans;
        }

        for (i = 0; i < nums.size(); i++) {
            ans.push_back(mul / nums[i]);
        }

        return ans;
    }
};

// refined solution
class MySoluction {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // calculate everything from left
        int i = 0;
        vector<int> leftArr;
        leftArr.push_back(1);
        for (i = 0; i < nums.size() - 1; i++) {
            leftArr.push_back(leftArr[i] * nums[i]);
        }
        // calculate everything from right
        vector<int> rightArr;
        rightArr.push_back(1);
        for (i = nums.size() - 1; i > 0; --i) {
            rightArr.push_back(nums[i] * rightArr[(nums.size() - 1) - i]);
        }
        // combine the left and the right
        vector<int> ans;
        for (i = 0; i < leftArr.size(); i++) {
            ans.push_back(leftArr[i] * rightArr[rightArr.size() - 1 - i]);
        }

        return ans;
    }
};

// optimized solution
class OptSoluction {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // calculate everything from left
        int i = 0;
        vector<int> outArr;
        outArr.push_back(1);
        for (i = 0; i < nums.size() - 1; i++) {
            outArr.push_back(outArr[i] * nums[i]);
        }

        // calculate everything from right
        int rightProd = 1;

        // combine the left and the right
        for (i = outArr.size() - 1; i >= 0; i--) {
            outArr[i] = outArr[i] * rightProd;
            rightProd *= nums[i];
        }

        return ans;
    }
};

int main() {
    OptSoluction ans;
    vector<int> test;
    // test.assign({1, 2, 3, 4});
}