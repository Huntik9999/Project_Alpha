#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    //open window with size 800 , 600
    sf::RenderWindow window(sf::VideoMode(1620, 780), "The Turorial");
    
    //fps limit
    window.setFramerateLimit(60);

    //create player
    sf::Texture pTexture; //texture for the player
    sf::Sprite  pSprite; //sprite for the player 
    //load sprite
    if (pTexture.loadFromFile("Assets/Player/Textures/bat.png"))
    {
        std::cout << "Player Image loaded" << std::endl;
        pSprite.setTexture(pTexture);
        int xIndex = 1;
        int yIndex = 0;
        pSprite.setTextureRect(sf::IntRect(xIndex * 32, yIndex * 32, 32, 32));
        pSprite.setScale(4, 4);
        pSprite.setPosition(778, 390);

    }
    else
    {
        std::cout << "Player Image not loaded" << std::endl;
    }
    //create background
    sf::Texture backT; //texture for background
    sf::Sprite  backS; //sprite for background
    //load background
    if (backT.loadFromFile("Assets/background/snow.png"))
    {
        std::cout << "Background Image laoded" << std::endl;
        backS.setTexture(backT);
        backS.setTextureRect(sf::IntRect(0, 0, 1620, 780));
    }
    else
    {
        std::cout << "Background did not load" << std::endl;
    }
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Vector2f position = pSprite.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            pSprite.setPosition(position + sf::Vector2f(5, 0));
            int xIndex = 1;
            int yIndex = 1;
            pSprite.setTextureRect(sf::IntRect(xIndex * 32, yIndex * 32, 32, 32));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            pSprite.setPosition(position + sf::Vector2f(0, -5));
            int xIndex = 1;
            int yIndex = 2;
            pSprite.setTextureRect(sf::IntRect(xIndex * 32, yIndex * 32, 32, 32));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            pSprite.setPosition(position + sf::Vector2f(0, 5));
            int xIndex = 1;
            int yIndex = 0;
            pSprite.setTextureRect(sf::IntRect(xIndex * 32, yIndex * 32, 32, 32));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            pSprite.setPosition(position + sf::Vector2f(-5, 0));
            int xIndex = 1;
            int yIndex = 3;
            pSprite.setTextureRect(sf::IntRect(xIndex * 32, yIndex * 32, 32, 32));
        }
        //clear black color 
        window.clear(sf::Color::Black);

        // draw everything here...
        
        // window.draw(...);
        window.draw(backS);
        window.draw(pSprite);
        // end the current frame
        window.display();


    }
    return 0;
}