# include"operations.h"

//initialization 
void initialize(long_number *nptr) {
    for(int i=0; i<18; i++) {
        nptr->number[i]=0;
    }
    nptr->sign_bit=0;
}

void initialize_mul(long_number_mul *nptr) {
    for(int i=0; i<36; i++) {
        nptr->number[i]=0;
    }
    nptr->sign_bit=0;
}

//counting the digits
int count_digits(long long int num) {
    int count=0;
    while(num!=0) {
        count++;
        num=num/10;
    }
    return count;
}

//converting string to number
long long int myAtoi(char str[], int n) {
    long long int num=0;
    for (int i=0; i<n; i++) {
        num=num*10+str[i]-'0';
    }
    return num;
}

//storing block of numbers into structure
void store_number(char str[], long_number* nptr) {
    int i=strlen(str)-2;
    int count=17;
    int j=0;
    while(i>0) {
        j++;
        if(j==18) {
            nptr->number[count]=myAtoi(str+i, 18);
            count--;
            j=0;
        }
        i--;
    }
    
    //nptr->number[count]=myAtoi(str, j);
    // count++;
    if(str[0]=='-') {
        nptr->number[count]=myAtoi(str+1, j);
        nptr->sign_bit=1;
    }
    else {
        j++;
        nptr->number[count]=myAtoi(str, j);
        nptr->sign_bit=0;
    }
}

void store_number_mul(char str[], long_number_mul* nptr) {
    int i=strlen(str)-2;
    int count=35;
    int j=0;
    while(i>0) {
        j++;
        if(j==9) {
            nptr->number[count]=myAtoi(str+i, 9);
            count--;
            j=0;
        }
        i--;
    }
    
    //nptr->number[count]=myAtoi(str, j);
    if(str[0]=='-') {
        nptr->number[count]=myAtoi(str+1, j);
        nptr->sign_bit=1;
    }
    else {
        j++;
        nptr->number[count]=myAtoi(str, j);
        nptr->sign_bit=0;
    }
    
}

//printing the numbers
void get_number(long_number *nptr, FILE *fptr) {
    int i=0;
    while(i<18 && nptr->number[i]==0) {
        i++;
    }
    if(i==18) fprintf(fptr, "%s", "0");
    else {
        if(nptr->sign_bit==1) {
            fprintf(fptr, "%s", "-");
        }
        fprintf(fptr, "%lld", nptr->number[i]);
        i++;
        while(i<18) {
            int count=count_digits(nptr->number[i]);
            for(int i=0; i<(18-count); i++) {
                fprintf(fptr, "%s","0");
            }
            if(nptr->number[i]!=0) {
                fprintf(fptr, "%lld", nptr->number[i]);
            }
            i++;
        }
    }
    fprintf(fptr, "%s", "\n");
}

void get_number_mul(long_number_mul *nptr, FILE *fptr) {
    int i=0;
    while(i<36 && nptr->number[i]==0) {
        i++;
    }
    if(i==36) fprintf(fptr, "%s", "0\n");
    else {
        if(nptr->sign_bit==1) {
            fprintf(fptr, "%s", "-");
        }
        fprintf(fptr, "%lld", nptr->number[i]);
        i++;
        while(i<36) {
            int count=count_digits(nptr->number[i]);
            for(int j=0; j<(9-count); j++) {
                fprintf(fptr, "%s", "0");
            }
            if(nptr->number[i]!=0) {
                fprintf(fptr, "%lld", nptr->number[i]);
            }
            i++;
        }
    }
    fprintf(fptr, "%s", "\n");
}

//subtraction
void sub(long_number *nptr1, long_number *nptr2, long_number *nptr) {
    for(int i=17; i>=0; i--) {
        if(nptr1->number[i]<(nptr2->number[i])) {
            int j=i-1;
            while(j>=0 && nptr1->number[j]==0) {
                j--;
            }
            if(j>=0) {
                nptr1->number[j]=nptr1->number[j]-1;
                j++;
                while(j<=i-1) {
                    nptr1->number[j]=999999999999999999;
                    j++;
                }
                long long num=1000000000000000000;
                nptr->number[i]=(nptr1->number[i]-nptr2->number[i])+num;
            }
            else {
                if(i!=0) {
                    nptr->number[i]=abs(nptr1->number[i]-nptr2->number[i]);
                }
                else {
                    nptr->number[i]=nptr1->number[i]-nptr2->number[i];
                }
                
            }
        }
        else {
            nptr->number[i]=nptr1->number[i]-nptr2->number[i];
        }
    }
    nptr->sign_bit=nptr1->sign_bit;
}

//addition
void add(long_number *nptr1, long_number *nptr2, long_number *nptr) {
    int carry=0;
    long long int div=1000000000000000000;
    for(int i=17; i>=0; i--) {
        nptr->number[i]=((nptr1->number[i])+(nptr2->number[i])+(carry))%div;
        carry=(carry+(nptr1->number[i])+(nptr2->number[i]))/div;
    }
    nptr->sign_bit=nptr1->sign_bit;
}

//multiplication
void mul(long_number_mul *nptr1, long_number_mul *nptr2, long_number_mul *nptr, FILE *fptr) {
    int carry=0;
    long long int div=1000000000;
    bool error=false;
    for(int i=35; i>=0; i--) {
        for(int j=35; j>=0; j--) {
            int index=i+j-35;
            if(index>=0) {
                nptr->number[index]=(nptr->number[index]+(nptr1->number[j]*nptr2->number[i])%div)%div;
                carry=((nptr1->number[j]*nptr2->number[i]))/div;
                if(index!=0) {
                    nptr->number[index-1]=nptr->number[index-1]+carry;
                    carry=0;
                }
                else {
                    if(carry!=0) {
                        error=true;
                        carry=0;
                    }
                }
            }
            else {
                error=true;
            }
        }
    }
    if(error && nptr->number[0]!=0) {
        fprintf(fptr, "%s", "The answer is exceeding the limits of 1024 bits\n");
    }
}