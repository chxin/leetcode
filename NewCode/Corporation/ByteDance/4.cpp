#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

int main() {
    int m = 0, n =0;
    cin >> m >> n;
    for(int i = 0; i < m; ++i) { // 样例数
        map<vector<int, int>, int> result;
        map<int, int> tmp_m;
        vector<map<int, int> > pre(n, tmp_m);
        int z = 0;
        cin >> z;
        for(int k = 0; k < z; ++k) { // 特征数
            int x, y;
            cin >> x >> y;
            pre[0].insert(make_pair(x, y));
        }
        for(int j = 1; j < n; ++j) { // 帧数
            int l = 0;
            cin >> l;
            for(int k = 0; k < l; ++k) { // 特征数
                int x, y;
                cin >> x >> y;
                pre[j].insert(make_pair(x, y));
                vector<int, int> tmp({x, y});
                if(pre[j-1].find(x) != pre[j-1].end()) {
                    result[tmp]++;
                } else {
                    result[tmp]=0;
                }
            }
        }
        int max = 0;
        for(auto it : result) {
            if(max < it.second)
                max = it.second;
        }
        cout << max;
    }
    return 0;
}
