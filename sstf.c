#include<stdio.h>
#include<stdlib.h>
#define MAX 200
int arr[7] ={82,170,43,140,24,16,190};
int min_dist,min_index,head=50,seek_time;
int n = 7;

void main(){
    int i,j;
    for(i=0;i<n;i++){
        min_dist = MAX;
        for(j=0;j<n;j++){
            if(abs(head - arr[j])<min_dist){
                min_dist = abs(head- arr[j]);
                min_index = j;
            }
        }
        seek_time+= abs(head - arr[min_index]);
        head = arr[min_index];
        printf("%d ",arr[min_index]);
        arr[min_index] = MAX;
        
        
    }
    printf("total seek time is : %d",seek_time);
}