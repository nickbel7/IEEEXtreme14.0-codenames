#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, input, Q;
    cin >> N;
    vector<int> spell;
    vector<bool> tel;
    vector<bool> temp;
    vector<int> rocks;

    for(int i=0; i<N; ++i){
        tel.push_back(true);
        temp.push_back(false);
    }
    for(int i=0; i<N; ++i){
        cin >> input;
        spell.push_back(input-1);
    }

    int count=0;
    bool flag;
    while(true){
        for(int i=0; i<N; ++i){
            temp[i] = false;
        }
        for(int i=0; i<N; ++i){
            if(tel[i] == true)
                temp[spell[i]] = true;
        }
        flag = false;
        for(int i=0; i<N; ++i){
            if(temp[i] != tel[i] ){
                flag = true;
                break;
            }
        }
        if(!flag)
            break;
        for(int i=0; i<N; ++i){
            tel[i] = temp[i];
            if(tel[i])
                count++;
        }
        rocks.push_back(count);
        count = 0;
    }

    cin >> Q;
    bool could = false;
    int ans=0;
    for(int i=0; i < Q; ++i){
        could = false;
        cin >> input;
        for(int i=0; i<rocks.size(); ++i){
            if(input ==  rocks[i]){
               could = true;
                ans = i+1;
                break;
            }
        }
        if(could)
            cout << ans << endl;
        else{
            ans = -1;
            cout << ans << endl;
         }
    }


    return 0;
}
