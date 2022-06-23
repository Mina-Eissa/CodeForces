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
// link https://codeforces.com/problemset/problem/455/A
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

const int N = 1e5 + 2;
int freq[N];
int main() {
	fast();
	int n;
	cin >> n;
	int it, maxi = 0;
	for (int i = 0; i < n; i++)
		cin >> it, freq[it]++, maxi = max(it, maxi);

	long long* Dp = new long long[maxi + 2];
	memset(Dp, 0, sizeof Dp);
	for (long long i = 1; i <= maxi; i++) {
		Dp[i] = freq[i] * i * 1LL;
		if (i >= 2)
			Dp[i] = max(Dp[i - 1], Dp[i] + Dp[i - 2]);
	}
	cout << Dp[maxi];
	return 0;
}