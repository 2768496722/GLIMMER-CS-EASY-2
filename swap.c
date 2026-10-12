#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;  
    *a = *b;        
    *b = temp;      
}

int main(){
    int a = 10;
    int b = 20;
    
    swap(&a, &b); 
    
    printf("交换后: a = %d, b = %d\n", a, b);
    
    return 0;
}