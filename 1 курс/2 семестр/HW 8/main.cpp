#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

void main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test");

    
    sf::Font font;
    font.loadFromFile("tuffy.ttf");
    sf::Text text("Hello, SFML!", font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(100, 100);

    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(400, 300);

    sf::SoundBuffer buffer;
    buffer.loadFromFile("killdeer.wav");
    sf::Sound sound(buffer);
    sound.play();

    while (window.isOpen()){
        
        sf::Event event;
        while (window.pollEvent(event)){

            if (event.type == sf::Event::Closed) {

                window.close();

            }

        }

        window.clear();

        window.draw(text);
        window.draw(circle);

        window.display();

    }

}