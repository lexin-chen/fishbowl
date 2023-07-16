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
    std::cout << "Welcome to Fishbowl!" << std::endl;
    std::cout << "How many players per team? (Default: 2)" << std::endl;
    int numPlayers;
    std::cin >> numPlayers;
    std::cout << "How many words per player?" << std::endl;
    int numWords;
    std::cin >> numWords;
    int roundTime = 60;
    for (int i = 0; i < numPlayers; i++)
    {
        std::cout << "Enter player " << i << " name: " << std::endl;
        std::string playerName;
        std::cin >> playerName;
        for (int j = 0; j < numWords; j++){
            std::cout << "Enter word/phase: " << std::endl;
            std::string word;
            std::cin.ignore();
            std::getline(std::cin, word);
            //if enter is pressed, generate random word
            if (word == ""){
                srand(static_cast<unsigned int>(time(0)));
                // Load dictionary
                std::vector<std::string> dictionary = loadDictionary("dictionary.txt");
                // Generate random word
                std::string randomWord = generateRandomWord(dictionary);
                std::cout << "Random word: " << randomWord << std::endl;
            } else {
                std::cout << "Word/phrase: " << word << std::endl;
            }

        }
    }
    //assign teams
    std::cout << "How many teams?" << std::endl;
    int numTeams;
    std::cin >> numTeams;
    std::cout << "random teams? (yes or no)" << std::endl;
    std::string teamChoice;
    std::cin >> teamChoice;
    if (teamChoice == "yes"){
        std::vector<std::vector<int>> teams(numTeams);
        for (int i = 0; i < numTeams; i++){
            int team = rand() % numTeams;
            teams[team].push_back(i);
        }
        // Output teams
        for (int i = 0; i < numTeams; i++){
            std::cout << "Team " << i + 1 << ": ";
            for (int j = 0; j < teams[i].size(); j++){
                std::cout << teams[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
}
