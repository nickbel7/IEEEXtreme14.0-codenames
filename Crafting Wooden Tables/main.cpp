#include <iostream>
#include <stack>

using namespace std;

int main() {
    long long int C, N, P, W, coins, freespaces=0, counter=0, coin_needed;
    scanf("%lld %lld %lld %lld", &C, &N, &P, &W);
    cin >> C >> N >> P >> W;
    coins = W;

    long long int remaining = W/P;
    long long int next = W - remaining*P;


    coins = W;
    if (next == 0) {
        freespaces = N - remaining;
        next = P;
        remaining--;
    }
    else
        freespaces = N - remaining - 1;

    while(true){
        if (next == 0 && remaining == 0) break;
        coin_needed = C;
        if(coins < C)
            break;
        coins -= C;
        while(next - coin_needed < 0){
            coin_needed -= next;
            remaining--;
            next = P;
            freespaces++;
        }
        next -= coin_needed;
        if(next == 0){
            freespaces++;
            remaining--;
            next = P;

        }
        if(freespaces <=0)
            break;
        counter++;
        freespaces--;
    }

    cout << counter << endl;
    return 0;
}
