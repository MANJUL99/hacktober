    #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 200050;
vector<int> vec[mx];
ll arr[mx];
ll dp[mx];
ll ans ;
int n;
int dfs(int u , int from)
{
    int i,v,l=vec[u].size();
    int sum = 1;
    for(i = 0 ; i < l ; i++)
    {
        v = vec[u][i];
        if(v == from)continue;
        sum += dfs(v,u);
    }
    return arr[u] = sum;
}
void dfs2(int u , int from)
{
    int i,j,k,v,l=vec[u].size();
    ll here = arr[u];
    if(u==1) dp[u]=ans;
    else
    {
        dp[u] = dp[from] - arr[u] + arr[from];
    }
    ans = max(ans,dp[u]);
    for(i = 0 ; i < l ; i++)
    {
        v = vec[u][i];
        if(v == from)continue;
        arr[u] = n-arr[v];
        dfs2(v,u);
    }
    arr[u] = here;
}
 
int main()
{
    int  m,i,j,k,u,v,p,q,r;
    scanf("%d",&n);
    for(i = 1 ; i < n ; i++)
    {
        scanf("%d %d",&u,&v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    ans = dfs(1,-1);
    ans = 0;
    for(i = 1 ;i <= n;  i++)	ans += arr[i];
    dfs2(1,0);
    printf("%lld\n",ans);
    return 0;
}