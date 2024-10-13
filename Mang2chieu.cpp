#include<iostream>
using namespace std;

int main(){
    int R, C;
    int ** mt;
    mt = new int *[R];//Tao mang cac con tro (R hang)
    int * temp = new int [R*C];//Tao mot khoi bo nho lien tuc cho toan bo ma tran
    for (int i = 0; i < R; i++){
        mt[i] = temp;//moi con tro mt[i] trỏ tới 1 phần tử của khối liên tục
        temp+= C;//dịch con trỏ temp sang vị trí đầu của hàng tiếp theo.
    }

    // Khoi tao ma tran voi
    //R hang va C cot
    float ** M = new float * [R];
    for (int i = 0; i  < R; i++){
        M[i] = new float [C];
        //dung M[i][j] cho cac phan tu cua ma tran
    }

    //giai phong
    for (int i = 0; i < R; i++){
        //giai phong cac hang
        delete[]M[i];
    }
    delete[]M;

    return 0;
}

/*
Giải thích sự thay đổi giá trị con trỏ 2 chiều mt khi truy cập 
các phần tử trong mảng:
- mt là mảng các con trỏ cấp 1
    mỗi con trỏ mt[i] trỏ đến phần bắt đầu của từng hàng trong mảng 2 chiều
- temp là con trỏ khối bộ nhớ liên tục, chứa tất cả cách phần tử của ma trận 
trong 1 mảng 1 chiều có kích thước R*C

- Thay đổi con trỏ temp:
. Trong mỗi vòng lặp, con trỏ temp được tăng thêm C đơn vị
(tức là trỏ sang đầu hàng tiếp theo trong khối bộ nhớ liên tục)
. Do đó, khi truy câp m[i][j] tương đương với: *(m[i]+j)== temp[i*C+j]
=> giúp ta mô phỏng được mảng 2 chiều với bộ nhớ liên tục 



- Khi truy cập mt[i][j]
. mt[i] là con trỏ tới đầu hàng thứ i
. còn mt[i][j] tương đương với *(mt[i]+j) (trỏ tới phần tử thứ j trong hàng i)
(việc truy cập này thực chất là truy cập mảng 1 chiều nhưng được mô phỏng thành mảng 2 chiều)
*/

