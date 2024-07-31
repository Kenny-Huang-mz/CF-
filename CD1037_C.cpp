// 贪心，如果 s 中相邻两个字符能通过交换变成和t一样，则直接交换，这样cost最小，只为1；否则只能0变1，1变0
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
int n;

int main() {
    cin >> n;
    string s, t;
    cin >> s >> t;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] != t[i] && s[i+1] != t[i+1]) { // 相邻两个都需要变
            if(s[i] != s[i+1]) { // 可以通过交换改变，如s = 10, t = 01
                ans++;
                s[i] = t[i], s[i+1] = t[i+1];
            } else { // 不能交换，只能0变1，1变0，如s = 00, t = 11
                ans++;
                s[i] = t[i];
            }
        }
        else if(s[i] != t[i]) s[i] = t[i], ans++;
    }
    cout << ans << endl;
    return 0;
}
