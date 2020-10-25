#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int charToInt(char c){
	switch(c){
        case '2' : return 0;
        case '3' : return 1;
        case '4' : return 2;
        case '5' : return 3;
        case '6' : return 4;
        case '7' : return 5;
        case '8' : return 6;
        case '9' : return 7;
    		case 'X' : return 8;
    		case 'J' : return 9;
    		case 'Q' : return 10;
    		case 'K' : return 11;
    		case 'A' : return 12;
    		default: return -17141324;
		}
}

char intToChar(int c){
	switch(c){
    case 0 : return '2';
    case 1 : return '3';
    case 2: return '4';
    case 3 : return '5';
    case 4 : return '6';
    case 5 : return '7';
    case 6 : return '8';
    case 7 : return '9';
  	case 8 : return 'X';
  	case 9 : return 'J';
  	case 10: return 'Q';
  	case 11 : return 'K';
  	case 12 : return 'A';
  	default: return 's';
	}
}

int main() {
    int K,N, fyllo;
    cin >> N >> K ;
    char seira[N],pontarisma;
    int prob_xeri[13], seen[13];

    for (int i=0; i < 13; ++i) prob_xeri[i] = seen[i] = 0;

    for (int i=0; i<N; ++i) {
        cin >> seira[i];
        fyllo = charToInt(seira[i]);
        seen[fyllo]++;
    }
    for (int i=0; i<N ; ++i) {
        cin >> pontarisma;
        fyllo = charToInt(seira[i]);
        if (pontarisma == 'n' && prob_xeri[fyllo] == 0) prob_xeri[fyllo] = -1;
        else if (pontarisma == 'n' && prob_xeri[fyllo] != 0) {
            cout << "impossible\n";
            return 0;
        }
        else if (pontarisma == 'y' && prob_xeri[fyllo] == 0) prob_xeri[fyllo] = 1;
        else if (pontarisma == 'y' && prob_xeri[fyllo] == -1) prob_xeri[fyllo] = -2;
    }
    int k = 0;
    for (int i = 0; i<13; ++i)
        if (prob_xeri[i] == 1) k++;

    int unknown = K - k;
    if (unknown < 0) {
            cout << "impossible\n";
            return 0;
    }

    int teliko[13] = {-1};
    for (int i = 0; i < 13; ++i)
        if (prob_xeri[i]>= 0)
            teliko[i] = seen[i] + prob_xeri[i];

    vector<int> res;
    for (int i = 0; i < 13; ++i) {
      if (prob_xeri[i] > 0) res.push_back(i);
    }
    int left[13];

    for (int i = 0; i < 13; ++i) {
      if (prob_xeri[i] > 0) left[i] = 4 - seen[i] - 1;
      else if (prob_xeri[i] == 0) left[i] = 4 - seen[i];
      else left[i] = 0;
    }
    int max = 0, pos;
    while (res.size() < K) {
      for (int i = 0; i < 13; ++i)
        if (prob_xeri[i] > 0 && left[i] > max) {
          max = left[i];
          pos = i;
        }
      if (max == 0) break;
      while (res.size() < K && left[pos] > 0) {
        res.push_back(pos);
        left[pos]--;
      }
      max = 0;
    }

    while (res.size() < K) {
      for (int i = 0; i < 13; ++i)
        if (prob_xeri[i] == 0 && left[i] > max) {
          max = left[i];
          pos = i;
        }
      while (max != 0 && res.size() < K && left[pos] > 0) {
        res.push_back(pos);
        left[pos]--;
      }
      max = 0;
    }

    if (res.size() < K) {
      cout << "impossible\n";
      return 0;
    }
    else {
      sort(res.begin(), res.end());
      for (int i = 0; i < K; ++i) cout << intToChar(res[i]);
    }


    //for (int i = 0; i < 13; ++i) cout << prob_xeri[i];
    //for (int i = 0; i < 13; ++i) cout << teliko[i];

    cout << endl;
    return 0;

}
