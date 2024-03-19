#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Tetris {
public:
  int squareSize = 30;
  sf::Color cyan = sf::Color(0, 255, 255);
  sf::Color blue = sf::Color(0, 0, 255);
  sf::Color orange = sf::Color(255, 165, 0);
  sf::Color yellow = sf::Color(255, 255, 0);
  sf::Color green = sf::Color(0, 255, 0);
  sf::Color purple = sf::Color(128, 0, 128);
  std::vector<sf::Color> colors = {cyan, blue, orange, yellow, green, purple};
  std::vector<sf::Shape> blocks;

  // create a vector of all basic shapes, igoring orientation
  void populateBlockVector() {}
};

int main() {

  // render the window
  sf::RenderWindow window(sf::VideoMode(600, 300), "Tetirs knockoff");

  Tetris tetris;

  // gen all shapes
  tetris.populateBlockVector();

  // game loop
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    // black background
    window.clear(sf::Color::Black);

    // show window
    window.display();
  }
}
