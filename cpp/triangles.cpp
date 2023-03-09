#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 200

int main() {
    
    int N, level, test_case = 1;
    char symbol;

    scanf("%d", &N);
    
    while (N--) {
        scanf("%d %c", &level, &symbol);
        printf ("CASE %d: \n", test_case);
        int ctr = 1;
        for (int i = 1; i <= level; i++) {
            char line[MAX] = {};
            
            int pad = level - i;
            for (int j = 0; j < pad; j++)
                line[j] = ' ';
            
            for (int j = pad; j < pad + ctr; j++) {
                line[j] = symbol;
            }
            printf("%s\n", line);
            ctr+=2;
        }
        test_case++;
    }
    return 0;
}

