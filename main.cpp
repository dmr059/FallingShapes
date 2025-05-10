#include <SFML/Graphics.hpp>
#include "Game.h"


int main() {

    //Init srand - initilize seed for random gen
    
    /*
        LINE BREAKDOWN:

        - time(NULL) - gives CURRENT TIME since Jan 1, 1970
                >>> returns value of time_t

        - static_cast<unsigned>(...) - cases time(NULL) to an unsigned int
                >>> srand() EXPECTS an unsigned int, this ensures the correct type
    
    */
    
    std::srand(static_cast<unsigned>(time(NULL)));
    
    //initi game engine
    Game game;  

    //Game Loop
    while (game.running() && !game.getEndGame()) {
        
        //Update
        game.update();
         

        //Render
        game.render();    

    }

    return 0;

}