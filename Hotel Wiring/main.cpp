#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases, M, N, K, input;
    long int counter;
    vector<int> rightRooms;

    cin >> testcases;
    for(int i=0; i < testcases; ++i){
        cin >> M >> N >> K;
        for(int j=0; j<M; ++j){
            cin >> input;
            rightRooms.push_back(input);
        }
        counter = 0;
        sort(rightRooms.begin(), rightRooms.end());
        for(int j=0; j<K; ++j){
            counter += (N - rightRooms[j]);
        }
        for(int j = K; j < M; ++j){
            counter += rightRooms[j];
        }
        cout << counter << endl;
        rightRooms.clear();
    }

    return 0;
}
