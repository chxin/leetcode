#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > result;
        for(int i = sum / 2 + 1; i >= 2; --i) {
            if(i % 2 == 1 && sum % i == 0 && sum / i >= i / 2) {
                int tmp = sum / i;
                vector<int> v;
                for(int m = 0; m < i; ++m) {
                    v.push_back(tmp - (i / 2) + m);
                }
                result.push_back(v);
            }
            if(i % 2 == 0 && sum % i == i / 2 && sum / i >= i / 2) {
                int tmp = sum / i;
                vector<int> v;
                for(int m = 0; m < i; ++m) {
                    v.push_back(tmp - (i / 2) + 1 + m);
                }
                result.push_back(v);
            }
        }
        return result;
    }
};

int main()
{
    Solution ins;
    /* std::cout << "Hello world" << std::endl; */
    vector<vector<int> > result = ins.FindContinuousSequence(100);
    for(auto i : result)
        for(auto m : i)
            cout << m << " ";
    return 0;
}

