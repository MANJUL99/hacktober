    #include<bits/stdc++.h>
    using namespace std;
    /*int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
            int r,c,k,co=0;
            cin>>r>>c>>k;
            for(int i=c;i<=8;i++)
            {
                if(pow((i-c),2)<=k)
                {
                    co++;
                    k--;
                    if(k==0)
                    break;
                }

            }
            if(k==0)
            {
                cout<<co<<endl;
                continue;
            }
            for(int i=c;i>0;i--)
            {
                if(pow((i-c),2)<=k)
                {
                    co++;
                    k--;
                    if(k==0)
                    break;
                }

            }
            if(k==0)
            {
                cout<<co<<endl;
                continue;
            }
            for(int i=r;i>0;i--)
            {
                if(pow((i-r),2)<=k)
                {
                    co++;
                    k--;
                    if(k==0)
                    break;
                }

            }
            if(k==0)
            {
                cout<<co<<endl;
                continue;
            }
            for(int i=r;i<=8;i++)
            {
                if(pow((i-r),2)<=k)
                {
                    co++;
                    k--;
                    if(k==0)
                    break;
                }

            }
            if(k==0)
            {
                cout<<co<<endl;
                continue;
            }
            for(int i=r,j=c;i<=8&&j<=8;i++,j++)
            {
                if((pow((i-r),2)+pow((j-c),2))<=k)
                {
                    co++;
                    k--;
                    if(k==0)
                    break;
                }

            }
            if(k==0)
            {
                cout<<co<<endl;
                continue;
            }
            for(int i=r,j=c;i>0&&j>0;i--,j--)
            {
                if((pow((i-r),2)+pow((j-c),2))<=k)
                {
                    co++;
                    k--;
                    if(k==0)
                    break;
                }

            }
            if(k==0)
            {
                cout<<co<<endl;
                continue;
            }
            for(int i=r,j=c;i>0&&j<=8;i--,j++)
            {
                if((pow((i-r),2)+pow((j-c),2))<=k)
                {
                    co++;
                    k--;
                    if(k==0)
                    break;
                }

            }
            if(k==0)
            {
                cout<<co<<endl;
                continue;
            }
            for(int i=r,j=c;i<=8&&j>0;i++,j--)
            {
                if((pow((i-r),2)+pow((j-c),2))<=k)
                {
                    co++;
                    k--;
                    if(k==0)
                    break;
                }

            }
            if(k==0)
            {
                cout<<co<<endl;
                continue;
            }

        }
        return 0;
    }
    */
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
            int r,c,k;
            cin>>r>>c>>k;
            int x=0;
            for(int i=r-k;i<=r+k;i++)
            {
                for(int j=c-k;j<=c+k;j++)
                {
                    if(i>0&&i<=8&&j>0&&j<=8)
                    x++;
                }
            }
            cout<<x<<endl;
        }
    }