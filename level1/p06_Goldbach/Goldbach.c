#include<stdio.h>
#include<stdbool.h>
#define SIZE 30
int main(){
	int a,i,n=0;
	int ch[SIZE]; 
	bool isp=true,ispp=false;
	
	for(a=2;a<101;a++){
	    for(i=2;i<a/2+1;i++){
		    if(a%i==0){
			    isp=false;
			    break;
		    }
	    }
	
		if(isp){
			ch[n++]=a;
		}
		isp=true;
    }

	printf("����2-100���ڵ�ż������֤���ϸ�°ͺղ���\n");
	int f;
	scanf("%d",&f);
	int c,d,e=0;
    for(c=0;c<n;c++){
    	for(d=0;d<=c;d++){
    		if(f==ch[c]+ch[d]){
    			printf("%d = %d + %d\n",f,ch[c],ch[d]);
    			ispp=true;
			}
		}
	}
    if(!ispp)
        printf("%d �����ϸ�°ͺղ���\n",f);
	
	return 0;
} 
