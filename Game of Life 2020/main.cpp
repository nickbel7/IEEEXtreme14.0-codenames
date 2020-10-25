#include <iostream>

using namespace std;

int main() {
    bool empty[5], alive[5];
    int c;
    for(int i=0; i<11; i++) {
        c = getchar();
        if(i < 6) {
            if (c == '1')
                empty[i] = true;
            else
                empty[i] = false;
        }
        else if (i > 5) {
            if (c == '1')
                alive[i-6] = true;
            else
                alive[i-6] = false;
        }
    }
    c = getchar();

    int N, M;
    cin >> N >> M;
    //cout << M << endl;
    bool arr[N][N], next[N][N];

    for (int i=0; i<N; i++) {
        for(int j=0; j<N; j++){
            c = getchar();
            if (c == '\n') c = getchar();
            if(c == '1')
                arr[i][j] = true;
            else
                arr[i][j] = false;
            //next[i][j] = arr[i][j];
        }
    }

    /*for(int i=0; i<N; ++i){
      for(int j=0; j<N; ++j){
        if (arr[i][j]) cout << 1;
        else           cout << 0;
      }
      cout << endl;
    }*/


    for(int a=0; a<M; ++a){
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){

                int counter = 0;
                if(arr[(i-1 + N) % N][j])
                    counter++;
                if(arr[(i+1) % N][j])
                    counter++;
                if(arr[i][(j-1 + N) % N])
                    counter++;
                if(arr[i][(j+1) % N])
                    counter++;

                //if(a==0) cout << "i" << i << " j" << j << "geitoneoi" << counter << endl;

                if(arr[i][j]){
                    if(alive[counter])
                        next[i][j] = true;
                    else
                        next[i][j] = false;
                }
                else{
                    if(empty[counter])
                        next[i][j] = true;
                    else
                        next[i][j] = false;
                }

            }
        }
        for(int k=0; k<N; ++k)
            for(int l=0; l<N; ++l)
                arr[k][l] = next[k][l];
    }

    for(int i=0; i<N; ++i){
      for(int j=0; j<N; ++j){
        if (arr[i][j]) cout << 1;
        else           cout << 0;
      }
      cout << endl;
    }
    return 0;
}
