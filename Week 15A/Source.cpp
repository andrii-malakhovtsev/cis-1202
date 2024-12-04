// Andrii Malakhovtsev
// CIS 1202 501
// December 3, 2024

#include <iostream>
#include <stdexcept>
using namespace std;

class invalidCharacterException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid character: start is not a letter (A-Z, a-z).";
    }
};

class invalidRangeException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid range: the target is not a letter.";
    }
};

char character(char, int);
void characterTest(char, int);

int main()
{
    characterTest('a', 1);

    characterTest('a', -1);

    characterTest('Z', -1);

    characterTest('?', 5);

    characterTest('A', 32);

    return 0;
}

char character(char start, int offset) {
    if (!((start >= 'A' && start <= 'Z') || (start >= 'a' && start <= 'z'))) {
        throw invalidCharacterException();
    }

    char target = start + offset;

    if ((start >= 'A' && start <= 'Z' && (target < 'A' || target > 'Z')) ||
        (start >= 'a' && start <= 'z' && (target < 'a' || target > 'z'))) {
        throw invalidRangeException();
    }

    return target;
}

void characterTest(char start, int offset) {
    try {
        cout << "character(" << start << ", " << offset << "): " << character(start, offset) << endl;
    }
    catch (exception& e) {
        cout << "character(" << start << ", " << offset << "): threw an exception: " << e.what() << endl;
    }
}

