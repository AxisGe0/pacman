#include "Game.h"

// Constructor for the Game class
Game::Game(int h, int w) :
    height(h),
    width(w),
    window(sf::VideoMode(w, h), "Pacman"),
    maze(20, width),
    player(window, 20),
    pellets(20, width, maze.getMaze()),
    speedDot(20, width, maze.getMaze()),
    cherry(20, width, maze.getMaze())
{
    // Set initial position of the player
    player.setPosition(sf::Vector2f(740, 740));

    // Initialize ghosts with different colors and positions
    ghosts[0] = new Ghost(window, 20, 1, 1, "red");
    ghosts[1] = new Ghost(window, 20, 6, 18, "blue");
    ghosts[2] = new Ghost(window, 20, 8, 7, "green");
    ghosts[3] = new Ghost(window, 20, 16, 1, "yellow");

    // Load font and set up text elements for score, lives, title, play text, and high score
    if (!font.loadFromFile("CrackMan.TTF")) {
        std::cerr << "Error: Failed to load font file." << std::endl;
    }
    score.setFont(font);
    score.setCharacterSize(20);
    score.setFillColor(sf::Color::Yellow);
    score.setStyle(sf::Text::Bold);
    score.setPosition(30, 330);
    livesText.setFont(font);
    livesText.setCharacterSize(20);
    livesText.setFillColor(sf::Color::Yellow);
    livesText.setStyle(sf::Text::Bold);
    livesText.setPosition(650, 330);

    // Start screen text setup
    title = sf::Text("PACMAN", font, 100);
    title.setFillColor(sf::Color::Yellow);
    sf::FloatRect titleBounds = title.getLocalBounds();
    title.setOrigin(titleBounds.left + titleBounds.width / 2.0f, titleBounds.top + titleBounds.height / 2.0f);
    title.setPosition(window.getSize().x / 2.0f, 200);

    playText = sf::Text("PLAY GAME", font, 30);
    playText.setFillColor(sf::Color::White);
    sf::FloatRect textBounds = playText.getLocalBounds();
    playText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    playText.setPosition(window.getSize().x / 2.0f, 500);

    highScoreText = sf::Text("HIGH SCORE: 0", font, 20);
    highScoreText.setFillColor(sf::Color::White);
    sf::FloatRect highScoreTextBounds = highScoreText.getLocalBounds();
    highScoreText.setPosition(10, 15);

    // Load sounds and set buffers
    if (!buffer.loadFromFile("sounds/sound_siren.wav")) {
        std::cerr << "Error: Failed to load siren sound file." << std::endl;
    }

    if (!buffer_ready.loadFromFile("sounds/sound_ready.mp3")) {
        std::cerr << "Error: Failed to load ready sound file." << std::endl;
    }

    if (!buffer_die.loadFromFile("sounds/sound_die.mp3")) {
        std::cerr << "Error: Failed to load die sound file." << std::endl;
    }

    // Set sound buffers
    siren.setBuffer(buffer);
    sound_ready.setBuffer(buffer_ready);
    sound_die.setBuffer(buffer_die);
    siren.setLoop(true);

    // Load high score from file
    std::ifstream file("highscore.txt");
    if (!file) {
        std::cerr << "Error: The file 'highscore.txt' does not exist or cannot be opened." << std::endl;
    }else{
        file >> highScore;
    }
}

// Runs the game loop
void Game::run() {
    auto sTime = std::chrono::high_resolution_clock::now();
    while (window.isOpen()) {
        sf::Event event;
        // Poll events from the window
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        handleClicks(); // Handle mouse clicks
        handleKeys();   // Handle keyboard inputs
        auto cTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> elapsed = cTime - sTime;
        sTime = cTime;
        float time = elapsed.count();
        if (isAlive && !isDying) {
            if (!player.move(direction, maze, time)) {
                direction = 4; // Reset direction if move fails
            }
            // Move ghosts and check for collisions with Pacman
            for (int i = 0; i < 4; ++i) {
                ghosts[i]->move(0, maze, time);
                if (ghosts[i]->checkDeath(player)) {
                    lives--;
                    if (lives == 0) {
                        isDying = true;
                        clock_die.restart();
                    } else {
                        player.setPosition(sf::Vector2f(740, 740));
                    }
                }
            }
            // Update points based on collectables
            points += pellets.addPoints(player);
            points += speedDot.addPoints(player);
            points += cherry.addPoints(player);
            score.setString("P* " + std::to_string(points));
            livesText.setString("Lives " + std::to_string(lives));
        }
        if (isDying) {
            if (clock_die.getElapsedTime().asSeconds() > 1.5) {
                isDying = false;
                resetGame(); // Reset game after death animation
            } else {
                if (sound_die.getStatus() != sf::Sound::Playing) {
                    siren.stop();
                    sound_die.play();
                }
            }
        }
        render(); // Render the game window
    }
}

// Handles keyboard inputs
void Game::handleKeys() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        direction = 0; // Move left
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        direction = 1; // Move right
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        direction = 2; // Move up
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        direction = 3; // Move down
    }
}

// Handles mouse clicks
void Game::handleClicks() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !isAlive && canGameStart) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (playText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            isAlive = true;
            siren.play(); // Start the siren sound when the game starts
        }
    }
}

// Renders the game window
void Game::render() {
    window.clear();
    if (!isAlive) {
        window.draw(title);
        window.draw(highScoreText);
        highScoreText.setString("HIGH SCORE: " + std::to_string(highScore));
        if (!canGameStart) {
            if (sound_ready.getStatus() != sf::Sound::Playing) {
                sound_ready.play();
            }
            if (clock.getElapsedTime().asSeconds() > 4) {
                canGameStart = true;
            }
        } else {
            window.draw(playText);
        }
    } else {
        // Draw game elements
        maze.draw(window);
        for (int i = 0; i < 4; ++i) {
            ghosts[i]->draw(window);
        }
        pellets.draw(window);
        speedDot.draw(window);
        cherry.draw(window);
        player.draw(window);
        window.draw(score);
        window.draw(livesText);
    }
    window.display();
}

// Resets the game to the initial state
void Game::resetGame() {
    isAlive = false;
    canGameStart = false;
    clock.restart();
    lives = 3;
    direction = 0;
    if (points > highScore) {
        highScore = points;
        std::ofstream file("highscore.txt");
        if (!file) {
            std::cerr << "Error: The file 'highscore.txt' does not exist or cannot be opened." << std::endl;
        }else{
            std::ofstream("highscore.txt") << highScore; // Save high score to file
        }
    }
    points = 0;
    maze.reset();
    speedDot.placeRandomly();
    cherry.placeRandomly();
    for (int i = 0; i < 4; ++i) {
        delete ghosts[i];
    }
    // Reinitialize ghosts
    ghosts[0] = new Ghost(window, 20, 1, 1, "red");
    ghosts[1] = new Ghost(window, 20, 6, 18, "blue");
    ghosts[2] = new Ghost(window, 20, 8, 7, "green");
    ghosts[3] = new Ghost(window, 20, 16, 1, "yellow");
    player.setPosition(sf::Vector2f(740, 740));
}

// Destructor for Game class
Game::~Game() {
    for (int i = 0; i < 4; ++i) {
        delete ghosts[i];
    }
    for (int i = 0; i < 20; ++i) {
        delete maze.getMaze()[i];
    }
    delete[] maze.getMaze();
}

// Getter for font used in the game
sf::Font Game::getFont() {
    return font;
}

// Getter for score text
sf::Text Game::getScore() {
    return score;
}

// Getter for lives text
sf::Text Game::getLivesText() {
    return livesText;
}

// Getter for game title text
sf::Text Game::getTitle() {
    return title;
}

// Getter for play button text
sf::Text Game::getPlayText() {
    return playText;
}

// Getter for high score text
sf::Text Game::getHighScoreText() {
    return highScoreText;
}

// Getter for game window width
int Game::getWidth() {
    return width;
}

// Getter for game window height
int Game::getHeight() {
    return height;
}

// Getter for high score value
int Game::getHighScore() {
    return highScore;
}

// Getter for current points
int Game::getPoints() {
    return points;
}

// Getter for number of lives remaining
int Game::getLives() {
    return lives;
}

// Getter for current direction of Pacman
int Game::getDirection() {
    return direction;
}

// Getter for isAlive flag
bool Game::getIsAlive() {
    return isAlive;
}

// Getter for canGameStart flag
bool Game::getCanGameStart() {
    return canGameStart;
}

// Getter for isDying flag
bool Game::getIsDying() {
    return isDying;
}