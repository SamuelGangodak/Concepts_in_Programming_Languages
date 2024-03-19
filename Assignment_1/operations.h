# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<limits.h>
# include<stdbool.h>

typedef struct long_number{
    long long int number[18];
    int sign_bit;
}long_number;

typedef struct long_number_mul{
    long long int number[36];
    int sign_bit;
}long_number_mul;

void initialize(long_number *nptr);

void initialize_mul(long_number_mul *nptr);

int count_digits(long long int num);

long long int myAtoi(char str[], int n);

void store_number(char str[], long_number* nptr);

void store_number_mul(char str[], long_number_mul* nptr);

void get_number(long_number *nptr, FILE *fptr);

void get_number_mul(long_number_mul *nptr, FILE *fptr);

void sub(long_number *nptr1, long_number *nptr2, long_number *nptr);

void add(long_number *nptr1, long_number *nptr2, long_number *nptr);

void mul(long_number_mul *nptr1, long_number_mul *nptr2, long_number_mul *nptr, FILE *fptr);