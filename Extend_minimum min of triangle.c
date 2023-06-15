#include<stdio.h>
#include<math.h>

int xy[(int) 1e6];

int main(void){
	int t;
    
    scanf("%d", &t);
    while(t--){
        long long ans=0; //ans position
    	int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        memset(xy, 0, sizeof(xy)); //memset
        for(int i=a; i<=b; i++){
        	xy[i+b]++;
            xy[i+c+1]--; //i+c+1
        }
        for(int i=1; i<=b+c; i++){
        	xy[i]=xy[i]+xy[i-1]; //xy[i-1]
        }
        for(int i=c; i<=b+c; i++){
        	long long int ub=(i/1.5)+1; //long long
            ans=ans+xy[i]*fmax((fmin(d, i-1)-fmax(c, ub)+1), 0); //xy[i], *2fmax
        }
        
        printf("%lld\n", ans);
        }
}
//----------------------------------------------------------
//https://acm.cs.nthu.edu.tw/problem/12494/
#include<stdio.h>

long long limit[4]={0};
long long ans=0;
long long temp[3];

void recursion(int x){
    if(x==3){
        if(temp[2]*1.5>temp[1]+temp[0]){
            ans++;
        }
        return;
    }
    else{
        if(x<2){
            for(long long i=limit[x]; i<=limit[x+1]; i++){
                    temp[x]=i;
                    recursion(x+1);
                    temp[x]=0;
            }
        }
        if(x==2){
            for(long long i=limit[x]; i<temp[1]+temp[0]; i++){
                    temp[x]=i;
                    recursion(x+1);
                    temp[x]=0;
            }
        }
    }
    
}

int main(void){
    int t;
    scanf("%d", &t);
    
    while(t--){
        for(int i=0; i<4; i++){
            scanf("%lld", &limit[i]);
        }
        
        
        recursion(0);
        
        
        printf("%lld\n", ans);
        ans=0;
        
    }
}
