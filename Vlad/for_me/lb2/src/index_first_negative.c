#include "index_first_negative.h"

int index_first_negative(int array[], int size){
    for (int i=0;i<size;i++){
        if (array[i]<0){
            return i;
        }
    }
    return -1;
}