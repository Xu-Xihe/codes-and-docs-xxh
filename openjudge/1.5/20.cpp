#include<cstdio>
#include<iostream>
using namespace std;
double len,ans;
int main(){
    cin>>len;
    //printf("%llf %llf\n",ans,len);
    ans=len;
    for (int i = 0; i < 10; i++)
    {
        len/=2;
        ans+=len*2;
        //printf("%g %g\n",ans,len);
    }
    printf("%g\n%g",ans-len*2,len);
    return 0;
}