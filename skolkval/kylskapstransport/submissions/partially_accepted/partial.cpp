#include <bits/stdc++.h>

using namespace std;

int main() {
  int pa, ka, pb, kb, n;
  cin >> pa >> ka >> pb >> kb >> n;

  int opt = pa * n;
  pair<int, int> sol;
  for (int i = 0; i <= 100; i++) {
    int cost = i * pa;
    if (i * ka >= n && cost < opt) {
      opt = cost;
      sol = make_pair(i, 0);
    }
  }
  cout << sol.first << " " << sol.second << " " << opt << endl;
}
