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
 
int cal(multiset<int>&l , multiset<int>&r ,int lSum , int rSum)
{ 
    auto it = (--l.end());
 
    return sz(l) * (*it) - lSum - sz(r) * (*it) + rSum;
}
 
 
void solve()
{
    
      int n , k;
      cin >> n >> k;
 
      vi arr(n);
 
      for(int i = 0 ;i < n; i++)
        cin >> arr[i];
 
      multiset<int>l,r;
      int lSum = 0 , rSum = 0;
 
      for(int i = 0; i < k; i++)
      {
            if(l.size() < (k + 1)/2)
            {
                l.insert(arr[i]);
                lSum += arr[i];
            }
            else
            {
                auto it = (--l.end());
                if(*it <= arr[i])
                {
                    r.insert(arr[i]);
                    rSum += arr[i];
                }
                else
                {   
                    int put = *it;
                    l.erase(it);
                    l.insert(arr[i]);
                    lSum += (arr[i] - put);
                    r.insert(put);
                    rSum += put;
                }
            }
      }
 
      cout << cal(l , r , lSum , rSum) << " ";
 
 
      for(int i = k;i < n; i++)
      {
             int remove = arr[i - k];
 
             if(l.find(remove) != l.end())
             {    
                  l.erase(l.find(remove));
                  lSum -= remove;
 
                  if(sz(r))
                  {
 
                      auto it = r.begin();
                      rSum -= (*it);
                      lSum += (*it);
                      l.insert(*it);
                      r.erase(it);
                  }
             }
             else 
             {
                  r.erase(r.find(remove));
                  rSum -= remove;
 
             }
 
 
           
           if(sz(l))
           {
              auto it = (--l.end());
 
                if(*it <= arr[i])
                {
                    r.insert(arr[i]);
                    rSum += arr[i];
                }
                else
                {   
                    int put = *it;
                    l.erase(it);
                    l.insert(arr[i]);
                    lSum += (arr[i] - put);
                    r.insert(put);
                    rSum += put;   
                }
 
           }
           else
           {
              l.insert(arr[i]);
              lSum += arr[i];
           }
 
 
            cout << cal(l , r , lSum , rSum) << " ";
 
      }
   
 
 
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
 


