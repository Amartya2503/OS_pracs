



// #include <stdio.h>
// int main()
// {
//     int n, m, i, j, k;
//     n = 5;
//     m = 3;
//     int alloc[5][3] = { { 0, 1, 0 },
//                         { 2, 0, 0 },
//                         { 3, 0, 2 },
//                         { 2, 1, 1 },
//                         { 0, 0, 2 } };
//     int max[5][3] = { {7, 5, 3 },
//                     { 3, 2, 2 },
//                     { 9, 0, 2 },
//                     { 2, 2, 2 },
//                     { 4, 3, 3 } };

//     int avail[3] = { 3, 3, 2 };
//     int f[n], ans[n], ind = 0;
//     for (k = 0; k < n; k++) {
//         f[k] = 0;
//     }
//     int need[n][m];
//     for (i = 0; i < n; i++) {
//         for (j = 0; j < m; j++)
//             need[i][j] = max[i][j] - alloc[i][j];
//     }
//     int y = 0;
//     //f[i] if 1 means already terminated the ith process 
//     for (k = 0; k < 5; k++) {
//         for (i = 0; i < n; i++) {
//             if (f[i] == 0) {
//                 int flag = 0;
//                 for (j = 0; j < m; j++) {
//                     if (need[i][j] > avail[j]){
//                         flag = 1;
//                         break;
//                     }
//                 }
//                 if (flag == 0) {
//                     ans[ind++] = i;
//                     for (y = 0; y < m; y++)
//                         avail[y] += alloc[i][y];
//                     f[i] = 1;
//                 }
//             }
//         }
//     }
//     int flag = 1; 
//     for(int i=0;i<n;i++)
//     {
//         if(f[i]==0)
//         {
//             flag=0;
//             printf("The following system is not safe");
//             break;
//         }
//     } 
//     if(flag==1)
//     {
//         printf("Following is the SAFE Sequence\n");
//         for (i = 0; i < n - 1; i++)
//             printf(" P%d ->", ans[i]);
//         printf(" P%d", ans[n - 1]);
//     } 
//     return (0);
// }

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool search(int key, vector<int>& fr){
    for(int i = 0 ; i<fr.size(); i++){
        if(fr[i] == key){
            return true;
        }
    }
    return false;
}

int predict(int pg[],vector<int>& fr, int pn, int index){
    int farthest = index, res =-1,j;
    for(int i = 0; i<fr.size(); i++){
        for(j =index ; j<pn; j++){
            if(fr[i] == pg[j]){
                if(j>farthest){
                    res = i;
                    farthest = j;
                }
                break;                
            }
        }
        if(j == pn){
            return i;
        }
    }
    return (res == -1)? 0 : res;
}

void optimalPage(int pn, int pg[],int fn ){
    vector<int> fr;
    int hit,i;
    for(i=0 ; i<pn ; i++){

        if(search(pg[i], fr)){
            hit += 1;
            continue;
        }
        if(fr.size() < fn){
            fr.push_back(pg[i]);
        }
        else{
            int j = predict(pg,fr,pn,i+1);
            fr[j] = pg[i];
        }

    }
    cout<<"the number of hits is "<<hit<<endl;
    cout<<"the number of faults is "<<pn - hit<<endl;
    
}
int main()
{
 int pg[] = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2 };
 int pn = sizeof(pg) / sizeof(pg[0]);
 int fn = 4;
 optimalPage(pn , pg, fn);
 return 0;
}


































