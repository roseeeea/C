//hw12-A------------------------------------------------
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
        
        
          for(int i=A+B; i<=B+C+1; i++){
        	num[i]=num[i]+num[i-1]; //prefixsum
	  }
        
        for(int z=C; z<=D; z++){
        	
            if(B+C>i){ // x+y的最大值是否大於 i(z)最小值 
                ans=ans+num[B+C]-num[i];
                //加起來（B+C）以前 的數量減掉未達或等於第三邊的量
            }
            /*
            //這樣runtime
            for(int k=A+B; k<=B+C; k++){
            	if(z<k){
                	ans=ans+num[k];
                }
            }
            */
        }
        
        printf("%lld\n", ans);
        
    }
}

// hw12-A redo ---------------------------------------------------
#include<stdio.h>

int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        //全部 long long
		long long  A, B, C, D;
        long long ans=0;
        long long f[200000]={0}; //要開到200000(4*5*10^4)
        scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
        
        for(int i=A; i<=B; i++){
        	f[i+B]++;
            f[i+C+1]--;
        }
        for(int i=A+B; i<=B+C+1; i++){
        	f[i]=f[i]+f[i-1];
        }
        for(int i=A+B; i<=B+C+1; i++){
        	f[i]=f[i]+f[i-1];
        }
        for(int i=C; i<=D; i++){
            if(B+C>i){ //in this condition!!!! B+C>i
        		ans=ans+f[B+C]-f[i];
            }
        }
        
        printf("%lld\n", ans);
        
    }
    
    
}

//extend--------------------------------------------------
#include<stdio.h>
#include<string.h>
#include<math.h>
long long int xy[(int)1e6];
int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c,d;
        long long int ans=0;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        memset(xy,0,sizeof(xy));
        for(int i=a;i<=b;i++)
        {
            xy[i+b]++;
            xy[i+c+1]--;
        }
        for(int i=1;i<=b+c;i++)
        {
            xy[i]+=xy[i-1];
        }
        for(int i=c;i<=b+c;i++)
        {
            long long int ub=i/1.5+1;
            ans+=xy[i]*fmax((fmin(d,i-1)-fmax(c,ub)+1),0);
        }
        printf("%lld\n",ans);
    }
}
