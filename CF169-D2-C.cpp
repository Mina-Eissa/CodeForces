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

// link https://codeforces.com/problemset/problem/276/C
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
	int n, q;
	cin >> n >> q;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());

	vector<long long>fre(n + 2, 0);
	while (q--) {
		int l, r;
		cin >> l >> r;
		fre[l]++, fre[r + 1]--;
	}

	for (int i = 1; i <= n; i++)
		fre[i] += fre[i - 1];
	sort(fre.begin(), fre.begin() + n + 1);
	long long sum = 0;
	for (int i = 1; i <= n; i++)
		sum += fre[i] * v[i];
	cout << sum;
	return 0;
}
