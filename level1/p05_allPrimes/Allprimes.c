#include<stdio.h>
#include<stdbool.h>
int main(){
	int a,i;
	bool isp=true;
	
	for(a=2;a<1001;a++){
        int n;
	    for(i=2;i<a/2+1;i++){
		    if(a%i==0){
			    isp=false;
			    break;
		    }
	    }
	
		if(isp){
			printf("%5d",a);
			if(++n%5==0){
				putchar('\n'); 
			}
		}
		isp=true;
    }
	
	return 0;
} 
