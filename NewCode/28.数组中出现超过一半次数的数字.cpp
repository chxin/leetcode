#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        for(int i = 0; i < numbers.size(); ++i) {
            for(int j = i; j < numbers.size(); ++j) {
                if(numbers[i] > numbers[j]){
                    int tmp = numbers[i];
                    numbers[i] = numbers[j];
                    numbers[j] = tmp;
                }
            }
        }
        int n = numbers.size() / 2;
        return numbers[n];
    }
};

int main() {
    Solution s;
    vector<int> numbers({1,2,3,2,2,2,5,4,2});
    cout << s.MoreThanHalfNum_Solution(numbers);
    return 0;
}
