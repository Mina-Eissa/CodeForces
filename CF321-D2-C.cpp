/*
* created by Mina Eissa
* in 22-5-2022
 ####  ####  ####
 ## ##  ##  ## ##
 ##  ## ## ##  ##
 ##   ######   ##
 ##     ## ######
 ###   ####   ###
*/
// link https://codeforces.com/problemset/problem/580/C
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define MOD 1000000007
#define pi acos(-1)
using namespace std;
long long Mod(long long num, long long mod) { return ((num % mod) + mod) % mod; }
long long Ceil(long long num, long long div) { return (num + div - 1) / div; }
long long Gcd(long long a, long long b) { if (a == 0)return b; return Gcd(b % a, a); }
long long Lcm(long long a, long long b) { return a / Gcd(a, b) * b; }

void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}
vector<int>* adj;
int m, ctrRest = 0;
bool* cats, * vis;
void dfs(int node, int ctr) {
	vis[node] = 1;
	if (ctr > m)
		return;
	for (auto it : adj[node])
		if (!vis[it])
		{
			if (!cats[it])
				dfs(it, 0);
			else
				dfs(it, ctr + 1);
		}
	ctrRest += adj[node].size() <= 1 && node != 1;
}
int main() {
	fast();
	int n;
	cin >> n >> m;
	adj = new vector<int>[n + 1];
	cats = new bool[n + 1];
	vis = new bool[n + 1];
	for (int i = 1; i <= n; i++)
		vis[i] = 0;
	for (int i = 1; i <= n; i++)
		cin >> cats[i];
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1, cats[1]);
	cout << ctrRest;
	return 0;
}