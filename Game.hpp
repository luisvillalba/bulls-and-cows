//
//  Game.hpp
//  hello
//
//  Created by Luis Villalba on 11/20/18.
//  Copyright © 2018 Luis Villalba. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <string>

class Game {
public:
    Game();
    void restart();
    void init();
    void getGuess();
    bool guessIsCorrect();
    int computeBulls();
    int computeCows();


private:
    int MAX_TRIES;
    int currentTries;
    int bulls;
    int cows;
    std::string expectedWord;
    std::string word;
};

#endif /* Game_hpp */
