#include <iostream>

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty()) return 0;
        // 对角线，找到大于target位置x y
        int row = array.size(), col = array[0].size();
        int x = 0, y = 0;
        while(x < row && y < col) {
            if(array[x][y] >= target) break;
            ++x;
            ++y;
        }
        if(x >= row || y >= col) return 0; //缺少这行导致栈错误
        if(array[x][y] == target) return 1;//缺少这行导致target位于对角线出错
        // 第一行，从x开始右移，找到大于target，x1 0
        int y1 = y;
        while(y1 < col) {
            if(array[0][y1] > target) break;
            ++y1;
        }
        // 在x 0 到 x1 y
        for(int pos_x = 0; pos_x < x; ++pos_x) {
            for(int pos_y = y; pos_y < y1; ++pos_y) {
                if(target == array[pos_x][pos_y]) return 1;
            }
        }
        // 第一列，从y开始下移，找到大于target，0， y1
        int x1 = x;
        while(x1 < row) {
            if(array[x1][0] > target) break;
            ++x1;
        }
        // 在0 y 到 x y1
        for(int pos_x = x; pos_x < x1; ++pos_x) {
            for(int pos_y = 0; pos_y < y; ++pos_y) {
                if(target == array[pos_x][pos_y]) return 1;
            }
        }
        return 0;
    }
};
