/*
 ============================================================================
 Name        : calculator.c
 Author      : grnbows
 Version     : 1.16
 Copyright   : free
 Description : calculator in C
 ============================================================================
 */


/*
У меня просто удалился старый проект из эклипса, как такое могло вообще произойти? Я начал его компилировать,
и эклипс просто самопроизвольно закрылся (вылетел, то есть). После этого я никак не могу взаимодействовать со своей
папкой проекта "calculator". Повезло, что код был на github и я просто смог его скопировать оттуда в один из старых проектов,
но это, конечно, что-то непонятное для меня.
Как можно испраивть эту ошибку на будущее?
 */

#include <stdio.h>
#include <stdlib.h>

// structure for numbers
typedef struct start_struct {
    char choice;
    char sign;
    int size;
    float *x;
    float *y;
    struct start_struct *next;
} elem;


// structure for vectors
typedef struct result_struct {
    float *result;
    struct result_struct *res_next;
} result;


// function, that handles operations with numbers
float *numbersResults(char sign, float *x, float *y) {
    float *numbersResult;
    float variable1, variable2;
    numbersResult = malloc(1 * sizeof(float));
    switch (sign) {
        case '+': {
            numbersResult[0] = x[0] + y[0];
            return numbersResult;
        }
        case '-': {
            numbersResult[0] = x[0] - y[0];
            return numbersResult;
        }
        case '*': {
            numbersResult[0] = x[0] * y[0];
            return numbersResult;
        }
        case '/': {
            if (y[0] != 0) {
                numbersResult[0] = x[0] / y[0];
                return numbersResult;
            }
            else {
                return 0;
            }
        }
        case '^': {
            variable1 = 1;
            variable2 = 1;
            for (int ist1=1;ist1<=y[0];ist1++) {
                variable1 = variable2;
                variable2 = variable1 * x[0];
            }
            numbersResult[0] = variable2;
            return numbersResult;
        }
        case '!': {
            variable1 = 1;
            for(int i = 1; i<=x[0]; i++) {
                variable1 = variable1 * i;
            }
            numbersResult[0] = variable1;
            return numbersResult;
        }
    }
    return x;
    return y;
    free(x);
    free(y);
    free(numbersResult);
}


// function, that handles operations with vectors
float *vectors(char sign, int size, float *firstVector, float *secondVector) {
    float *vectorsResult;
    switch (sign) {
        case '+': {
            vectorsResult = malloc(size * sizeof(float));
            for (int i = 0; i < size; i++)
            {
                vectorsResult[i] = firstVector[i] + secondVector[i];
            }
            return vectorsResult;
        }
        case '-': {
            vectorsResult = malloc(size * sizeof(float));
            for (int i = 0; i < size; i++) {
                vectorsResult[i] = firstVector[i] - secondVector[i];
            }
            return vectorsResult;
        }
        }
    return firstVector;
    return secondVector;
    free(firstVector);
    free(secondVector);
    free(vectorsResult);
}


// funnction, that read numbers from file
float *add_number(FILE *input, int size) {
    float *numbersResult;
    numbersResult = malloc(size * sizeof(float));
    for(int i = 0;i < size;i++) {
        fscanf(input,"%f", &numbersResult[i]);
    }
    return numbersResult;
}


// function, that write number to my structure
void add_element(elem *current, FILE *input) {
    elem *now = malloc(1 * sizeof(elem));
    fscanf(input, " %c %c", &now->sign, &now->choice);
    if (now->choice == 'v') {
        fscanf(input, " %i", &now->size);
    }
    else {
        now->size = 1;
    }
    if (now->sign != '!') {
        now->x = add_number(input, now->size);
        now->y = add_number(input, now->size);
    }
    else {
        now->x = add_number(input, now->size);
        now->y = NULL;
    }
    now->next = NULL;
    current->next = now;
}


// function, that add result of operation into result structure
void add_element_result(result *current_res, elem *current)
{
    result *now_res = malloc(1 * sizeof(result));
    if (current->choice == 'v'){
        now_res->result = vectors(current->sign, current->size, current->x, current->y);
    }
    else {
        now_res->result = numbersResults(current->sign, current->x, current->y);
    }
    now_res->res_next = NULL;
    current_res->res_next = now_res;
}



int main() {

    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    char inputFileName[254+1], outputFileName[254+1];
    FILE *input, *output;
    elem *previous, *current;
    result *previous_result, *current_result;
    printf("Now you can choose names of input and output files.\n\nWARNING: Please, check correct of input file before program starting:\nAvailable operations: (+ - / * ! ^) for numbersResults and (+ -) for vectors.\nLater you should point size of vector, if it need.\n\nIMPORTANT: Indicated files should be located in such directory as executable file. Save your relatives and love cats.\n\n");
    printf("Enter name of input file:  ");
    scanf(" %s", inputFileName);
    printf("Enter name of output file: ");
    scanf(" %s", outputFileName);
    input = fopen(inputFileName, "r");
    if(feof(input) != 1) {
        previous = malloc(1 * sizeof(elem));
        fscanf(input, " %c %c", &previous->sign, &previous->choice);
        if (previous->choice == 'v') {
            fscanf(input, " %i", &previous->size);
        }
        else {
            previous->size = 1;
        }
        if (previous->sign != '!') {
            previous->x = add_number(input, previous->size);
            previous->y = add_number(input, previous->size);
        }
        else {
            previous->x = add_number(input, previous->size);
            previous->y = NULL;
        }
        current = previous;
        for (int test;test<255;test++) {
            add_element(current, input);
            current = current->next;
        }
        previous_result = malloc(sizeof(result));
        current = previous;
        if (current->choice == 'v') {
            previous_result->result = vectors(current->sign, current->size, current->x, current->y);
        }
        else {
            previous_result->result = numbersResults(current->sign, current->x, current->y);
        }
        previous_result->res_next = NULL;
        current = current->next;
        current_result = previous_result;
        while (current != NULL) {
            add_element_result(current_result, current);
            current = current->next;
            current_result = current_result->res_next;
        }
        current = previous;
        current_result = previous_result;
        fclose(input);
        output = fopen(outputFileName, "w");
        while (current != NULL) {
            if (current->choice == 'v') {
                fprintf(output, "(");
                for (int i = 0; i < current->size; i++) {
                    fprintf(output, " %.2f ", current->x[i]);
                }
                fprintf(output, ") %c (", current->sign);
                for (int i = 0; i < current->size; i++) {
                    fprintf(output, " %.2f ", current->y[i]);
                }
                fprintf(output, ") = ");
                if (current->sign != '*') {
                    fprintf(output, "(");
                    for (int i = 0; i < current->size; i++) {
                        fprintf(output, " %.2f ", current_result->result[i]);
                        }
                    fprintf(output, ")\n");
                } else {
                    fprintf(output, " %.2f\n", current_result->result[0]);
                }
            } else if (current->choice == 's') {
                fprintf(output, "%.2f\n", current_result->result[0]);
           }
            current = current->next;
            current_result = current_result->res_next;
        }
        fclose(output);
    }
}
