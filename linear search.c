#include<stdio.h>
int main(){
    int i,n,search;

    printf("Enter the value of n: ");
    scanf("%d",&n);

    int a[n];

    printf("Enter the array\n");
    for(i=0; i<n; i++){
        scanf("%d",&a[i]);
    }

     printf("The array\n");
    for(i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");

    printf("Enter the number to find\n");
    scanf("%d",&search);


    for(i=0; i<n; i++){
            if(a[i] == search){
                printf("%d found at the index: %d\n", a[i],i);
                break;
            }
    }
            if(a[i] != search){
                printf("Not found\n");
            }


       return 0;


}



