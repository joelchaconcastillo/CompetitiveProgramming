#include <bits/stdc++.h>

#define int long long

using namespace std;
using ll = long long;

void solve();

int32_t main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        solve();
    }
    return 0;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> max0by1(n + 1, -1e9);
    vector<vector<int>> max0pref(n + 1, vector<int>(n + 1));
    vector<vector<int>> max0suf(n + 1, vector<int>(n + 1));
    for (int l = 0; l < n; ++l) {
        int cnt1 = 0;
        for (int r = l + 1; r <= n; ++r) {
            cnt1 += s[r - 1] == '1';
            max0pref[r][cnt1] = max(max0pref[r][cnt1], r - l);
            max0suf[l][cnt1] = max(max0suf[l][cnt1], r - l);
        }
    }
    for (int r = 0; r <= n; ++r) {
        for (int cnt = 0; cnt <= n; ++cnt) {
            if (r) max0pref[r][cnt] = max(max0pref[r][cnt], max0pref[r - 1][cnt]);
            if (cnt) max0pref[r][cnt] = max(max0pref[r][cnt], max0pref[r][cnt - 1]);
        }
    }
    for (int l = n; l >= 0; --l) {
        for (int cnt = 0; cnt <= n; ++cnt) {
            if (l + 1 <= n) max0suf[l][cnt] = max(max0suf[l][cnt], max0suf[l + 1][cnt]);
            if (cnt) max0suf[l][cnt] = max(max0suf[l][cnt], max0suf[l][cnt - 1]);
        }
    }
    vector<int> ans(n + 1, -1e9);
    for (int l = 0; l < n; ++l) {
        int cnt0 = 0;
        for (int r = l; r <= n; ++r) {
            if (r > l) cnt0 += s[r - 1] == '0';
            if (cnt0 > k) break;
            max0by1[r - l] = max(max0by1[r - l], max0pref[l][k - cnt0]);
            max0by1[r - l] = max(max0by1[r - l], max0suf[r][k - cnt0]);
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int a = 1; a <= n; ++a) ans[a] = max(ans[a], i + max0by1[i] * a);
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
    cout << '\n';
}
