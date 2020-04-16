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
    float a,b,res,*x,*y;
    int k,factRes,size,i;
    char c,l,v, inputFileName[254+1], outputFileName[254+1], again, stroke[254+1];


        printf("What are you want to use? File or console? [f/c]");
        scanf(" %c", &l);
        switch(l)  //  choose with what are you want to work, console or file
            {
        case 'f':
            {
            do
            {
                FILE *input, *output;  // define files
                printf("\nNow you can choose names of input and output files.\nIMPORTANT: Indicated files should be located in such directory as executable file.\nSave your relatives and love cats.\n\n");
                printf("Enter name of input file:");
                scanf(" %s", inputFileName);
                printf("Enter name of output file:");
                scanf(" %s", outputFileName);
                input = fopen(inputFileName,"r");  // open all files that we need
                output = fopen(outputFileName, "w");
                while (feof(input) == 0)
                {
                    fscanf(input, " %c", &c); // scan operation
                    fscanf(input, " %c", &v); // scan vector or number

                switch(v)  // choose vector or number
                {
                case 's': // if number
                {
                    switch(c)
                    {
                    case '+':
                        {
                            fscanf(input, " %f", &a);
                            fscanf(input, " %f", &b);
                            fprintf(output, "%f + %f = %f", a, b, a+b);
                            break;
                        }
                    case '-':
                        {
                            fscanf(input, " %f", &a);
                            fscanf(input, " %f", &b);
                            fprintf(output, "%f - %f = %f", a, b, a-b);
                            break;
                        }
                    case '/':
                        {
                            fscanf(input, " %f", &a);
                            fscanf(input, " %f", &b);
                            if (b!=0) fprintf(output, "%f / %f = %f", a, b, a/b);
                            break;
                        }
                    case '*':
                        {
                            fscanf(input, " %f", &a);
                            fscanf(input, " %f", &b);
                            fprintf(output, "%f * %f = %f", a, b, a*b);
                            break;
                        }
                    case '^':
                        {
                            fscanf(input, " %f", &a);
                            fscanf(input, " %i", &k);
                            res = 1;
                                for (int i=0; i<k;i++) res = res*a; // just * number on itself for k times
                            fprintf(output, "%f ^ %i = %f", a, k, res);
                            break;
                        }
                    case '!':
                        {
                            factRes = 1;
                            fscanf(input," %i",&k);
                            if (k >= 0) for (int i=k; i!=1;i--) factRes = factRes*i;    // calculate factorial from back
                            else fprintf(output, "This number is below zero. Please, try again.");
                            fprintf(output, "!%i = %i", k, factRes);
                            break;
                        }
                    }
                fprintf(output, "\n");
                break;
                }

                case 'v':  // if vector
                {
                    x=malloc(size*sizeof(int));
                    y=malloc(size*sizeof(int));
                    switch(c)
                    {
                    case '+':
                        {
                            fscanf(input, " %i", &size);
                            for(int i=0;i<size;i++)
                                fscanf(input, " %f",&x[i]);
                            for(int i=0;i<size;i++)
                                fscanf(input, " %f",&y[i]);
                            fprintf(output, "( ");
                            for(int i=0;i<size;i++)
                                fprintf(output, "%.0f ", x[i]);
                            fprintf(output, ") + ( ");
                            for(int i=0;i<size;i++)
                                fprintf(output, "%.0f ", y[i]);
                            fprintf(output, ") = ( ");
                            for(int i=0;i<size;i++)
                                fprintf(output, "%.0f ",x[i]+y[i]);
                            fprintf(output, ")");
                            break;
                        }
                    case '-':
                        {
                            fscanf(input, " %i", &size);
                            for(int i=0;i<size;i++)
                                fscanf(input, " %f",&x[i]);
                            for(int i=0;i<size;i++)
                                fscanf(input, " %f",&y[i]);
                            fprintf(output, "( ");
                            for(int i=0;i<size;i++)
                                fprintf(output, "%.0f ", x[i]);
                            fprintf(output, ") - ( ");
                            for(int i=0;i<size;i++)
                                fprintf(output, "%.0f ", y[i]);
                            fprintf(output, ") = ( ");
                            for(int i=0;i<size;i++)
                                fprintf(output, "%.0f ",x[i]-y[i]);
                            fprintf(output, ")");
                            break;
                        }
                    }
                }
                fprintf(output, "\n");
                    free(x);  //  make memory free
                    free(y);
                break;
                }
                }
                fclose(input); //  close files
                fclose(output);
                printf("\nTry again? Type any symbol to continue and 'q' for exit.");
                scanf(" %c", &again);
                }  while (again != 'q');
                break;
            }
        case 'c':
            {
            do
                {
                printf("Enter operation (+ - / * ! ^) for numbers and\n");  // prints operations list on the screen
                printf("enter operation (p, s) [plus, subtraction] for vectors:");
                scanf(" %c", &c);    // scan operation
                switch(c)
                    {
                case '+':  // 'plus' operation cycle
                    {
                        printf("Enter the first number:");
                        scanf("%f", &a);
                        printf("Enter the second number:");
                        scanf("%f", &b);
                        printf("Result is %.2f (operation %c)\n",a+b,c);
                        break;
                    }
                case '-':  // 'minus' operation cycle
                    {
                        printf("Enter the first number:");
                        scanf("%f", &a);
                        printf("Enter the second number:");
                        scanf("%f", &b);
                        printf("Result is %.2f (operation %c)\n", a-b,c);
                        break;
                    }
                case '/':  // 'divide' operation cycle
                    {
                        printf("Enter the first number:");
                        scanf("%f", &a);
                        printf("Enter the second number:");
                        scanf("%f", &b);
                        if (b != 0) printf("Result is %.4f (operation %c)\n", a/b,c); // you can divide something only if second number != 0. 'Idiot check'
                        else printf("You can't divide by zero\n");
                        break;
                    }
                case '*':  // 'multiplication' operation cycle
                    {
                        printf("Enter the first number:");
                        scanf("%f", &a);
                        printf("Enter the second number:");
                        scanf("%f", &b);
                        printf("Result is %.2f (operation %c)\n", a*b,c);
                        break;
                    }
                case '^':  // exponent cycle
                    {
                        printf("Enter the number:");
                        scanf("%f", &a);
                        printf("Enter the exponent (!only integer!):");
                        scanf("%i", &k);
                        res = 1;
                            for (int i=0; i<k;i++) res = res*a; // just * number on itself for k times
                        printf("Result is %.2f\n", res);
                        break;
                    }
                case '!':  // factorial calculating
                    {
                        factRes = 1;
                        printf("Enter the number (!only integer!):");
                        scanf("%i",&k);
                        if (k >= 0) for (int i=k; i!=1;i--) factRes = factRes*i;    // calculate factorial from back
                        else printf("This number is below zero. Please, try again.");
                        printf("Result is %i\n", factRes);
                        break;
                    }
                case 'p':
                    {
                        i=0;
                        x=malloc(size*sizeof(int));
                        y=malloc(size*sizeof(int));
                        printf("Enter vector's size: ");
                        scanf(" %i",&size);
                        printf("Enter first vector: ");
                        for(int i=0;i<size;i++)
                            scanf(" %f",&x[i]);
                        printf("Enter second vector: ");
                        for(int i=0;i<size;i++)
                            scanf(" %f",&y[i]);
                        printf("Result vectors summ: ");
                        for(int i=0;i<size;i++)
                            printf("%.2f ",x[i]+y[i]);
                        printf("\n");
                        free(x);
                        free(y);
                        break;
                    }
                 case 's':
                    {
                        i=0;
                        x=malloc(size*sizeof(int));
                        y=malloc(size*sizeof(int));
                        printf("Enter vector's size: ");
                        scanf(" %i",&size);
                        printf("Enter first vector: ");
                        for(int i=0;i<size;i++)
                            scanf(" %f",&x[i]);
                        printf("Enter second vector: ");
                        for(int i=0;i<size;i++)
                            scanf(" %f",&y[i]);
                        printf("Result vectors subtraction : ");
                        for(int i=0;i<size;i++)
                            printf("%.2f ",x[i]-y[i]);
                        printf("\n");
                        free(x);
                        free(y);
                        break;
                    }
                    }
                printf("\nTry again? Type any symbol to continue and 'q' for exit.");
                scanf(" %c", &c);
                } while (c != 'q');    // program working status
            }
        }
}
