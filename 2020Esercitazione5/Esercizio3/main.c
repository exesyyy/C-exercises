/*
Your company is designing a dam to be built across a stream to create a small lake.
To reduce materials cost, it will be made of one or more concrete walls with mud packed
in between them. Determine the maximum height of the mud segments in the dam with the following 
restrictions:

   - One unit width of the gap between walls will contain one segment of packed mud.
   - The height of mud in a segment cannot exceed 1 unit more than an adjacent wall or
     mud segment.
     
Given the placement of a number of walls and their heights, determine the maximum height of a mud segment that can
ben built. If no mud segment can be built, return 0.

Example:

wallPositions = [1,2,4,7]
wallHeights = [4,6,8,11]


----
------
-------         7  mud
--------
---------       9  mud
----------      10 mud
-----------

There is no space between the first 2 walls.
Between positions 2 and 4, there is one unit open for mud. Heights of the surrounding walls
are 6 and 8, so maximum height of mud is 6 + 1 = 7.

Between positions 4 and 7 there 2 units. The heights of surrounding walls are 8 and 11.
The maximum height segment next to the wall of height 8 is 9.
The maximum height segment next to the wall of height 9 is 10.

Overall, mud segment heights are 7, 9 and 10, and the maximum height is 10.

Complete the function maxHeight, below. It has the following parameter(s):
int wallPositions[n]
int wallHeights[n]

Returns: int: the maximum height mud segment that can be build.

1 < n <= 10^5
1 <= wallPositions[i], wallHeights[i] <= 10^9  (where 0 <= i < n)



Another example:

wallPositions = [1,3,7] and
wallHeights = [4,3,3]

----
----    4 mud
---     
----    4 mud
-----   5 mud
----    4 mud
---

Another one:

wallPositions = [1,10]
wallHeights = [1, 5]


-
--              2 mud
---             3 mud
----            4 mud
-----           5 mud
------          6 mud
-------         7 mud
-------         7 mud
------          6 mud
-----



 * Complete the 'maxHeight' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY wallPositions
 *  2. INTEGER_ARRAY wallHeights
 
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
 * Complete the 'maxHeight' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY wallPositions
 *  2. INTEGER_ARRAY wallHeights
 */

int pari(int gap){
    if(gap%2==0)
        return 1;
    return 0;
}

int fill(int min, int max, int gap){
    if(max == min){
        if(pari(gap)){
            return (min + (gap/2));
        }
        else{
            return (min + (gap/2) +1);
        }
    }
    if(gap <= (max - min))
        return (min + gap);
    else{
        return ((max + 1) + (gap - (max - min) - 1)/2);
    }
}

int maxHeight(int wallPositions_count, int* wallPositions, int wallHeights_count, int* wallHeights) {
    
    
    int muroGrande, muroPiccolo, gap, a, max, tmp;

    max = 0;
    
    for(a = 0; a < wallPositions_count - 1; a++) {

        gap = wallPositions[a+1] - wallPositions[a] - 1;
        if(gap != 0) {
            if(wallHeights[a] > wallHeights[a+1]) {
                muroGrande = wallHeights[a];
                muroPiccolo = wallHeights[a+1];
            }else{
                muroGrande = wallHeights[a+1];
                muroPiccolo = wallHeights[a];
            }

            tmp = fill(muroPiccolo, muroGrande, gap);

            if(tmp > max) {
                max = tmp;
            }

        }
    }     
    
    return max;
}
int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int wallPositions_count = parse_int(ltrim(rtrim(readline())));

    int* wallPositions = malloc(wallPositions_count * sizeof(int));

    for (int i = 0; i < wallPositions_count; i++) {
        int wallPositions_item = parse_int(ltrim(rtrim(readline())));

        *(wallPositions + i) = wallPositions_item;
    }

    int wallHeights_count = parse_int(ltrim(rtrim(readline())));

    int* wallHeights = malloc(wallHeights_count * sizeof(int));

    for (int i = 0; i < wallHeights_count; i++) {
        int wallHeights_item = parse_int(ltrim(rtrim(readline())));

        *(wallHeights + i) = wallHeights_item;
    }

    int result = maxHeight(wallPositions_count, wallPositions, wallHeights_count, wallHeights);

    fprintf(fptr, "%d\n", result);

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