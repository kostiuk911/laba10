#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Route {
    int number;
    std::string start;
    std::string end;
    int distance;
};

int main() {
    std::vector<Route> routes;

    std::ifstream file("t.txt");
    int number, distance;
    std::string start, end;
    while (file >> number >> start >> end >> distance) {
        Route route = { number, start, end, distance };
        routes.push_back(route);
    }

    while (true) {
        std::cout << "1. Create route\n";
        std::cout << "2. View routes\n";
        std::cout << "3. Update route\n";
        std::cout << "4. Display information about a route\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Enter route number: ";
            std::cin >> number;
            std::cout << "Enter start location: ";
            std::cin >> start;
            std::cout << "Enter end location: ";
            std::cin >> end;
            std::cout << "Enter distance: ";
            std::cin >> distance;

            Route route = { number, start, end, distance };
            routes.push_back(route);
            std::cout << "Route added successfully!" << std::endl;
        }
        else if (choice == 2) {
            std::cout << "Number\tStart\tEnd\tDistance\n";
            for (const auto& route : routes) {
                std::cout << route.number << "\t" << route.start << "\t" << route.end
                    << "\t" << route.distance << std::endl;
            }
        }
        else if (choice == 3) {
            std::cout << "Enter route number: ";
            std::cin >> number;

            bool found = false;
            for (auto& route : routes) {
                if (route.number == number) {
                    std::cout << "Enter start location: ";
                    std::cin >> start;
                    std::cout << "Enter end location: ";
                    std::cin >> end;
                    std::cout << "Enter distance: ";
                    std::cin >> distance;

                    route.start = start;
                    route.end = end;
                    route.distance = distance;
                    found = true;
                    break;
                }
            }
            if (found) {
                std::cout << "Route updated successfully!" << std::endl;
            }
            else {
                std::cout << "Route not found!" << std::endl;
            }
        }
        else if (choice == 4) {
            std::cout << "Enter route number: ";
            std::cin >> number;

            bool found = false;
            for (const auto& route : routes) {
                if (route.number == number) {
                    std::cout << "Number: " << route.number << std::endl;
                    std::cout << "Start: " << route.start << std::endl;
                    std::cout << "End: " << route.end << std::endl;
                    std::cout << "Distance: " << route.distance << std::endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Route not found!" << std::endl;
            }
        }
    }

    return 0;
}