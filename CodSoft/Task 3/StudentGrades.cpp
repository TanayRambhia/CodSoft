#include <iostream>
#include <string>
#include <limits>

const int MAX_STUDENTS = 10;

void displayMenu() {
    std::cout << "\n--- Student Grade Management ---\n";
    std::cout << "1. Add student grades\n";
    std::cout << "2. Calculate average grade\n";
    std::cout << "3. Display highest and lowest grades\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice (1-4): ";
}

void addStudentGrades(std::string names[], int grades[][5], int& numStudents) {
    if (numStudents >= MAX_STUDENTS) {
        std::cout << "\nMaximum number of students reached.\n";
        return;
    }

    std::string name;
    std::cout << "\nEnter student name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    names[numStudents] = name;

    std::cout << "Enter 5 grades (separated by spaces): ";
    for (int i = 0; i < 5; ++i) {
        std::cin >> grades[numStudents][i];
    }

    ++numStudents;
}

double calculateAverage(int grades[], int numGrades) {
    int sum = 0;
    for (int i = 0; i < numGrades; ++i) {
        sum += grades[i];
    }
    return static_cast<double>(sum) / numGrades;
}

void displayHighestAndLowest(int grades[], int numGrades) {
    int highest = grades[0];
    int lowest = grades[0];

    for (int i = 1; i < numGrades; ++i) {
        highest = std::max(highest, grades[i]);
        lowest = std::min(lowest, grades[i]);
    }

    std::cout << "\nHighest grade: " << highest << std::endl;
    std::cout << "Lowest grade: " << lowest << std::endl;
}

int main() {
    std::string names[MAX_STUDENTS];
    int grades[MAX_STUDENTS][5];
    int numStudents = 0;

    while (true) {
        displayMenu();

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudentGrades(names, grades, numStudents);
                break;
            case 2:
                if (numStudents == 0) {
                    std::cout << "\nNo student grades found. Please add grades first.\n";
                } else {
                    for (int i = 0; i < numStudents; ++i) {
                        double average = calculateAverage(grades[i], 5);
                        std::cout << "\nAverage grade for " << names[i] << ": " << average << std::endl;
                    }
                }
                break;
            case 3:
                if (numStudents == 0) {
                    std::cout << "\nNo student grades found. Please add grades first.\n";
                } else {
                    for (int i = 0; i < numStudents; ++i) {
                        std::cout << "\nGrades for " << names[i] << ":\n";
                        displayHighestAndLowest(grades[i], 5);
                    }
                }
                break;
            case 4:
                std::cout << "\nExiting program. Goodbye!\n";
                return 0;
            default:
                std::cout << "\nInvalid choice. Please enter a valid option.\n";
        }
    }
}
