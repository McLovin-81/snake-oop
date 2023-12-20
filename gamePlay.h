#ifndef GAME_PLAY_H
#define GAME_PLAY_H

class GamePlay
{
    private:
        bool gameOver;
        int score;
    public:
        GamePlay();
        bool getGameOver();
        int getScore();
};

#endif // GAME_PLAY_H
