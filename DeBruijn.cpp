//nice

#include<bits/stdc++.h>
using namespace std;

unordered_set<string> hash;
vector<int> edge;

void euler_dfs(string s,int k,string a)
{
  for(int i=0;i<k;i++)
  {
     string temp=s+a[i];
     if(hash.find(temp) != hash.end())
     {
       hash.insert(temp);
       euler_dfs(temp.substr(1),k,a);
       egde.push_back(i);
    }
  }
}

string debruijn(int n,int k,string a)
{
  string s=string(n-1,a[0]);
  euler_dfs(s,k,a);
  string res;
  
  int p=pow(k,n);
  for(int i=0;i<p;i++)
  {
    res+=a[edge[i]];
  } 
  res+=s;
  return res;
}

int main()
{
  int n,k;
  cin>>n>>k;
  set<char> A;
  A.insert(0);
  A.insert(1);
  cout<<debuijn(n,k,a)<<"\n";
  return 0;
}
