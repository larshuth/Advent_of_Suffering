#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
#include <ctime>

using namespace std;


//Isabel Vargas @ Stack Overflow
void merge(int *arr, int size, int first, int middle, int last)
{
    int temp[size];
    for(int i = first; i<=last; i++)
    {
        temp[i] = arr[i];
    }

    int i=first, j=middle+1, k=first;
    while(i<=middle && j<=last)
    {
        if(temp[i] <= temp[j])
        {
            arr[k] = temp[i];
            i++;
        }
        else
        {
            arr[k]=temp[j];
            j++;
        }
        k++;
    }
    while(i<=middle)
    {
        arr[k]=temp[i];
        k++;
        i++;
    }
}

void mergesort(int *arr, int size, int first, int last)
{
    if(first<last)
    {
        int middle = ( first + last )/2;
        mergesort(arr,size,first,middle);
        mergesort(arr,size,middle+1,last);
        merge(arr,size,first,middle,last);
    }
}

// this is my code

void reading_input(int n, int *numbers, string filepath) {
    // set parameters
    ifstream inputfile; //declaring a file

    inputfile.open(filepath, ios::in);
    string line;
    int line_number = 0;


    if (!inputfile.is_open()) {
        perror("Error open");
        exit(EXIT_FAILURE);
    }
    while (getline(inputfile, line)) {
        int value = stoi(line.substr(0,-1));
        numbers[line_number++] = value;
    };
    inputfile.close();

    ;
}

void day_1_part_1(int *input, int n) {
    int pos_smaller = 0;
    int pos_larger = n-1;
    int current_search = input[pos_smaller]+input[pos_larger];

    while(current_search != 2020){
        if(current_search < 2020){
            pos_smaller++;
        }
        else{
            pos_larger--;
        }
        current_search = input[pos_smaller]+input[pos_larger];
    }

    cout << input[pos_smaller] << endl << input[pos_larger] << endl;
    double burger = input[pos_smaller] * input[pos_larger];
    cout << "burger: " << burger;
}

bool binary_search(int *input, int first, int last, int target){
    int middle = round((first+last)/2);
    //check
    if (not (first <= last)) {
        return false;
    }

    //recursion
    if (input[middle] > target){
        binary_search(input, first, middle-1, target);
    } else if (input[middle] < target) {
        binary_search(input, middle, last, target);
    } else {
        return true;
    }
    return false;
}



void day_1_part_2(int *input, int n) {

    int pos_1 = 0;
    int pos_2 = pos_1;
    int pos_3 = n-1;

    int current_search = input[pos_1] + input[pos_2] + input[pos_3];
    cout << pos_1 << endl << pos_2 << endl << pos_3 << endl;
    cout << input[pos_1] << endl << input[pos_2] << endl << input[pos_3] << endl;

    //get all triples
    if (false){
        while(current_search != 2020){
            pos_2 = pos_1;
            current_search = input[pos_1] + input[pos_2] + input[pos_3];
            if (current_search > 2020){
                pos_3--;
            }
            else {
                while (current_search < 2020) {
                    pos_2++;
                    current_search = input[pos_1] + input[pos_2] + input[pos_3];
                }
                if (current_search == 2020) {
                    break;
                } else {
                    pos_1++;
                }
            }
            current_search = input[pos_1] + input[pos_2] + input[pos_3];
            if (not 0 < pos_1 + pos_2 + pos_3 < 200*3) {
                break;
            }
        }
    }

    //bruteforce
    for (int pos_1= 0; pos_1<n; pos_1++) {
        for (int pos_2 = 0; pos_2 < n; pos_2++) {
            for (int pos_3 = 0; pos_3 < n; pos_3++) {
                if (input[pos_1] + input[pos_2] + input[pos_3] == 2020) {
                    cout << input[pos_1] << endl << input[pos_2] << endl << input[pos_3] << endl;
                    long burger = input[pos_1] * input[pos_2] * input[pos_3];
                    cout << "burger: " << burger << endl;

                }
            }
        }
    }

    //still brutal but smarter brutality
    for (int pos_1= 0; pos_1<n; pos_1++) {
        for (int pos_3 = 0; pos_3 < n; pos_3++) {
            if (2*input[pos_1] + input[pos_3] < 2020) {

                int target_2 = 2020-(input[pos_1]+input[pos_3]);

                if (binary_search(input, pos_1, pos_3, target_2)) {
                    cout << input[pos_1] << endl << target_2 << endl << input[pos_3] << endl;
                    long burger = input[pos_1] * target_2 * input[pos_3];
                    cout << "burger: " << burger << endl;
                }
            }
        }
    }

}

int day1(int n, string filepath) {
    int input[n];
    reading_input(200, input, "/home/lars/CLionProjects/AoS/d1_input.txt");

    mergesort(input, n, 0, n-1);

    day_1_part_1(input, n);
    day_1_part_2(input, n);

    return 0;
}

int main() {
    day1(200, "/home/lars/CLionProjects/AoS/d1_input.txt");
    return 0;
}
