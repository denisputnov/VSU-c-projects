/*
 ============================================================================
 Name        : calculator.c
 Author      : grnbows
 Version     : 1.16
 Copyright   : free
 Description : calculator in C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    // variable description
    float a,b,res;
    int k,factRes;
    char c;

    do
    {
        printf("Enter operation (+ - / * ! ^):");  // prints operations list on the screen
        scanf(" %c", &c);    // scan operation
        if (c == '+')   // 'plus' operation cycle
            {
                printf("Enter the first number:");
                scanf("%f", &a);
                printf("Enter the second number:");
                scanf("%f", &b);
                printf("Result is %.2f (operation %c)\n",a+b,c);
            }
        else if (c == '-')  // 'minus' operation cycle
            {
                printf("Enter the first number:");
                scanf("%f", &a);
                printf("Enter the second number:");
                scanf("%f", &b);
                printf("Result is %.2f (operation %c)\n", a-b,c);
            }
        else if (c == '/')  // 'divide' operation cycle
            {
                printf("Enter the first number:");
                scanf("%f", &a);
                printf("Enter the second number:");
                scanf("%f", &b);
                if (b != 0) printf("Result is %.4f (operation %c)\n", a/b,c); // you can divide something only if second number != 0. 'Idiot check'
                else printf("You can't divide by zero\n");
            }
        else if (c == '*')  // 'multiplication' operation cycle
            {
                printf("Enter the first number:");
                scanf("%f", &a);
                printf("Enter the second number:");
                scanf("%f", &b);
                printf("Result is %.2f (operation %c)\n", a*b,c);
            }
        else if (c == '^')  // exponent cycle
            {
                printf("Enter the number:");
                scanf("%f", &a);
                printf("Enter the exponent (!only integer!):");
                scanf("%i", &k);
                res = 1;
                    for (int i=0; i<k;i++) res = res*a; // just * number on itself for k times
                printf("Result is %.2f\n", res);
            }
        else if (c == '!')  // factorial calculating
            {
                factRes = 1;
                printf("Enter the number (!only integer!):");
                scanf("%i",&k);
                if (k >= 0) for (int i=k; i!=1;i--) factRes = factRes*i;    // calculate factorial from back
                else printf("This number is below zero. Please, try again.");
                printf("Result is %i\n", factRes);
            }
        else printf("\nTrouble with operation. Please, use operations from list: (+ - / * ! ^).\n");
        printf("\nTry again? Type any symbol to continue and 'q' for exit.");
        scanf(" %c", &c);
    } while (c != 'q');    // program working status
}
