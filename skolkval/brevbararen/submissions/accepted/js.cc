#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int common[27][27];

string lcs(string a, string b){
    for(int i = 0; i<a.size(); i++)
        for(int j = 0; j<b.size(); j++)
            common[i][j] = max(i ? common[i-1][j] : 0, j ? common[i][j-1] : 0) + (a[i] == b[j]);
    int va = a.size()-1, vb = b.size()-1;
    string ans;
    while(va >= 0 && vb >= 0){
        if(a[va] == b[vb]){
            ans.push_back(a[va]);
            va--;
            vb--;
        } else {
            if(!va){
                vb--;
            } else if(!vb) {
                va--;
            } else {
                if(common[va-1][vb] > common[va][vb-1]){
                    va--;
                } else {
                    vb--;
                }
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string in;
    cin >> in;
    string in2 = in;
    sort(in2.begin(), in2.end());
    cout << lcs(in, in2) << endl;
}
