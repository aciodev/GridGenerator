// Author: Andres Cruz
// Class: COMP620 - Computer Architecture
// Date: February 18, 2023
// Term: Spring 2023

#include <iostream>
#include <fstream>
#include <vector>
#include <random>

// Helper function to generate subsets using backtracking
void findAllPairsHelper(std::vector<std::vector<int>> &sol, std::vector<int> &curr, int l, int n, int t) {
    if (curr.size() == t) {
        sol.push_back(curr);
        return;
    }

    if (l == n) {
        return;
    }

    curr.push_back(l);
    findAllPairsHelper(sol, curr, l + 1, n, t);
    curr.pop_back();
    findAllPairsHelper(sol, curr, l + 1, n, t);
}

// Create pairs of size T of the elements 0 to n
std::vector<std::vector<int>> findAllPairs(int n, int t) {
    std::vector<std::vector<int>> sol;
    std::vector<int> curr;
    findAllPairsHelper(sol, curr, 0, n, t);
    return sol;
}

// Run the program
int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    std::vector<int> inputSizes = {5, 6, 7, 8, 9, 10, 25, 50, 100};

    for (int &inputSize: inputSizes) {
        // Open the file for writing
        std::string fileName = "n_" + std::to_string(inputSize) + ".txt";
        std::ofstream file;
        file.open(fileName);

        // Initially fill with -1s
        std::vector<std::vector<int>> finalGrid(inputSize, std::vector<int>(inputSize, -1));

        // Fill in pairs correctly
        std::vector<std::vector<int>> allPairs = findAllPairs(inputSize, 2); // Find all index pairs of inputSize 2
        for (auto &pair: allPairs) {
            int randomNumber = dis(gen);
            finalGrid[pair[0]][pair[1]] = randomNumber;
            finalGrid[pair[1]][pair[0]] = randomNumber;
        }

        // Print the grid to the file
        for (int i = 0; i < inputSize; ++i) {
            for (int j = 0; j < inputSize; ++j) {
                file << finalGrid[i][j] << " ";
            }
            file << "\n";
        }

        // Close the file
        file.close();
    }
}
