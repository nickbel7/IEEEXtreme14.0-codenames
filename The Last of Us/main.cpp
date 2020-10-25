#include <iostream>
#include <string>

using namespace std;

void walkUp(int n) {
    for (int i=0 ; i<n ; i++) {
        cout << "w" << " " << 0 << " " << 1 << endl;
    }
}
void walkDown(int n) {
    for (int i=0 ; i<n ; i++) {
        cout << "w" << " " << 0 << " " << -1 << endl;
    }
}
void walkLeft(int n) {
    for (int i=0 ; i<n ; i++) {
        cout << "w" << " " << -1 << " " << 0 << endl;
    }
}
void walkRight(int n) {
    for (int i=0 ; i<n ; i++) {
        cout << "w" << " " << 1 << " " << 0 << endl;
    }
}
void walkUpRight(int n) {
    for (int i=0 ; i<n ; i++) {
        cout << "w" << " " << 1 << " " << 1 << endl;
    }
}
void walkUpLeft(int n) {
    for (int i=0 ; i<n ; i++) {
        cout << "w" << " " << -1 << " " << 1 << endl;
    }
}
void walkDownRight(int n) {
    for (int i=0 ; i<n ; i++) {
        cout << "w" << " " << 1 << " " << -1 << endl;
    }
}
void walkDownLeft(int n) {
    for (int i=0 ; i<n ; i++) {
        cout << "w" << " " << -1 << " " << -1 << endl;
    }
}
void throwBrick(int x, int y) {
    cout << "b" << " " << x << " " << y << endl;
}


int main() {
    string area;
    cin >> area;
    // cout << area;
    int r,c,b;
    cin >> r >> c >> b;
    int xd, yd, x_start=3, y_start=3;
    // . is walkable
    // # is blocked
    // E is ellie's location
    // X is exit
    // c is clicker
    char map[r][c];
    for (int i=0 ; i<r ; i++) {
        for (int j=0 ; j<c ; j++) {
            cin >> map[i][j];
            if (map[i][j] == "X") {
                xd=i, yd=j;
            }
        }
    }

    if (area == "area-1") {
        cout << 47 << endl;
        walkDown(4);
        throwBrick(-2, -4);
        walkDown(1);
        walkDownRight(2);
        walkRight(9);
        throwBrick(4, 2);
        walkDownRight(1);
        walkRight(4);
        walkUpRight(1);
        walkRight(1);
        walkDownRight(3);
        walkDown(1);
        walkDownRight(3);
        walkRight(1);
        walkDownRight(3);
        walkDown(11);
    }

    if (area == "area-special-4") {
        cout << yd-y_start + xd-x_start;
        walkDown(yd-y_start);
        walkRight(xd-x_start);
    }

    return 0;
}
