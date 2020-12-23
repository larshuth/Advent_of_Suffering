//
// Created by lars on 23.12.20.
//

using namespace std;

#ifndef ADVENT_OF_SUFFERING_SORTING_AND_SEARCHING_ARRAYS_H
#define ADVENT_OF_SUFFERING_SORTING_AND_SEARCHING_ARRAYS_H

#endif //ADVENT_OF_SUFFERING_SORTING_AND_SEARCHING_ARRAYS_H

//Originally by Isabel Vargas @ Stack Overflow
//Slightly modified

void merge(int *arr, int size, int first, int middle, int last)
{
    //merging is not happening in place but instead using a temporary extra array
    int temp[size];
    //copying values into temporary array
    for(int i = first; i<=last; i++) {
        temp[i] = arr[i];
    }

    //1st element 1st half - i
    //1st element 2nd half - j
    //current position being filled k

    int i=first, j=middle+1, k=first;
    while(i<=middle && j<=last) {
        if(temp[i] <= temp[j]) {
            arr[k] = temp[i];
            i++;
        }
        else {
            arr[k]=temp[j];
            j++;
        }
        k++;
    }
    while(i<=middle) {
        arr[k]=temp[i];
        k++;
        i++;
    }
}


void mergesort(int *arr, int size, int first, int last)
{
    if(first<last) {
        int middle = round((first + last )/2 );

        mergesort(arr,size,first,middle);
        mergesort(arr,size,middle+1,last);

        merge(arr,size,first,middle,last);
    }
}



bool binary_search_for_target_value_rec(int *input, int first, int last, int target){
    int middle = round((first+last)/2);
    //check
    if (first == last) {
        if (input[first] == target) {
            return true;
        } else {
            return false;
        }
    }

    //recursion
    if (input[middle] > target){
        return binary_search_for_target_value_rec(input, first, middle-1, target);
    } else if (input[middle] < target) {
        return binary_search_for_target_value_rec(input, middle, last, target);
    } else {
        return true;
    }
}


bool binary_search_for_target_value(int *input, int first, int last, int target){
    if (input[first] > target || input[last] < target) {
        return false;
    } else {
        return binary_search_for_target_value_rec(input, first, last, target);
    }
}