#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main () {
    int ranges[10] = {9, 19, 29, 39, 49, 59, 69, 79, 89, 99};
    int counters[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int num;
    while (scanf("%d", &num)) {
        for (int i = 0; i < 9; i++) {
            if (num <= ranges[0]) {
                counters[0] = counters[0]++;
                break;
            } else if (num > ranges[i] && num <= ranges[i + 1]){
                counters[i + 1] = counters[i + 1]++;
                break;
            }
        }
    }
    
    for (int i = 0; i < 9; i++) {
        printf("%d-%d: %d\n", ranges[i] - 9, ranges[i], counters[i]);
    }
    
}
