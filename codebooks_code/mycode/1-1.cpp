#include<cstdio>
int main(){
    const double pi=3.1415926;
    double r,h,ans;
    scanf("%lf%lf",&r,&h);
    ans=r*r*pi*2+h*2*r*pi;
    printf("Area=%.3f\n",ans);
    return 0;
}