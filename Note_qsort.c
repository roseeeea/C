// qsort(arr, numberofstuff, sizeof(arr[0]), cmp);
/*
int cmp(void const * A, void const *B){
  (struct) AA= *(struct *) A, BB=*(struct *) B;
  return AA-BB //升冪
  // return BB-AA //降冪
}
*/

//hw12-B-----------------------------
#include<stdio.h>

typedef struct _Price{
	long a;
    long b;
    long gap; //要long long
} price;

int cmp(const void *A, const void *B){
	price AA=*(price *)A, BB=*(price *)B;
    	return (BB.gap-AA.gap); 
}

int main(void){
	int n, k;
    price goods[100000];
    scanf("%d%d",&n, &k);
    for(int i=0; i<n; i++){
    	scanf("%lld", &goods[i].a);
    }
    for(int i=0; i<n; i++){
    	scanf("%lld", &goods[i].b);
        goods[i].gap=goods[i].b-goods[i].a;
    }
    
    qsort(goods, n, sizeof(goods[0]), cmp); //用落差去排
    
    long long ans=0;
    
    for(int i=0; i<k; i++){
    	ans=ans+goods[i].a;
    }
    for(int i=k; i<n; i++){
    	if(goods[i].gap>0){
        	ans=ans+goods[i].a; //ans<10*5*n 需要long long
        }
        else if(goods[i].gap<0){
        	ans=ans+goods[i].b;
        }
    }
    
    printf("%lld\n", ans);
    
    
    
}

//hw11-A(34)---------------------------------------
#include<stdio.h>
#include<string.h>


int flag2=1;  //數量重複但相同者是成功！！！

typedef struct _Str{
	char s[1001];
    int len; //不能在struc 中直接計算長度
} Str;

int cmp(const void *a, const void *b){
	Str A=*(Str *)a, B=*(Str *)b; //記得轉換型態
    //if(A.len==B.len) flag2=0; //紀錄flag2
    return A.len-B.len;
}

int main(void){
	Str a[1000];
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
    	scanf("%s", a[i].s);
        a[i].len=strlen(a[i].s);
    }
    qsort(a, n, sizeof(a[0]), cmp);
    
    //check Y/N
    int flag=1;
    for(int i=1; i<n; i++){
		//strstr 用來比對子字串(a[i-1]), 
		//被搜尋（比較長） a[i].s
        if(strstr(a[i].s, a[i-1].s) == NULL){
        	flag=0;
            break;
        }
   	}
    
    if(flag==1 && flag2==1){
    	printf("YES\n");
        for(int i=0; i<n; i++){
        	printf("%s\n", a[i].s);
        }
    }
    else printf("NO\n");
    
}

//hw10-B-------------------------------------------
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//how to determine its MSB 
// 10^999

int cmp(const void *a, const *b){
	char ab[2000], ba[2000];
    strcpy(ab, (char*)a);
    strcpy(ba, (char*)b); //連起來看誰比較大
    strcat(ab, (char*)b);
    strcat(ba, (char*)a);
    return strcmp(ba, ab);  //strcmp=1~ba>ab; =-1~ab>ba 
    //a-b a放在b前面
}

int main(void){
	int n;
    
    while(scanf("%d", &n)!=EOF){
        char str[101][1001];
        for(int i=0; i<n; i++){
        	scanf("%s", str[i]);
        }
    	qsort(str, n, sizeof(str[0]), cmp); 
		//=1~升冪; =-1～降冪
		//str是二維char陣列
        for(int i=0; i<n; i++){
        	printf("%s", str[i]);
        }
        printf("\n");
        
    }


}

//hw10-C----------------------------------------------
#include<stdio.h>
#include<stdlib.h>


//typedef 讓struct point 可以簡化成 point 
typedef struct _Point //要空格底限
{
	double l;
    double r;
} Point; //initialize typedef

/*
空間是所有的裡面宣告的綜合
Point p;
p.l;
p.r;

Point *p; 指標，指標固定64bits
*/


int cmp(const void *A, const void *B){
    Point a=*(Point *)A, b=*(Point *)B;
	if(a.l<b.l) return -1;  //注意a.l
    else if (a.l>b.l) return 1;
    else{
    	if(a.r>b.r) return 1;
        else if(a.r<b.r) return -1;
        else return 0;
    }
}



int main(void){
    //sort L ~ 得到起始點遞增, 比對前一段的R和後一段到Ｌ; R>L 重疊
    int t;
    scanf("%d", &t);
    while(t--){
		int n, q;
        Point a[100000]; //尺寸注意, ＠如果a[q]會runtime(?)
        scanf("%d%d", &n, &q);
        for(int i=0; i<q; i++){
        	scanf("%lf%lf", &a[i].l, &a[i].r);
        }
        
        qsort(a, q, sizeof(a[0]), cmp); 
        //sizeof 中 a[0]改Point~不影響
        //只需要第一個大小，**是q不是n
    	double sum=0, L=a[0].l, R=a[0].r;
        
        //for(int i=0; i<q; i++){
        //	printf("%lf %lf\n", a[i].l, a[i].r);
        //}
        
        for(int i=1; i<q; i++){
        	if(a[i].l<=a[i-1].r && a[i].r>=a[i-1].r){
                /*
                考慮以下情況，不成立：
                i   ------
               i-1 --------------
                */
            	R=a[i].r;
            }
            if(a[i].l>a[i-1].r){
            	sum=sum+(R-L);
                L=a[i].l;
                R=a[i].r;
            }
            
            
            if(i==q-1){ //記得最後一個也要考慮
            	sum=sum+(R-L);
            }
            
        }
        
        
        
        double ans=(n-sum)/n;
        printf("%lf\n", ans);
    }
}


