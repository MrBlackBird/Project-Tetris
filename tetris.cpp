#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Tetris {
public:
  sf::Vector2f squareSize = {30, 30};
  sf::Color cyan = sf::Color(0, 255, 255);
  sf::Color blue = sf::Color(0, 0, 255);
  sf::Color orange = sf::Color(255, 165, 0);
  sf::Color yellow = sf::Color(255, 255, 0);
  sf::Color green = sf::Color(0, 255, 0);
  sf::Color purple = sf::Color(128, 0, 128);
  std::vector<sf::Color> colors = {cyan, blue, orange, yellow, green, purple};
  std::vector<std::vector<sf::Shape *>> blocks;

  // NOTE: define structure of all the blocks

  void buildBar(int initialPosition) {
    std::vector<sf::Shape *> barVec;
    int randColor = rand() % 6;
    for (int i = 0; i < 4; i++) {
      sf::RectangleShape *square = new sf::RectangleShape(squareSize);
      square->setPosition(initialPosition + (i * 30), 0);
      square->setFillColor(colors[randColor]);
      barVec.emplace_back(square);
    }
    blocks.emplace_back(barVec);
  }

  void buildCube(int initialPosition) {
    std::vector<sf::Shape *> cubeVec;
    int randColor = rand() % 6;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        sf::RectangleShape *square = new sf::RectangleShape(squareSize);
        square->setPosition(initialPosition + (i * 30), 0 + (j * 30));
        square->setFillColor(colors[randColor]);
        cubeVec.emplace_back(square);
      }
    }
    blocks.emplace_back(cubeVec);
  }

  void buildL(int initialPosition) {
    std::vector<sf::Shape *> lVec;
    int randColor = rand() % 6;
    for (int i = 0; i < 4; i++) {
      if (i != 3) {
        sf::RectangleShape *square = new sf::RectangleShape(squareSize);
        square->setPosition(initialPosition, 0 + (i * 30));
        square->setFillColor(colors[randColor]);
        lVec.emplace_back(square);
      } else {
        sf::RectangleShape *square = new sf::RectangleShape(squareSize);
        square->setPosition(initialPosition + 30, 0 + (i * 30));
        square->setFillColor(colors[randColor]);
        lVec.emplace_back(square);
      }
    }
    blocks.emplace_back(lVec);
  }

  void buildInverseL(int initialPosition){};

  void buildZigzag(int initialPosition){};

  void buildInverseZigzag(int initialPosition){};

  void buildStickout(int initialPosition){};

  // NOTE: store all the blocks here

  // create a vector of all basic shapes, igoring orientation
  void createModelBlocks() {}
};

int main() {

  // FIX: balance the speed across various framerates, make movement non-smooth
  // wait a set amount of time before moving a block further

  // render the window
  sf::RenderWindow window(sf::VideoMode(300, 600), "Tetirs knockoff");

  Tetris tetris;

  // gen all shapes
  tetris.createModelBlocks();

  // game loop
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    // FIX: add movement, event handling (movement + roation), conditions for
    // when a row is filled

    // black background
    window.clear(sf::Color::Black);

    // drawing tests
    for (auto &block : tetris.blocks) {
      for (auto &sh : block) {
        window.draw(*sh);
      }
    }

    // show window
    window.display();
  }

  return 0;
}
