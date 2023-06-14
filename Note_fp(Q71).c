#include<stdio.h>

int main(void){
	float x;
    while(scanf("%f", &x)!=EOF){
        unsigned int y= *(int *)(&x); //二進位取出
        for(int i=31; i>=0; i--){
            if(((1<<i)&y)!=0)printf("1");
        	else printf("0");
    	}
        printf("\n");
    }
}
