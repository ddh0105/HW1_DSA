#include<iostream>
#include<math.h>
using namespace std;

//tao ham sang so nguyen to eratosthenes
void sangsnt(int N, bool prime[]){
    for (int i = 0;  i < N; i++){
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for (int i = 2; i < N; i++){
        if (prime[i]){
            for(int j = i * i; j < N; j+=i){
                prime[j] = 0;
            }
        }
    }
}


//Ham tao ra mag so Blum nho hon N
int arrblumNumbers(int N,bool prime[], int blumNumbers[]){
    int dem = 0;

    for (int p = 2; p < N; p++){
        if(prime[p]){
            for (int q = p; q < N; q++){
                if (prime[q]){
                    int blumNumber = p * q;
                    if (blumNumber < N){
                        blumNumbers[dem++]= blumNumber;
                    }
                }
            }
        }
    }

    //Sap xep mang so blum bang thuat toan noi bot
    for (int i = 0; i < dem-1; i++){
        for(int j = 0; j < dem-i-1; j++){
            if (blumNumbers[j] >= blumNumbers[j+1]){
                int tg = blumNumbers[j];
                blumNumbers[j] = blumNumbers[j+1];
                blumNumbers[j+1]= tg;
            }
        } 
    }

    return dem;
}


//Ham tim cac cap so blum cung la so Blum trong day
void findPairofBlum(int blumNumbers[], int size){
    cout << "Cac cap so Blum cung co tong la so Blum trong day:\n";
    for (int i = 0; i < size; i++){
        for (int j = i; j < size; j++){
            int sum = blumNumbers[i]+ blumNumbers[j];
            for (int k = 0; k < size; k++){
                if (blumNumbers[k] == sum){
                    cout <<"("<<blumNumbers[i]<<","<<blumNumbers[j]<<")"<<endl;
                    break;
                } 
            }
        }
    }
}


//Ham kiem tra su ton tai cua so blum M
bool checkBlum(int blumNumbers[], int size, int M){
    for (int i = 0; i < size; i++){
        if (blumNumbers[i] == M) return true;
    }
    return false;
}

int main(){
    int N; 
    cout <<"Nhap so N: ";
    cin >> N;
    bool prime[N];//danh dau cac so nguyen to < N
    sangsnt(N, prime);//tat ca cac so nguyen to < N

    int blumNumbers[1000];
    int size = arrblumNumbers(N, prime, blumNumbers);//so luong so blum trong mang

    cout <<"Cac so Blum nho hon"<<" N "<<"la: "<<endl;
    for (int i = 0; i < size; i++){
        cout << blumNumbers[i]<<" ";
    }
    cout << endl;

    // Tim cac cap so Blum co tong cung la so Blum trong mang
    findPairofBlum(blumNumbers, size);

    //Kiem tra su ton tai cua so Blum M
    int M;
    cout << "\nNhap so Blum M: "; cin >>M;
    if(checkBlum(blumNumbers, size, M)) cout <<"\nLa so blum thuoc day";
    else cout << "\nKhong thuoc day";

    return 0;
    

}

