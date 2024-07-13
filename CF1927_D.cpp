/*没啥好说的，直接O(n)对数组 a 的每一个元素预处理一遍，找到a[i]左侧最近的，不等于a[i]的数，便可以实现O(1)回答*/
/*孩子们，我回来了*/

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int a[N], d[N] = {-1};
int T, n, q;

int main() {
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

        // 对于a数组中的每个元素，找到其左侧的，且不等于它的最近的元素位置
        for(int i = 2; i <= n; i++) {
            if(a[i] == a[i-1]) d[i] = d[i - 1];
            else d[i] = i - 1;
        }

        cin >> q;
        while(q--) {
            int l, r;
            cin >> l >> r;
            if(d[r] < l) cout << -1 << " " << -1 << endl;
            else cout << d[r] << " " << r << endl;
        }
    }
    return 0;
}
