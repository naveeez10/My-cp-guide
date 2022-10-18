#include"bits/stdc++.h"
using namespace std;
const int mod = 1e9 + 7;
#define ll long long
#define ld long double
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define MP make_pair
#define INF LLONG_MAX
#define vi vector<int>
#define vll vector<ll>
#define pl pair<ll,ll>
#define pi pair<int,int>
#define mint map<int,int>
#define llmint map<ll,ll>
#define nline cout << nl;
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define spree(x) fixed << setprecision(x)

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#define debug2(x,y) cerr << #x <<" "; _print(x); cerr << sp; cerr << #y <<" "; _print(y); cerr << endl;
#define debug3(x,y,z) cerr << #x <<" "; _print(x); cerr << sp;cerr << #y <<" "; _print(y); cerr << sp;cerr << #z <<" "; _print(z); cerr << nl;
#else
#define debug(x)
#define debug2(x,y)
#define debug3(x,y,z)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(deque <T> v);
template <class T> void _print(priority_queue <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.f); cerr << ","; _print(p.s); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(deque <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(priority_queue <T> v) {cerr << "[ "; while (!v.empty()) {_print(v.top()); v.pop(); cerr << " ";} cerr << "]";}
template <class T> void _print(priority_queue <T, vector<T>, greater<T>> v) {cerr << "[ "; while (!v.empty()) {_print(v.top()); v.pop(); cerr << " ";} cerr << "]";}

////////////////////////////////////////////////////////////////////
bool testcase = 0;
int casenumber = 1;
bool cases = 0;
const char sp = ' ';
const char nl = '\n';

/*
    Read the problem again!
    Read the constraints!
    If get mulitple WA's change your approach and rewrite the code!
    Read all the problems , there might be a easier one ahead!
    Read the constraints(again)!.
    Read the problem again!
*/
////////////////////////////////////////////////////////////////////

const int N = 1e5 + 5;
vector<int> parent(N);
vector<int> sizes(N);

void make(int v) {
      parent[v] = v;
      sizes[v] = 1;
}

int find(int v) {
      if (v == parent[v]) return v;
      return parent[v] = find(parent[v]);
}


void Union(int a, int b) {
      a = find(a);
      b = find(b);

      if (a == b) {
            return;
      }

      if (sizes[a] < sizes[b]) {
            swap(a, b);
      }

      parent[b] = a;
      sizes[a] += sizes[b];
}
void getans() {
      int n; cin >> n;
      for (int i = 1; i <= n; ++i) {
            make(i);
      }
      vector < pair<int, pair<int, int>>> edges;
      for (int i = 0; i < n; ++i) {
            int u, v, wt; cin >> u >> v >> wt;
            edges.push_back({wt, {u, v}});
      }
sort(edges.begin(), edges.end()); d:
      ll totcost = 0;

      for (auto edge : edges) {
            int wt = edge.f;
            int u = edge.s.f;
            int v = edge.s.s;
            if (find(u) == find(v)) continue;
            Union(u, v);
            totcost += wt;

            cout << u << ' ' << v << nl;
      }
      cout << totcost << nl;
}

int main() {

#ifndef ONLINE_JUDGE
      freopen("Error.txt", "w", stderr);
#endif

      ios_base::sync_with_stdio(false);
      cin.tie(NULL);

      ll T = 1;

      if (testcase) {
            cin >> T;
      }

      while (T--) {
            if (cases) {
                  cout << "Case #" << casenumber << ": ";
                  casenumber++;
            }
            getans();
      }
#ifndef ONLINE_JUDGE
      cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
#endif

      return 0;
}