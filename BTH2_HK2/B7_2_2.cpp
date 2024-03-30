#include<iostream>

using namespace std;

long even_odd(int n, int check, int x = 0){
    if (n == 0)
        return x;
    if (n % 2 == check){
        return even_odd(n/10, check, x + n%10);
    }
    else {
        return even_odd(n/10,check ,x);
    }
}

int main(){
    int n;
    int choice; 
    printf("Hay 1 day so bat ky: ");
    cin >> n;
    printf("Tinh tong gia tri cac so le (0) hoac chan (1) trong day so: ");
    cin >> choice;    
    printf(choice == 1 ? "Tong gia tri cac so le cua %d la: %d" : "Tong gia tri cac so chan cua %d la: %d", n, even_odd(n, choice));
    return 0;
}