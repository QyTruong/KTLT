#include<iostream>

using namespace std;

void inp(int a[], int& n){
    do {
        printf("Nhap so luong phan tu: ");
        scanf("%d", &n);
        if (n <= 0)
            printf("Nhap lai!!\n");
    } while (n <= 0);

    for (int i = 0; i < n; i++){
        printf("Gia tri a[%d]: ", i+1);
        scanf("%d", &a[i]);
    }
}


int findMin(int a[], int n){
    if (n == 0)
        return -1;
    if (n == 1)
        return a[0];
    else {   
        
        if (a[n-1] < findMin(a, n-1))
            return a[n-1];
        else
            return findMin(a, n-1);
    }
}


int main(){
    int a[100], n;
    
    inp(a,n);
    printf("Gia tri nho nhat trong mang la: %d\n", findMin(a,n));

    return 0;
}