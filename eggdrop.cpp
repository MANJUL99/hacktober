#include<bits/stdc++.h>
using namespace std;
void doEggDropping(int n,int k)
{
     int d[n+1][k+1];
    for(int i=0;i<n+1;i++)
    d[i][1]=i;
    for(int i=0;i<k+1;i++)
    d[1][i]=1;
    for(int i=2;i<n+1;i++)
    {
        for(int j=2;j<k+1;j++)
        { d[i][j]=INT_MAX;
        for(int x=1;x<i;x++)
        {
            int t=max(d[i-x][j],d[x-1][j-1])+1;
            if(t<d[i][j])
            d[i][j]=t;
        }
        }
    }
    // for( int a[]:d[n][k])
    // cout<<to_string(a)<<endl;
    cout<<d[n][k];

}
int main()
{
    int n,k;
    cin>>n,k;
    doEggDropping(n,k);
}