#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int x, a, b, c;
        cin >> x >> a >> b >> c;
        vector<int> ar(n);
        ar[0] = x;
        for(int i = 1; i < n; i++) {
            ar[i] = (a * ar[i-1] + b) % c;
        }

        deque<int> dq;
        int xorr = 0;
        for(int i = 0; i < n; i++) {
            if(!dq.empty() && dq.front() <= i-k) {
                dq.pop_front();
            }

            while(!dq.empty() && ar[dq.back()] >= ar[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
            if(i >= k-1) {
                xorr ^= ar[dq.front()];
            }
        }

        cout << xorr << "\n";
    }
}
