#include <iostream>
#include <cstring>
using namespace std;

int main() {

    char X[] = "ite:GeeksforGeeks.org";
    char Y[] = "Site:GeeksQuiz.com";

    int m = strlen(Y);
    int n = strlen(Y);
    int max = 0;

    int LCSuff[m + 1][n + 1];

//    for (int i=0; i<=m; i++)
//    {
//        LCSuff[i][0] = 0;
//    }
//
//
//    for (int j=0; j<=n; j++)
//    {
//          LCSuff[0][j] = 0;
//    }




    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {

            if ( i == 0  ){
                LCSuff[i][j] = 0 ;
            }

            if ( j == 0 ){
                LCSuff[i][j] = 0 ;
            }

            else if (X[i-1] == Y[j-1])
            {
                LCSuff[i][j] = LCSuff[i-1][j-1] + 1;

                if (max < LCSuff[i][j]){
                    max = LCSuff[i][j];
                }

            }
            else LCSuff[i][j] = 0;
        }
    }

    for (int i=0; i<=m; i++) {
        for (int j = 0; j <= n; j++) {

            cout<<LCSuff[i][j]<<" ";
        }

        cout<<endl;

    }

    cout<<"max = "<<max;

}