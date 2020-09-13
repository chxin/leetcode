#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<fstream>

using namespace std;

void recurse(vector<int> & pos, int sel, vector<bool> flags, int & result, int sum, int & n) {
    if(flags[sel] == 1) return;
    flags[sel] = 1;
    if(sum >= 3) {
        vector<int> cal;
        for(int i = 0; i < flags.size(); ++i) {
            if(flags[i] == 1) {
                cal.push_back(pos[i]);
                // cout << pos[i] << " ";
            }
        }
        int d1 = cal[1] - cal[0];
        int d2 = cal[2] - cal[1];
        int d3 = cal[2] - cal[0];
        if(d1 > n || d2 > n || d3 > n)
            return;
        else {
            result++;
            return;
        }
    }
    for(int i = 0; i < pos.size(); ++i) {
        recurse(pos, i, flags, result, sum+1, n);
    }
}

int main() {
    ifstream cin("0t");
    if (! cin.is_open()) {
        cout << "Error opening cin";
        exit (1);
    }

    int m = 0, n = 0;
    cin >> m >> n;
    vector<int> pos(m, 0);
    for(int i = 0; i < m; ++i) {
        cin >> pos[i];
    }
    int result = 0;
    for(int i = 0; i < m; ++i) {
        vector<bool> flags(m, 0);
        recurse(pos, i, flags, result, 1, n);
    }
    cout << result / 6;
    return 0;
}
