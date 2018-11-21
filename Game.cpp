//
//  Game.cpp
//  hello
//
//  Created by Luis Villalba on 11/20/18.
//  Copyright © 2018 Luis Villalba. All rights reserved.
//

#include <iostream>
#include <string>
#include "Game.hpp"

void Game::init() {
    std::cout << "Hello, welcome to bulls and cows \n";

    while (!guessIsCorrect() && currentTries < MAX_TRIES) {
        getGuess();
        computeBulls();
        computeCows();
        std::cout << (!guessIsCorrect() ? "You have " + std::to_string(bulls) + " bulls and " + std::to_string(cows) + " cows." : "") << std::endl;
        currentTries++;
    }

    std::cout << (guessIsCorrect() ? "You Win" : "\n You Lose") << std::endl;
}

Game::Game() : MAX_TRIES(10) {
    std::cout << "Initializing...\n";
    currentTries = 0;
    expectedWord = "aprendiendo";
}

bool Game::guessIsCorrect() {
    return word.length() == expectedWord.length() && bulls == word.length();
}

void Game::getGuess() {
    std::cout << "Insert a " << expectedWord.length() << " letter word: ";
    std::getline(std::cin, word);
}

int Game::computeBulls() {
    bulls = 0;
    for (int i = 0; i < word.length(); i++) {
        bulls += word[i] == expectedWord[i] ? 1 : 0;
    }
    return bulls;
}

int Game::computeCows() {
    cows = 0;
    for (int i = 0; i < word.length(); i++) {
        if (word[i] != expectedWord[i]) { // not a bull
            for (int j = 0; j < word.length(); j++) {
                cows += (j != i && word[i] == expectedWord[j] && expectedWord[j] != word[j]) ? 1 : 0;
            }
        }
    }
    return cows;
}
