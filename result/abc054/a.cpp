#include<iostream>
#include<math.h>
#include<vector>
#include<stdio.h>
#include<string>
using namespace std;
int main(void){

    int a,b;
    cin>>a;
    cin>>b;


    if(a==1){
        if(b==1){
            cout<<"Draw"<<endl;
            return 0;
        }
    }
    if(a==1){
        cout<<"Alice"<<endl;
        return 0;
    }
    if(b==1){
        cout<<"Bob"<<endl;
        return 0;
    }
    if(a==b){
        cout<<"Draw"<<endl;
        return 0;
    }

    if(a<b){
        cout<<"Bob"<<endl;
        return 0;
    }
    if(b<a){
        cout<<"Alice"<<endl;
        return 0;
    }


    
    
    return 0;

}
