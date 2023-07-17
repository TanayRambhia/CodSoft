#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }

    std::string word;
    int wordCount = 0;

    while (file >> word) {
        ++wordCount;
    }

    file.close();

    std::cout << "Number of words in the file: " << wordCount << std::endl;

    return 0;
}
