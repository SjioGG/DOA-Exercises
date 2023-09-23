#include <iostream>
#include <vector>
#include <random>

int main() {
    int M;
    std::cout << "Enter the number of integers in the vector (M): ";
    std::cin >> M;

    std::vector<int> random_vector;

    int min_value, max_value;
    std::cout << "Enter the minimum value for random integers: ";
    std::cin >> min_value;
    std::cout << "Enter the maximum value for random integers: ";
    std::cin >> max_value;

    // Seed for random number generation
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(min_value, max_value);

    // Generate the vector of random integers
    for (int i = 0; i < M; ++i) {
        random_vector.push_back(distribution(gen));
    }

    int count = 0;
    int integer_to_count;
    std::cout << "Enter an integer to count in the vector: ";
    std::cin >> integer_to_count;

    // Count how many times the integer_to_count appears in the vector using an iterator
    for (auto it = random_vector.begin(); it != random_vector.end(); ++it) {
        if (*it == integer_to_count) {
            count++;
        }
    }

    std::cout << "Generated Vector: ";
    for (const int& num : random_vector) {
        std::cout << num << " ";
    }
    std::cout << "\nNumber of times " << integer_to_count << " appears in the vector: " << count << std::endl;

    return 0;
}
