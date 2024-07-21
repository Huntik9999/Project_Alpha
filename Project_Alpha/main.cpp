#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    //open window with size 800 , 600
    sf::RenderWindow window(sf::VideoMode(1620, 780), "The Turorial");
    
    //fps limit
    window.setFramerateLimit(60);
    //create snowball
    sf::Texture ballTexture;
    sf::Sprite ballSprite;
    if (ballTexture.loadFromFile("Assets/Enemy/Textures/snowball.png"))
    {
        std::cout << "Snowball Loaded" << std::endl;
        ballSprite.setTexture(ballTexture);
    }

    sf::CircleShape ball(50.f);
    ball.setFillColor(sf::Color::Red);
    ball.setOrigin(25, 25);
    ball.setPosition(1000, 400);

    //ball logic
    float xstep = 5;
    float ystep = 5;
    float enemymove = 2.5;
    // create enemy player
    sf::Texture enemyTexture;
    sf::Sprite enemySprite;
    if (enemyTexture.loadFromFile("Assets/Enemy/Textures/elementals.png"))
    {
        std::cout << "Enemy model loaded" << std::endl;
        enemySprite.setTexture(enemyTexture);
        int x = 0;
        int y = 0;
        enemySprite.setTextureRect(sf::IntRect(x * 0, y * 0, 72, 88));
        enemySprite.setOrigin(36, 44);
        enemySprite.setPosition(1476, 120);
        enemySprite.setScale(4, 4);
    }
    else
    {
        std::cout << "Enemy Image not loaded" << std::endl;
    }
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
        pSprite.setOrigin(16, 16);
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
        //moving enemy
        enemySprite.move(0, enemymove);
        if (enemySprite.getPosition().y == 120 || enemySprite.getPosition().y == 630)
        {
            enemymove = -enemymove;
        }
        //moving the ball
        ball.move(xstep, ystep);
        if (ball.getPosition().x == 1550 || ball.getPosition().x == 25)
        {
            xstep = -xstep;
        }
        if (ball.getPosition().y == 710 || ball.getPosition().y == 25)
        {
            ystep = -ystep;
        }
        //clear black color 
        window.clear(sf::Color::Black);

        // draw everything here...
        
        // window.draw(...);
        window.draw(backS);
        window.draw(pSprite);
        window.draw(ball);
        window.draw(ballSprite);
        window.draw(enemySprite);
        
        // end the current frame
        window.display();


    }
    return 0;
}