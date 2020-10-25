#include <iostream>

using namespace std;

unsigned long long w,h,a,b,m,c,res=0;

int main() {
    cin >> w >> h >> a >> b >> m >> c;

    unsigned long long int maxRight = w / a + (w%a==0 ? 0 : 1);
    unsigned long long int maxBottom = h / b + (h%b==0 ? 0 : 1);
    unsigned long long int cutsRight = (w % a != 0 ? h : 0);
    // cout << cutsRight << endl;
    unsigned long long int cutsBottom = (h % b != 0 ? w : 0);
    // cout << cutsBottom << endl;
    unsigned long long int totalCuts = cutsBottom + cutsRight ;

    unsigned long long int tilesSum = maxBottom*maxRight;
    unsigned long long int res = (tilesSum/10+(tilesSum%10 == 0 ? 0 : 1))*m;
    res += totalCuts*c;
    cout << res << endl;
    return 0;
}
