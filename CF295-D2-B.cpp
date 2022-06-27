/*
* created by Mina Eissa
* 27-6-2022
 ####  ####  ####
 ## ##  ##  ## ##
 ##  ## ## ##  ##
 ##   ######   ##
 ##     ## ######
 ###   ####   ###
*/

// link https://codeforces.com/problemset/problem/520/B
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
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

int main() {
	fast();
	// BFS
	int n, m;
	cin >> n >> m;
	queue<pair<int, int>>q;
	map<pair<int, int>, int>vis;
	q.push({ n,0 });
	while (!q.empty()) {
		pair<int, int>p = q.front();
		q.pop();

		if (p.first == m)
			return cout << p.second, 0;

		if (!vis[{p.first, -1}] && p.first >= 1)
			q.push({ p.first - 1,p.second + 1 }), vis[{p.first, -1}] = 1;

		if (!vis[{p.first, 2}] && p.first <= m * 2)
			q.push({ p.first * 2,p.second + 1 }), vis[{p.first, 2}] = 1;
	}

	// greedy
	int n, m;
	cin >> n >> m;
	long long ctr = 0;
	while (n != m) {
		if (m > n) {
			if (m & 1)
				m += 1, m /= 2, ctr += 2;
			else
				m /= 2, ctr++;
		}
		else
			m++, ctr++;
	}
	cout << ctr;
	return 0;
}
