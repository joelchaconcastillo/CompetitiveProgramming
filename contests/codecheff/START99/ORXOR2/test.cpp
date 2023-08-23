#include<bits/stdc++.h>
using namespace std;

#define fo(i,n) for( i=0;i<n;i++)
#define foA(i,a,b) for(i=a;i<=b;i++)
#define foD(i,a,b) for( i=a;i>=b;i--)
#define int long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define el cout<<"\n"
#define max3(a,b,c) max(max((a),(b)),(c))
#define max4(a,b,c,d) max(max((a),(b)),max((c),(d)))
#define min3(a,b,c) min(min((a),(b)),(c))
#define min4(a,b,c,d) min(min((a),(b)),min((c),(d)))
/////////////////////
int dx[] = {0, 0, -1, 1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};

//////////////////for vectors
# define maxv(a) (*max_element(a.begin(),a.end()))
# define minv(a) (*min_element(a.begin(),a.end()))
# define sumvi(a) (accumulate(a.begin(),a.end(),0LL))
# define sumvd(a) (accumulate(a.begin(),a.end(),double(0)))

# define printv(v) {auto i = v;for(auto j : i) cout<< j << ' ';cout << "\n";}
# define printvv(v) {auto i = v;for(auto j : i) {for(auto k : j) cout<< k << ' ';cout << "\n";}}
# define prints(s) {auto i = s;for(auto j : i) cout<< j << ' ';cout << "\n";}
# define printm(m) {auto i = m;for(auto j : i) cout<< j.first << ':' << j.second << ' ';cout << "\n";}
/////////////////////////
typedef pair<int, int>  pii;
typedef vector<int>   vi;
typedef vector<pii>   vpii;
typedef vector<vi>    vvi;
/////////////////////////
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
  uniform_int_distribution<int> uid(0, lim - 1);
  return uid(rang);
}
/////////////////////
const int inf = 1e9;
const int INF = 1e18;
const int mod = 1000000007;
// const int mod = 998244353;
const int N = 3e5 + 5, M = N;
////////////////

int parent[N];
int sizeo[N];
int tempparent[N];
int temppsizeo[N];

int findop(int v) {
  if (v == parent[v])
    return v;
  return parent[v] = findop(parent[v]);
}
void setunionop(int a , int b) {
  a = findop(a);
  b = findop(b);
  if (a == b)
    return;
  else {
    if (sizeo[a] < sizeo[b])
      swap(a, b);
    parent[b] = a;
    sizeo[a] += sizeo[b];
  }
}
void initialize(int n) {
  for (int i = 1; i < n + 1 ; i++) {
    sizeo[i] = 1;
    parent[i] = i;
  }
}
void solve() {
  int i, j, n, m;
  cin >> n;
  vector<int> arr(n + 1);

  fo(i, n) cin >> arr[i + 1];

  sort(arr.begin() , arr.end());

  if (arr[1] == arr[n]) {
    cout << 0 << "\n";
    return;
  }
  else if (n == 2) {
    cout << (arr[1] ^ arr[2]) << "\n";
    return;
  }


  // printv(arr);
  int highestbit = 0;
  for (int j = 30; j >= 0  ; j--) {
    int count = 0 ;
    for (int i = 0 ; i < n ; i++) {
      if ( (1ll << j) & arr[i + 1]) {
        count++;
      }
    }
    if (count > 0 && count < n) {
      highestbit = j;
      break;
    }
  }


  vector<int> whichset(n + 1);
  initialize(n);

  for (int i = 0 ; i < n ; i++) {
    if ( (1ll << highestbit) & arr[i + 1])
      whichset[i + 1] = 2;
    else whichset[i + 1] = 1;
  }

  for (int j = highestbit - 1 ; j >= 0 ; j--) {
    int activeintwo = 0;
    int activeinone = 0;
    for (int i = 0 ; i < n ; i++) {
      if ( (1ll << j) & arr[i + 1]) {
        if (whichset[i + 1] == 1) {
          activeinone =  1;
        }
        else activeintwo = 1;
      }
    }
    if (activeintwo == 0 && activeinone == 0) {
      continue;
    }
    else if ( activeintwo == 1 && activeinone == 0) {
      continue;
    }
    else if (activeintwo == 0 && activeinone == 1) {
      vector<int> members;
      for (int i = 0 ; i < n ; i++) {
        if ( (1ll << j) & arr[i + 1]) {
          members.pb(i + 1);
        }
      }
      for (int i = 1 ; i < members.size() ; i++) {
        setunionop( members[i - 1] , members[i]);
      }
    }
    else {
      vector<int> members;
      for (int i = 0 ; i < n ; i++) {
        if ( (1ll << j) & arr[i + 1]) {
          if ( whichset[i + 1] == 1)
            members.pb(i + 1);

        }
      }
      for (int i = 1 ; i <= n ; i++) {
        int a = findop(i);
        tempparent[i] = a;
        temppsizeo[i] = sizeo[a];
      }
      for (int i = 1 ; i < members.size() ; i++) {
        setunionop( members[i - 1] , members[i]);
      }
      int countinsetone = 0;
      fo(i, n) {
        if (whichset[i + 1] == 1) countinsetone++;
      }
      int sizeofmembers = sizeo[findop(members[0])];
      // deb2(sizeofmembers , countinsetone);
      if (countinsetone == sizeofmembers) {
        for (int i = 1 ; i <= n ; i++) {
          parent[i] = tempparent[i];
          sizeo[i] = temppsizeo[i];
        }
      }
      else {
        fo(i, n) {
          if ( findop(i + 1) == findop( members[0])) {
            whichset[i + 1] = 2;
          }
        }
      }
      // printv(members);

    }
    // printv(whichset);
    // fo(i, n + 1) cout << findop(i) << " ";
    // cout << "\n";
  }

  int or1 = 0 ;
  int or2 = 0 ;

  int ans = 0;

  fo(i, n) {
    if (whichset[i + 1] == 1) {
      or1 = or1 | arr[i + 1];
    }
    else
      or2 = or2 | arr[i + 1];
  }

  ans = or1 ^ or2;
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
