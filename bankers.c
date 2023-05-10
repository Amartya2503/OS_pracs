#include<stdio.h>

int main(){

    int i,j,k;
    int n=5,m=3,ans[n];
    int avail[3]={3,3,2};
    int allocated[5][3] ={{ 0, 1, 0 },
                          { 2, 0, 0 },
                          { 3, 0, 2 },
                          { 2, 1, 1 },
                          { 0, 0, 2 }};
    int max[5][3] = { {7, 5, 3 },
                    { 3, 2, 2 },
                    { 9, 0, 2 },
                    { 2, 2, 2 },
                    { 4, 3, 3 } };
    int needed[5][3];
    int flag,f[n];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            needed[i][j] = max[i][j] - allocated[i][j];
        }
    }
    for(i=0 ; i<n ; i++){
        f[i] = 0;
    }
    int y = 0,ind = 0;
    int count =0;
    // for(i=0; i<n; i++){

    // }
    for(k=0;k<=n;k++){
        // printf("parent ->");
        for(i=0; i<n ; i++){
            // printf(" here\t");
            if(f[i] == 0){      //f[i] if 1 means already terminated the ith process 
                flag = 0;
                for(y=0; y<m ; y++){
                    if(needed[i][y] > avail[y]){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    ans[ind++] = i;
                    count +=1;
                    f[i] = 1;
                    // printf("processed\t");
                    for(j=0 ; j<m ; j++){
                        avail[j] += allocated[i][j]; 
                    }

                }
            }
        }
    }
    flag = 1;
    for(i=0 ; i<n; i++){
        if(f[i]== 0){
            flag = 0;
            printf("the safe sequense not generated");
        }
        
    }
    if(flag ==1){
        printf("safe sequence generated:\n");
        for(i=0;i<n;i++){
            printf(" P%d-> ",ans[i]);
        }
    }
    return 0;
}