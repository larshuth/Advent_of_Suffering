//
// Created by lars on 23.12.20.
//
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <regex>

using namespace std;

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


void mediocre_pattern_matching_line_by_line(string filepath) {
    ifstream inputfile; //declaring a file

    inputfile.open(filepath, ios::in);
    string line;

    if (!inputfile.is_open()) {
        perror("Error open");
        exit(EXIT_FAILURE);
    };

    while (getline(inputfile, line)) {
        istringstream iss(line);

        int min, max;
        string letter, password;
        char separator = ':';

        letter = line[line.find(separator)-1];
        password = line.erase(0,line.find(separator)+2);

        iss >> min >> max ;

        string string_wanted = "(.*)" , string_unwanted = "(.*)";
        for (int i = 0; i < min; i++){
            string_wanted += "(" + letter + ")(.*)";
        };

        for (int i = 0; i < max+1; i++){
            string_unwanted += letter + "(.*)";
        };

        if (regex_match (password, regex(string_wanted)) && not (regex_match (password, regex(string_unwanted)))) {
            cout << min << " " << max << " " << letter << ": " << line << " -- yes" << endl;
        };
    };

    inputfile.close();
}