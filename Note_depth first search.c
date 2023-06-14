

//hw10-A---------------------------------------------
#include<stdio.h>
int x[10000];
int y[10000]; //無法開到10^9
int visited[10000]={0};

int check(int a, int b, int r){
	if((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b])<=r*r) return 1;
    else return 0;
}

int dfs(int n, int now, int r){ //index of current point 
    int res=1;
    visited[now]=1; //必須放這裡，如果放在if裡面，for迴圈跑會一直是1
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
