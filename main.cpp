#include <iostream>
#include <conio.h>

using namespace std;

bool GameOver;
const int width = 20;
const int height = 20;
int snakeHeadX, snakeHeadY, fruitX, fruitY, score;

enum snakeDirection
{
    STOP = 0 ,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

snakeDirection dir;


void Setup()
{
    GameOver = false;

    dir = STOP;
    snakeHeadX = width/2;
    snakeHeadY = height/2;
    fruitX = rand() % width;
    fruitY = rand() % height;


}

void Draw()
{
    system("cls");
    for (int i = 0; i < width; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if(j == 0)
                cout << "#";
            if (i == snakeHeadY && j == snakeHeadX)
                cout << 0;
            if (i == fruitY && j == fruitX)
                cout << "F>";

                cout << "";
            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i=0; i<height; i++)
        cout << "#";
    cout << endl;
    cout << "Score: " << score << endl;

}

void Input()
{
    if (kbhit())
    {
        switch(getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            GameOver = true;
            break;
        }
    }


}

void Logic()
{
    switch(dir)
    {
    case UP:
        snakeHeadY --;
        break;
    case DOWN:
        snakeHeadY ++;
        break;
    case LEFT:
        snakeHeadX --;
        break;
    case RIGHT:
        snakeHeadY ++;
        break;
    default:
        break;
    }
    if(snakeHeadX > width || snakeHeadX < 0 ||
        snakeHeadY > height || snakeHeadY < 0)
        GameOver = true;
    if (snakeHeadX == fruitX && snakeHeadY == fruitY)
    {
        score += 10;

        fruitX = rand() % width;
        fruitY = rand() % height;
    }

}

int main()
{
    Setup();
    while (!GameOver)
    {
        Draw();
        Input();
        Logic();

    }
}