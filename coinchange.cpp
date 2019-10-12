#include<bits/stdc++.h>
using namespace std;
int coinchange(int a[],int m,int n)
{
    int table[n+1];
    memset(table,0,sizeof(table));
    table[0]=1;
    for(int i=0;i<m;i++)
    {
        for(int j=a[i];j<=n;j++)
        {
            table[j]+=table[j-a[i]];
        }

    }
    for(int i=0;i<n+1;i++)
    cout<<table[i]<<endl;
    return table[n];
    
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n=20, m=3;
        int a[3]={3,5,10};
        cout<<coinchange(a,3,20);


    }
}