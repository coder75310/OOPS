/* #include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

bool containsError(const std::string& line) {
    // Convert the line to lowercase for case-insensitive search
    std::string lowerLine = line;
    std::transform(lowerLine.begin(), lowerLine.end(), lowerLine.begin(), ::tolower);
    return lowerLine.find("error") != std::string::npos;
}

int main() {
    std::ifstream logFile("logfile.txt");
    std::ofstream errorFile("error.txt");

    if (!logFile.is_open()) {
        std::cerr << "Error: Unable to open logfile.txt" << std::endl;
        return 1;
    }

    if (!errorFile.is_open()) {
        std::cerr << "Error: Unable to open error.txt" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(logFile, line)) {
        if (containsError(line)) {
            errorFile << line << std::endl;
        }
    }

    logFile.close();
    errorFile.close();

    std::cout << "Error messages have been written to error.txt" << std::endl;
    return 0;
} */



















#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
bool isWordPresent(string sentence, string word)
{
    // To break the sentence in words
    stringstream s(sentence);
 
    // To temporarily store each individual word
    string temp;
 
    while (s >> temp) {
 
        // Comparing the current word
        // with the word to be searched
        if (temp.compare(word) == 0) {
            return true;
        }
    }
    return false;
}
int main()
{
   ofstream o1("logfile.txt");
   o1<<"[2023-12-1 10:00:00] Error : Application started"<<endl;
   o1<<"[2023-12-1 10:00:05] Error : Connection Failed"<<endl;
   o1<<"[2023-12-1 10:10:00] Error : Database Error"<<endl;
   o1<<"[2023-12-1 10:15:00] Warning: Close the Application"<<endl;

   ofstream e1("error.txt");

    string line;
    string word = "Error";
   ifstream in("logfile.txt");
   while(in){
    getline(in,line);
    if(isWordPresent(line,word)==true){
        e1<<line<<endl;
    }
    cout<<line<<endl;
   }
   return 0;
}
