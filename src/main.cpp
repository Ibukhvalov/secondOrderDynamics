#include <iostream>
#include <SFML/Graphics.hpp>
#include "settings.h"
#include "shape.h"


#define debug

int main() {
    setbuf(stdout, nullptr);
    srand(time(nullptr));

    sf::RenderWindow window;
    window.create(sf::VideoMode(settings::width, settings::height), "Animation");

    #ifdef debug
    sf::CircleShape debugShape(settings::shapeRadius/2.f);
    debugShape.setOrigin(settings::shapeRadius/2.f,settings::shapeRadius/2.f);
    debugShape.setFillColor(sf::Color(50,50,50,100));
    #endif

    Shape shape(settings::shapeRadius);
    sf::Clock clock;
    sf::Time elapsed;
    sf::Vector2i localPosition;

    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed: {
                    window.close();
                    break;
                }
            }
        }

        elapsed = clock.restart();
        localPosition = sf::Mouse::getPosition(window);

        window.clear(settings::background);

        shape.update(elapsed, {(float)localPosition.x, (float)localPosition.y});


        shape.draw(window);

        #ifdef debug
        debugShape.setPosition((float)localPosition.x, (float)localPosition.y);
        window.draw(debugShape);
        #endif


        window.display();
    }


    return 0;
}
