//標準 search
int bs(int *arr, int len, int target){
	int l=0, r=len, m;
    while(l<r){
    	m=(l+r)/2;
        if(arr[m]<target) l=m+1;
        else if (arr[m]>target) r=m;
        else break;
    }
    return m;
}


//upperbound（不需要包含在區域內）------------------
int upperbound(int *arr, int len, int target){
  int l=0, r=len;
  while(l<r){
    int m=(l+r)/2;
    if(arr[m]>target) r=m; // >= 就是包含target本身
    else l=m+1;
  }
  return l; //l&r都沒差
}
 
//lowerbound（需要包含在區域內）------------------
int lowerbound(int *arr, int len, int target){
  int l=0, r=len, m;
    while (l != r) {
        m = (l+r)/2;
        if (arr[m]>=target) r=m;
        else l=m+1;
    }
  return m; //l&r都沒差
}

//-------------------------------------
int main(void){
    int a[7]={1, 2, 3, 7, 12, 13, 15};
    int x;
    while(scanf("%d", &x)!=EOF){
    int lowerp=lowerbound(a, 7, x);
    int upperp=upperbound(a, 7, x);
    
    printf("%d upper:%d lower:%d\n", x, a[upperp], a[lowerp]);
    }
}

---------------------------------------

//problem 37, 69, 102

//Q37---------------------------------------
#include<stdio.h>

int bs(int *arr, int len, int target){
	int l=0, r=len, m;
    while(l<r){
    	m=(l+r)/2;
        if(arr[m]<target) l=m+1;
        else if (arr[m]>target) r=m;
        else break;  //這裡沒有<=，bound 和 search 差別
    }
    return m;
}

int main(void){
	int n, t;
    int a[2000000];
    scanf("%d%d", &n, &t);
    for(int i=0; i<n; i++){
    	scanf("%d", &a[i]);
    }
    while(t--){
    	int x;
        scanf("%d", &x);
        int ans=bs(a, n, x);
        printf("%d is at index: %d \n", x, ans);
    }
}
//hw9-A------------------------------------------
/////TA
#include<stdio.h>
#include<stdlib.h>
//全部都要long long
long long a[1000000];

int lower_bound(long long *arr, long long  L, long long R, long long num){
	long long mid;
    while(L<R){
    	mid=(L+R)/2;
        if(arr[mid]>=num)R=mid; //upperbound 就是沒有等於
        else L=mid+1;
    }
    
    return R; //若數值不存在此陣列，Ｒ＝Ｒ
}12

int main(void){
    long long n, k, q;
    scanf("%lld%lld%lld", &n, &k, &q);
	for(int i=0; i<n; i++){
    	scanf("%lld", &a[(i+(n-k))%n]); //shift，兩個括弧
    }
    while(q--){
    	long long f;
    	scanf("%lld", &f);
        long long a1=lower_bound(&a, 0, (n-k), f); //a1 must >a2
        long long  a2=lower_bound(&a, (n-k), n, f);
        //printf("a1=%d\n", a1);
        //printf("a2=%d\n", a2);
        if(a1 ==(n-k)){ //Ｒ＝Ｒ
        	printf("gan ni nya sai bau\n");
        }
        else if(a2==n){ //a2的最邊邊（算不存在）
        	printf("%lld\n", a1+1);
        }
        else{
        	if((a[a1]-f)<=(a[a2]-f)){  //不能用abs
            	printf("%lld\n", a1+1);
            }
            else{
            	printf("%lld\n", a2+1);
            }
            
        }
    
    }

}
//hw8-C(102)---------------------------------------------------
#include<stdio.h>

long long n;
long long a[100000];

int cmp(void const *A, void const *B){
    long long AA= *(long long *)A, BB= *(long long *)B; //*一個在外面
    return AA-BB;
}

long long upperbound(int goal){
	long long L=0, R=n;
    long long m;
    while(L<R){
    	m=(L+R)/2;
        if(a[m]>goal) R=m;
        else L=m+1;
    }
    
    return R;
}

long long lowerbound(int goal){
	long long L=0, R=n;
    long long m;
    while(L<R){
    	m=(L+R)/2;
        if(a[m]>=goal) R=m;
        else L=m+1;
    }
    
    return R;
}

int main(void){
	scanf("%lld", &n);
    for(int i=0; i<n; i++){
    	scanf("%lld", &a[i]);
    }
    
    qsort(a, n, sizeof(a[0]), cmp);
    
    int q;
    scanf("%d", &q);
    while(q--){
    	long long x;
        scanf("%d", &x);
        long long lp=lowerbound(x);
        long long up=upperbound(x);
        long long ans= up-lp;
        printf("%lld\n", ans);
    }
}

