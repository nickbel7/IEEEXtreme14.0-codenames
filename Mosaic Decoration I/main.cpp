#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, CB, CP;
    int sumB = 0, sumP = 0;
    cin >> N >> CB >> CP;
    for (int i = 0; i < N; ++i) {
        int B, P;
        cin >> B >> P;
        sumB += B;
        sumP += P;
    }
    int res = 0;
    res += (sumB/10+(sumB%10 == 0 ? 0 : 1))*CB;
    res += (sumP/10+(sumP%10 == 0 ? 0 : 1))*CP;
    cout << res << endl;

    return 0;
}
