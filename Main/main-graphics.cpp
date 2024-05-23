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
    ////////// GLOBAL VARIABLES //////////

    // Add variables for keeping track of the animation
    int walkAnimFrame = 2;
    float walkAnimSkippedFrames = 0;

    // Add variable for selected cell in the inventory
    int curSelectedInvCell = 0;

    // Tracking pressed for the UI and placement system
    bool invNavigationButtonPressed = false;
    bool placementPressed = false;
    bool fastForwardPressed = false;

    // Time variables
    float time = 0;

    int months = 0;
    int days = 0;
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    
    int fastForwardTime = 1;

    std::string season = "Spring";

    ////////// CREATING OBJECTS AND TERMINAL INSTRUCTIONS //////////

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

    // Create dirt object
    Shovel shovel;

    // Create flower object
    Flower flower;

    ////////// CREATING WINDOW AND CHARACTER //////////

    // Create window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Farm Game");

    // Create brackground sprite
    sf::Sprite* grassSprite = farm.createBackground();
    
    // Create an array of textures for the character sprite
    sf::Texture** characterAnims = user.createAnimation();

    // Create the character srite
    sf::Sprite characterSprite;
    characterSprite.setScale(10, 10);
    // Set the character sprite's texture the the first frame of the first animation (standing idle)
    characterSprite.setTexture(characterAnims[0][0]);
    
    ////////// VECTORS FOR PLACED OBJECTS AND SPRITES //////////

    std::vector<Vegetable*> vegetables;
    std::vector<sf::Sprite*> dirtSprites;
    std::vector<sf::Sprite*> flowerSprites;

    // Load a texture for the flowers
    sf::Texture flowerTexture;
    flowerTexture.loadFromFile("Sprites/Objects/Basic_Grass_Biom_things.png", sf::IntRect(112, 34, 16, 16));

    sf::Texture* grownPlantTex = new sf::Texture;
    grownPlantTex->loadFromFile("Sprites/Objects/Basic_Plants.png", sf::IntRect(64, 0, 16, 16));

    ////////// CREATING INVENTORY UI //////////

    // Inventory cells and sprites
    sf::RectangleShape* inventoryCells[10];
    sf::Sprite* inventoryIcons[10];

    // Create inventory
    for (int i = 0; i < 10; i++) {
        // Craete cell rectangle shape
        sf::RectangleShape* cell = new sf::RectangleShape;
        cell->setSize(sf::Vector2f(100.f, 100.f));
        cell->setPosition(sf::Vector2f(((1920 * 0.5) - 600) + (120 * i), 960));
        cell->setFillColor(sf::Color::White);

        // Add it to the array
        inventoryCells[i] = cell;

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

    ////////// CREATING TEXT UI //////////

    // Create font
    sf::Font font;
    font.loadFromFile("Fonts/upheavtt.ttf");

    // Create money text
    sf::Text moneyText;
    moneyText.setFont(font); // font is a sf::Font
    moneyText.setString("$" + std::to_string(farm.getMoney()));
    moneyText.setCharacterSize(60);
    moneyText.setFillColor(sf::Color::White);
    moneyText.setStyle(sf::Text::Bold);
    moneyText.setOutlineColor(sf::Color(0,0,0,225));
    moneyText.setOutlineThickness(5);
    moneyText.setPosition(35, 0);

    // Create day text
    sf::Text dayText;
    dayText.setFont(font); // font is a sf::Font
    dayText.setString("asdsdfsdf");
    dayText.setCharacterSize(60);
    dayText.setFillColor(sf::Color::White);
    dayText.setStyle(sf::Text::Bold);
    dayText.setOutlineColor(sf::Color(0,0,0,225));
    dayText.setOutlineThickness(5);
    dayText.setPosition(35, 60);

    // Create season text
    sf::Text seasonText;
    seasonText.setFont(font); // font is a sf::Font
    seasonText.setString("sdfsdfsdf");
    seasonText.setCharacterSize(60);
    seasonText.setFillColor(sf::Color::White);
    seasonText.setStyle(sf::Text::Bold);
    seasonText.setOutlineColor(sf::Color(0,0,0,225));
    seasonText.setOutlineThickness(5);
    seasonText.setPosition(35, 120);

    // Create time text
    sf::Text timeText;
    timeText.setFont(font); // font is a sf::Font
    timeText.setString("456456");
    timeText.setCharacterSize(60);
    timeText.setFillColor(sf::Color::White);
    timeText.setStyle(sf::Text::Bold);
    timeText.setOutlineColor(sf::Color(0,0,0,225));
    timeText.setOutlineThickness(5);
    timeText.setPosition(850, 0);

    ////////// MAIN SFML CODE //////////

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

        // Setting the time variable
        time += elapsed.asSeconds() * fastForwardTime;

        // Convert the float time to an int and set it to the seconds variable
        seconds = int(time);

        // Calculate months
        months = seconds / 2629746;
        seconds = seconds - (months * 2629746);
        
        // Calculate days
        days = seconds / (24 * 3600);
        seconds = seconds - (days * 24 * 3600);

        // Calculate hours
        hours = seconds / 3600;
        seconds = seconds - (hours * 3600);

        // Calculate minutes
        minutes = seconds / 60;
        seconds = seconds - (minutes * 60);

        // Set season variable
        switch (months)
        {
            case 0:
                season = "Summer";
                break;
            case 3:
                season = "Autumn";
                break;
            case 6:
                season = "Winter";
                break;
            case 9:
                season = "Spring";
                break;
            default:
                break;
        }

        // Setting the time, date and season UI
        timeText.setString(std::to_string(hours) + ":" + std::to_string(minutes) + ":" + std::to_string(seconds));
        dayText.setString("Day: " + std::to_string(days));
        seasonText.setString(season);

        // Inventory controls
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && invNavigationButtonPressed == false) { curSelectedInvCell -= 1; invNavigationButtonPressed = true; }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && invNavigationButtonPressed == false) { curSelectedInvCell += 1; invNavigationButtonPressed = true; }
        else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !sf::Keyboard::isKeyPressed(sf::Keyboard::E)) { invNavigationButtonPressed = false; }

        // Reset hotbar pos when it gets to the edge
        if (curSelectedInvCell > 9) { curSelectedInvCell = 0; }
        if (curSelectedInvCell < 0) { curSelectedInvCell = 9; }

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
        walkAnimSkippedFrames += elapsed.asSeconds();
        if (walkAnimSkippedFrames > user.getAnimFramerate()) { 
            walkAnimSkippedFrames = 0;
            walkAnimFrame += 1;
            if (walkAnimFrame == 4) { walkAnimFrame = 2; };
            if (length == 0 && walkAnimFrame > 1) { walkAnimFrame -= 2; }
        }

        // Set the direction of the player based off the user input
        int dir = 0;
        if (direction.y > 0) { dir = 0; } else if (direction.y < 0) { dir = 1; }
        if (direction.x > 0) { dir = 3; } else if (direction.x < 0) { dir = 2; }
        
        // Set te characters texture to the current animation frame
        characterSprite.setTexture(characterAnims[dir][walkAnimFrame]);

        // Move the character in the direction multiplied by the walkSpeed
        characterSprite.move(direction.x * user.getWalkSpeed() * elapsed.asSeconds(), direction.y * user.getWalkSpeed() * elapsed.asSeconds());

        // Mouse controls
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (placementPressed == false) {
                //std::cout << dirtSprites.size() << std::endl;
                placementPressed = true;

                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                localPosition = sf::Vector2i(localPosition.x - localPosition.x % 80, localPosition.y - localPosition.y % 80);

                if (user.inventory[curSelectedInvCell] != nullptr) {
                    //std::cout << user.inventory[curSelectedInvCell]->GetName() << std::endl;

                    if (user.inventory[curSelectedInvCell]->GetName() == "Shovel") {
                        // Dig a hole and "snap" it to the grid
                        dirtSprites.push_back(shovel.digHole(localPosition));
                    } else if (user.inventory[curSelectedInvCell]->GetName() == "Watering Can") {
                        std::cout << "Watering Can selected!\n";
                    } else if (user.inventory[curSelectedInvCell]->GetName() == "Seeds") {
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
                                    moneyText.setString("$" + std::to_string(farm.getMoney()));
                                }
                            }
                        }
                    } else if (user.inventory[curSelectedInvCell]->GetName() == "Flower Seeds") {
                        if (farm.getMoney() > 0) {

                            sf::Sprite* flower = new sf::Sprite();
                            flower->setTexture(flowerTexture);
                            flower->setScale(5, 5);
                            flower->setPosition(sf::Vector2f(localPosition));
                            flowerSprites.push_back(flower);

                            farm.setMoney(farm.getMoney() - 5);
                            moneyText.setString("$" + std::to_string(farm.getMoney()));

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
                                    moneyText.setString("$" + std::to_string(farm.getMoney()));

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
            placementPressed = false;
        }

        // Change time
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) && fastForwardPressed == false) {
            fastForwardPressed = true;
            if (fastForwardTime == 1) {
                fastForwardTime = 100;
            } else if (fastForwardTime == 100) {
                fastForwardTime = 1000;
            } else if (fastForwardTime == 1000) {
                fastForwardTime = 10000;
            } else if (fastForwardTime == 10000) {
                fastForwardTime = 100000;
            } else if (fastForwardTime == 100000) {
                fastForwardTime = 1000000;
            } else {
                fastForwardTime = 1;
            }
         } else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::T) && fastForwardPressed == true) {
            fastForwardPressed = false;
         }

        // Grow vegetables
        for (int i = 0; i < (int)vegetables.size(); i++) { 
            if (vegetables[i] != nullptr) {
                vegetables[i]->setDaysToHarvest(vegetables[i]->getDaysToHarvest() - (elapsed.asSeconds() * vegetables[i]->get_growthRate()));
                if (vegetables[i]->getDaysToHarvest() < 0) { 
                    

                    vegetables[i]->setDaysToHarvest(0); 
                    vegetables[i]->vegSprite->setTexture(*grownPlantTex);
                }
            }
        }

        // Set cell border to the currently selected cell
        cellBorder.setPosition(sf::Vector2f((1920 * 0.5) - 605 + (120 * curSelectedInvCell), 955));

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

        window.draw(moneyText);
        window.draw(timeText);
        window.draw(dayText);
        window.draw(seasonText);
        window.display();
    }
    return 0;
}