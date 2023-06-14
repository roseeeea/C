//hw12-A
#include<stdio.h>
//f(i)={num of (x+y=i)}
//prefixsum

int main(void){
	int t;
    long long num[200000];
    
    scanf("%d", &t);
    
    while(t--){
        long long A, B, C, D;
        memset(num, 0, sizeof(num)); //重新初始化
        long long ans=0;
    	
        scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
        
        for(int i=A; i<=B; i++){ //差值，num of x+y=i概念
        	num[i+B]++; //x fixed 最小值
            num[i+C+1]--; //x fixed y最大值 加一
        }
        
        for(int i=A+B; i<=B+C+1; i++){
        	num[i]=num[i]+num[i-1]; //prefixsum
        }
        
        /*
          for(int i=A+B; i<=B+C+1; i++){
        	num[i]=num[i]+num[i-1]; //prefixsum
        }
        */
        
        for(int z=C; z<=D; z++){
        	/*
            if(B+C>i){ // x+y的最大值是否大於 i(z)最小值 
                ans=ans+num[B+C]-num[i];
                //加起來（B+C）以前 的數量減掉未達或等於第三邊的量
            }
            */
            //這樣runtime
            for(int k=A+B; k<=B+C; k++){
            	if(z<k){
                	ans=ans+num[k];
                }
            }
            
        }
        
        printf("%lld\n", ans);
        
    }
}
