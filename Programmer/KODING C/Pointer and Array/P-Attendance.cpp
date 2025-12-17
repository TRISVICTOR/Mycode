#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n); 

    int a[n][n]; 
    int team[n+1];  
    

    for(int i=0;i<=n;i++){
        team[i]=0;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]!=0){  
                team[a[i][j]]++;  
            }
        }
    }

    int count =0;
    for(int i=1;i<=n;i++){
        if(team[i]<n) {
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}
