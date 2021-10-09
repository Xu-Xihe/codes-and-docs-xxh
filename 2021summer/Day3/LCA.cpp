void dfs1(int u)
{
    siz[u]=1;
    for(int i=head[u];i;i=e[i].next)
    {
        int v=e[i].to;
        if(dep[v])continue;
        dep[v]=dep[u]+1,fa[v]=u;
        dfs1(v);
        siz[u]
    }
}