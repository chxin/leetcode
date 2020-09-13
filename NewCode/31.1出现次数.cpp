#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
        {
            vector<vector<int> > v;
            vector<int> tmp(10, 0);
            int pre = 0;
            int mul = 1;
            for(int m = 0; m <= 9; ++m){
                v.push_back(tmp);
                for(int i = 0; i <= 9; ++i) {
                    if(i == 0) v[m][i] = 0;
                    if(i >= 1) v[m][i] = mul + pre * i;
                    cout << v[m][i] << " ";
                }
                cout << endl;
                pre = v[m][9];
                mul *= 10;
            }
            return 0;
        }
};

int main() {
    Solution s;
    cout << endl;
    cout << s.NumberOf1Between1AndN_Solution(1200);
    return 0;
}
