#include "validator.h"

void run() {
    bool onlya = Arg("onlya");

    int pa = Int(500, 2000); Space();
    int ka = Int(10, 50); Space();
    int pb = Int(500, 2000); Space();
    int kb = Int(10, 50); Space();
    int n = Int(1, 1000); Endl();
    Eof();

    int opt = pa * n;
    pair<int, int> sol;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            int cost = i * pa + j * pb;
            if (i * ka + j * kb >= n && cost < opt) {
                opt = cost;
                sol = make_pair(i, j);
            }
        }
    }
    if (onlya) assert(sol.second == 0);
}
