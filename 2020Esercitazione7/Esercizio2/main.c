/*
CUT THE BAMBOO

Given an array with the lengths pieces of bamboo, repeatedly perform the following:
1. Count the number of pieces of bamboo.
2. Find the shortest lenght piece(s).
3. Discard any piece of that lenght.
4. Cut that shortest lenght from each of the longer pieces. Each piece just cut is an offcut.
5. Discard all offcuts.
6. Repeat until there are no more pieces.

Maintain an arry of the numbers of pieces at the beginning of each round of actions.

For example, there are n = 4 pieces, with lenghts = [1,1,3,4]. The shortest pieces are 1 unit long, so discard them and remember their
length. Remove their length, 1 unit, from the longer pieces and discard the offcuts. 
Now there are 2 pieces of bamboo, lenghts [2,3]. Discard the piece of length 2, cut 2 from the piece length 3 and discard the offcut.
Now there is only one piece of length 1. Discard it and return an array with the number of pieces at the start of each turn:
[4,2,1].

Function description: Complete the function cutBamboo in the editor below. The function must return an array of integers,
each the number of pieces at the start of a turn.

cutBamboo has the following parameter(s):
lengths[lengths[0],...lengths[n-1]]: an array of integers that represent the starting lengths of each piece of bamboo.


Constraints:

1 <= n <= 10^3
1 <= lengths[i] <= 10^3, where 0 <= i <= n


Example 2:
lengths         cut length      pieces

5 4 4 2 2 8         2              6
3 2 2 _ _ 6         2              4
1 _ _ _ _ 4         1              2
_ _ _ _ _ 3         3              1
_ _ _ _ _ _        DONE           DONE

*/

#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);



/*
 * Complete the 'cutBamboo' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY lengths as parameter.
 */

/*
 * To return the integer array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * int* return_integer_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static int a[5] = {1, 2, 3, 4, 5};
 *
 *     return a;
 * }
 *
 * int* return_integer_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     int *a = malloc(5 * sizeof(int));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = i + 1;
 *     }
 *
 *     return a;
 * }
 *
 */

int findSmallestPositive(int *v, int dim) {
    int small;
    int i = 0;
    while(i < dim) {
        if(v[i] > 0) {
            small = v[i];
        }
    i++;
    }
    
    i = 0;
    while(i < dim) {
        if(v[i] > 0 && v[i] < small) {
            small = v[i];
        }
    i++;
    }
    return small;
    
}
void subtractSmallestLenght(int *v, int dim, int lenght) {
    int i;

    for(i = 0; i < dim; i++) {
        v[i] = v[i] - lenght;
    }
}

int countGreaterZero(int *v, int dim, int count) {
    int i;
    for(i = 0; i < dim; i++) {
        if(v[i] > 0) {
            count++;
        } 
    }
    return count;
}
int* cutBamboo(int lengths_count, int* lengths, int* result_count) {

    int supp[lengths_count];
    int *finalArray;
    int i;
    int small, count;

    *result_count = 0;
    
    count = countGreaterZero(lengths, lengths_count, 0);
    
    while(count > 0) {

        (*result_count)++;
        
        supp[*result_count] = count;

        small = findSmallestPositive(lengths, lengths_count);
        subtractSmallestLenght(lengths, lengths_count, small);
        count = countGreaterZero(lengths, lengths_count, 0);
        
    }
    
    
    finalArray = (int*)malloc(*result_count * sizeof(int));
    assert(finalArray != NULL);
    
    for(i = 0; i < *result_count; i++) {
        finalArray[i] = supp[i]; 
    }

    return finalArray;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int lengths_count = parse_int(ltrim(rtrim(readline())));

    int* lengths = malloc(lengths_count * sizeof(int));

    for (int i = 0; i < lengths_count; i++) {
        int lengths_item = parse_int(ltrim(rtrim(readline())));

        *(lengths + i) = lengths_item;
    }

    int result_count;
    int* result = cutBamboo(lengths_count, lengths, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%d", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}