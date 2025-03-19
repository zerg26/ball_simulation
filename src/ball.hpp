#pragma once
#include <SFML\System\Vector2.hpp>

struct ball {
    sf::CircleShape shape{conf::radius};
    sf::Vector2f position = sf::Vector2f(5, 5);

};