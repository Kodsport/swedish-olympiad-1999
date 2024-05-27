#include "validate.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;

#define repe(i, container) for (auto& i : container)

int main(int argc, char **argv) {
	init_io(argc, argv);

	string in;
	judge_in >> in;


	auto check = [&](istream& sol, feedback_function feedback){
		string ans;
		if(!(sol >> ans)) feedback("Expected more output");
		vi cnt(256);
		
		for (auto c : ans)
		{
			if (!(c>='A'&&c<='Z')) feedback("Solution has non-allowed character");
			if (cnt[c]>0) feedback("Used same character twice");
			cnt[c]++;
			if (find(in.begin(),in.end(),c)==in.end()) feedback("Used character not in input");
		}

		bool increasing = true;
		for (int i = 0; i + 1 < ans.size(); i++)
		{
			increasing &= ans[i] < ans[i+1];
		}
		if (!increasing) return 0;

		string modifiedin;
		for (auto c : in)
		{
			if (find(ans.begin(), ans.end(), c)!=ans.end())
			{
				modifiedin.push_back(c);
			}
		}
		if (modifiedin!=ans) feedback("Changed relative order of input");

		string trailing;
		if(sol >> trailing) feedback("Trailing output");
		return (int)ans.size();
	};

	int judge_sol = check(judge_ans, judge_error);
	int author_sol = check(author_out, wrong_answer);

	cout << judge_sol << " " << author_sol << "\n";
	if(author_sol > judge_sol)
		judge_error("NO! contestant found better solution than judge");

	if(author_sol < judge_sol)
		wrong_answer("Contestant found suboptimal solution");

	accept();
}
