#include <fstream>
#include <string>
#include <iostream>
bool hasAdjacentPair(const std::string& str) {
    for (size_t i = 0; i < str.size() - 1; ++i) {
        if (str[i] == 'a' && str[i + 1] == 'a') {
            return true;
        }
        if (str[i] == 'b' && str[i + 1] == 'b') {
            return true;
        }
        if (str[i] == 'c' && str[i + 1] == 'c') {
            return true;
        }
    }
    return false;
}
int main() {
    // Open the text file for reading
    std::ifstream file("t.txt");

    // Read the contents of the file into a string
    std::string str((std::istreambuf_iterator<char>(file)),
        std::istreambuf_iterator<char>());

    // Check if the string has a pair of adjacent "aa", "bb", or "cc"
    if (hasAdjacentPair(str)) {
        std::cout << "There is a pair of adjacent letters 'aa', 'bb', or 'cc' in the file." << std::endl;
    }
    else {
        std::cout << "There is no pair of adjacent letters 'aa', 'bb', or 'cc' in the file." << std::endl;
    }

    return 0;
}