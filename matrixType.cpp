#include<iostream>

using namespace std;

void nhapmang(int **a, int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            cout << "\nNhap vao Mang A[" << i << "]" << "[" << j << "]: ";
            cin >> a[i][j];

        }

    }
    //cout<<"Nhap vao mang a["
}
void xuat(int **a, int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            //cout << "\nNhap vao Mang A[" << i << "]" << "[" << j << "]: ";
            cout << a[i][j]<<"    ";
        }
        cout <<endl;
    }
}

int main()
{

    int **a;
    int dong, cot;
    cout << "Nhap dong: ";
    cin >> dong;
    cout << "Nhap cot: ";
    cin >> cot;
    a = new int *[dong];//// cap phat n o nho cho n con tro (n hang)  (n dong)
    /* 3x4
    1 2 3 4
    1 2 3 4
    1 2 3 4

    */
    for (int i = 0; i < dong; i++)
    {
        a[i] = new int [cot];//// cap phat m o nho cho moi con tro (moi hang)
        /*
        ví dụ có 4 hàng...thì ở mỗi hàng cấp phát 4 ô nhớ (cột)

        */
    }
    nhapmang(a, dong, cot);
    xuat(a, dong, cot);

    int count1 = 0;
    int demStar = dong + 2*(dong - 1);
    int demRing = 3*dong;
    int demMesh = dong*dong;


     //if (cot > 3) {

//         int count = 0;
//         for (int i = 0; i < cot; i++) {
//             if (a[0][i] == 1) {
//                 count++;
//
//             }
//
//         }

    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            if (a[i][j] == 1) {
                count1++;

            }

        }

    }

    cout<<"count1 = "<<count1<<endl;






         if (count1 == demRing) {
             cout << "it is a ring" << endl;

         } else if (count1 == demStar) {
             cout << "it is a star" << endl;
         } else if (count1 == demMesh) {
             cout << "it is a mesh" << endl;
         }


    // }

//    if (count == dem) {
//        cout << "it is a star" << endl;
//
//    }

//    if (count == 3) {
//        cout << "it is a ring" << endl;
//
//    } else if (count == 2) {
//        cout << "it is a star" << endl;
//    } else if (count == cot) {
//        cout << "it is a mesh" << endl;
//    } else {
//        cout << "it is nothing" << endl;
//    }


    return 0;
}