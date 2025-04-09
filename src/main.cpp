
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "configuration.hpp"
#include "ball.hpp"
#include <math.h>




ball ball2;


int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({2560u, 1440u}), "CMake SFML Project", sf::State::Fullscreen);
    window.setFramerateLimit(conf::frames);
    std::srand(static_cast<unsigned>(std::time(nullptr))); // Seed for randomness



    // stores the shapes in this vector
    std::vector<ball> circles;
    // makes sure to keep for left click
    bool throwing = true;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            } else if(event->is<sf::Event::KeyPressed>()) {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
                    window.close();
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
                    circles.clear();
                }
            // checks to see if the button clicked and released was the left mouse.
            } else if(event->is<sf::Event::MouseButtonReleased>()) {
                throwing = true;
                if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                    throwing = false;
                }
            }
        }




        window.clear();

        //gets mouse position
        sf::Vector2i mouse = sf::Mouse::getPosition(window);

        sf::CircleShape ball3{conf::radius};
        ball3.setPosition(sf::Vector2f(mouse.x-conf::radius, mouse.y-conf::radius));
        ball3.setFillColor(sf::Color::Green);


        // creates ball when left-clicked
        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && throwing) {
            int xrandom = -10 + std::rand() % (21);
            int yrandom = -10 + std::rand() % (21);
            ball2.position = sf::Vector2f(xrandom, yrandom);
            ball2.shape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
            throwing = false;
        } else if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !throwing) {
            //grows the ball and keeps it on mouse
            ball2.shape.sf::CircleShape::setRadius(ball2.shape.sf::CircleShape::getRadius() + conf::radiusGrowth);
            ball2.shape.setPosition(sf::Vector2f(mouse.x-ball2.shape.sf::CircleShape::getRadius(), mouse.y-ball2.shape.sf::CircleShape::getRadius()));


        } else {
            // prevents empty ball getting added to circles every cycle
            if(ball2.shape.getRadius() > .005) {
                circles.push_back(ball2);
            }
            ball2.shape.sf::CircleShape::setRadius(0);
            ball2.position = sf::Vector2f(0,0);

        }



        //gets and sets location of ball
        for(int i = 0; i < circles.size(); i++) {
            sf::Vector2f position = circles[i].shape.getPosition();
            float circlePositionI = circles[i].shape.sf::CircleShape::getRadius();

            for(int j = 0; j < circles.size(); j++) {
                sf::Vector2f position2 = circles[j].shape.getPosition();
                float circlePositionJ = circles[j].shape.sf::CircleShape::getRadius();

                if(position == position2) {
                    //does nothing
                } else if(pow((circlePositionI-circlePositionJ), 2) >= pow((position.x-position2.x), 2) + pow((position.y-position2.y), 2)) {
                    //checks if they hit
                    // if(position.x > position2.x && position.y > position2.y) {
                    //     int yLength = position.y - position2.y;
                    //     // if position is ylength that means position is higher
                    //     int xLength = position.x - position2.x;
                    //     // if position is xlength that means position is to the right
                    //     sf::Vector2f position3 = sf::Vector2f(xLength, yLength);
                    //     float angle = atan2(position2.y - position2.x, position2.x - position2.y);
                    // circles[i].shape.setPosition(sf::Vector2f(circles[i].position-position));
                    // circles[i].position = sf::Vector2f(-circles[i].position.x, -circles[i].position.y);


                }
            }

            // if the ball moves outside of window stops it
            if(position.y >= 0 && position.y + circlePositionI*2 <= window.getSize().y) {
                if(position.x >= 0 && position.x + circlePositionI*2 <= window.getSize().x ) {

                } else {
                    circles[i].position = sf::Vector2f(-circles[i].position.x, circles[i].position.y);
                }
            } else {
                circles[i].position = sf::Vector2f(circles[i].position.x, -circles[i].position.y);
            }
            circles[i].shape.setPosition(circles[i].position + position);

            window.draw(circles[i].shape);
        }
        window.draw(ball3);
        window.draw(ball2.shape);
        window.display();
    }
}
