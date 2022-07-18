/*
Each day, to enter their building, employees of an e-commerce company have to type a string of numbers
into a console using a 3 x 3 numeri keypad. Every day, the numbers on the keypad are mixed up.

Use the following rules to calculate the total amount of time it takes to type a string:

It takes 0 seconds to move their finger to the first key, and it takes 0 seconds to press the key where
their finger is located any number of times.

They can move their finger from one location to any adjacent key in one second. Adjacent keys include those
on a diagonal.

Moving to a non-adjacent key is done as a series of moves to adjacent keys.

Complete the function entryTime in the editor below.
entryTime has the following parameter(s):
    string s: the string to type
    string keypad: a string of 9 difgits where each group of 3 digits represents a row on the keypad of the day, in order.

Returns: int: integer denoting the minimum amount of time it takes to type the string s.

Constraints:

1 <= |s| <= 10^5
|keypad| = 9
keypad[i] belongs [1-9]

Example:
string s: "423692"
string keypad: "923857614"

4: Start here, so it takes 0 seconds.
2: It takes 2 seconds to move from 4 to 2.
3: It takes 1 seconds to move from 2 to 3.
6: It takes 2 seconds to move from 3 to 6.
9: It takes 2 seconds to move from 6 to 9.
2: It takes 1 seconds to move from 9 to 2.

The total time is 2 + 1 + 2 + 2 + 1 = 8.
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

/*
 * Complete the 'entryTime' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. STRING keypad
 */

int max(int x, int y) {
    if (x > y) {
        return x;
    }else{
        return y;
    }

}

int distance(int x, int y, int a, int b) {
    
    int second;
    int c, d;
    c = abs(a - x);
    d = abs(b - y);
    second = max(c, d);
    
    return second;
}

void coordinates(int v[2], int mat[3][3], char s) {     
    
    int i, j, flag;
    int a ,b;
    
    flag = 0;
    
    for (i = 0; i<3 && !flag; i++){
        for(j = 0; j<3 && !flag; j++){
            if (mat[i][j] == s - 48) {
                flag = 1;
                a = i;
                b = j;
            }
        }
    }
    
    v[0] = a;
    v[1] = b; 
    
}

int entryTime(char* s, char* keypad) {

    int mat[3][3];
    int currentPos[2];
    int nextPos[2];
    int flag = 0;
    int i, j, seconds;

    seconds = 0;

    for (i = 0; i<3; i++) {
        for(j = 0; j<3; j++) {
            mat[i][j] = keypad[i * 3 + j] - 48;
        }
    }

    coordinates(currentPos, mat, s[0]);

    i = 1;
    while(s[i] != '\0') {
        coordinates(nextPos, mat, s[i]);
        seconds = seconds + distance(currentPos[0], currentPos[1], nextPos[0], nextPos[1]);
        coordinates(currentPos, mat, s[i]);
        i++;
        coordinates(nextPos, mat, s[i]);
    }
      
    return seconds;

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* keypad = readline();

    int result = entryTime(s, keypad);

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