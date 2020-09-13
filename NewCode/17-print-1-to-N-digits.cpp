#include <iostream>
#include <vector>

using namespace std;

int main() {
    int input = 0;
    // cases: 0, 1, 100000
    while(cin >> input) {
        // n elements vector
        // vector all 9
        // n elements vector: result
        // result all 0
        // valid len of result: len
        // for(len) cout result[len - i]
        if(input == 0) cout << 0 << endl;
        vector<int> max_digit(input, 9);
        vector<int> result(input + 1, 0);
        result[0] = 1;
        int len = 0;
        while(result.back() == 0) {
            for(int j = len; j >= 0; --j) {
                cout << result[j];
            }
            cout << " ";

            result[0]++;
            for(int i = 0 ; i < input; ++i) {
                if(result[i] == 10) {
                    result[i] = 0;
                    result[i+1]++;
                }
                if(result[i] != 0) {
                    len = i;
                }
            }
        }
    }
}
