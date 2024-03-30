#include<iostream>

using namespace std;

void inp(int &n){
    do {
        printf("Hay nhap chieu cao cho tam giac pascal: ");
        scanf("%d", &n);
        if (n <= 0)
            printf("Nhap lai!!");
    } while (n <= 0);
}

int tg_pascal(int k, int n){
    if (k == 0 || k == n)
        return 1;
    if (k == 1)
        return n;
    return tg_pascal(k-1,n-1) + tg_pascal(k,n-1);
}

void out(int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            cout << tg_pascal(j,i) << " ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    
    inp(n);
    out(n);

    return 0;
}