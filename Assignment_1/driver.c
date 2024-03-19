# include<stdio.h>
# include<string.h>
# include"operations.h"

int main() {
    FILE *fptr1=fopen("./input.txt", "r");
    FILE *fptr2=fopen("./output.txt", "w");

    //creating strings to store the input numbers 
    char *num_str1=(char*)malloc(sizeof(char)*310);
    char *num_str2=(char*)malloc(sizeof(char)*310);
    char *str=(char*)malloc(sizeof(char)*310);

    //reading the strings from the input.txt file and printing the output in output.txt file
    while(fgets(str, 311, fptr1)!=NULL) {
        strcpy(num_str1, str);
        fgets(str, 311, fptr1);
        strcpy(num_str2, str);
        fgetc(fptr1);
        
        //creating the variables to store input and output
        long_number num1;
        long_number num2;
        long_number num_add;
        long_number num_sub;

        //initialization
        initialize(&num1);
        initialize(&num2);
        initialize(&num_add);
        initialize(&num_sub);

        //storing the first number 
        store_number(num_str1, &num1);

        //storing the second number 
        store_number(num_str2, &num2);

        //printing the numbers in output.txt files
        fprintf(fptr2, "%s", "Num1 : ");
        get_number(&num1, fptr2);
        fprintf(fptr2, "%s", "Num2 : ");
        get_number(&num2, fptr2);
        fprintf(fptr2, "%s", "Num_add : ");

        //addition 
        if(num1.sign_bit==num2.sign_bit) {
            add(&num1, &num2, &num_add);
        }
        else {
            if(strlen(num_str1)>strlen(num_str2)) {
                sub(&num1, &num2, &num_add);
                //num_add.sign_bit=num1.sign_bit;
            }
            else if(strlen(num_str1)< strlen(num_str2)) {
                sub(&num2, &num1, &num_add);
                //num_add.sign_bit=num2.sign_bit;
            }
            else {
                int cmp=strcmp(num_str1, num_str2);
                if(cmp>=0) {
                    sub(&num1, &num2, &num_add);
                    //num_add.sign_bit=num1.
                }
                else {
                    sub(&num2, &num1, &num_add);
                    //num.add
                }
            }
        }
        get_number(&num_add, fptr2);
        fprintf(fptr2, "%s", "Num_sub : ");

        //subtraction
        if(num1.sign_bit==num2.sign_bit) {
            if(strlen(num_str1)>strlen(num_str2)) {
                sub(&num1, &num2, &num_sub);
            }
            else if(strlen(num_str1)< strlen(num_str2)) {
                sub(&num2, &num1, &num_sub);
                int i=0;
                while(num_sub.number[i]==0) {
                    i++;
                }
                if(i<18) {
                    num_sub.number[i]=-num_sub.number[i];
                }
            }
            else {
                int cmp=strcmp(num_str1, num_str2);
                if(cmp>=0) {
                    sub(&num1, &num2, &num_sub);
                }
                else {
                    sub(&num2, &num1, &num_sub);
                    int i=0;
                    while(i<18 && num_sub.number[i]==0) {
                        i++;
                    }
                    num_sub.number[i]=-num_sub.number[i];
                }
            }
        }
        else {
            add(&num1, &num2, &num_sub);
        }
        get_number(&num_sub, fptr2);

        //multiplication
        long_number_mul num1_mul;
        long_number_mul num2_mul;
        long_number_mul num_mul;
        initialize_mul(&num1_mul);
        initialize_mul(&num2_mul);
        initialize_mul(&num_mul);
        store_number_mul(num_str1,&num1_mul);
        store_number_mul(num_str2, &num2_mul);
        fprintf(fptr2, "%s", "Num1_mul : ");
        get_number_mul(&num1_mul, fptr2);
        fprintf(fptr2, "%s", "Num2_mul : ");
        get_number_mul(&num2_mul, fptr2);
        fprintf(fptr2, "%s", "Num_mul : ");
        mul(&num1_mul, &num2_mul, &num_mul, fptr2);
        if(num1_mul.sign_bit==num2_mul.sign_bit) {
            num_mul.sign_bit=0;
        }
        else {
            num_mul.sign_bit=1;
        }
        get_number_mul(&num_mul, fptr2);
        fprintf(fptr2, "%s", "\n");
    }
    printf("Status : Success\n");
    free(num_str1);
    free(num_str2);
    free(str);
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}