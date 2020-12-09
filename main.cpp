// Lee-Way Wang
// 11/14/2020

// YazInterpreter
// This program interprets YazLang programs and outputs the results to a
// text file. The user can select which YazLang file to interpret, and the user
// can also view the interpreted results.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;


void printIntroduction(){
    cout << "Welcome to YazInterpreter!" << endl;
    cout << "You may interpret a YazLang program and output" << endl;
    cout << "the results to a file or view a previously" << endl;
    cout << "interpreted YazLang program.\n" << endl;
}


// Appends a string to a text file.
void appendToFile(string outputFileName, string outputString){
    ofstream outFile(outputFileName.c_str(), ios::app);
    outFile << outputString << endl;
}


// Prints to console the entire contents of a text file.
void printFileContents(string fileName){
    ifstream openFile;
    openFile.open(fileName.c_str());
    string line;

    while (getline(openFile, line)){
        cout << line << endl;
    }
    openFile.close();
}


// Interprets the CONVERT command. Converts a temperature from Celsius to
// Fahrenheit and vice versa. Returns a string containing the converted
// temperature and the new temperature scale (C or F).
string interpretCONVERT(std::stringstream &wordStream){
    double temperature;
    string tempScale;
    wordStream >> temperature;
    wordStream >> tempScale;

    int convertedTemp;
    string newTempScale;
    string f = "f";
    string F = "F";

    if (tempScale == f || tempScale == F){
        convertedTemp =  (int) trunc((temperature - 32) / 1.8);
        newTempScale = "C";
    } else {
        convertedTemp = (int) trunc((1.8 * temperature) + 32);
        newTempScale = "F";
    }
    stringstream stringTemp;
    stringTemp << convertedTemp;

    string outputString = stringTemp.str() + newTempScale;
    return outputString;
}


// Interprets the RANGE command. Based on a starting and ending value, this
// function returns a string of all numbers between the starting and ending value.
// Starting at the starting value, each subsequent number is incremented by a
// specific value.
string interpretRANGE(std::stringstream &wordStream){
    int start;
    wordStream >> start;
    int stop;
    wordStream >> stop;
    int increment;
    wordStream >> increment;

    string outputString = "";

    for (int i = start; i < stop; i += increment){
        stringstream ss;
        ss << i;
        outputString += ss.str() + " ";
    }

    return outputString;
}


// Interprets the REPEAT command. Repeats a certain string a certain number
// of times. There can be an arbitrary number of string/number pairs. Returns
// a string containing all repeated strings.
string interpretREPEAT(std::stringstream &wordStream){
    string word;
    string outputString = "";

    while (wordStream >> word){
        // Replace the quotation marks at the beginning and end of the
        // word with an empty string.
        word.replace(0, 1, "", 0);
        word.replace(word.size() - 1, 1, "", 0);

        // Replace every underscore with a space
        replace(word.begin(), word.end(), '_', ' ');

        int repetitions;
        wordStream >> repetitions;

        for (int i = 0; i < repetitions; i++){
            outputString += word;
        }
    }
    return outputString;
}


// Interprets a YZY file. Appends the output of each command to a new line
// of an output file.
void readFileContents(string fileName, string outputFileName){
    // Erases the contents of the output file.
    fstream eraseContent;
    eraseContent.open(outputFileName.c_str(), ios::out | ios::trunc);
    eraseContent.close();

    ifstream openFile;
    openFile.open(fileName.c_str());
    string line;
    string outputString;

    while (getline(openFile, line)){
        // Tokenize the line. In other words, split the word on its spaces.
        stringstream wordStream(line);
        string word;
        wordStream >> word;

        if (word == "CONVERT"){
            outputString = interpretCONVERT(wordStream);
        } else if (word == "RANGE"){
            outputString = interpretRANGE(wordStream);
        } else if (word == "REPEAT") {
            outputString = interpretREPEAT(wordStream);
        }
        appendToFile(outputFileName, outputString);
    }
    openFile.close();
}


int main(){
    printIntroduction();

    string userOption;

    while (1){
        string inputFile;
        string outputFile;
        cout << "(I)nterpret .yzy program, (V)iew .yzy output, (Q)uit? ";
        cin >> userOption;

        if (userOption.length() == 1 && (userOption[0] == 'i' || userOption[0] == 'I')){
            cout << "Input file name: ";
            while (1){
                cin >> inputFile;
                ifstream inFile;
                inFile.open(inputFile.c_str());

                if (inFile){
                    cout << "Output file name: ";
                    cin >> outputFile;
                    readFileContents(inputFile, outputFile);
                    cout << "YazLang interpreted and output to a file!\n" << endl;
                    break;
                } else{
                    cout << "File not found. Try again: ";
                }
            }

        } else if (userOption.length() == 1 && (userOption[0] == 'v' || userOption[0] == 'V')){
            cout << "Input file name: ";

            while(1){
                cin >> inputFile;
                ifstream inFile;
                inFile.open(inputFile.c_str());

                if (inFile){
                    cout << "" << endl;
                    printFileContents(inputFile);
                    cout << "" << endl;
                    break;
                } else{
                    cout << "File not found. Try again: ";
                }
            }
        } else if (userOption.length() == 1 && (userOption[0] == 'q' || userOption[0] == 'Q')){
            break;
        } else {
            //Do nothing. Go back to the top of the while loop.
        }
    }
    return 0;
}
