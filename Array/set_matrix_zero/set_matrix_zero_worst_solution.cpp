#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        vector<vector<int>> vcopy = matrix;
        // make a copy of vector

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                cout << vcopy[i][j] << " ";
            }
            cout << endl;
        }
        // do the set 0 operation
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (matrix[i][j] == 0) {
                    for (int k = 0; k < column; k++) {
                        vcopy[i][k] = 0;
                    }
                    for (int k = 0; k < row; k++) {
                        vcopy[k][j] = 0;
                    }
                }
            }
        }

        matrix = vcopy;
    }
};

int main() {
    Solution run;

    vector<vector<int>> arg{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

    run.setZeroes(arg);
}
