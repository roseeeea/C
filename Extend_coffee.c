#include<stdio.h>

long long coffee[(int)1e6];
int n, q;

int cmp(void const *A, void const *B){
	long long AA=*(long long *)A, BB=*(long long *) B;
    return BB-AA;
}

long long day(long long d){ //long long d not int 
	 long long int code=0; //long long
    for(int i=0; i<d; i++){
    	code=code+coffee[i];
    }
    int count=0, minus=1;
    for(int i=d; i<n; i++){
        count ++;
    	if(coffee[i]>minus){
        	code=code+coffee[i]-minus;
        }
        else{
        	break;
        }
        if(count==d){
        	count=0;
            minus++;
        }
    }
    
    return code;
}

int main(void){
	int t;
    scanf("%d", &t);
    while(t--){
        memset(coffee, 0, sizeof(coffee)); 
        scanf("%d%d", &n, &q);
        for(int i=0; i<n; i++){
        	scanf("%lld", &coffee[i]);
        }
        qsort(coffee, n, sizeof(coffee[0]), cmp);
        
        int l=1, r=n+1, m;
        long long ans=-1; //ans need to be -1
        while(l<r){
        	m=(l+r)/2;
            if(day(m)>q){
            	r=m;
                ans=m;
            }
            else{
            	l=m+1;
            }
        }
        printf("%lld\n", ans); //lld
    }
}
