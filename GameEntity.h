#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

// include class header files
#include "User.h"
#include "Flower.h"

using namespace sf;

class GameEntity {
    private:
        sf::RenderWindow* win;
        User* user;
        std::vector<Flower*> flowers;       // to store multiple flowers

        sf::Text info;
        sf::Font font;


    public:
        GameEntity(int size, std::string title) {
            win =       new sf::RenderWindow(sf::VideoMode(size,size), title);
            user =      new User();

            //// add code
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
                win->display();
                
            }
        }
        
        ~GameEntity() {
            delete win;
            delete user;
        }
};

#endif