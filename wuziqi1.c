#include <stdio.h>
#include <stdlib.h>
#define N 15
#define OK 1
#define NO 0
 
int map[N][N] = {};
int whoturn = 0;
 
void initgame();
void playchess();
void printfchessmap();
int judge(int x, int y);
 
int main()
{
    initgame();
 
    while(1)
    {
        playchess();
        whoturn++;
    }
 
    return 0;
}
 
void initgame()
{
    char choice;
    printf("�Ƿ������Ϸ(Y/N)");
    choice = getchar();
    if (choice != 'y' && choice != 'Y')     
        exit(0);
    //getchar();
    printf("\n");
    system("cls");
    printfchessmap();
}
 
void printfchessmap()
{
    int i, j;
 
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i == 0)
                printf("%3d", j);       //��ӡ���� 
            else if (j == 0)
                printf("%3d", i);       //��ӡ���� 
            else if (1 == map[i][j])
                printf("%3c", 'O');
            else if (2 == map[i][j])
                printf("%3c", 'X');
            else
                printf("%3c", '*');
        }
        printf("\n");
    }
}
 
void playchess()
{
    int x, y;
 
    if (0 == whoturn % 2)
    {
        printf("�����ֵ����1�������ӣ�");
        scanf("%d %d", &x, &y);
        while(0 != map[x][y])
        {
            printf("���λ���Ѿ��������ˣ����������룺");
            scanf("%d %d", &x, &y);
        }
        map[x][y] = 1;
    }
    else if (1 == whoturn % 2)
    {
        printf("�����ֵ����2�������ӣ�");
        scanf("%d %d", &x, &y);
        while(0 != map[x][y])
        {
            printf("���λ���Ѿ��������ˣ����������룺");
            scanf("%d %d", &x, &y);
        }
        map[x][y] = 2;
    }
    system("cls");
    printfchessmap();
    if (judge(x, y)){
        printf("���%d��ʤ\n",1 + whoturn % 2);
        exit(0);
    }
}
 
int judge(int x, int y)
{
    int i, j;
    int count;
    int winflag = 1;    //��һ���㲻���ٴζ�ȡ
    int cur;   //��¼��ǰ���µ���
    cur = map[x][y] == 1 ? 1 : 2;
    printf("cur = %d", cur);
    //ˮƽ�����ж�
    count = 0;
    for (i = x, j = y - 1; j > 0 && count++ < 5; j--)
    {
        if (map[i][j] == cur)
        {
            winflag++;
        }
        else
            break;
    }
    count = 0;
    for (i = x, j = y + 1; j < N && count++ < 5; j++)
    {
        if (map[i][j] == cur)
        {
            winflag++;
        }
        else
            break;
    }
    if (winflag >= 5)
        return OK;
    else
        winflag = 1;
    //��ֱ�����ж�
    count = 0;
    for (i = x - 1, j = y; i > 0 && count++ < 5; i--)
    {
        if (map[i][j] == cur)
        {
            winflag++;
        }
        else
            break;
    }
    count = 0;
    for (i = x + 1, j = y; i < N && count++ < 5; i++)
    {
        if (map[i][j] == cur)
        {
            winflag++;
        }
        else
            break;
    }
    if (winflag >= 5)
        return OK;
    else
        winflag = 1;
    //���Խ����ж�
    count = 0;
    for (i = x - 1, j = y - 1; i > 0 && j > 0 && count++ < 5; j--, i--)
    {
        if (map[i][j] == cur)
        {
            winflag++;
        }
        else
            break;
    }
    count = 0;
    for (i = x + 1, j = y + 1; i < N && j < N && count++ < 5; j++, i++)
    {
        if (map[i][j] == cur)
        {
            winflag++;
        }
        else
            break;
    }
    if (winflag >= 5)
        return OK;
    else
        winflag = 1;
    //б�Խ����ж�
    count = 0;
    for (i = x + 1, j = y - 1; x < N && j > 0 && count++ < 5; j--, i++)
    {
        if (map[i][j] == cur)
        {
            winflag++;
        }
        else
            break;
    }
    count = 0;
    for (i = x - 1, j = y + 1; i > 0 && j < N && count++ < 5; j++, i--)
    {
        if (map[i][j] == cur)
        {
            winflag++;
        }
        else
            break;
    }
    if (winflag >= 5)
        return OK;
    else
        winflag = 1;
 
    return NO;
}


