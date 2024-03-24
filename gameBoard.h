#ifndef GAME_BOARD_H
#define GAME_BOARD_H


class GameBoard
{
    private:
        int height;
        int width;
        int score; // TODO: Thats not the right place 

    public:
        GameBoard();
        int getHeight();
        int getWidth();
        int getScore();
        void increaseScore();
};

#endif // GAME_BOARD_H
