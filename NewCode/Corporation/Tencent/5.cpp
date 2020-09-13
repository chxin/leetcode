// 5 5 3
// 1 2 1
// 2 3 1
// 3 5 1
// 5 1 1
// 4 5 1

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<fstream>
using namespace std;


vector<vector<int> > cost;
int sz;
void find_path(int & target, int c, int next, vector<int> & result) {
    if(next == target) {
        result.push_back(c);
        return;
    }
    for(int i = 0; i < sz; ++i) {
        if(cost[i][1] == next) {
            find_path(target, c + cost[i][2], cost[i][0], result);
        }
    }
}

int main() {
    ifstream cin("5t");
    if (! cin.is_open()) {cout << "Error opening cin"; exit (1);}

    int point = 0, path = 0, mul = 0;
    cin >> point >> path >> mul;
    int n1 = 0, n2 = 0, n3 = 0;
    for(int i = 0; i < path; ++i) {
        cin >> n1 >> n2 >> n3;
        cost.push_back({n1, n2, n3});
    }
    sz = cost.size();
    // 找到到point的最小路径
    vector<int> result;
    int target = 1;
    find_path(target, 0, point, result);
    int ans = INT_MAX;
    for(auto i : result) {
        if(ans > i) ans = i;
    }
    int target1 = point;
    find_path(target1, 0, 1, result);
    int ans1 = INT_MAX;
    for(auto i : result) {
        if(ans1 > i) ans1 = i;
    }
    cout << (ans+1) * mul;
    return 0;

}
