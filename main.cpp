#include <iostream>
#include <conio.h>
#include<windows.h>

using namespace std;

bool GameOver;
const int width = 20;
const int height = 20;

int snakeHeadX, snakeHeadY, fruitX, fruitY, score;
int tailX[60], tailY[60];
int nTail;

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
            else if (i == fruitY && j == fruitX)
                cout << "F>";
            else
            {
                bool print = false;
                for(int k = 0; k < nTail; k ++)
                {


                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;

                    }

                }
                if (!print)
                    cout << " ";
            }

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
    int previousTailX = tailX[0];
    int previousTailY = tailY[0];
    int previousTail2X , previousTail2Y;

    tailX[0] = snakeHeadX;
    tailY[0] = snakeHeadY;


    for (int i = 1 ; i < nTail; i++)
    {
        previousTail2X = tailX[i];
        previousTail2Y = tailY[i];

        tailX[i] = previousTailX;
        tailY[i] = previousTailY;

        previousTailX = previousTail2X;
        previousTailY = previousTail2Y;

    }
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

    for(int i = 0; i < nTail; i++)
        if(tailX[1] == snakeHeadX && tailY[1] == snakeHeadY)
            GameOver = true;

    if (snakeHeadX == fruitX && snakeHeadY == fruitY)
    {
        score += 10;

        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail ++;
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
        Sleep(60);

    }
}