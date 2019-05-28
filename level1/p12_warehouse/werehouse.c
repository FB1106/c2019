#include<stdio.h>
#define N 20
#define PRESS_ANYKEY printf("�������������������");getchar();getchar();
#include<string.h>
struct repertory {
	char id[10],name[10],list[10],production[10];
	int num;
} per[N];
void menu() {
	printf("\t\t***************************************\n");
	printf("\t\t*          �����Ϣ����ϵͳ           *\n");
	printf("\t\t*              1���½�                *\n");
	printf("\t\t*              2����ѯ                *\n");
	printf("\t\t*              3����ɾ                *\n");
	printf("\t\t*          4���۳������              *\n");
	printf("\t\t*              5���˳�                *\n");
	printf("\t\t***************************************\n");
}
void add_menu() {
	printf("\t\t<<<<<<<<<<<<<<�½�>>>>>>>>>>>>>>>\n");
	printf("\t\t         1���½���Ϣ��           \n");
	printf("\t\t         2�������Ʒ             \n");
	printf("\t\t         3������                 \n");
	printf("\t\t<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>\n");
}
void seek_menu() {
	printf("\t\t<<<<<<<<<<<<<<�鿴>>>>>>>>>>>>>>>\n");
	printf("\t\t         1���鿴��Ϣ��           \n");
	printf("\t\t         2��������Ʒ��           \n");
	printf("\t\t         3������                 \n");
	printf("\t\t<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>\n");
}
void change_menu() {
	printf("\t\t<<<<<<<<<<<<�޸Ļ�ɾ��>>>>>>>>>>>>\n");
	printf("\t\t         1���޸���Ʒ��Ϣ          \n");
	printf("\t\t         2��ɾ����Ʒ��Ϣ          \n");
	printf("\t\t         3������                  \n");
	printf("\t\t<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>\n");
}
void jinchu_menu() {
	printf("\t\t<<<<<<<<<<<<���������>>>>>>>>>>>>\n");
	printf("\t\t         1������                  \n");
	printf("\t\t         2������                  \n");
	printf("\t\t         3������                  \n");
	printf("\t\t<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>\n");
}
char load();
void save(char m);
void add();
void charu();
void print();
void seek();
void change();
void del();
void jinchu();
char load() {
	int m=0;
	FILE *fp;
	if((fp = fopen("mchar","r"))==NULL) {
		fclose(fp);
	} else {
		m = fgetc(fp);
		if(m<=0) {
			fclose(fp);
		} else {
			return (m);
			fclose(fp);

		}
	}
}
void save(char m) {
	FILE*fp;
	if((fp = fopen("mchar","w"))==NULL) {
		m=0;
		fputc(m,fp);
		fclose(fp);
	} else {
		fputc(m,fp);
		fclose(fp);
		fp=fopen("repertory_list","w");
		fwrite(per,sizeof(struct repertory),m,fp);
		fclose(fp);
	}
}
void add() {
	char m = load();
	int i,n,count=0;
	char M;
	printf("����������Ҫ���ӵ�����:");
	scanf("%d",&n);
	for(i=m; i<(m+n); i++) {
		count++;
		printf("�������%d����Ʒ��Ϣ",count);
		printf("��Ʒ�ţ�");
		scanf("%s",&per[i].id);
		printf("��Ʒ����:");
		scanf("%s",&per[i].name);
		printf("��Ʒ���:");
		scanf("%s",&per[i].list);
		printf("��Ʒ����:");
		scanf("%d",&per[i].num);
		printf("����:");
		scanf("%s",&per[i].production);
	}
	M=n+m;
	save(M);
}
void charu() {
	char m=load();
	int i;
	i = m;
	printf("��Ʒ�ţ�");
	scanf("%s",&per[i].id);
	printf("��Ʒ����:");
	scanf("%s",&per[i].name);
	printf("��Ʒ���:");
	scanf("%s",&per[i].list);
	printf("��Ʒ����:");
	scanf("%d",&per[i].num);
	printf("����:");
	scanf("%s",&per[i].production);
	m = m+1;
	save(m);
}
void print() {
	char m=load();
	int i;
	if(m>0) {
		printf("���\t����\t���\t����\t����\t����\n");
		for(i=0; i<m; i++) {
			printf("%s\t%s\t%s\t%d\t%s\t",per[i].id,per[i].name,per[i].list,per[i].num,per[i].production);
			if(per[i].num < 3) {
				printf("����̫��\n");
			} else {
				printf("\n");
			}
		}
	} else
		printf("���û����Ʒ\n");
}
void seek() {
	char j[5],m=load();
	int i;
	printf("������Ҫ��ѯ�����ƣ�");
	scanf("%s",&j);
	if(m<=0)
		printf("��ǰ���ݿ�û����Ʒ��Ϣ\n");
	else
		for(i=0; i<m; i++) {
			if(strcmp(j,per[i].name)==0) {
				printf("���\t����\t���\t����\t����\n");
				printf("%s\t%s\t%s\t%d\t%s\t\n", per[i].id,per[i].name,per[i].list,per[i].num,per[i].production);
			}
		}
}
void change() {
	char m =load();
	char c[10];
	int c1;
	int i,j=0;
	if(m<=0)
		printf("��ǰ���ݿ�û������");
	else
		printf("��������Ҫ�޸���Ʒ���");
	scanf("%s",&c);
	for(i=0; i<m; i++) {
		if(strcmp(per[i].id,c)==0) {
			printf("���ҵ�����Ʒ��Ϣ����\n");
			printf("���\t����\t���\t����\t����\n");
			printf("%s\t%s\t%s\t%d\t%s\t\n", per[i].id,per[i].name,per[i].list,per[i].num,per[i].production);
			printf("���ĳ����Ϣ����Ķ�����ֱ������-");
			printf("�������Ʒ�����Ƹ�Ϊ��");
			scanf("%s",&c);
			if (strcmp(c, "-"))
				strcpy(per[i].name, c);
			printf("�������Ʒ����Ʒ����Ϊ��");
			scanf("%s", &c);
			if (strcmp(c, "-"))
				strcpy(per[i].list, c);
			printf("�������Ʒ��������Ϊ��");
			scanf("%d", &c1);
			if (strcmp(c, "-"))
				per[i].num=c1;
			printf("�������Ʒ�Ĳ��ظ�Ϊ��");
			scanf("%s", &c);
			if (strcmp(c, "-"))
				strcpy(per[i].production, c);
			save(m);
			break;
		} else
			j++;
	}
	if(j>0)
		printf("�Ҳ�������Ʒ");
}
void del() {
	char num[5],m=load();
	int i,k;
	if(m<0)
		printf("��ǰ���ݿ�û����Ʒ��Ϣ");
	else
		printf("������ɾ������Ʒ���:");
	scanf("%s",&num);
	for(i=0; i<m; i++)
		if(strcmp(per[i].id,num)==0) {
			for(k=i; k<m-1; k++) {
				per[k]=per[k+1];
			}
			m--;
			save(m);
			printf("������ɾ��");
			break;
		}
}
void jinchu() {
	char na[5],m=load();
	int yu1,i,j,k;
	jinchu_menu();
	printf("��������ţ�");
	scanf("%d", &i);
	switch(i) {
		case 1: {
			if(m<=0)
				printf("\t\t����Ϣ��Ϊ��!!!\n");
			else
				printf("������Ҫ������Ʒ��:");
			scanf("%s",&na);
			for(j=0; j<m; j++) {
				if(strcmp(na,per[j].id)==0) {
					printf("���ҵ���Ʒ��������Ҫ�۳�����Ʒ������");
					scanf("%d",&yu1);
					if(yu1 <= 0) {
						printf("�������������");
					} else if(per[i].num>=yu1) {
						per[i].num = per[i].num - yu1;
						printf("\t\t���۳ɹ�\n");
						save(m);
					} else {
						printf("��Ʒ��������");
					}
					break;
				} else
					k++;

			}
			printf("��Ʒ������\n");
			break;
		}
		case 2: {
			if(m<=0) {
				printf("\t\t����Ϣ��Ϊ��!!!\n");
			}
			printf("������Ҫ������Ʒ��:");
			scanf("%s", &na);
			for(j=0; j<m; j++) {
				if(strcmp(na,per[j].id)==0) {
					printf("���ҵ���Ʒ��������Ҫ������Ʒ������");
					scanf("%d",&yu1);
					if(yu1 <= 0) {
						printf("�������������");
					} else
						per[i].num = per[i].num + yu1;
					printf("\t\t�����ɹ�\n");
					save(m);
					break;
				} else
					printf("��Ʒ������\n");
				break;
			}
		}
	}
}

void main() {
	int i;
	char m=0;
	FILE *fp;
	m=load();
	if(m>0) {
		fp=fopen("repertory_list","r");
		fread(per,sizeof(struct repertory),m,fp);
		fclose(fp);
	}
	do {
		m = load();
		menu();
		printf("��ѡ������Ҫ��������ţ�");
		scanf("%d",&i);
		switch(i) {
			case 1:
				add_menu();
				printf("��ѡ������Ҫ��������ţ�");
				scanf("%d",&i);
				switch(i) {
					case 1:
						add();
						continue;
					case 2:
						charu();
						print();
						PRESS_ANYKEY
						continue;
					case 3:
						break;
				}
				continue;
			case 2:
				seek_menu();
				printf("��ѡ������Ҫ��������ţ�");
				scanf("%d",&i);
				switch(i) {
					case 1:
						print();
						PRESS_ANYKEY
						continue;
					case 2:
						seek();
					case 3:
						break;
				}
				continue;
			case 3:
				change_menu();
				printf("��ѡ������Ҫ��������ţ�");
				scanf("%d",&i);
				switch(i) {
					case 1:
						change();
						print();
						PRESS_ANYKEY
						continue;
					case 2:
						del();
						print();
						continue;
					case 3:
						break;
				}
				continue;
			case 4:
				jinchu();
				continue;
			case 5:
				printf("BYE BYE!\n");
				PRESS_ANYKEY
		}
		break;
	} while(1);
}

