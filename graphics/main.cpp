// Graphics
// To compile on Linux:
    // g++ -c graphics/main.cpp
    // g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
    // ./sfml-app

#include <SFML/Graphics.hpp>
#include<iostream>
#include<cmath>

int main()
{
    // Create window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Farm Game");

    // Create grass sprite
    sf::Sprite grassSprite;
    // Create grass texture
    sf::Texture grass;
    {
        // Set grass texture
        if (!grass.loadFromFile("Sprites/Tilesets/Grass.png", sf::IntRect(48, 96, 16, 16))) { return EXIT_FAILURE; }
        grass.setRepeated(true);

        // Set the grass sprite texture to the grass texture
        grassSprite.setTexture(grass);
        grassSprite.setScale(5, 5);
        grassSprite.setTextureRect({ 0, 0, 1920, 1080 });
    }
    
    // Create an array of textures for the character sprite
    sf::Texture characterAnims[4][4];
    {
        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++) {
                sf::Texture texture;
                if (!texture.loadFromFile("Sprites/Characters/basic.png", sf::IntRect(y * 48, x * 48, 48, 48))) { return EXIT_FAILURE; }
                characterAnims[x][y] = texture;
            }
        }
    }

    // Create the character srite
    sf::Sprite characterSprite;
    characterSprite.setScale(10, 10);
    // Set the character sprite's texture the the first frame of the first animation (standing idle)
    characterSprite.setTexture(characterAnims[0][0]);
    
    // Set charcter walk speed
    float WALK_SPEED = 5;
    // Set the framerate of the character's animations
    int ANIM_FRAMERATE = 20;
    
    // Add variables for keeping track of the animation
    int curAnimFrame = 2;
    int skippedFrames = 0;

    // Add variable for selected cell in hotbar
    int curCell = 0;

    // For the UI
    bool pressed = false;

    // While the window is open (user hasn't closed it)
    while (window.isOpen())
    {
        
        // Check for the closed event
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                // Clsoe the window
                window.close();
        }

        sf::RectangleShape inventoryCells[10];

        // Create inventory
        for (int i = 0; i < 10; i++) {
            sf::RectangleShape cell;
            cell.setSize(sf::Vector2f(100.f, 100.f));
            cell.setPosition(sf::Vector2f(((1920 * 0.5) - 600) + (120 * i), 960));
            cell.setFillColor(sf::Color::White);

            inventoryCells[i] = cell;
        }

        // Create border for selected cell
        sf::RectangleShape cellBorder;
        cellBorder.setSize(sf::Vector2f(110.f, 110.f));
        cellBorder.setPosition(sf::Vector2f((1920 * 0.5) - 605 + (120 * curCell), 955));
        cellBorder.setFillColor(sf::Color::Black);

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

        // Check if enough frames ahve elapsed to play the next frame of the animation
        skippedFrames += 1;
        if (skippedFrames % ANIM_FRAMERATE == 0) { 
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
        characterSprite.move(direction.x * WALK_SPEED, direction.y * WALK_SPEED);

        // Draw the window and sprites
        window.clear();
        window.draw(grassSprite);
        window.draw(characterSprite);
        window.draw(cellBorder);
        for (int i = 0; i < 10; i++) { window.draw(inventoryCells[i]); }
        window.display();
    }

    return 0;
}