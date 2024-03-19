# include<stdio.h>
# include"heap.h"

int main() {

    use_heap();
    printf("MetaList :\n");
    printFreeList();
    int n1, n2, n3;

    printf("Enter the size of integer array : ");
    scanf("%d", &n1);
    int *temp1=allocate_memory(sizeof(int)*n1);
    printf("MetaList :\n");
    printFreeList();
    
    for(int i=0; i<n1; i++) {
        temp1[i]=i*3;
    }

    printf("Enter the size of character array to be allocated : ");
    scanf("%d", &n2);
    char *temp2=allocate_memory(sizeof(char)*n2);
    printf("MetaList :\n");
    printFreeList();
    
    for(int i=0; i<n2; i++) {
        temp2[i]=i+65;
    }
    temp2[n2]='\0';

    printf("Enter the size of float point array to be allocated : ");
    scanf("%d", &n3);
    float *temp3=allocate_memory(sizeof(float)*n3);
    printf("MetaList :\n");
    printFreeList();

    for(int i=0; i<n3; i++) {
        temp3[i]=2.53*(i+1);
    }

    printf("Temp1 : ");
    for(int i=0; i<n1; i++) {
        printf("%d ", temp1[i]);
    }
    printf("\t");
    printf("Temp1 add : %x\n\n", temp1);
    printf("Temp2 : ");
    printf("%s \t", temp2);
    printf("Temp2 add : %x\n\n", temp2);
    printf("Temp 3 : ");
    for(int i=0; i<n3; i++) {
        printf("%.2f ", temp3[i]);
    }
    printf("\t");
    printf("Temp3 add : %x\n\n", temp3);

    free_memory(temp2);
    printf("MetaList :\n");
    printFreeList();
    free_memory(temp1);
    printf("MetaList :\n");
    printFreeList();
    free_memory(temp3);
    printf("MetaList :\n");
    printFreeList();
    return_heap();
    return 0;
}