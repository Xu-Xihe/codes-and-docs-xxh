const int N=1e3+10;
int d[N][N];
inline void upd(int x,int y,int v){
    for(int px=x;px<=n;px+=px&-px)
        for(int py=y;py<=m;py+=py&-py)
            d[px][py]+=v;
}
inline int qry(int x,int y){
    int res=0;
    for(int px=x;px;px-=px&-px)
        for(int py=y;py;py-=py&-py)
            res+=d[px][py];
    return res;  
}