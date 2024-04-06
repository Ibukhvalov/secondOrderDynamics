#ifndef ECOSYSTEM_SETTINGS_H
#define ECOSYSTEM_SETTINGS_H

#include <SFML/Graphics.hpp>
#include <cmath>

namespace settings {

    const int width = 1600;
    const int height = 900;

    const float shapeRadius = width/30.f;

    const double f = 3.5;
    const double z = 0.3;
    const double r = 0;


    const sf::Color background = sf::Color(0, 100, 100);
    const sf::Color shapeColor = sf::Color(200, 160, 160);


}

#endif //ECOSYSTEM_SETTINGS_H
