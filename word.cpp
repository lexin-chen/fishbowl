#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<std::string> loadDictionary(const std::string& filename) {
    std::vector<std::string> dictionary;
    std::ifstream file(filename);
    
    if (file.is_open()) {
        std::string word;
        while (std::getline(file, word)) {
            dictionary.push_back(word);
        }
        
        file.close();
    } else {
        std::cerr << "Failed to open dictionary file: " << filename << std::endl;
    }
    
    return dictionary;
}

std::string generateRandomWord(const std::vector<std::string>& dictionary) {
    int index = rand() % dictionary.size();
    return dictionary[index];
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    // Load dictionary
    std::vector<std::string> dictionary = loadDictionary("dictionary.txt");
    
    // Generate random word
    std::string randomWord = generateRandomWord(dictionary);
    
    std::cout << "Random word: " << randomWord << std::endl;
    
    return 0;
}