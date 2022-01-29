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
vector<vector<int>> adj(N);
vi par(N);
void dfs(int child, int p) {
	par[child] = p;
	for (int x : adj[child]) {
		debug2(x, child)
		if (x == p) {
			continue;
		}
		dfs(x, child);
	}
}
vector<int> path(int v) {
	vi pars;
	while (v != -1) {
		pars.push_back(v);
		v = par[v];
	}
	return pars;
}
void getans() {
	int n; cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1);
	int x, y; cin >> x >> y;
	vi path_x = path(x);
	vi path_y = path(y);
	reverse(all(path_x));
	reverse(all(path_y));
	debug(path_x) debug(path_y)
	int lca = -1;
	for (int i = 0; i < min(sz(path_y), sz(path_x)); ++i) {
		if (path_x[i] == path_y[i]) {
			lca = path_x[i];
		}
		else {
			cout << lca << nl;
			return;
		}
	}
	cout << lca << nl;
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