// constrain
// the lenght of vector would not exceed 3 *  10 ^ 4 and no smaller than 1
// the value of numsp[i] >= 3 * 10 ^4 and higher or equal -3 * 10 ^ 4
// array to store occurence --> how to fit into right slot  (insertion =
// efficiency) hashmap (insertion and search O(1))
#define INVALD_NUMS 3 * 100000
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        // use an dictionary to implement
        int tmp = INVALD_NUMS;
        unordered_map<int, int> table;

        for (auto iter = nums.begin(); iter != nums.end(); iter++) {
            tmp = *iter;
            if (table.find((tmp)) == table.end()) {
                table[tmp] = 1;
            } else {
                table[tmp] += 1;
            }
        }

        for (auto iter = table.begin(); iter != table.end(); iter++) {
            if (iter->second == 1) {
                return iter->first;
            }
        }

        return INVALD_NUMS;
    }
};

int main() {}