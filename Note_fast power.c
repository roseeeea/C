//fast power 快速冪
long long fpw(long x, long y){ //x是底數 y是次方
  if(y==0) return 1;
  long long tmp= fpw(x, y/2);
  if(y%2==1) return tmp*tmp*x;
  else return tmp*tmp;
  //要注意是否需要mod
}

//_________________________________________
//矩陣思考：馬卡夫矩陣
/*
| 0 1 0 |   |p(n-2)|. |p(n-1)|
| 0 0 1 | * |p(n-1)|=.|p(n)  |
| 1 2 1 |   |p(n). |. |p(n+1)|
multiply from start~
| 0 1 0 |^(x-3)   |p(1)|  |p(x-2)|
| 0 0 1 |       * |p(2)|= |p(x-1)|
| 1 2 1 |         |p(3)|  |p(x)  |
and therefore can use fast power
*/
//___________________________________________
//Matrix fast power
typdef struct _Matirx //矩陣
{
  long long mat[3][3];
}Matrix;

Matrix identity; 
identity.mat[0]={1, 0, 0};
identity.mat[1]={1, 1, 0};
identity.mat[2]={0, 0, 1};

Matrix matrix_mul(Matrix L, Matrix R){ 
  //用matrix這個型態宣告一個function
  //return L(ij) * R(jk);~ sigma to j(Lij*Rjk)=Aik
 
  Matrix res;
  memset(res.mat, 0, sizeof(res.mat)); 
  //初始化內從，將res,mat(void * s)內sizeof(res.mat)個單位（int n）替換成(0)(int c)
  //# include <string.h>: void *memset(void *s, int c, unsigned long n);
  
  for(int i=0;i<3; i++){
    for(int k=0; k<3; k++){
      for(int j=0; j<3; j++){
          res,mat[i][k]=(res.mat[i][k]+(L.mat[i][j]*R.mat[j][k])%mod)%mod;
      }}}
   return res;
}  


long long fpw(Matrix x, long long y){ //x是底數 y是次方
  if(y==0) return identity;
  long long tmp= fpw(x, y/2);
  if(y%2==1) return matrix_mul(matrix_mul(tmp, tmp), x); //tmp*tmp*x
  else return matrix_mul(tmp, tmp);
}

//______________________________________________________
//hw11-C
#include<stdio.h>
#include<string.h>

long long mod = 1e9+7; //科學記號是double, define mod 會double
//Matrix fast power
typedef struct _Matirx //矩陣
{
  long long mat[3][3];
}Matrix;

Matrix identity; 
Matrix k; 

Matrix matrix_mul(Matrix L, Matrix R){ 
  //用matrix這個型態宣告一個function
  //return L(ij) * R(jk);~ sigma to j(Lij*Rjk)=Aik
 
  Matrix res;
  memset(res.mat, 0, sizeof(res.mat)); 
  //初始化內從，將res,mat(void * s)內sizeof(res.mat)個單位（int n）替換成(0)(int c)
  //# include <string.h>: void *memset(void *s, int c, unsigned long n);
  
  for(int i=0;i<3; i++){
    for(int k=0; k<3; k++){
      for(int j=0; j<3; j++){
          res.mat[i][k]=(res.mat[i][k]%mod+(L.mat[i][j]*R.mat[j][k])%mod)%mod;
      }}}
   return res;
}  

Matrix fpw(Matrix x, long long y){ //x是底數 y是次方
  if(y==0) return identity;
  Matrix tmp = fpw(x, y/2);
  if(y%2==1) return matrix_mul(matrix_mul(tmp, tmp), x); //tmp*tmp*x
  else return matrix_mul(tmp, tmp);
}

int main(void){
    //matrix 初始化不能放在全域，並且需要一個一個assign
identity.mat[0][0]=1;
identity.mat[0][1]=0;
identity.mat[0][2]=0;
identity.mat[1][0]=0;
identity.mat[1][1]=1;
identity.mat[1][2]=0;
identity.mat[2][0]=0;
identity.mat[2][1]=0;
identity.mat[2][2]=1;

k.mat[0][0]=0;
k.mat[0][1]=1;
k.mat[0][2]=0;
k.mat[1][0]=0;
k.mat[1][1]=0;
k.mat[1][2]=1;
k.mat[2][0]=1;
k.mat[2][1]=2;
k.mat[2][2]=1;

	int t;
    scanf("%d", &t);
    while(t--){
        long long ans;
    	long long n;
        scanf("%lld", &n);
        if(n<=3){ //注意n<=3
            if(n==1) ans=1;
            if(n==2) ans=12;
            if(n==3) ans=13;
        }
        else{
            Matrix ansmatrix;
            ansmatrix=fpw(k, n-3);
            ans= ((ansmatrix.mat[2][0]*1)%mod+(ansmatrix.mat[2][1]*12)%mod+(ansmatrix.mat[2][2]*13)%mod)%mod;
        }
        printf("%lld\n", ans);
    }
}

//hw11-c redo-----------------------------------------------------------
#include<stdio.h>

long long mod=1e9+7;

typedef struct _Matrix{
	long long mat[3][3];
}matrix;

matrix identity;

matrix base;


matrix mul(matrix a, matrix b){
    matrix res;
    memset(res.mat, 0, sizeof(res.mat));
    //important!!!! 
    //res.mat not just res
	for(int i=0; i<3; i++){
    	for(int j=0; j<3; j++){
        	for(int k=0; k<3; k++){
            	res.mat[i][k]=(res.mat[i][k]%mod+(a.mat[i][j]*b.mat[j][k])%mod)%mod;
            }
        }
    }
    
    return res;
}

matrix fps(long long x){
	if(x==0){
    	return identity;
    }
    else{
        matrix temp=fps(x/2);
    	if(x%2) return mul(mul(temp, temp), base);
        else return mul(temp, temp);
    }
}

int main(void){
identity.mat[0][0]=1;
identity.mat[0][1]=0;
identity.mat[0][2]=0;
identity.mat[1][0]=0;
identity.mat[1][1]=1;
identity.mat[1][2]=0;
identity.mat[2][0]=0;
identity.mat[2][1]=0;
identity.mat[2][2]=1;
    
base.mat[0][0]=1;
base.mat[0][1]=2;
base.mat[0][2]=1;
base.mat[1][0]=1;
base.mat[1][1]=0;
base.mat[1][2]=0;
base.mat[2][0]=0;
base.mat[2][1]=1;
base.mat[2][2]=0;
    
	int t;
    scanf("%d", &t);
    while(t--){
    	long long x;
        long long ans=0;
        scanf("%lld", &x);
        if(x>3){
        	matrix amat=fps(x-3);
            ans=(amat.mat[0][0]*13%mod+amat.mat[0][1]*12%mod+amat.mat[0][2]*1%mod)%mod; 
            //這裡也要mod!!!!!!
        }
        else{
            if(x==1) ans=1;
            if(x==2) ans=12;
            if(x==3) ans=13;
        }
        
        printf("%lld\n", ans);
    }
}

//______________________________________________________________________
//hw12-c
#include<stdio.h>
#include<string.h>

long long mod=1e9+7;

typedef struct _Matrix{
	long long mat[2][2];
}matrix;

matrix mul(matrix a, matrix b){
    matrix r;
    memset(r.mat, 0, sizeof(r.mat)); //一定要初始化，不然數字會是亂數
	for(int i=0; i<2; i++){
    	for(int j=0; j<2; j++){
        	for(int k=0; k<2; k++){
            	r.mat[i][k]=(r.mat[i][k]%mod+a.mat[i][j]*b.mat[j][k]%mod)%mod;
            }
        }
    }
    return r;
}

matrix identity;
matrix base;

matrix fps(long long x){
	if(x==0){
    	return identity;
    }
    else{
    	matrix temp=fps(x/2);
        if(x%2==1) return mul(mul(temp, temp), base);
        else return mul(temp, temp);
    }
}

int main(void){
    identity.mat[0][0]=1;
    identity.mat[0][1]=0;
    identity.mat[1][0]=0;
    identity.mat[1][1]=1;
    
    base.mat[0][0]=1;
    base.mat[0][1]=1;
    base.mat[1][0]=1;
    base.mat[1][1]=0;
    
	long long x;
    while(scanf("%lld", &x) != EOF){
        
        
        if(x<=2){
        	printf("%d\n", 1);
        }
        else{
            matrix mans=fps(x-2); //前兩項是1
            long long ans=(mans.mat[0][0]*1%mod+mans.mat[0][1]*1%mod)%mod;
            printf("%lld\n", ans);
        }
    }
}

//hw8-a---------------------------
#include<stdio.h>

long long fp(long long x, long long y, long long m){
	if(y==0){
    	return 1%m; //m也可能是1
    }
    long long temp=fp(x, y/2, m);
    if(y%2==0){
    	return temp*temp%m; 
    }
    else{
    return ((temp*temp)%m*x)%m; //m兩個
    }
}

int main(void){
	long long x, y, m;
    scanf("%lld%lld%lld", &x, &y, &m);
    long long ans=fp(x%m, y, m);  //x若為10^8會爆
    if(ans<0){
    	ans=ans+m;
    }
    printf("%d\n", ans);
    
}



  
  
  
  
  
  
  
  
  
  
