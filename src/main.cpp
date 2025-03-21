
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "configuration.hpp"
#include "ball.hpp"





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
            ball2.shape.setPosition(sf::Vector2f(mouse.x-conf::radius, mouse.y-conf::radius));
            ball2.shape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
            int xrandom = -10 + std::rand() % (21);
            int yrandom = -10 + std::rand() % (21);
            ball2.position = sf::Vector2f(xrandom, yrandom);

            throwing = false;
        } else if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !throwing) {
            ball2.shape.sf::CircleShape::setRadius(ball2.shape.sf::CircleShape::getRadius() + 10.0f);
        } else {
            circles.push_back(ball2);
            ball2.shape.sf::CircleShape::setRadius(conf::radius);
        }



        //gets and sets location of ball
        for(auto& c : circles) {
            sf::Vector2f position = c.shape.getPosition();
            // if the ball moves outside of window stops it
            if(position.y >= 0 && position.y + conf::radius*2 <= window.getSize().y) {
                if(position.x >= 0 && position.x + conf::radius*2 <= window.getSize().x ) {

                } else {
                    c.position = sf::Vector2f(-c.position.x, c.position.y);
                }
            } else {
                c.position = sf::Vector2f(c.position.x, -c.position.y);
            }
            c.shape.setPosition(c.position + position);

            window.draw(c.shape);
        }
        window.draw(ball3);
        window.draw(ball2.shape);
        window.display();
    }
}
