#include <iostream>

#define N 16
#define M 12

using std::cout;    using std::endl;
using std::cin;

typedef enum {wood, stone} material;

typedef struct {
    int x, y;
    bool isWall;
    material type;
} field;

// external variables
field playground[N][M];
int x = 5;
int y = 5;

// prototypes 
void initialize_maze();
void move(char steps);
void display_maze(int x, int y);

int main()
{
    char direction;

    initialize_maze();
    display_maze(x, y);

    while (cin >> direction) {
        move(direction);
        display_maze(x, y);
    }

    return 0;
}

void initialize_maze()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            playground[i][j].x = i;
            playground[i][j].y = j;
            playground[i][j].isWall = (i == 0 || i == (N - 1) || (j == 0 && i != 3) || j == (M - 1));
            if (playground[i][j].isWall && !(i == 3 && j == 0))
                playground [i][j].type = stone;
            else
                playground [i][j].type = wood;
        }
    }
}

void move(char direction)
{
    switch (direction) {
        case 'u':
            if (!playground[x][y - 1].isWall)
                y--;
            break;
        case 'd':
            if (!playground[x][y + 1].isWall)
                y++;
            break;
        case 'r':
            if (!playground[x + 1][y].isWall)
                x++;
            break;
        case 'l':
            if (!playground[x - 1][y].isWall)
                x--;
            break;
        case 'q':
            exit(0);
        default:
            break;
    }
}

void display_maze(int x, int y)
{
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (playground[j][i].isWall)
                cout << "*";
            else if (j == x && i == y)
                cout << "O";
            else 
                cout << " ";
        }
        cout << endl;
    }
}
