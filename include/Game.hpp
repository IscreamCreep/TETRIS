#ifndef GAME_HPP
#define GAME_HPP

class Game {
public:
    Game();
    void run();
    int getScore() const;

private:
    int score;
};

#endif // GAME_HPP