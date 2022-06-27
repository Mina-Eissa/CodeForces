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

// link https://codeforces.com/problemset/problem/1389/C
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
clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
int mini(string& s, string& tmp) {
	int pos = 0, ctr = 0;
	for (auto it : s) {
		if (it == tmp[pos])
			pos = (pos + 1) % 2;
		else
			ctr++;
	}
	return ctr + (tmp[0] != tmp[1] && (pos & 1));
}
int main() {
	fast();
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int ans = INT_MAX;
		for (char i = '0'; i <= '9'; i++) {
			for (char j = '0'; j <= '9'; j++) {
				string tmp = "";
				tmp.push_back(i), tmp.push_back(j);
				ans = min(ans, mini(s, tmp));
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
