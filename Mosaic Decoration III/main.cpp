#include <iostream>
#include <math.h>
#include <string>
#include<climits>

using namespace std;

int maxSubArraySum(int a[], int size)
{
   int max_so_far = 0, max_ending_here = 0;
   for (int i = 0; i < size; i++)
   {
       max_ending_here = max_ending_here + a[i];
       if (max_ending_here < 0)
           max_ending_here = 0;

       else if (max_so_far < max_ending_here)
           max_so_far = max_ending_here;
   }
   return max_so_far;
}

int main() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    int tile[r][c];
    int tileCost=0;
    int rowSum[r]={0}, columnSum[c]={0};
    for (int i=0 ; i<r ; i++) {
        for (int j=0 ; j<c ; j++) {
            cin >> tile[i][j];
            tileCost += tile[i][j];
            rowSum[i] += tile[i][j];
        }
    }
    for (int i=0 ; i<c ; i++)
        for (int j=0 ; j<r ; j++)
            columnSum[i] += tile[j][i];

    int width = m / c;
    int height = n / r;
    int base_cost = width*height*tileCost;

    int width_l = m%c;
    int x = c - width_l;
    int height_l = n%r;
    int y = r - height_l;

    int rest_cost = height*(tileCost - maxSubArraySum(columnSum, x)) +
                   width*(tileCost - maxSubArraySum(rowSum, y));

    //cout << tileCost - maxSubArraySum(columnSum, x) <<endl;
    //cout << tileCost - maxSubArraySum(rowSum, y) << endl;
    cout << base_cost + rest_cost << endl;
    return 0;
}
