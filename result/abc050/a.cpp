#include<iostream>
#include<math.h>
#include<vector>
#include<stdio.h>
#include<string>
using namespace std;
int main(void){
   
    int a,b;
    cin>>a;
    string c;
    cin>>c;
    if(c=="+"){
        cin>>b;
        cout<<a+b<<endl;
    }else{
        cin>>b;
        cout<<a-b<<endl;
    }


    return 0;
}
