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
// link https://codeforces.com/problemset/problem/550/C
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
string s;
int dp[101][10002], ans = 0;
bool ok = 0;
int checkDiv(int i, int num) {
	if ((int)log10(num) + 1 <= 3) {
		ans = num % 8 == 0 && num != 0 ? num : ans;
	}
	else
		return ans % 8 == 0 && ans != 0;
	if (i >= s.size())
		return 0;
	int& ret = dp[i][num];
	if (~ret)
		return ret;
	ret = 0;
	return ret |= checkDiv(i + 1, (num * 10) + (s[i] - '0')) || checkDiv(i + 1, num);
}
int main() {
	fast();
	memset(dp, -1, sizeof dp);
	cin >> s;
	ok = count(s.begin(), s.end(), '0') > 0;
	checkDiv(0, 0);
	if (ans != 0 || ok)
		cout << "YES\n" << ans;
	else
		cout << "NO";
	return 0;
}