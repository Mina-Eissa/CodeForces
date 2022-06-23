/*
* created by Mina Eissa
* in 23-5-2022
 ####  ####  ####
 ## ##  ##  ## ##
 ##  ## ## ##  ##
 ##   ######   ##
 ##     ## ######
 ###   ####   ###
*/
// link https://codeforces.com/problemset/problem/1338/A
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

int main() {
	fast();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int maxi = INT_MIN, diff = 0;
		int* num = new int[n];
		for (int i = 0; i < n; i++)
			cin >> num[i], maxi = max(maxi, num[i]), diff = max(diff, maxi - num[i]);
		int ans = 0;
		while ((1LL << ans) - 1 < diff)
			ans++;
		cout << ans << "\n";
	}
	return 0;
}