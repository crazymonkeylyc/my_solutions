#include <cstdio>
int head[1001], next[1001 << 1], to[1001 << 1], ecnt, ts;
int vis[1001], pre[1001];
inline void addEdge(int f, int t)
{
    ecnt++;
    next[ecnt] = head[f];
    head[f] = ecnt;
    to[ecnt] = t;
}
bool dfs(int u)
{
    for (int cur = head[u], v; cur; cur = next[cur])
        if (vis[to[cur]] != ts)
        {
            v = to[cur], vis[v] = ts;
            if (!pre[v] || dfs(pre[v]))
            {
                pre[v] = u;
                return true;
            }
        }
    return false;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1, x, y; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        addEdge(i, x);
        addEdge(i, y);
    }
    for (ts = 1; ts <= m + 1; ts++)
        if (!dfs(ts)) break;
    printf("%d", ts - 1);
    return 0;
}