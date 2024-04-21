#include<iostream>
#include<math.h>

using namespace std;

void nhap(int &hs1, int &hs2, int &hs3){
    do {
        cout << "Nhap he so cho a: ";
        cin >> hs1;
        cout << "Nhap he so cho b: ";
        cin >> hs2;
        cout << "Nhap he so cho c: ";
        cin >> hs3;
        if (hs1 == 0)
            cout << "Vui long nhap lai he so a khac 0!!\n";
    } while (hs1 == 0);
}

int main(){
    int a,b,c;
    double x1, x2;    
    double delta;
    nhap(a,b,c);
    delta = b*b - 4*a*c;
    if (delta < 0)
        printf("Phuong trinh vo nghiem!!\n");
    else if (delta == 0) {
        x1 = -b/(2*a);
        printf("Phuong trinh co 1 nghiem kep x = %1.3f", x1);
    }
    else {
        x1 = (-b+sqrt(pow(b,2)-4*a*c))/(2*a);
        x2 = (-b-sqrt(pow(b,2)-4*a*c))/(2*a);
        printf("Phuong trinh co 2 nghiem phan biet x1 = %1.3f va x2 = %1.3f", x1,x2);
    } 

    return 0;
}