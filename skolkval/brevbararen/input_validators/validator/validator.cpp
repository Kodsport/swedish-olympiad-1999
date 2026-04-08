#include "validator.h"

void run() {
    set<char> seen;
    string s = Line();
    int n = s.size();
    assert(n >= 1 && n <= 26);

    for (char c : s) {
        assert(c >= 'A' && c <= 'Z');
        assert(!seen.count(c));
        seen.insert(c);
    }
}
