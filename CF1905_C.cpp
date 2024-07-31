// 原来erase不是O(1)的我擦
// 单调栈+贪心。
// 字典序最大子序列可以用单调栈求出。
// 由于字典序最大子序列是递减的，把子序列反转，如果s不是有序的，输出-1
// 否则，例如 bbbaa 循环右移 2 次就变成 aabbb 有序的了，所以答案为原最大子序列长度去掉和子序列首字母一样的字母后，子序列的剩余字母个数。
#include <bits/stdc++.h>
using namespace std;
typedef pair<char, int> PII;

const int N = 2e5 + 5;
int a[N];
int T, n;
int st[N];

inline int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        memset(st, 0, sizeof st);
        string s;
        n = read();
        cin >> s;
        string temp = s;
        sort(temp.begin(), temp.end());
        if(s == temp) printf("0\n");
        else {
            temp = "";
            vector<PII> v;
            for(int i = 0; i < n; i++) {
                if(v.empty() || s[i] <= v.back().first) v.push_back({s[i], i});
                else {
                    while(!v.empty() && s[i] > v.back().first) v.pop_back();
                    v.push_back({s[i], i});
                }
            }
            int len = v.size();
            int ans = 0;
            for(int i = 0; i < v.size(); i++) if(v[i].first == v[0].first) ans++;
            // sort(v.begin(), v.end());
            reverse(v.begin(), v.end());
            // cout << temp << endl; // 最大字典序子序列
            string temp1 = "";
            for(auto x : v) st[x.second] = 1;
            int id = 0;
            for(int i = 0; i < n; i++) {
                if(st[i] == 0) temp1.push_back(s[i]);
                else {
                    // cout << v[i].first << " ";
                    // printf("%c ", v[0].first);
                    temp1.push_back(v[id++].first);
                }
            } // temp1为，原字符串中的最大字典序子序列排序之后的序列
            // cout << temp;
            string temp2 = temp1; // 判断temp1是否有序
            sort(temp2.begin(), temp2.end());
            if(temp2 == temp1) printf("%d\n",len - ans);
            else printf("-1\n");
        }
    }
    return 0;
}
