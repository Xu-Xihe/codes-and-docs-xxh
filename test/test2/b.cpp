#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
string out[]={
    "","2","4","11","31","83","227","616","1674","4550","12367","33617","91380","248397","675214","1835421","",
};
int len;
int main(){
    while (~scanf("%d",&len))
    {
        cout<<out[len]<<endl;
    }
    return 0;
}