#include <cstdio>
char seat[1001][6];
int main()
{
    int n;
    bool flag = false;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", &seat[i]);
    for (int i = 0; i < n; i++)
        if (seat[i][0] == 'O' && seat[i][1] == 'O')
        {
            seat[i][0] = seat[i][1] = '+';
            flag = true;
            break;
        }
        else if (seat[i][3] == 'O' && seat[i][4] == 'O')
        {
            seat[i][3] = seat[i][4] = '+';
            flag = true;
            break;
        }
    if (flag)
    {
        printf("YES\n");
        for (int i = 0; i < n; i++)
            printf("%s\n", seat[i]);
    }
    else
        printf("NO");
    return 0;
}