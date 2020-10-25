#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

#define PI 3.14159265

double findAngle(double x1, double y1, double x2, double y2) {
    double dot = x1*x2 + y1*y2;
    double det = x1*y2 - y1*x2;
    double angle = atan2(det, dot);
    return abs(angle * 180 / PI);
}

int main() {
    int t, n;
    cin >> t;
    for (int i=0 ; i<t ; i++) {
        double pos[5]={0};
        double neg[5]={0};
        bool flag = false;
        cin >> n;
        for (int j=0 ; j<n ; j++) {
            double x,y;
            int l;
            cin >> x >> y >> l;
            // cout << x << " " << y << " " <<  l <<endl;
            if (l == 1) {
                if (pos[1]==0 && pos[2]==0) {
                    pos[1]=x; pos[2]=y;
                    // cout << "flag 1" << endl;
                    continue;
                }
                else if ((pos[1]!=0 || pos[2]!=0) && (pos[3]==0 && pos[4]==0)) {
                    pos[3]=x; pos[4]=y;
                    pos[0] = findAngle(pos[1], pos[2], pos[3], pos[4]);
                    // cout << "flag 2" << endl;
                    continue;
                }

                double deg1 = findAngle(x,y,pos[1],pos[2]);
                double deg2 = findAngle(x,y,pos[3],pos[4]);
                if (deg1 + deg2 + pos[0] == 360) {
                    cout << "NO" << endl;
                    flag = true;
                    break;
                }
                else if (deg1 - deg2 == pos[0]) {
                    pos[3] = x;
                    pos[4] = y;
                    pos[0] = deg1;
                }
                else if (deg2 - deg1 == pos[0]) {
                    pos[1] = x;
                    pos[2] = y;
                    pos[0] = deg2;
                }
            }
            else {
                if (neg[1]==0 && neg[2]==0) {
                    neg[1]=x; neg[2]=y;
                    continue;
                }
                else if ((neg[1]!=0 || neg[2]!=0) && (neg[3]==0 && neg[4]==0)) {
                    neg[3]=x; neg[4]=y;
                    neg[0] = findAngle(neg[1], neg[2], neg[3], neg[4]);
                    continue;
                }

                double deg1 = findAngle(x,y,neg[1],neg[2]);
                double deg2 = findAngle(x,y,neg[3],neg[4]);
                if (deg1 + deg2 + neg[0] == 360) {
                    cout << "NO" << endl;
                    flag = true;
                    break;
                }
                else if (deg1 - deg2 == neg[0]) {
                    neg[3] = x;
                    neg[4] = y;
                    neg[0] = deg1;
                }
                else if (deg2 - deg1 == neg[0]) {
                    neg[1] = x;
                    neg[2] = y;
                    neg[0] = deg2;
                }
            }
        }
        if (!flag) {
            if ((findAngle(pos[1],pos[2],neg[1],neg[2]) +
                findAngle(pos[3],pos[4],neg[1],neg[2])) !=
                pos[0] &&
                (findAngle(pos[1],pos[2],neg[3],neg[4]) +
                findAngle(pos[3],pos[4],neg[3],neg[4])) !=
                pos[0])
                cout << "YES" << endl;
            else {
                if (pos[1]/neg[1] == pos[2]/neg[2] &&
                   (findAngle(pos[1],pos[2],neg[3],neg[4]) +
                    findAngle(pos[3],pos[4],neg[3],neg[4])) !=
                    pos[0]) {
                    cout << "YES" << endl;
                }
                else if (pos[1]/neg[3] == pos[2]/neg[4] &&
                       (findAngle(pos[1],pos[2],neg[1],neg[2]) +
                        findAngle(pos[3],pos[4],neg[1],neg[2])) !=
                        pos[0]){
                    cout << "YES" << endl;
                }
                else if (pos[3]/neg[1] == pos[4]/neg[2] &&
                       (findAngle(pos[1],pos[2],neg[1],neg[2]) +
                        findAngle(pos[1],pos[2],neg[3],neg[4])) !=
                        neg[0]){
                    cout << "YES" << endl;
                }
                else if (pos[3]/neg[3] == pos[4]/neg[4] &&
                       (findAngle(pos[1],pos[2],neg[1],neg[2]) +
                        findAngle(pos[1],pos[2],neg[3],neg[4])) !=
                        neg[0]){
                    cout << "YES" << endl;
                }
                else if (pos[1]/neg[1] == pos[2]/neg[2] && pos[3]/neg[3] == pos[4]/neg[4])
                    cout << "YES" << endl;
                else
                    cout << "NO" <<endl;
            }

        }
    }
    return 0;
}
