#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;
 
 
#define LETS_GET_SCHWIFTY ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
#define ff              first
#define ss              second
#define int             long long
#define ll              long long
#define pb              push_back
#define pii             pair<int,int>
#define vi              vector<int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)      __builtin_ctzll(x)
#define mod             998244353
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define vpii            vector<pair<int,int> >
#define all(x)          x.begin(),x.end()
#define matrixprint(arr,a,b,c,d) for(int i=a;i<=c;i++){for(int j=b;j<=d;j++){cout<<arr[i][j]<<" ";}cout<<"\n";}
#define show(arr,x,y)   for(int i=x;i<=y;i++){cout<<arr[i]<<" ";}cout<<"\n"
#define sz(x)           (int)x.size()
#define db(x)           cout<<x<<"\n";
 
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
 
//insert,find_by_order,order_of_key,lower_bound,upper_bound;
 
#define TRACE
#ifdef TRACE
#define deb(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#else
#define deb(...)
#endif
 
  
//////////////////////////////code//////////////////////////////
 
const int N = 200;
 
class BIT
{   
    public:
    
    int N;vector<int>bit;
    
    BIT(int n,int v)
    {   N=n;
        bit.assign(n,v);
    }
    
  void update(int idx,int val)
  {
      while(idx<N)
      {
          bit[idx]+=val;
          idx+= idx & (-idx);
      }
  }
  
   int sum(int idx)
   {  
       int ans=0;
       while(idx>0)
       {
           ans+=bit[idx];
           idx -= idx & (-idx);
       }
       return ans;
   }
   
   int rsum(int l,int r)
   {
       return sum(r)-sum(l-1);
   }
   
    void updateMax(int idx, int val)
  {
    while(idx < N)
    {
      bit[idx] = max(bit[idx], val);
      idx += idx & -idx;
    }
  }
   
    int prefMax(int idx)
  {
    int ans = -inf;
    while(idx > 0)
    {
      ans = max(ans, bit[idx]);
      idx -= idx & -idx;
    }
    return ans;
  }
 
       int prefMin(int idx)
  {
    int ans = inf;
    while(idx > 0)
    {
      ans = min(ans, bit[idx]);
      idx -= idx & -idx;
    }
    return ans;
  }
 
  
 
    
};
 
 
map<int,int>comp;
 
void solve()
{
 
      int n;
      cin >> n;
 
 
      vi adj[n + 1];
 
      map<int,vi>lines;
 
      for(int i = 1;i <= n ; i++)
      {
            int u , v;
            cin >> u >> v;
            lines[u].pb(-i);
            lines[v].pb(i);
            adj[i].pb(u),adj[i].pb(v);
      }
 
 
      int cnt = 1;
      int ans1[n + 1] , ans2[n + 1];
 
      for(auto x : lines)
      {
            if(!comp[x.ff])
              comp[x.ff] = cnt++;
      }
 
      BIT tr1(cnt + 5,0) , tr2(cnt + 5, 0);
 
 
      for(auto x : lines)
      {     
            vi endHere;
            for(auto y : x.ss)
            {
                 if(y > 0)
                 {
                      tr2.update(comp[adj[y][0]] , 1);
                      endHere.pb(comp[adj[y][0]]);
                      tr1.update(comp[adj[y][0]] , -1);
                 }
            }
 
            sort(all(endHere));
 
            for(auto y : x.ss)
            {
                if(y > 0)
                 {
                      ans1[y] = tr2.rsum(comp[adj[y][0]] , comp[adj[y][1]]) - 1;
                      ans2[y] = tr1.sum(comp[adj[y][0]]);
                      auto it = upper_bound(all(endHere) , comp[adj[y][0]]);
                      ans2[y] += it - endHere.begin() - 1;
 
                 }
            }
 
            for(auto y : x.ss)
            {
                 if(y < 0)
                 {
                      tr1.update(comp[adj[-y][0]] , 1);
                 }
            }
 
 
      }
 
      for(int i = 1;i <= n ;i++)
        cout << ans1[i] << " ";
 
      cout << "\n";
      
       for(int i = 1;i <= n ;i++)
        cout << ans2[i] << " ";
 
 
     
 
}
 
int32_t main()
{   
 
    LETS_GET_SCHWIFTY;
 
     #ifndef ONLINE_JUDGE
     freopen("INP.txt", "r", stdin);
     freopen("out.txt", "w", stdout);
     #endif  
 
 
    int t = 1;
   //cin >> t;
 
    while (t--)
        solve();
 
}
 
// check out for following mistakes-
// if using pb operation on vector and then trying to access index..check if sizeof that vec could remain 0 only
// is using prime sieve make sure it fits
// when using factorial template or combinatorics make sure that you edit fillfac fun values and array values
 