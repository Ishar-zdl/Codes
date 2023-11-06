#include <bits/stdc++.h>
#include "testlib.h"
const int max_N = 5000005;
int n, m, cnt, X[max_N], Y[max_N];
bool flag[max_N];
std::string S;
int main(int argc, char** argv) {
	registerLemonChecker(argc, argv);
	n = inf.readInt(), m = inf.readInt();
	for (int i = 0; i < m; i++) X[i] = inf.readInt(), Y[i] = inf.readInt();
	for (int i = 1; i <= n; i++) flag[i] = true;
	S = ouf.readToken();
	if (S != "YES") quit(_wa, "There is a solution but you didn't find it!");
	S = ouf.readToken(); if (S.size() != m) quit(_wa, "invalid output");
	for (int i = 0; i < m; i++) if (S[i] != '0' && S[i] != '1') quit(_wa, "invalid output");
	for (int i = 0; i < m; i++) {
		if (S[i] == '0') std::swap(X[i], Y[i]);
		if (flag[X[i]]) flag[Y[i]] = true, flag[X[i]] = false;
	}
	for (int i = 1; i <= n; i++) cnt += flag[i];
	if (cnt < (n ) / 2) quit(_wa, "Your answer is less than n / 2.");
	return quit(_ok, "correct!"), 0;
}

