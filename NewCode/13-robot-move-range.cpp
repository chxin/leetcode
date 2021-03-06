#include  <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
        {
            T = threshold;
            R = rows;
            C = cols;
            result = 0;
            vector<bool> flag(R*C, 0);
            move_recurse(0, 0, flag);
            return result;
        }

    void move_recurse(int pos_r, int pos_c, vector<bool> & flag) {
        if(sum_pos(pos_r) + sum_pos(pos_c) > T) return;
        if(pos_r >= R || pos_c >= C) return;
        if(flag[pos_r*C+pos_c] == 1) return;
        result++;
        flag[pos_r*C+pos_c] = 1;
        cout << pos_r << " " << pos_c << "|";
        if(pos_r + 1 < R) move_recurse(pos_r + 1, pos_c, flag);
        if(pos_c + 1 < C) move_recurse(pos_r, pos_c + 1, flag);
    }

    int sum_pos(int value) {
        int sum = 0;
        while(value) {
            sum += value % 10;
            value /= 10;
        }
        return sum;
    }
private:
    int R;
    int C;
    int T;
    int result;
};

int main() {
    Solution ins;
    std::cout << ins.movingCount(5, 10, 10);
}


// 回朔法
// 为了避免重复，标记已经处理的子事件
