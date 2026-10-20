#include "index_last_negative.h"

int index_last_negative(int array[], int size){
    int b = -1;
    for (int i = 0; i < size; i++) {
        if (array[i] < 0) {
            b = i;
        }
    }
    return b;
}