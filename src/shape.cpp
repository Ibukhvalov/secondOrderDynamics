//
// Created by vivan on 4/6/2024.
//

#include "shape.h"
#include "settings.h"
#include <iostream>
#include <cmath>



Shape::Shape(float radius): sf::CircleShape(radius),
animation(settings::f, settings::z, settings::r, {settings::width/2.f, settings::height/2.f}) {
    setOrigin(radius,radius);
    setFillColor(settings::shapeColor);
    setOrigin(settings::shapeRadius, settings::shapeRadius);
    setPosition(settings::width/2, settings::height/2);
}

void Shape::update(sf::Time elapsed, sf::Vector2f mousePosition) {
    position = mousePosition;
    setPosition(animation.update(elapsed.asSeconds(), position));
}

sf::Vector2f Shape::getPos(float x) {
    return sf::Vector2f(sinf(x), settings::height/2);
}
