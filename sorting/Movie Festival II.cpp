#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;
 
 
#define LETS_GET_SCHWIFTY ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
#define ff              first
#define ss              second
//#define int             long long
#define ll              long long
#define pb              push_back
#define pii             pair<int,int>
#define vi              vector<int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)      __builtin_ctzll(x)
#define mod             1000000007
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
 
const int N = 5002;
 
 
/*bool cmp(pii p1 ,pii p2)
{
      if(p1.ff != p2.ff)
        return p1.ff < p2.ff;
 
      return p1.ss > p2.ss;
}*/
 
void solve()
{
    
    /*int n , k;
    cin >> n >> k;
 
    multiset<int>s;
 
    for(int i = 0;i < k; i++)
      s.insert(0);
 
    vpii arr(n);
 
    for(int i = 0;i < n; i++)
      cin >> arr[i].ss >> arr[i].ff;
 
    sort(all(arr));
 
    int ans = 0;
 
    for(auto x : arr)
    {
        if(*s.begin() <= x.ss)
        {
            auto it = s.upper_bound(x.ss);
            it--;
 
            s.erase(it);
            s.insert(x.ff);
            ans++;
        }
    }
 
    db(ans)*/
 
  int n, k; cin >> n >> k;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) // read start time, end time
    cin >> v[i].second >> v[i].first;
  sort(begin(v), end(v)); // sort by end time
 
  int ans = 0;
  multiset<int> end_times; // times when members will finish watching movies
  for (int i = 0; i < k; ++i)
    end_times.insert(0);
 
  for (int i = 0; i < n; i++) {
    auto it = end_times.upper_bound(v[i].second);
    if (it == begin(end_times)) continue;
    // assign movie to be watched by member in multiset who finishes at time *prev(it)
    end_times.erase(--it);
    // member now finishes watching at time v[i].first
    end_times.insert(v[i].first);
    ++ ans;
  }
 
  db(ans)
 
 
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
 