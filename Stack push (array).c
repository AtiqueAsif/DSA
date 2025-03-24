//insert and display in a stack

#include<stdio.h>
int maxSize = 8;
int stack [8];
int top = -1;

int isfull(){
    if (top == maxSize - 1){
        return 1;
    }
    else{
        return 0;
    }
}

int push(int data){
    if(! isfull()){
        top = top + 1;
        stack[top] = data;
    }
    else{
        printf("Stack is full!!!\n");
    }
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);

    printf("Elements are: \n");

    for(int i = 0; i <= top; i++){
        printf("%d ", stack[i]);
    }

}




