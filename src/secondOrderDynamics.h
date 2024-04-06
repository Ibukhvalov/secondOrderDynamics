#ifndef ECOSYSTEM_SECONDORDERDYNAMICS_H
#define ECOSYSTEM_SECONDORDERDYNAMICS_H

#include <SFML/Graphics.hpp>
#include <cmath>


class SecondOrderDynamics {
public:
    SecondOrderDynamics(float f, float z, float r, sf::Vector2f initialPosition) {
        k1 = z / M_PI / f;
        k2 = pow(2 * M_PI * f, -2);
        k3 = r * z / 2 / M_PI / f;

        xp = initialPosition;
        y = initialPosition;
        yd = {0, 0};
    }

    sf::Vector2f update(float T, sf::Vector2f x) {
        sf::Vector2f xd = (x - xp) / T;
        y = y + yd * T;
        yd = yd + T * (x + k3*xd - y - k1*yd) / k2;
        return y;
    }


private:
    sf::Vector2f xp;
    sf::Vector2f y, yd;

    float k1;
    float k2;
    float k3;

};


#endif //ECOSYSTEM_SECONDORDERDYNAMICS_H
