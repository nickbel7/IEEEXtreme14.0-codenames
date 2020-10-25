#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    char c;
    string s;
    vector<string> coupons;
    for(int i=0; i<N; ++i){
        for(int j=0; j<15; ++j){
            c = getchar();
            s.push_back(c);
        }
        coupons.push_back(s);
        s.clear();
    }

    int counter, ans=0;
    for(int i=0; i<N-1; ++i){
        for(int j=i+1; j < N; ++j){
            counter = 0;
            for(int k=0; k < 15; ++k){
                if(coupons[i][k] != coupons[j][k]){
                    counter++;
                }
            }
            if(counter <= 1)
                ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
