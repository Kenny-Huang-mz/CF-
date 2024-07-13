```
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
set<int> s[N];
int a[N];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s[a[i]].insert(i);
    }

    sort(a + 1, a + 1 + n); // 排序后的数组即为正确的抽卡顺序, 即先抽最小的, 最后抽最大的

    long long ans = n;
    int pos = 1;
    for(int i = 1; i <= n; i++) {
        auto it = s[a[i]].lower_bound(pos); // 从pos开始寻找, 初始时pos默认为1, 即从第1个位置开始向后寻找
        if(it == s[a[i]].end()) { // 此时待寻找元素出现在前面位置, 如: 5 4 3 2 1, 1找完后, pos = 5, 接下来找2, 但是2在1的前面, 因此应从头循环
            ans += n - i + 1; // n - i + 1表示在访问第i个元素时, 还有多少个元素需要寻找, 如: 5 4 3 2 1, i = 4时, 此时还有4, 5两个元素待寻找
            pos = 1;
            it = s[a[i]].lower_bound(pos); // 重新设置pos为从头开始寻找
        }
        pos = *it;
        s[a[i]].erase(pos);
    }
    cout << ans << endl;
    return 0;
}
``` 
