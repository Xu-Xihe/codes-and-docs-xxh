struct bit{
    long long d[N];
    inline void upd(int p,long long v){
        for(;p<=n;p+=p&-p)d[p]+=v;
    }
    inline int qry(int p){
        long long res=0;
        for(;p;p-=p&-p)res+=d[p];
        return res;
    }
}t1,t2;
long long sum(int r){
    return t1.qry(r)*(r+1)-t2.qry(r);
}
void upd(int p,long long v){
    t1.upd(p,v),t2.upd(p,p*v);
}
