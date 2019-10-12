    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long

    const ll N = 1e5 + 5;
    ll n;
    vector<vector<ll>> adj(N);
    vector<bool> vis(N);
    unordered_map<ll, unordered_map<char, ll>> ans;
    string a;

    void clean() {
        ans.clear();
        for(ll i=0 ; i<=n ; i++) {
            adj[i].clear();
            vis[i] = false;
        }
    }

    unordered_map<char, ll> dfs(ll src=1) {
        vis[src] = true;
        unordered_map<char,ll> cnt;
        cnt[a[src-1]]++;
        for(auto it:adj[src]) {
            if(!vis[it]) {
                unordered_map<char, ll> next = dfs(it);
                for(auto c: next) cnt[c.first] += c.second;
            }
        }
        ans[src] = cnt;
        return cnt;
    }

    int main() {
        ll t; cin >> t;
        while(t--) {
            cin >> n;
            clean();
            ll q; cin >> q;
            cin >> a;
            for(ll i=0 ; i<n-1 ; i++) {
                ll x, y; cin >> x >> y;
                adj[x].push_back(y);
                adj[y].push_back(x);
            }
            dfs();
            while(q--) {
                ll x; char c; cin >> x >> c;
                cout << ans[x][c] << endl;
            }
        }
        return 0;
    }