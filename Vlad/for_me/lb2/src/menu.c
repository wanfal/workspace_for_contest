#include <stdio.h>
#include "index_first_negative.h"
#include "index_last_negative.h"
#include "multi_before_and_after_negative.h"
#include "multi_between_negative.h"

int main(){

    int k;

    if (scanf("%d", &k) != 1) {
        printf("Данные некорректны\n");
        return 0;
    }

    int array[20];
    int size = 0;
    int value;
    int too_many = 0;

    while (scanf("%d", &value) == 1) {
        if (size < 20) {
            array[size++] = value;
        } else {
            too_many = 1;
        }
    }

    if (k < 0 || k > 3 || size == 0 || too_many ||
    index_first_negative(array, size) == -1 ||
    (k == 2 &&
     index_first_negative(array, size) ==
     index_last_negative(array, size))) {
    printf("Данные некорректны\n");

    }else{
        switch (k){
        case 0:
            printf("%d\n",index_first_negative(array,size));
            break;
        case 1:
            printf("%d\n",index_last_negative(array,size));
            break;
        case 2:
            printf("%lld\n",multi_between_negative(array,size));
            break;
        case 3:
            printf("%lld\n",multi_before_and_after_negative(array,size));
            break;
        }
        
    }

    return 0;
}