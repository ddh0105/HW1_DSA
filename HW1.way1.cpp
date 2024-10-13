#include<iostream>
using namespace std;

//RED = 0; WHITE = 1; BLUE = 2

void SortColor(int a[], int n){
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high){
        if (a[mid] == 0){//gap mau do
            //dua phan tu mau do ra dau mang
            int temp = a[low];
            a[low] = a[mid];
            a[mid] = temp;
            low++;
            mid++;
        }
        else if (a[mid] == 1){//gp mau trang
            //kiem tra teip phan tu tiep theo
            mid++;
        }
        else {//gap mau xanh
            int temp = a[mid];
            a[mid] = a[high];
            a[high] = temp;
            high--;
        }
    }
}

int main(){
    //Input {xanh, đỏ, xanh, đỏ, đỏ, trắng, đỏ, xanh, trắng}
    //chuyen thanh cac soi 0, 1, 2 tuong ung
    int a[]={2, 0, 2, 0, 0, 1, 0, 2, 1};
    int n = sizeof(a)/sizeof(a[0]);
    
    cout << "Truoc khi sap xep: "<<endl;
    
    for (int i = 0; i < n; i++){
        cout << a[i]<< " ";
    }
    cout << endl;
    

    SortColor(a, n);
    

    cout <<endl<<"Sau khi sap xep la: \n";
    for (int i = 0; i < n; i++){
        cout << a[i]<<" ";
    }
    cout <<endl;
    

    return 0;
}