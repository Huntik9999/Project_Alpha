#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    //open window with size 800 , 600
    sf::RenderWindow window(sf::VideoMode(1620, 780), "The Turorial");
    
    //fps limit
    window.setFramerateLimit(60);




    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                // if the window is closed 
                case sf::Event::Closed:
                    window.close();
                    break;
                // key is pressed
                case sf::Event::KeyPressed:
                    std::cout << "Key was pressed" << std::endl;
                    break;
                //dont process any other events 
                default:
                    break;
            }
            
        }
        //clear black color 
        window.clear(sf::Color::Black);

        // draw everything here...
        
        // window.draw(...);

        // end the current frame
        window.display();


    }
    return 0;
}