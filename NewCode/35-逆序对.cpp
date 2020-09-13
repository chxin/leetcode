#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) {
        int left = 0, right = data.size();
        int result = divide(data, left, right);
        return result;
    }

    int divide(vector<int> & data, int left, int right) {
        if(right - left < 2) {
            return 0;
        }
        int mid = left + (right - left) / 2;
        int n1 = divide(data, left, mid);
        int n2 = divide(data, mid, right);
        int n = cal(data, left, mid, right);
        return n1 + n2 + n;
    }

    int cal(vector<int> & data, int left, int mid, int right) {
        vector<int> tmp1(data.begin()+left, data.begin()+mid);
        vector<int> tmp2(data.begin()+mid,  data.begin()+right);
        sort(tmp1.begin(), tmp1.end(), [] (int a, int b) -> bool {return a > b;});
        sort(tmp2.begin(), tmp2.end(), [] (int a, int b) -> bool {return a > b;});
        int count = 0;
        for(int i = 0; i < tmp1.size(); ++i) {
            for(int j = 0; j < tmp2.size(); ++j) {
                if(tmp1[i] > tmp2[j]) {
                    count += tmp2.size() - j;
                    break;
                }
            }
        }
        return count;
    }
};

int main() {
    vector<int> data({1,2,3,4,5,6,7,0});
    // vector<int> data({7,0});
    Solution s;
    cout << s.InversePairs(data) << endl;
    return 0;
}
