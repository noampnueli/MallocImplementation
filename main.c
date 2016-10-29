//
// Created by Noam pnueli on 14/10/2016.
//
#include <stdio.h>
#include <string.h>
#include "myMalloc.h"


int main()
{
    init();
    int num = 123456;
    int* num_ptr = allocate(sizeof(num));
    *num_ptr = num;

    printf("%i\n", *num_ptr);

    int num2 = 123;
    int* num_ptr2 = allocate(sizeof(num));
    *num_ptr2 = num2;

    printf("%i\n", *num_ptr2);

    char txt[] = "Hello";
    char* txt_ptr = (char *)allocate((int) strlen(txt) + 1);
    strcpy(txt_ptr, "Hello");

    printf("%s\n", txt_ptr);

    freeMem(num_ptr);

    int num3 = 654321;
    int* num_ptr3 = allocate(sizeof(num3));
    *num_ptr3 = num3;

    printf("%i\n", *num_ptr3);

    freeMem(num_ptr2);
    freeMem(txt_ptr);
    freeMem(num_ptr3);

    return 0;
}
