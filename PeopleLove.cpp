//euler ee...minimise the maximum sadness sadness=degree ante...greedy ga deg compare chesesi....update accordinlgy.
//same ide logic failed for maximum nodes with sadness=0

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;

int n,m,a,b,res;
int cnt[N];
int edge[N][2];

int32_t main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    int t;
    cin>>t;
    cout<<"BOTH_AUBTASKS\n";
    while(t--)
    {
        res=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cnt[i]=0;
        }
        for(int i=1;i<=m;i++)
        {
            cin>>a>>b;
            
            if(cnt[a]>cnt[b])
            {
                cnt[a]--;
                cnt[b]++;
                edge[i][0]=b;
                edge[i][1]=a;
            }
            else
            {
                cnt[a]++;
                cnt[b]--;
                edge[i][0]=a;
                edge[i][1]=b;
            }
        }
        for(int i=1;i<=n;i++)
        {
            res=max(res,cnt[i]);
        }
        cout<<res<<"\n";
        for(int i=1;i<=m;i++)
        {
            cout<<edge[i][0]<<" "<<edge[i][1]<<"\n";
        }
    }
    return 0;
}
