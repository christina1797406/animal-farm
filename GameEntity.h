#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
// include class header files

using namespace sf;

class GameEntity {
    private:
        sf::RenderWindow* win;



    public:
        GameEntity(int size, std::string title) {
            win = new sf::RenderWindow(sf::VideoMode(size,size), title);
        }
    

        // function to run the loop/game
        void run() {
            while (win->isOpen()) {

                Event e;
                while (win->pollEvent(e)) {
                    if (e.type == Event::Closed) {
                        win->close();
                    }

                    // add more functions for windows



                    
                }

                win->clear();
                
            }
        }
        
        ~GameEntity() {}
};

#endif