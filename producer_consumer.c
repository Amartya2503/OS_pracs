#include<stdio.h>
#include <stdlib.h>
int mutex = 1,full = 0,empty=3,x=0;

int signal(int s){
    return ++s;
}
int wait(int w){
    return --w;
}

void producer(){
    mutex= wait(mutex);
    x++;
    full = signal(full);
    empty = wait(empty);
    mutex = signal(mutex);

}
void consumer(){
    mutex= wait(mutex);
    x--;
    full = wait(full);
    empty = signal(empty);
    mutex = signal(mutex);
}

int main(){
    int i,j,n;
    while(1){
        printf("enter 1). Produce 2.Consume 3. Exit ");
        scanf("%d",&n);
        switch(n){
            case 1:
                if(empty != 0 && mutex == 1){
                    producer();
                }
                else{
                    printf("buffer is full");
                }
                break;
            case 2:
                if(mutex == 1 && full != 0){
                    consumer();
                }
                else{
                    printf("buffer is empty");

                }
                break;
            case 3:
                exit(0);
                break;

        }
    }
    return 0;
}