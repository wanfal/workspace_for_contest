#include "multi_before_and_after_negative.h"
#include "index_first_negative.h"
#include "index_last_negative.h"

long long multi_before_and_after_negative(int array[], int size){
    long long product  = 1;
    int first,last;
    first=index_first_negative(array,size);
    last=index_last_negative(array,size);
    for (int i=0;i<size;i++){
        if (i<first || i>=last){
            product*=array[i];
        }
    }
    return product;
}