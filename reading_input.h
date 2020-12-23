//
// Created by lars on 23.12.20.
//
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

#ifndef ADVENT_OF_SUFFERING_READING_INPUT_H
#define ADVENT_OF_SUFFERING_READING_INPUT_H

#endif //ADVENT_OF_SUFFERING_READING_INPUT_H

void reading_input_integer_lines_into_array_entries(int n, int *numbers, string filepath) {
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
}