//DISTANCE VECTOR ROUTING - bellman ford algorithm
#include<iostream>
#include<vector>
#include<utility>
#include<climits>
using namespace std;
typedef long long LL;
typedef pair<LL,int> PI;
class graph
{
  int nodes,edges;
  vector<PI> *a;
  vector<LL> *d;
  vector<int> *par,*rout;
  void printpath(int,int);
public:
  graph(){}
  graph(int nodes,int edges)
  {
    this->nodes=nodes;
    this->edges=edges;
    a=new vector<PI>[nodes+1];
    d=new vector<LL>[nodes+1];
    par=new vector<int>[nodes+1];
    rout=new vector<int>[nodes+1];
    for(int i=0 ; i<=nodes ; i++)
    {
      d[i].assign(nodes+1,LLONG_MAX);
      par[i].assign(nodes+1,-1);
      rout[i].assign(nodes+1,-1);
    }
  }
  void addedges()
  {
    int x,y,i; LL w;
    for(i=1;i<=edges;i++)
    {
      cin>>x>>y>>w;
      a[x].push_back({w,y});
      //a[y].push_back({w,x});
    }
  }
  void bellmanford(int);
  void display(int);
};
void graph::bellmanford(int s)
{
  d[s][s]=0;
  int i,j,k,u,v,flag=0;
  LL w;
  for(i=1;i<=nodes-1 ; i++)
  {
    for(j=0;j<nodes;j++)//for all edges
      for(k=0;k<a[j].size();k++)
      {
        u=j;  v=a[j][k].second;
        w=a[j][k].first;
        if(d[s][u]!=LLONG_MAX && d[s][u] + w < d[s][v])
        {
          d[s][v]=d[s][u]+w;
          par[s][v]=u;
        }
      }
  }
   display(s);
}
void graph::printpath(int i,int s)
{
    vector<int> z;
    int x=i;
    while(i!=-1)
    {
      z.push_back(i);
      i=par[s][i];
    }
    for(i=z.size()-1;i>=0;i--)
    cout<<z[i]<<" ";
     if(z.size()>1)
      rout[s][x]=z[z.size()-2];
}
void graph::display(int s)
{
  cout<<"\n\nFOR VERTEX "<<s<<"\n";
  cout<<"vertex\tdistance\tpath\t\tNEXT HOP\n";
  for(int i=0;i<nodes;i++)
  {
   if(d[s][i]!=LLONG_MAX)
    {
     cout<<i<<"\t"<<d[s][i]<<"\t\t";
     printpath(i,s);
     cout<<"\t\t"<<rout[s][i];
    }
   else
    cout<<i<<"\t"<<"INF";
   cout<<"\n";
  }
}
int main()
{
  graph g;
  int n,m; cin>>n>>m;
  g=graph(n,m);
  g.addedges();
  for(int i=0 ; i<n ;i++)
    g.bellmanford(i);
  return 0;
}
/*
5 8
0 1 -1 0 2 4 1 2 3 1 3 2 1 4 2 3 2 5 3 1 1 4 3 -3
*/
