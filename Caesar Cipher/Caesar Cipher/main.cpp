#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "cipher.h"

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ios_base;
using std::ifstream;
using std::copy;
using std::numeric_limits;
using std::streamsize;

// the file to be encrypted
const string& inputFilePath = "test.txt";

int main() {
    string target_file = inputFilePath;
    
    ifstream input_file(target_file);
    if (!input_file.is_open()) {
        cout << "Input file couldn't open." << endl;
        return 1;
    }

    int shift;
    cout << "Shift value: ";
    cin >> shift;
    while (cin.fail()) {
        cout << "Invalid input please enter a number." << endl;
        cout << "Shift value: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> shift;
    }

    string direction;
    getline(cin, direction);
    while (direction != "left" && direction != "right") {
        cout << "Invalid input please enter 'left' or 'right'." << endl;
        cout << "Direction (left/right): ";
        getline(cin, direction);
        cin.clear();
    }

    vector<char> vec;
    string file_string;
    string original_output_string = "";

    cout << "File contents:" << endl;
    while (getline(input_file, file_string)) {
        copy(file_string.begin(), file_string.end(), back_inserter(vec));
        cout << file_string << endl;
        original_output_string += file_string + '\n' ;
    }

    input_file.close();
    cipher(vec, target_file, original_output_string, shift, direction);

    return 0;
}