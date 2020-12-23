#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
#include <ctime>
#include <regex>
#include <sstream>

using namespace std;


int day2_part1(string filepath){

    int amount_valid_strings = 0;
    // set parameters
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
        max = sqrt(max*max);

        string string_wanted = "(.*)" , string_unwanted = "(.*)";
        for (int i = 0; i < min; i++){
            string_wanted += "(" + letter + ")(.*)";
        };

        for (int i = 0; i < max+1; i++){
            string_unwanted += letter + "(.*)";
        };

        if (regex_match (password, regex(string_wanted)) && not (regex_match (password, regex(string_unwanted)))) {
            amount_valid_strings++;
            cout << min << " " << max << " " << letter << ": " << line << " -- yes" << endl;
        };
    };

    inputfile.close();

    cout << amount_valid_strings << endl;

    return amount_valid_strings;
}

int day2_part2(string filepath){
    int amount_valid_strings = 0;

    // set parameters
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
        string password;
        char letter, separator = ':';

        cout << line << endl;

        letter = line[line.find(separator)-1];
        password = line.erase(0,line.find(separator)+2);

        iss >> min >> max ;
        max = sqrt(max*max);

        if ((line[min-1] == letter) ^ (line[max-1] == letter)) {
            amount_valid_strings++;
            cout << min << " " << max << " " << letter << ": " << line << " -- yes" << endl;
        };
    };

    inputfile.close();

    cout << amount_valid_strings << endl;

    return amount_valid_strings;
}


int day2(string filepath) {
    day2_part1(filepath);
    day2_part2(filepath);

    return 0;
}


int main() {
    //day1(200, "/home/lars/CLionProjects/Advent_of_Suffering/d1_input.txt");
    day2("/home/lars/CLionProjects/Advent_of_Suffering/d2_input.txt");
    cout << "Hello, world!" << endl;
    return 0;
}