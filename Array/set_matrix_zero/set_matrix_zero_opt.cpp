#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row_nums = matrix.size();
        int column_nums = matrix[0].size();

        vector<int> row_rec(row_nums, 0);
        vector<int> column_rec(column_nums, 0);

        int row_index = 0, column_index = 0;
        for (row_index = 0; row_index < row_nums; row_index++) {
            for (column_index = 0; column_index < column_nums; column_index++) {
                if (matrix[row_index][column_index] == 0) {
                    row_rec[row_index] = 1;
                    column_rec[column_index] = 1;
                }
            }
        }
        int alter_index = 0;
        for (row_index = 0; row_index < row_nums; row_index++) {
            if (row_rec[row_index] == 1) {
                for (alter_index = 0; alter_index < column_nums;
                     alter_index++) {
                    matrix[row_index][alter_index] = 0;
                }
            }
        }

        for (column_index = 0; column_index < column_nums; column_index++) {
            if (column_rec[column_index] == 1) {
                for (alter_index = 0; alter_index < row_nums; alter_index++) {
                    matrix[alter_index][column_index] = 0;
                }
            }
        }
    }
};

int main() {
    Solution run;

    vector<vector<int>> arg{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

    run.setZeroes(arg);
}
