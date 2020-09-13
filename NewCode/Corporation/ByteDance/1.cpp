// 1. 三个同样的字母连在一起，一定是拼写错误，去掉一个的就好啦：比如 helllo -> hello
// 2. 两对一样的字母（AABB型）连在一起，一定是拼写错误，去掉第二对的一个字母就好啦：比如 helloo -> hello
// 3. 上面的规则优先“从左到右”匹配，即如果是AABBCC，虽然AABB和BBCC都是错误拼写，应该优先考虑修复AABB，结果为AABCC
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void state_machine(string & s, int pos, int state, char pre, string & result) {
    while(pos < s.size()) {
        switch(state) {
        case 0:
            if(pre == s[pos])
                state = 2;
            else
                state = 0;
            pre = s[pos];
            result.push_back(pre);
            pos++;
            break;
        case 2: // 2个相同
            if(pre == s[pos]) {
                state = 2;
            }
            else {
                state = 4;
                result.push_back(s[pos]);
            }
            pre = s[pos];
            pos++;
            break;
        case 4: //第三个不同
            if(pre == s[pos]) {
                state = 0;
            }
            else {
                result.push_back(s[pos]);
                state = 0;
            }
            pre = s[pos];
            pos++;
            break;
        }
    }
}

int main(){
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
// 两个相同，第三个相同，情况1，处理之后，状态机返回
// 第三个不同，第四个相同，情况2，
        string result;
        state_machine(s, 0, 0, '\0', result);
        cout << result << endl;
    }
    return 0;
}
