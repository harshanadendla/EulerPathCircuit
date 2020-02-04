//sense
// source https://www.geeksforgeeks.org/minimum-edges-required-to-add-to-make-euler-circuit/
// sarigga alochinchu...graph theory is indeed maths..in which u r a thop

#include<bits/stdc++.h>
using namespace std;

vector<int> graph[N];
vector<int> deg(N);
vector<bool> vis(N);
vector<int> oddV;
vector<int> evnV;
vector<int> oddVinSubset(N);
int subset=1;

void dfs(int u)
{
  vis[u]=true;
  if(deg[u]%2) oddVinSubset[subset]++;
  for(int v : graph[u])
  {
    if(!vis[v]) dfs(v);
  }
}

int minEdges()
{
  int ans=0;
  
  for(int i=1;i<=n;i++)
  {
    if(!vis[i])
    {
      dfs(i);
      
      if(oddVinSubset[subset]==0)
      {
        evnS.push_back(subset);
      }
      else
      {
        oddS.push_back(subset);
      }
      
      subset++;
    }
  }
  
  if(oddS.size()==0 && evnS.size()==1) return 0;
  if(oddS.size()==0) return evnS.size();
  if(evnS.size()!=0) ans+=evnS.size();
  for(int i : oddS) ans+=oddVinSubset[i]/2;
  
  return ans;
}

int main()
{
  int n,m,a,b;
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
    deg[a]++;
    deg[b]++;
  }
  cout<<minEdges()<<"\n";
  return 0;
}
