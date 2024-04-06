//
// Created by vivan on 4/6/2024.
//

#ifndef ECOSYSTEM_SHAPE_H
#define ECOSYSTEM_SHAPE_H

#include "settings.h"
#include <iostream>
#include "secondOrderDynamics.h"
#include <SFML/Graphics.hpp>

class Shape : public sf::CircleShape {
public:
    explicit Shape(float radius);

    void update(sf::Time elapsed, sf::Vector2f mousePosition);

    void draw(sf::RenderWindow& window) {
        window.draw(*this);
    }

    sf::Vector2f getPos(float x);


private:
    sf::Vector2f position;
    sf::Vector2f positionAnim;

    SecondOrderDynamics animation;
};

#endif //ECOSYSTEM_SHAPE_H
