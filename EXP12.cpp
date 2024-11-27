#include <iostream>
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
}
