#include<stdio.h>

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
