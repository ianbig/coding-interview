#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row_nums = matrix.size();
        int column_nums = matrix[0].size();
        bool col_alter = false;

        int row_index = 0, column_index = 0;
        for (row_index = 0; row_index < row_nums; row_index++) {
            for (column_index = 0; column_index < column_nums; column_index++) {
                if (matrix[row_index][column_index] == 0) {
                    if (column_index == 0) {
                        col_alter = true;
                        matrix[row_index][0] = 0;
                    } else {
                        matrix[0][column_index] = 0;
                        matrix[row_index][0] = 0;
                    }
                }
            }
        }

        int alter_index = 0;
        for (row_index = 1; row_index < row_nums; row_index++) {
            if (matrix[row_index][0] == 0) {
                for (alter_index = 0; alter_index < column_nums;
                     alter_index++) {
                    matrix[row_index][alter_index] = 0;
                }
            }
        }

        for (column_index = 1; column_index < column_nums; column_index++) {
            if (matrix[0][column_index] == 0) {
                for (alter_index = 0; alter_index < row_nums; alter_index++) {
                    matrix[alter_index][column_index] = 0;
                }
            }
        }

        if (col_alter == true) {
            for (alter_index = 0; alter_index < row_nums; alter_index++) {
                matrix[alter_index][0] = 0;
            }
        }

        if (matrix[0][0] == 0) {
            for (alter_index = 0; alter_index < column_nums; alter_index++) {
                matrix[0][alter_index] = 0;
            }
        }
    }
};

int main() {
    Solution run;

    vector<vector<int>> arg{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

    run.setZeroes(arg);
}
