#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        // create and hash data structure
        unordered_set<int> hash_rec;
        // loop through the array if arr[i] in hash return true
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            if (hash_rec.find(*it) == hash_rec.end()) {
                hash_rec.insert(*it);
            } else {
                return true;
            }
        }
        return false;
    }
};