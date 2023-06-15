//hw12-B(Q45)---------------------------
#include<stdio.h>

int cmp(const void *A, const void *B){
	long long AA= *(long long *) A, BB=*(long long *)B;
    return AA-BB;
}


int main(void){
	int t;
    scanf("%d", &t);
    while(t--){
        long long ans=0;
    	long long n, p, k;
        long long a[300002]={0};//陣列大小300002
        long long q[300002]={0};
        long long exp[300002]={0}; 
        //買到第i個（包含前面）要花的錢（prefixsum）
        
        
        scanf("%lld%lld%lld", &n, &p, &k);
        for(int i=1; i<=n; i++){ //<=n 包含
        	scanf("%lld", &a[i]);
        }
        
        qsort(a+1, n, sizeof(a[0]), cmp); //a+1很重要
	    ////到n!!!!!!(a+1後個)
        
       //計算買幾個多少錢，不管p
        for(int i=1; i<=n; i++){ //<=n 包含
        	if(i<k){
            	exp[i]=exp[i-1]+a[i];
                //q[i]=i;
            }
            else{
            	exp[i]=exp[i-k]+a[i];
                //q[i]=k+q[i-k];
            }
        }
        
        for(int i=1; i<=n; i++){ //<=n 包含
        	if(p>=exp[i]){
                //ans=i;
                if(ans<i){
                    ans=i;
                }
            }
        }
        
        //printf("ans=%lld, q[%d]=%d \n", ans, ans, q[ans]);
        //q==i???
        printf("%lld\n", ans);
    }
        
}

//hw9-B(Q47)--------------------------------
#include<stdio.h>

int main(void){
	int n, k;
    int a[100000];
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++){
    	scanf("%d", &a[i]);
    }
    
    int flag=1;
    int energy=k;
    int checkpoint=0;
    for(int i=0; i<n; i++){
    	if(a[i]>energy){
            if(i>0){
                checkpoint=checkpoint+1;
                energy=a[i-1]+k;
                if(a[i]>energy){
                    flag=0;
                    break;
            	}
            }
            else{
            	flag=0; 
                break;
            }
        }
    }
    
    if(flag==1){
    	printf("%d\n", checkpoint);
    }
    else{
    	printf("The Legend Falls.\n");
    }
}
//hw8-b-------------------------------------
#include<stdio.h>

int min[1000]; //INT_MAX=(1ll<<31)-1
int max[1000]={0}; //INT_MIN=-(1ll<<31)

int main(void){
    int n;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
    	min[i]=50000;
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int temp;
     		scanf("%d", &temp);
            //printf("temp=%d\n", temp);
            if(max[i]<=temp){
            	max[i]=temp;
            }
            //printf("min[%d]=%d\n", j, min[j]);
            if(min[j]>=temp){
            	min[j]=temp;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        if(i!=n-1){
    		printf("%d ", max[i]);
        }
        else{
        	printf("%d\n", max[i]);
        }
    }
    
    for(int i=0; i<n; i++){
        if(i!=n-1){
    		printf("%d ", min[i]);
        }
        else{
        	printf("%d\n", min[i]);
        }
    }
	
}
