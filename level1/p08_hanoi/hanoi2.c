#include<stdio.h>
#include"hanoi1.c" 
int bushu=0;
void move(int,char,char,char);
int main(){
char ch1 = 'A';
char ch2 = 'B'; 
char ch3 = 'C'; 
 
int n;
printf("������Բ�̸�����");
scanf("%d",&n);
move(n,ch1,ch2,ch3);
printf("����Ϊ%d\n",bushu);
return 0;
}
