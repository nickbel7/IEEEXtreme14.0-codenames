#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int dp(vector<char> a, int start, int end, int size, vector<vector<int>> v){
    if (v[start][end] != -1) return v[start][end];
    int i = 0;
    while (start+i <= end-i && start+i < size && end-i>-1 && a[start+i] == a[end-i]) ++i;
    if (start+i > end-i)
        v[start][end] = end - start + 1;
    else
        v[start][end] = max(dp(a, start+1, end, size, v), (dp(a, start, end-1, size, v)));
    return v[start][end];
}

int main() {
    int T;
    scanf("%d", &T);
    char c = getchar();
    for (int k = 0; k < T; ++k) {
        int ans = -1;
        vector<char> a;
        c = getchar();
        while (c!= '\n') {
            a.push_back(c);
            c = getchar();
        }
        int size = a.size();

        vector<vector<int>> v;

        for(int i = 0; i < size; ++i) {
            vector<int> v1;
            for(int j = 0; j < size; ++j) {
                if(i == j) v1.push_back(1);
                else if(i < j) v1.push_back(-1);
                else v1.push_back(0);
            }
            v.push_back(v1);
        }

        for (int i = 0; i < size-1; ++i){
            ans = max(dp(a, 0, i, size, v) + dp(a, 1+i, size-1, size, v), ans);
            //cout << "i: " << i << " " << ans << endl;
        }
        printf("%d\n", ans);
    }
    return 0;
}
