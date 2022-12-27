#include <fstream>
#include <string>
#include <iostream>

int main()
{
    // Open the file for reading
    std::ifstream file("file.txt");

    // Check if the file was opened successfully
    if (!file.is_open())
    {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    // Count the number of lines that start with the given character
    char start_char = 'H'; // The character to search for
    int count = 0; // The number of lines that start with the given character
    std::string line; // A string to hold each line as it is read
    while (std::getline(file, line)) // Read the file line by line
    {
        // Check if the first character of the line is the given character
        if (!line.empty() && line[0] == start_char)
        {
            count++;
        }
    }

    // Print the result
    std::cout << "Number of lines that start with '" << start_char << "': " << count << std::endl;

    // Close the file
    file.close();

    return 0;
}