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
// link https://codeforces.com/problemset/problem/550/A
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
	string s;
	cin >> s;
	string tmp = "";
	map<string, int>mp;
	mp["AB"] = (int)1e6;
	mp["BA"] = (int)1e6;
	bool ok = 0;
	for (int i = 0; i < (int)s.size() - 1 && !ok; i++) {
		tmp.clear();
		tmp += s[i];
		tmp += s[i + 1];
		if (tmp == "AB") {
			if (mp["BA"] == (int)1e6)
				mp[tmp] = min(i, mp[tmp]);
			else {
				ok = i - mp["BA"] >= 2;
				mp[tmp] = min(i, mp[tmp]);
			}
		}
		else if (tmp == "BA") {
			if (mp["AB"] == (int)1e6)
				mp[tmp] = min(i, mp[tmp]);
			else {
				ok = i - mp["AB"] >= 2;
				mp[tmp] = min(i, mp[tmp]);
			}
		}
	}
	cout << (ok ? "YES" : "NO");
	return 0;
}