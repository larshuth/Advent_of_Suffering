//
// Created by lars on 23.12.20.
//

#include "sorting_and_searching_arrays.cpp"
#include "reading_input.cpp"


int day_1_part_1(int *input, int n) {
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

    int burger = input[pos_smaller] * input[pos_larger];
    return burger;
}


int day_1_part_2(int *input, int n) {

    int pos_1 = 0;
    int pos_2 = pos_1;
    int pos_3 = n-1;

    int current_search = input[pos_1] + input[pos_2] + input[pos_3];
    cout << pos_1 << endl << pos_2 << endl << pos_3 << endl;
    cout << input[pos_1] << endl << input[pos_2] << endl << input[pos_3] << endl;

    //bruteforce O(n³)
    if (false) {
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
    }

    //still brutal but smarter brutality O(n² log n)
    for (int pos_1= 0; pos_1<n; pos_1++) {
        for (int pos_3 = n-1; pos_3 > pos_1; pos_3--) {
            if (2*(input[pos_1]) + input[pos_3] < 2020) {

                int target_2 = 2020-(input[pos_1]+input[pos_3]);

                if (binary_search_for_target_value(input, pos_1, pos_3, target_2)) {
                    int burger = input[pos_1] * target_2 * input[pos_3];
                    return burger;
                }
            }
        }
    }
    return 0;
}


void day1(int n, string filepath) {
    int input[n];
    reading_input_integer_lines_into_array_entries(n, input, filepath);

    mergesort(input, n, 0, n-1);
    int result_part1, result_part2;

    result_part1 = day_1_part_1(input, n);
    result_part2 = day_1_part_2(input, n);
}