#include <iostream>

using namespace std;

int main() {
    long long  n, soldiers=0;
    cin >> n;
    long long hideouts[n];
    long long  available[n] = {0};
    for (int i=0 ; i<n ; i++) {
        cin >> hideouts[i];
    }
    long long t, a, b, c, rides=0;
    cin >> t;
    for (long long i=0 ; i<t ; i++) {
        cin >> a >> b >> c;
        for (long long j=a ; j<=b ; j++) {
            available[j-1] = 1;
        }
        rides += c;
    }
    for (long long i=0 ; i<n ; i++) {
        soldiers += available[i]*hideouts[i];
    }
    cout << min(soldiers, rides) << endl;
}
