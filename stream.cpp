//
// Created by amedvedev on 16/11/23.
//


#include "stream.h"
#include "position.h"



void print_pos(const int * pos) {
    for (int i = 0; i < n; i++) cout << pos[i] << " ";
    cout << endl;
}

void print_sol(vector<int> &sol) {
    for (int el: sol) cout << el << " -> ";
    cout << "<end>." << endl;
}



int * read_vector() {
    std::ifstream inFile("./input_position.txt");
    std::string line;

    int * pos = new_pos();

    // Read the file line by line
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        char ch;

        // Split the line into individual characters and convert to bool
        int i = 0;
        while (iss >> ch) {
            pos[i] = (ch == '1') ? 1: 0;
            i++;
        }
    }

    return pos;
}

void writeSol(vector<int> &sol) {
    ofstream outFile;
    outFile.open("./fastest_answer.txt");

    for (int mv : sol) {
        outFile << mv << " ";
    }

    outFile.close();
}
