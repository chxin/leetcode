#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int result = 0;
        for(auto i : data) result ^= i;
        int pos = 0;
        while(result & (0x00000001 << pos) == 0) ++pos;
        vector<int> v1;
        vector<int> v2;
        for(auto i : data){
            if(i & (0x00000001 << pos) == 0) v1.push_back(i);
            else v2.push_back(i);
        }
        *num1 = 0;
        *num2 = 0;
        for(auto i : v1) *num1 ^= i;
        for(auto i : v2) *num2 ^= i;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

