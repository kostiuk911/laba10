#include <fstream>
#include <sstream>
#include <string> 
#include <iostream>
bool hasWordStartingWithA(const std::string& str) {
    // Set up a stringstream to parse the string
    std::stringstream ss(str);

    // Read each word from the stringstream
    std::string word;
    while (ss >> word) {
        // Check if the word starts with "a"
        if (!word.empty() && word[0] == 'a') {
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

    // Check if the string contains a word that starts with "a"
    if (hasWordStartingWithA(str)) {
        std::cout << "The file contains a word that starts with the letter 'a'." << std::endl;
    }
    else {
        std::cout << "The file does not contain a word that starts with the letter 'a'." << std::endl;
    }

    return 0;
}