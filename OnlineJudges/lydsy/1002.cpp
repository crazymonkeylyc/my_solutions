#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
int f[101][101];
const int L = 1 << 8;
char buffer[L], *S, *T;
#define bufferInit()                                   \
    ;                                                  \
    {                                                  \
        T = (S = buffer) + fread(buffer, 1, L, stdin); \
        while (!isdigit(*T)) T--;                      \
        T++;                                           \
    }
#define getint() (S != T ? strtol(S, &S, 10) : -1)
void optimize(int *a)
{
    for (int i = 0; i < 100; i++)
    {
        while (a[i] < 0) a[i] += 10, a[i + 1]--;
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
}
void add(int *a, int b)
{
    a[0] += b;
}
void mul(int *a, int b)
{
    for (int i = 0; i < 100; i++)
        a[i] *= b;
}
void sub(int *a, int *b)
{
    for (int i = 0; i < 100; i++)
        a[i] -= b[i];
}
int main()
{
    bufferInit();
    f[1][0] = 1;
    f[2][0] = 5;
    int n = getint();
    for (int i = 3; i <= n; i++)
    {
        memmove(f[i], f[i - 1], sizeof(int) * 101);
        mul(f[i], 3);
        sub(f[i], f[i - 2]);
        add(f[i], 2);
        optimize(f[i]);
    }
    int *ans = f[n];
    optimize(ans);
    int i = 100;
    for (; ans[i] == 0 && i >= 0; i--)
        ;
    for (; i >= 0; i--) putchar(ans[i] + '0');
    return 0;
}
