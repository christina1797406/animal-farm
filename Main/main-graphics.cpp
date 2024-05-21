// Graphics
// To compile on Linux:
    // g++ -c graphics/main.cpp
    // g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
    // ./sfml-app

#include <SFML/Graphics.hpp>
#include<iostream>
#include<cmath>

#include "../Include/Farm.h"
#include "../Include/User.h"
#include "../Include/Shovel.h"
#include "../Include/Vegetable.h"
#include "../Include/Flower.h"

int main()
{
    std::cout << "Welcome to the Farming Simulator!" << std::endl; 

    // Ask user for name
    std::string userName;
    std::cout << "Enter your name: ";
    std::cin >> userName;

    // Ask user age
    int userAge;
    std::cout << "Enter your age: ";
    std::cin >> userAge;

    // Create a User object
    User user(userName, userAge);

    // Ask user for farm name
    std::string farmName;
    std::cout << "Enter a name for your farm: ";
    std::cin >> farmName;

    // Create a Farm object
    Farm farm(farmName, 100, user);  // Starting with 100 coins

    // Provide game instructions
    std::cout << "\nWelcome, " << user.getName() << "!" << std::endl;
    std::cout << "You are " << user.getAge() << " years old." << std::endl;
    std::cout << "Your farm, " << farm.get_farmName() << ", is ready to go!"
                << std::endl;
    std::cout
        << "In this game, you will manage your farm by buying and selling crops, "
        << "refilling your water can, and repairing equipment. Let's start "
            "Farming!"
        << std::endl;

    // Create window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Farm Game");

    // Create brackground sprite
    sf::Sprite* grassSprite = farm.createBackground();
    
    // Create an array of textures for the character sprite
    sf::Texture** characterAnims = user.createAnimation();

    // Create dirt sprite
    Shovel shovel;

    // Flower
    Flower flower;

    // Create the character srite
    sf::Sprite characterSprite;
    characterSprite.setScale(10, 10);
    // Set the character sprite's texture the the first frame of the first animation (standing idle)
    characterSprite.setTexture(characterAnims[0][0]);
    
    // Add variables for keeping track of the animation
    int curAnimFrame = 2;
    float skippedFrames = 0;

    // Add variable for selected cell in hotbar
    int curCell = 0;

    // For the UI
    bool pressed = false;
    
    // For the inventory
    bool pressed2 = false;

    // Sprites for when the palyer digs
    std::vector<sf::Sprite*> dirtSprites;
    std::vector<Vegetable*> vegetables;
    std::vector<sf::Sprite*> flowerSprites;

    // Load a texture for the flowers
    sf::Texture flowerTexture;
    flowerTexture.loadFromFile("Sprites/Objects/Basic_Grass_Biom_things.png", sf::IntRect(112, 34, 16, 16));

    // Inventory cells and sprites
    sf::RectangleShape* inventoryCells[10];
    sf::Sprite* inventoryIcons[10];

    // Create inventory
    for (int i = 0; i < 10; i++) {
        sf::RectangleShape* cell = new sf::RectangleShape;
        cell->setSize(sf::Vector2f(100.f, 100.f));
        cell->setPosition(sf::Vector2f(((1920 * 0.5) - 600) + (120 * i), 960));
        cell->setFillColor(sf::Color::White);

        inventoryCells[i] = cell;



        //////// Adding sprites to the inventory /////////
        // Create icon sprite
        sf::Sprite* iconSprite = new sf::Sprite;
        // Create icon texture
        sf::Texture* iconTexture = new sf::Texture;

        if (user.inventory[i] != nullptr) {
            if (user.inventory[i]->GetName() == "Shovel") {
                iconTexture->loadFromFile("Sprites/Characters/Tools.png", sf::IntRect(0, 64, 16, 16));
            } else if (user.inventory[i]->GetName() == "Watering Can") {
                iconTexture->loadFromFile("Sprites/Characters/Tools.png", sf::IntRect(0, 0, 16, 16));
            } else if (user.inventory[i]->GetName() == "Seeds") {
                iconTexture->loadFromFile("Sprites/Objects/Basic_Plants.png", sf::IntRect(0, 0, 16, 16));
            } else if (user.inventory[i]->GetName() == "Flower Seeds") {
                iconTexture->loadFromFile("Sprites/Objects/Basic_Grass_Biom_things.png", sf::IntRect(112, 34, 16, 16));
            }
         }

        // Set the sprite texture to the texture
        iconSprite->setTexture(*iconTexture);
        iconSprite->setScale(5, 5);
        iconSprite->setPosition(sf::Vector2f(((1920 * 0.5) - 600) + (120 * i), 960));

        inventoryIcons[i] = iconSprite;
    }



    // Create border for selected cell
    sf::RectangleShape cellBorder;
    cellBorder.setSize(sf::Vector2f(110.f, 110.f));
    cellBorder.setFillColor(sf::Color::Black);



    // Create font
    sf::Font font;
    font.loadFromFile("Fonts/upheavtt.ttf");

    // Create money text
    sf::Text text;
    text.setFont(font); // font is a sf::Font
    text.setString("$" + std::to_string(farm.getMoney()));
    text.setCharacterSize(80);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);

    text.setOutlineColor(sf::Color(0,0,0,225));
    text.setOutlineThickness(5);

    text.setPosition(40, 0);


    // While the window is open (user hasn't closed it)
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();

        // Check for the closed event
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                // Clsoe the window
                window.close();
        }

        // Inventory controls
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && pressed == false) { curCell -= 1; pressed = true; }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && pressed == false) { curCell += 1; pressed = true; }
        else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !sf::Keyboard::isKeyPressed(sf::Keyboard::E)) { pressed = false; }

        // Reset hotbar pos when it gets to the edge
        if (curCell > 9) { curCell = 0; }
        if (curCell < 0) { curCell = 9; }

        // Create direction vector variable
        sf::Vector2f direction;

        // Check for user input and set the direction vector
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { direction.y = -1; }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { direction.y = 1; }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { direction.x = -1; }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { direction.x = 1; }

        // Get the length of the direction vector
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

        // Normalize the vector if the length is more than 0
        if (length != 0) {
            direction = sf::Vector2f(direction.x / length, direction.y / length);
        } else {
            direction = sf::Vector2f(0.f, 0.f);
        }

        // Check if enough frames has elapsed to play the next frame of the animation
        skippedFrames += elapsed.asSeconds();
        if (skippedFrames > user.getAnimFramerate()) { 
            skippedFrames = 0;
            curAnimFrame += 1;
            if (curAnimFrame == 4) { curAnimFrame = 2; };
            if (length == 0 && curAnimFrame > 1) { curAnimFrame -= 2; }
        }

        // Set the direction of the player based off the user input
        int dir = 0;
        if (direction.y > 0) { dir = 0; } else if (direction.y < 0) { dir = 1; }
        if (direction.x > 0) { dir = 3; } else if (direction.x < 0) { dir = 2; }
        
        // Set te characters texture to the current animation frame
        characterSprite.setTexture(characterAnims[dir][curAnimFrame]);

        // Move the character in the direction multiplied by the walkSpeed
        characterSprite.move(direction.x * user.getWalkSpeed() * elapsed.asSeconds(), direction.y * user.getWalkSpeed() * elapsed.asSeconds());

        // Mouse controls
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (pressed2 == false) {
                //std::cout << dirtSprites.size() << std::endl;
                pressed2 = true;

                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                localPosition = sf::Vector2i(localPosition.x - localPosition.x % 80, localPosition.y - localPosition.y % 80);

                if (user.inventory[curCell] != nullptr) {
                    //std::cout << user.inventory[curCell]->GetName() << std::endl;

                    if (user.inventory[curCell]->GetName() == "Shovel") {
                        // Dig a hole and "snap" it to the grid
                        dirtSprites.push_back(shovel.digHole(localPosition));
                    } else if (user.inventory[curCell]->GetName() == "Watering Can") {
                        std::cout << "Watering Can selected!\n";
                    } else if (user.inventory[curCell]->GetName() == "Seeds") {
                        for (int i = 0; i < (int)dirtSprites.size(); i++) { 
                            if (dirtSprites[i] != nullptr) {
                                if (dirtSprites[i]->getPosition().x == localPosition.x && dirtSprites[i]->getPosition().y == localPosition.y
                                && farm.getMoney() >= 25) {
                                    // The player clicked on some dirt

                                    Vegetable* vegetable = new Vegetable;
                                    vegetable->plantVegetable(localPosition);
                                    vegetable->setDaysToHarvest(10);
                                    vegetable->set_growthRate(2);
                                    vegetables.push_back(vegetable);

                                    farm.setMoney(farm.getMoney() - 25);
                                    text.setString("$" + std::to_string(farm.getMoney()));
                                }
                            }
                        }
                    } else if (user.inventory[curCell]->GetName() == "Flower Seeds") {
                        if (farm.getMoney() > 0) {

                            sf::Sprite* flower = new sf::Sprite();
                            flower->setTexture(flowerTexture);
                            flower->setScale(5, 5);
                            flower->setPosition(sf::Vector2f(localPosition));
                            flowerSprites.push_back(flower);

                            farm.setMoney(farm.getMoney() - 5);
                            text.setString("$" + std::to_string(farm.getMoney()));

                            std::cout << "You've planted a flower\n";
                        }
                        else {
                            std::cout << "Oh no, you're out of money. \nUnfortunately you cannot plant the flower.\n";
                        }
                    }
                } else {
                    std::cout << "Vegetable selected\n";
                    for (int i = 0; i < (int)vegetables.size(); i++) { 
                        if (vegetables[i] != nullptr) {
                            if (vegetables[i]->vegSprite->getPosition().x == localPosition.x && vegetables[i]->vegSprite->getPosition().y == localPosition.y) {
                                std::cout << "Vegetable selected\n";
                                // The player clicked on a vegetable

                                if (vegetables[i]->getDaysToHarvest() <= 0) {
                                    farm.setMoney(farm.getMoney() + 50);
                                    text.setString("$" + std::to_string(farm.getMoney()));

                                    vegetables[i] = nullptr;
                                    vegetables.erase(vegetables.begin() + i);
                                } else {
                                    std::cout << vegetables[i]->getDaysToHarvest();
                                }
                            }
                        }
                    }
                }
            }
        } else {
            pressed2 = false;
        }

        // Grow vegetables
        for (int i = 0; i < (int)vegetables.size(); i++) { 
            if (vegetables[i] != nullptr) {
                vegetables[i]->setDaysToHarvest(vegetables[i]->getDaysToHarvest() - (elapsed.asSeconds() * vegetables[i]->get_growthRate()));
                if (vegetables[i]->getDaysToHarvest() < 0) { vegetables[i]->setDaysToHarvest(0); }
            }
        }

        // Set cell border to the currently selected cell
        cellBorder.setPosition(sf::Vector2f((1920 * 0.5) - 605 + (120 * curCell), 955));

        // Draw the window and sprites
        window.clear();
        window.draw(*grassSprite);
        for (int i = 0; i < (int)dirtSprites.size(); i++) { window.draw(*dirtSprites[i]); }
        for (int i = 0; i < (int)vegetables.size(); i++) { window.draw(*vegetables[i]->vegSprite); }
        for (int i = 0; i < (int)flowerSprites.size(); i++) { window.draw(*flowerSprites[i]); }
        window.draw(characterSprite);
        window.draw(cellBorder);
        for (int i = 0; i < 10; i++) { window.draw(*inventoryCells[i]); }
        for (int i = 0; i < 10; i++) { window.draw(*inventoryIcons[i]); }

        window.draw(text);
        window.display();
    }
    return 0;
}