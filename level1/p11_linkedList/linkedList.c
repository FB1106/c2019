#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
 
//���������� 
typedef struct Node {
    ElemType data;              
    struct Node *next;        
}Node,*LinkedList;
 
 
//������ĳ�ʼ��
 
LinkedList LinkedListInit() {
    Node *L;
    L = (Node *)malloc(sizeof(Node)); 
    if(L == NULL) { 
        printf("�����ڴ�ռ�ʧ��\n");
    }
    L->next = NULL;                  
 	return L;
}
 
 
//������Ľ���1��ͷ�巨����������
 
LinkedList LinkedListCreatH() {
    Node *L;
    L = (Node *)malloc(sizeof(Node));  
    L->next = NULL;                    
     
    ElemType x;                         
    while(scanf("%d",&x) != EOF) {
        Node *p;
        p = (Node *)malloc(sizeof(Node));  
        p->data = x;                     
        p->next = L->next;                    
        L->next = p; 
    }
    return L; 
} 
 
 
//������Ĳ��룬������ĵ�i��λ�ò���x��Ԫ��
 
LinkedList LinkedListInsert(LinkedList L,int i,ElemType x) {
    Node *pre;                     
    pre = L;
    int tempi = 0;
    for (tempi = 1; tempi < i; tempi++) {
    	pre = pre->next;                
	}
    Node *p;                                
    p = (Node *)malloc(sizeof(Node));
    p->data = x; 
    p->next = pre->next;
    pre->next = p;
     
    return L;                           
} 
 
 
//�������ɾ������������ɾ��ֵΪx��Ԫ��
 
LinkedList LinkedListDelete(LinkedList L,ElemType x)
{
    Node *p,*pre;                  
    p = L->next;
    while(p->data != x) {            
        pre = p; 
        p = p->next;
    }
    pre->next = p->next;         
    free(p);
    return L;
} 


//������ת 

 LinkedList reverseList(LinkedList head){
 
    Node *pre = NULL;
    Node *next = NULL;

    while (head != NULL) {

        next = head->next;

        head->next = pre;

        pre = head;

        head = next;
    }

    return pre;
}
 
 
int main() {
    LinkedList list,start;
 	printf("�����뵥��������ݣ�"); 
    list = LinkedListCreatH();
    for(start = list->next; start != NULL; start = start->next) {
    	printf("%d ",start->data);
	}
    printf("\n");
    int i;
    ElemType x;
    printf("������������ݵ�λ�ã�");
    scanf("%d",&i);
    printf("������������ݵ�ֵ��");
    scanf("%d",&x);
    LinkedListInsert(list,i,x);
    for(start = list->next; start != NULL; start = start->next) {
    	printf("%d ",start->data);
	}
    printf("\n");
    printf("������Ҫɾ����Ԫ�ص�ֵ��");
    scanf("%d",&x);
    LinkedListDelete(list,x); 
    for(start = list->next; start != NULL; start = start->next) {
    	printf("%d ",start->data);
	}
	//��ת���� 
	reverseList(list);
	
    printf("\n");
     
    return 0;
}

