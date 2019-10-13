z #include<bits / stdc++.h> using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ld long double
#define fr first
#define sc second
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define umap unordered_map<ll, ll>
#define prq priority_queue<int>
#define inf 1e18
#define test cout << "abcd\n";
#define show1(x) cout << x << "\n"
#define show2(x, y) cout << x << " " << y << "\n"
#define show3(x, y, z) cout << x << " " << y << " " << z << "\n"
#define endl "\n"
#define mod (int)1000000007
#define N 2005
int main()
{
    fast;
    // long long t;
    long long t, n, p_ = 1, p, x, ans, cost;
    cin >> t;
    // cin >> n;
    // vector<long long> v(n), dp(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> v[i];
    // }
    // long long t, n, p = 1, x, ans, cost;

    while (t--)
    {
        // p = p_; s
        // long long t, n, p, x, ans, cost;
        cin >> n >> p;

        vector<long long> v(n), dp(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        dp[0] = v[0];
        for (int i = 0; i < n - 1; i++)
        {
            dp[i + 1] = min(v[i + 1], 2LL * dp[i]);
        }
        ans = (long long)4e18;
        cost = 0;
        for (long long i = n - 1; i >= 0; i--)
        {
            x = p / (1LL << i);
            cost += (long long)x * dp[i];
            p -= x << i;
            ans = min(ans, cost + (p > 0) * dp[i]);
        }
        cout << ans << endl;
        p_ += 1;
    }
    return 0;
}