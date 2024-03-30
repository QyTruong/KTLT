#include<iostream>

using namespace std;

int gcd(int a, int b){
    if (b == 0) 
        return a;
    return gcd(b, a%b);
}

int main(){
    int a, b; 
    printf("Hay nhap 2 so nguyen bat ky: ");
    scanf("%d %d", &a, &b);
    printf("Uoc chung lon nhat cua %d va %d la: %d",a,b,gcd(a,b));

    return 0;
}