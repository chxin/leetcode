#include <vector>
#include <iostream>
using namespace std;
// class Solution {
// public:
//     int FindGreatestSumOfSubArray(vector<int> array) {
//         // {6,-3,-2,7,-15,1,2,2}
//         // 从正数开始，找到由负数变为正数，之和是否为正，
//         // 正，继续，负，下一个
//         int max = 0;
//         for(int i = 0; i < array.size(); ++i) {
//             if(array[i] > 0) {
//                 if(array[i] > max) max = array[i];
//                 int sum = 0;
//                 int last = 0;
//                 for(int j = i; j < array.size(); ++j) {
//                     sum += array[j];
//                     if(array[j] > 0) {
//                         if(sum > max) max = sum;
//                         if(last < 0) {
//                             if(sum < 0)
//                                 break;
//                         }
//                     }
//                 }
//             }
//         }
//         return max;
//     }
// };

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        vector<int> result(array.size(), 0);
        result[0] = array[0];
        int m = INT_MIN;
        for(int i = 1; i < array.size(); ++i) {
            result[i] = max(result[i-1]+array[i], array[i]);
            cout << result[i];
            m = max(m, result[i]);
        }
        return m;
    }
};

int main() {
    vector<int> array({6,-3,-2,7,-15,1,2,2});
    Solution s;
    cout << s.FindGreatestSumOfSubArray(array) << endl;
    return 0;
}
