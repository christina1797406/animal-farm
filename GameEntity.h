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

        sf::Texture backgroundTexture;
        sf::Sprite backgroundSprite;

        sf::Text info;
        sf::Font font;


    public:
        GameEntity(int x_size, int y_size, std::string title) {
            win =       new sf::RenderWindow(sf::VideoMode(x_size, y_size), title);
            user =      new User("Christina", 30);

            //// add code
            if (!backgroundTexture.loadFromFile("./sfml/background.png")) {
                std::cout << "Failed to load background file." << std::endl;
                return;
            }

            backgroundSprite.setTexture(backgroundTexture);
            backgroundSprite.setPosition(0.0f, 0.0f);
            backgroundSprite.setScale(0.5f, 0.5f);
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

                    // 1. to move player
                    if (Keyboard::isKeyPressed(Keyboard::A)) {
                            user->move_left(6);       
                    } else if (Keyboard::isKeyPressed(Keyboard::D)) {
                            user->move_right(6);
                    } else if (Keyboard::isKeyPressed(Keyboard::W)) {
                            user->move_up(6);
                    } else if (Keyboard::isKeyPressed(Keyboard::S)) {
                            user->move_down(6);
                    }

                    


                    
                }

                win->clear();
                win->draw(backgroundSprite);

                user->draw(win);
                //flower->draw(*win);

                win->display();
                
            }
        }
        
        ~GameEntity() {
            delete win;
            delete user;
        }
};

#endif