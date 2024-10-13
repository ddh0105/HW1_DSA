#include<iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a; 
    a = b;
    b = temp;
}

void SortColor(int a[], int n, int moc){
    // Lan 1: Duyet mang tu trai qua phai de sap xep phan tu nho hon o ben trai moc
    int nhohon = 0;
    for (int i = 0; i < n; i++){
        if (a[i] < moc){
            swap(a[i], a[nhohon]);//neu phan tu thu i nho hon moc thi doi cho phan tu thu nho hon voi phan tu thu i, dong thoi tang nho hon len 1 don vi
            nhohon++;
        }
    }

    //Lan 2: Duyet mang t6u phai qua trai de sap xep phan tu lon hon nam o ben phai moc
    int lonhon = n - 1;
    for (int i = n -1; i >= 0; i--){
        if (a[i] > moc){
            swap(a[i], a[lonhon]);
            lonhon--;
        }
        else if (a[i] < moc) {break;}
    }
}

int main(){
    //Input {xanh, đỏ, xanh, đỏ, đỏ, trắng, đỏ, xanh, trắng}
    //chuyen thanh cac soi 0, 1, 2 tuong ung
    int a[]={2, 0, 2, 0, 0, 1, 0, 2, 1};
    int n = sizeof(a)/sizeof(a[0]);
    //Chon mau trang (1) la moc
    int moc = 1;
    
    cout << "Truoc khi sap xep: "<< endl;
    
    for (int i = 0; i < n; i++){
        cout << a[i]<< " ";
    }
    cout << endl;
    

    SortColor(a, n, moc);
    

    cout <<endl<<"Sau khi sap xep la: \n";
    for (int i = 0; i < n; i++){
        cout << a[i]<<" ";
    }
    cout <<endl;
    

    return 0;
}