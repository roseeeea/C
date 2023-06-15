//9/ 10/ 49/ 63/ 84

//hw10-A(Q49)---------------------------------------------
#include<stdio.h>
int x[10000];
int y[10000]; //無法開到10^9
int visited[10000]={0};

int check(int a, int b, int r){
	if((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b])<=r*r) return 1;
    else return 0;
}

int dfs(int n, int now, int r){ //index of current point 
    int res=1; //res=1 not 0
    visited[now]=1; //必須放這裡，如果放在if裡面，for迴圈跑會一直是1
	// 如果visited[i] 只有visited～run time 
    for(int i=0; i<n; i++){
        //continue 開始下一個循環
        if(visited[i]) continue; //是檢驗i不是now
    	if(check(now, i, r)==0) continue;  //find if it the neighbor 
        //是檢驗i不是now
    	res=res+dfs(n, i, r);
    }
    return res;
}

int main(void){
	int n, r;
    scanf("%d%d", &n, &r);
    for(int i=0; i<n; i++){
        scanf("%d%d", &x[i], &y[i]);
    }
    
    int k=0;
    int sng=0;
    int grp=0;
    while(k<n){
    	if(visited[k]==0){
        	int temp=dfs(n, k, r);
            if(temp==1){
            	sng++;
            }
            else grp++;
        }
        k++;
    }
    
    printf("%d %d\n", sng, grp);
    
    
}

//Q9----------------------------------
#include<stdio.h>

int x[500];
int y[500];

int check(int a, int b, int r){
	if((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b])<=r*r) return 1;
    else return 0;
}

int dfs(int now, int n, int r, int *visited){
	int res=1;
    visited[now]=1;
    //printf("now=%d\n", now);
    for(int i=0; i<n; i++){
    	if(visited[i]==1) continue;
        if(check(now, i, r)==0) continue;
        res=res+dfs(i, n, r, visited);
    }
    
    return res;
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        int visited[500]={0}; //不能用memset
        int n, r, k;
        scanf("%d%d%d", &n, &r, &k);
        //printf("%d %d %d\n", n, r, k);
        for(int i=0; i<n; i++){
            scanf("%d%d", &x[i], &y[i]);
        }

        int s=0;
        int gpa=0;
        int gpb=0;
        while(s<n){
            //printf("s=%d\n", s);
        	if(visited[s]==0){
                int temp=dfs(s, n, r, visited);
                //printf("grp: s=%d, %d\n", s, temp);
            	if(temp<k){
               	 gpa++;
            	}
           	 	else gpb++;
            }
            s++;
        }
        
        printf("%d %d\n", gpa, gpb);
    }
    
}
//Q10------------------------------
#include<stdio.h>
#include<string.h>

int mark[2000][26]={0};
int check(int now, int g){
    int flag=0;
	for(int i=0; i<26; i++){
    	if(mark[now][i]*mark[g][i]>0){ //不能用相等== 有兩個都是零
        	flag=1;
            break;
        }
    }
    return flag;
}

void dfs(int now, int n, int *visited){ // char s no *
    //printf("now=%d\n", now);
    visited[now]=1;
    for(int i=0; i<n; i++){
    	if(visited[i]==1) continue;
        if(check(now, i)==0) continue;
           dfs(i, n, visited);
    }
}

int main(void){
	int t;
    scanf("%d", &t);
    while(t--){
        int visited[2000]={0};
        char s[2000][1001];
    	int n; 
        scanf("%d", &n);
        for(int i=0; i<n; i++){
        	scanf("%s", s[i]);
            //尋找字母組合!!!!!
            for(int j=0; j<26; j++){
            	if(strchr(s[i], 'a'+j)) mark[i][j]=1;
                //strchr 搜尋字元
            }
        }
        
        
        int k=0;
        int grp=0;
        while(k<n){
        	if(visited[k]==0){
            	dfs(k, n, visited);
                grp++;
            }
            k++;
        }
        
        printf("%d\n", grp);
        memset(mark, 0, sizeof(mark));
        
    }
}
//---------------------
//Q84: http://140.114.85.195/status/43c83fd3ecd7e4b0813f442b1df0a437
