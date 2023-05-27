#include<bits/stdc++.h>
using namespace std;

/// https://www.youtube.com/watch?v=ExXbGZ0i6N4&list=PLgLCjVh3O6ShKtFjewv_nSaoyON0Au-OD&index=4&ab_channel=LoveExtendsCode

void ref(int &n){
    n = 0;
}
void basic(){
    int n;
    cin>>n;
    int *p;
    p = &n;
    cout<<*p<<endl;
    ref(n);
    cout<<*p<<endl;
}
void pointer_to_a_pointer(){
    int n; cin>>n;
    int *px = &n;
    cout<<px<<" "<<*px<<endl;

    int* *ppx = &px;
    cout<<*ppx<<" "<<**ppx;
}

void change_pass_by_ref(int* px, int v){
    *px = v;
}

void pass_by_ref(){
    int x,v; cin>>x>>v;
    change_pass_by_ref(&x,v);
    cout<<x<<endl;
}
void failedExperiment(){
    int num = 42;
    int* ptr = &num;
    int* ptr2 = ptr + 1;
    *ptr2 = 40;
    change_pass_by_ref(ptr2,69);
    cout<<*ptr<<" "<<ptr2<<endl;
}
void Malloc(){
    int *ptr;
    ptr = (int*)malloc(sizeof(int));
    *ptr = 10;
    cout<<*ptr<<endl;
}
int main(){
    //basic();
    //pointer_to_a_pointer();
    //pass_by_ref();
    //failedExperiment();
    //Malloc();

}
