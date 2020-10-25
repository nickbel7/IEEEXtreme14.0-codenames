#include <iostream>
#include <cstdio>
#include <math.h>
#include <set>

using namespace std;

bool a[1000000000] = {0};

unsigned long long int circularRot(unsigned long long int n, unsigned long long int T) {
    if (n & (1 << T)) {
      unsigned long long int num = (n << 1) + 1;
      num &= (~(1 << (T+1)));
      return num;
    }
    else return n << 1;
}

int main() {
    unsigned long long int N, T, num = 1, po;
    scanf("%lld %lld", &N, &T);

    /*unsigned long long int res = 1;
    scanf("%lld", &a);
    for (long int i = 0; i < N-1; ++i) {
        scanf("%lld", &pow);
        for (unsigned long long int j = a; j < pow; ++j)
            res *= 2;
        num += res;
        a = pow;
    }*/

    unsigned long long int res = 0;
    for (unsigned long long int i = 0; i < N; ++i) {
        scanf("%lld", &po);
        res += pow(2,po);
    }
    num = res;

    unsigned long long int counter = 0;
    a[num] = 1;
    for (unsigned long long int i = 0; i < T; ++i) {
        unsigned long long int New = circularRot(num, T-1);
        //cout << num << " " << New << endl;
        num = New;
        if (!a[New]) {
            a[New] = 1;
            counter++;
        }
        else break;
    }
    /*set<unsigned long long int> lights;
    set<unsigned long long int>::iterator it;

    lights.insert(num);

    for (unsigned long long int i = 0; i < T; ++i) {
        unsigned long long int New = circularRot(num, T-1);
        //cout << num << " " << New << endl;
        num = New;
        it = lights.find(New);
        if (it == lights.end()) {
            counter++;
            //cout << counter << ": " << New << endl;
        }
        else break;
    }*/
    printf("%llu\n", counter);
    return 0;
}
