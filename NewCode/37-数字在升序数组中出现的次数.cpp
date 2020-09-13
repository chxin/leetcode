#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int l = left_binary(data, k, 0);
        int r = left_binary(data, k, 1);
        cout << l << " " << r << " ";
        return r - l + 1;
    }
    int left_binary(vector<int> & data, int & k, bool flag) {
        int left = 0, right = data.size();
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(data[mid] == k) {
                if(flag) left = mid + 1; // flag1 right; 0 left
                else right = mid;
            } else if(data[mid] > k) {
                right = mid;
            } else if(data[mid] < k) {
                left = mid + 1;
            }
        }
        if(flag && data[left] != k) return left - 1;
        return left;
    }
};

int main() {
    vector<int> data({1,2,3,3,3,3,4,5});
    Solution s;
    int ans = s.GetNumberOfK(data, 3);
    cout << ans;
    return 0;
}
