#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<math.h>
#include<climits>
#include<cstring>
#include<iomanip>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define deb(x) cout<<x<<"\n";
#define deB(x,y) cout<<x<<" "<<y<<"\n";
#define Deb(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n";
#define YES cout<<"YES\n";
#define Yes cout<<"Yes\n";
#define NO cout<<"NO\n";
#define No cout<<"No\n";
#define clt(x) 63-__builtin_clzll(x)
#define bct(x) __builtin_popcountll(x)
#define all(v) (v).begin(),(v).end()
#define pi pair<ll,ll>
#define vi vector<ll>
#define vpi vector<pair<ll,ll>>
#define maxq priority_queue<ll>
#define minq priority_queue<ll,vector<ll>, greater<ll>>
#define cont continue;
#define reto return 0;
#define sz(x) (ll)(x.size()) 
#define spmod 1116295198451
#define md 998244353 
#define mod 1000000007
#define N 200009
ll ans;
string s;
ll v[10][10];
ll n=7;
void f(ll i,ll j,ll cnt)
{
  if(i==n&&j==1&&cnt==n*n)
  {
    ans++;
    return;
  }
  if(i==n&&j==1)
    return;
  v[i][j]=1;
    if(i-1>0&&v[i-1][j]==0&&i+1<=n&&v[i+1][j]==0&&(j==1||v[i][j-1])&&(j==n||v[i][j+1]))
    {
      v[i][j]=0;
      return;
    }
    if(j-1>0&&v[i][j-1]==0&&j+1<=n&&v[i][j+1]==0&&(i==1||v[i-1][j])&&(i==n||v[i+1][j]))
    {
      v[i][j]=0;
      return;
    }
  if(s[cnt]=='?')
  {
    if(i-1>0&&v[i-1][j]==0)
      f(i-1,j,cnt+1);
    if(i+1<=n&&v[i+1][j]==0)
      f(i+1,j,cnt+1);
    if(j-1>0&&v[i][j-1]==0)
      f(i,j-1,cnt+1);
    if(j+1<=n&&v[i][j+1]==0)
      f(i,j+1,cnt+1);
  }
  else if(s[cnt]=='R'&&j+1<=n&&v[i][j+1]==0)
    f(i,j+1,cnt+1);
  else if(s[cnt]=='L'&&j-1>0&&v[i][j-1]==0)
    f(i,j-1,cnt+1);
  else if(s[cnt]=='U'&&i-1>0&&v[i-1][j]==0)
    f(i-1,j,cnt+1);
  else if(s[cnt]=='D'&&i+1<=n&&v[i+1][j]==0)
    f(i+1,j,cnt+1);
  v[i][j]=0;
}
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  cin>>s;
  s='!'+s;
  f(1,1,1);
  deb(ans)
}    