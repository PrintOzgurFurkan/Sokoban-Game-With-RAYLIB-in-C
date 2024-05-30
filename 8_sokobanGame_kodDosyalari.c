#include "raylib.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#define SCREEN_WIDTH 992
#define SCREEN_HEIGHT 672
#define MAP_WIDTH 31
#define MAP_HEIGHT 21
#define CELL_SIZE 32
#define NUM_FRAMES 1
  char map[MAP_HEIGHT][MAP_WIDTH] = {
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','W','W','W','W','W','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','W','G','G','G','W','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','W','G','G','G','W','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','W','W','W','G','G','G','W','W','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','W','G','G','G','G','G','G','W','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','W','W','W','G','W','G','W','W','G','W','.','.','.','W','W','W','W','W','W','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','W','G','G','G','W','G','W','W','G','W','W','W','W','W','G','G','T','T','W','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','W','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','T','T','W','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','W','W','W','W','W','G','W','W','W','G','W','G','W','W','G','G','T','T','W','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','W','G','G','G','G','G','W','W','W','W','W','W','W','W','W','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','W','W','W','W','W','W','W','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'}
};
 char map2[MAP_HEIGHT][MAP_WIDTH] = {
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','W','W','W','W','W','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','W','G','G','G','W','W','W','W','W','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','W','G','W','G','W','W','G','G','W','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','W','G','G','G','G','G','G','G','W','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','W','W','W','W','W','W','W','W','W','G','W','W','W','G','G','G','W','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','W','T','T','T','T','G','G','W','W','G','G','G','G','G','W','W','W','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','W','T','T','T','T','G','G','G','G','G','G','G','G','G','W','W','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','W','T','T','T','T','G','G','W','W','G','G','G','G','G','G','W','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','W','W','W','W','W','W','W','W','W','G','G','G','G','G','W','W','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','W','G','G','G','G','G','G','W','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','W','W','W','G','W','W','G','W','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','W','G','G','G','G','W','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','W','W','W','W','W','W','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'}
};

char map3[MAP_HEIGHT][MAP_WIDTH] = {
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','W','W','W','W','W','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','W','W','W','W','W','W','W','G','G','G','W','W','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','W','W','G','W','G','G','W','W','G','G','G','G','W','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','W','G','G','G','G','G','G','G','G','G','G','G','W','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','W','G','G','G','G','G','W','W','W','G','G','G','W','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','W','W','W','G','W','W','W','W','W','G','W','W','W','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','W','G','G','G','G','W','W','W','G','T','T','W','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','W','G','G','G','G','G','G','G','T','T','T','W','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','W','G','G','G','G','W','W','W','T','T','T','W','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','W','G','G','G','G','W','.','W','T','T','T','W','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','W','G','G','W','W','W','.','W','W','W','W','W','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','W','W','W','W','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'}
};
char map4[MAP_HEIGHT][MAP_WIDTH] = {
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','W','W','W','W','W','W','W','W','W','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','W','W','G','G','G','W','W','G','G','W','W','W','W','W','W','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','W','W','W','G','G','G','G','G','W','G','G','W','G','G','G','G','W','W','W','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','W','G','G','G','G','W','G','G','W','G','G','W','G','G','T','T','T','G','W','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','W','G','W','G','G','W','G','G','W','W','G','W','G','W','T','W','T','G','W','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','W','G','G','W','G','W','G','G','G','W','G','G','G','G','T','G','T','G','W','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','W','G','G','G','G','G','G','G','G','W','G','W','G','W','T','W','T','G','W','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','W','G','G','G','W','W','G','G','W','W','G','G','G','G','T','G','T','G','W','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','W','G','G','G','W','G','G','G','W','G','G','W','G','W','T','W','T','G','W','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','W','W','G','G','G','G','G','G','G','G','G','G','G','G','T','T','T','G','W','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','W','G','G','W','W','W','W','W','W','G','G','G','G','W','W','G','G','W','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','W','G','G','W','.','.','.','.','W','W','W','W','W','W','W','W','W','W','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','W','W','W','W','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'}
};   

typedef enum GameScreen {LEVELONE, LEVELTWO, LEVELTHREE , LEVELFOUR , LEVEL_SCREEN ,BEFOREGAME, PAUSE, MAIN_MENU, LOGO, HOW_TO_PLAY, CREDITS , ENDING} GameScreen;

#define NUM_MENU_OPTIONS 5
#define START_PLAY_OPTION 1
#define HOW_TO_PLAY_OPTION 2
#define CREDITS_OPTION 3
#define EXIT_GAME_OPTION 4
#define BACKGROUND_MOVE_SPEED 5.0f
#define OPTION_WIDTH 200
#define OPTION_HEIGHT 50
#define OPTION_MARGIN 20
#define MENU_TOP_MARGIN ((SCREEN_HEIGHT - (4 * OPTION_HEIGHT + 3 * OPTION_MARGIN)) / 2)
#define OPTION_X (SCREEN_WIDTH - OPTION_WIDTH) / 2
#define OPTION_Y(index) (MENU_TOP_MARGIN + (OPTION_HEIGHT + OPTION_MARGIN) * index)

Texture2D textures[128]; 

float playerPosX = 17*32;
float playerPosY = 13*32;
Texture2D playerTexture;

float player2PosX = 21*32;
float player2PosY = 12*32;
Texture2D player2Texture;

float player3PosX = 14*32;
float player3PosY =  6*32;
Texture2D player3Texture;

float player4PosX = 12*32;
float player4PosY =  8*32;
Texture2D player4Texture;

typedef struct {
    float posX;
    float posY;
    Texture2D texture;
    bool onTarget;
} Box;

Box boxes[] = 
{
    {32 * 11, 32 * 12, 0},
    {32 * 8, 32 * 12, 0},
    {32 * 11, 32 * 9, 0},
    {32 * 11, 32 * 7, 0},
    {32 * 13, 32 * 8, 0},
    {32 * 13, 32 * 9, 0}
};
int numBoxes = sizeof(boxes) / sizeof(boxes[0]);

Box boxes2[] = 
{
    {32 * 16, 32 * 11, 0},
    {32 * 17, 32 * 10, 0},
    {32 * 16, 32 * 12, 0},
    {32 * 17, 32 * 14, 0},
    {32 * 18, 32 * 7, 0},
    {32 * 18, 32 * 11, 0},
    {32 * 19, 32 * 12, 0},
    {32 * 18, 32 * 13, 0},
    {32 * 19, 32 * 14, 0},
    {32 * 19, 32 * 11, 0},
    {32 * 20, 32 * 10, 0},
    {32 * 21, 32 * 8, 0}
};
int numBoxes2 = sizeof(boxes2) / sizeof(boxes2[0]);

Box boxes3[] = 
{
    {32 * 18, 32 * 6, 0},
    {32 * 18, 32 * 9, 0},
    {32 * 19, 32 * 6, 0},
    {32 * 14, 32 * 7, 0},
    {32 * 12, 32 * 8, 0},
    {32 * 15, 32 *11, 0},
    {32 * 13, 32 *11, 0},
    {32 * 11, 32 *11, 0},
    {32 * 11, 32 *10, 0},
    {32 * 11, 32 *13, 0},
    {32 * 12, 32 *13, 0}
};
int numBoxes3 = sizeof(boxes3) / sizeof(boxes3[0]);

Box boxes4[] = 
{
    {32 * 12, 32 *  9, 0},
    {32 * 12, 32 *  7, 0},
    {32 * 13, 32 *  8, 0},
    {32 * 13, 32 * 10, 0},
    {32 *  9, 32 *  7, 0},
    {32 * 10, 32 *  8, 0},
    {32 *  8, 32 * 10, 0},
    {32 * 16, 32 * 11, 0},
    {32 * 18, 32 * 11, 0},
    {32 *  8, 32 * 12, 0},
    {32 * 18, 32 * 12, 0},
    {32 *  9, 32 * 13, 0},
    {32 * 12, 32 * 13, 0},
    {32 * 16, 32 * 13, 0},
    {32 * 19, 32 * 13, 0},
    {32 *  8, 32 * 14, 0}
};
int numBoxes4 = sizeof(boxes4) / sizeof(boxes4[0]);

typedef struct MoveNode {
    float posX;
    float posY;
    struct MoveNode* next;
} MoveNode;

typedef struct {
    MoveNode* top;
} MoveStack;

MoveStack playerMoveStack;

MoveStack boxMoveStacks[128];

MoveNode* CreateMoveNode(float posX, float posY) {
    MoveNode* newNode = (MoveNode*)malloc(sizeof(MoveNode));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->posX = posX;
    newNode->posY = posY;
    newNode->next = NULL;
    return newNode;
}

void PushMove(MoveStack* stack, float posX, float posY) {
    MoveNode* newNode = CreateMoveNode(posX, posY);
    if (newNode == NULL) {
        return;
    }
    newNode->next = stack->top;
    stack->top = newNode;
}

MoveNode* PopMove(MoveStack* stack) {
    if (stack->top == NULL) {
        return NULL;
    }
    MoveNode* topNode = stack->top;
    stack->top = topNode->next;
    return topNode;
}

void UndoMove(MoveStack* stack, float* posX, float* posY) {
    MoveNode* prevMove = PopMove(stack);
    if (prevMove != NULL) {
        *posX = prevMove->posX;
        *posY = prevMove->posY;
        free(prevMove);
    }
}

void SaveMove(MoveStack* stack, float posX, float posY) {
    PushMove(stack, posX, posY);
}

void ClearMoveStacks() {
    while (playerMoveStack.top != NULL) {
        free(PopMove(&playerMoveStack));
    }

    for (int i = 0; i < 128; i++) {
        while (boxMoveStacks[i].top != NULL) {
            free(PopMove(&boxMoveStacks[i]));
        }
    }
}

void kaydetSkorlar(int sure, int hamle) {
    FILE *dosya = fopen("skorlar.txt", "w");
    if (dosya != NULL) {
        fprintf(dosya, "Time: %02d:%02d \nMove: %d\n", sure / 60, sure % 60, hamle);
        fclose(dosya);
    } 
}

void skorlariCiz() {
    FILE *dosya = fopen("skorlar.txt", "r");
    if (dosya != NULL) {
        char satir[100];
        int y = 290;
        while (fgets(satir, 100, dosya) != NULL) {
            DrawText(satir, 350, y, 55, DARKBLUE);
            y +=65 ;
        }
        fclose(dosya);
    } else {
        printf("Skorlar dosyasi bulunamadi.\n");
    }
}

void drawRecord(int level) {
    char record[20];
    switch(level){
        case 1:
            strcpy(record, "recordone.txt");
            break;
        case 2:
            strcpy(record, "recordtwo.txt");
            break;
        case 3:
            strcpy(record, "recordthree.txt");
            break;
        case 4:
            strcpy(record, "recordfour.txt");
            break;
    }
    
    FILE *file = fopen(record, "r");
    if (file != NULL) {
        int bestTime, bestMoves;
        fscanf(file, "%d %d", &bestTime, &bestMoves);
        fclose(file);
        DrawText(TextFormat("Best Time: %02d:%02d", bestTime / 60, bestTime % 60), 410,415, 20, WHITE);
        DrawText(TextFormat("Best Moves: %d", bestMoves), 410, 440, 20, WHITE);
    }
}

void readRecord(int *bestTime, int *bestMoves, int level) {
    char record[20];
    switch(level){
        case 1:
            strcpy(record, "recordone.txt");
            break;
        case 2:
            strcpy(record, "recordtwo.txt");
            break;
        case 3:
            strcpy(record, "recordthree.txt");
            break;
        case 4:
            strcpy(record, "recordfour.txt");
            break;
    }
    FILE *file = fopen(record, "r");
    if (file != NULL) {
        fscanf(file, "%d %d", bestTime, bestMoves);
        fclose(file);
    }
}

void writeRecord(int bestTime, int bestMoves , int level) {
    char record[20];
    switch(level){
        case 1:
            strcpy(record, "recordone.txt");
            break;
        case 2:
            strcpy(record, "recordtwo.txt");
            break;
        case 3:
            strcpy(record, "recordthree.txt");
            break;
        case 4:
            strcpy(record, "recordfour.txt");
            break;
    }
    FILE *file = fopen(record, "w");
    if (file != NULL) {
        fprintf(file, "%d %d", bestTime, bestMoves);
        fclose(file);
    }
}

void checkAndUpdateRecord(int *bestTime, int *bestMoves, int currentTime, int currentMoves , int level) {
    readRecord(bestTime, bestMoves , level);

    if (currentTime < *bestTime || *bestTime == 0) {
        *bestTime = currentTime;
        *bestMoves = currentMoves;
        writeRecord(*bestTime, *bestMoves , level);
    } else if (currentTime == *bestTime && currentMoves < *bestMoves) {
        *bestMoves = currentMoves;
        writeRecord(*bestTime, *bestMoves , level);
    }
}

double startPauseTime = 0; 
double startTime = 0; 
int gameTime = 0; 
int moveCount = 0; 
int pauseTime = 0; 

void LoadTextures() {
    textures['.'] = LoadTexture("BACKGROUND.png");
    textures['W'] = LoadTexture("wall.png");
    textures['G'] = LoadTexture("groundBordered.png");
    textures['T'] = LoadTexture("targetBordered.png");
    textures['B'] = LoadTexture("NOTBoxOntoTarget.png");
    textures['t'] = LoadTexture("BoxOntoTargetFixed.png");
    textures['D'] = LoadTexture("frogFromUp.png");
    textures['U'] = LoadTexture("frogFromDown.png");
    textures['L'] = LoadTexture("frogLookingLeft.png");
    textures['R'] = LoadTexture("frogLookingRight.png");
}

bool UpdateWinCondition(Box BOXES[], int numBOXES , char MAP[MAP_HEIGHT][MAP_WIDTH] ) {
    bool allOnTargets = true;

    for (int i = 0; i < numBOXES; i++) {
        bool onTarget = false;

        for (int y = 0; y < MAP_HEIGHT; y++) {
            for (int x = 0; x < MAP_WIDTH; x++) {
                if (MAP[y][x] == 'T' && BOXES[i].posX == x * CELL_SIZE && BOXES[i].posY == y * CELL_SIZE) {
                    onTarget = true;
                    break;
                }
            }
            if (onTarget)
                break;
        }

        if (!onTarget) {
            allOnTargets = false;
            break;
        }
    }

    if (allOnTargets) {
        return true;
    }

    return false;
}

int main()
{
    InitWindow(992,672 , "Sokoban Oyunu");
    
    SetTargetFPS(144);
    InitAudioDevice();
    
    LoadTextures();
    
    
   
    
    
    Sound gameS = LoadSound("sokoban.mp3");
    Sound menuS = LoadSound("menu.mp3");
    Sound jump = LoadSound("jump.wav");
    
    SetSoundVolume(gameS, 0.2f); 
    SetSoundVolume(menuS, 0.2f); 
    SetSoundVolume(jump, 0.3f); 
    
    Texture2D startbutton = LoadTexture("STARTBUTTON.png");
    Texture2D exitbutton = LoadTexture("exitbutton.png");
    Texture2D howtoplaybutton = LoadTexture("HOWTOPLAYBUTTON.png");
    Texture2D creditsbutton = LoadTexture("creditsbutton.png");
    Texture2D background = LoadTexture("BACKGROUNDART.png");
    Texture2D level1button = LoadTexture("level1button.png");
    Texture2D level2button= LoadTexture("level2button.png");
    Texture2D level3button = LoadTexture("level3button.png");
    Texture2D level4button = LoadTexture("level4button.png");
    Texture2D backButton = LoadTexture("back.png");
    Texture2D levelonepre = LoadTexture("levelonepre.png");
    Texture2D leveltwopre = LoadTexture("leveltwopre.png");
    Texture2D levelthreepre = LoadTexture("levelthreepre.png");
    Texture2D levelfourpre = LoadTexture("levelfourpre.png");
    Texture2D pausebutton = LoadTexture("pausebutton.png");
    Texture2D restartbutton = LoadTexture("restartbutton.png");
    Texture2D undobutton = LoadTexture("undobutton.png");
    
    GameScreen currentScreen = LOGO;
    
    
    float frameHeight = (float)startbutton.height/NUM_FRAMES;
    Rectangle sourceRec = { 0, 0, (float)startbutton.width, frameHeight };
    
    float frameHeight2 = (float)howtoplaybutton.height/NUM_FRAMES;
    Rectangle sourceRec2 = { 0, 0, (float)howtoplaybutton.width, frameHeight2 };
     
    float frameHeight3 = (float)creditsbutton.height/NUM_FRAMES;
    Rectangle sourceRec3 = { 0, 0, (float)creditsbutton.width, frameHeight3 };
    
     float frameHeight4 = (float)exitbutton.height/NUM_FRAMES;
    Rectangle sourceRec4 = { 0, 0, (float)exitbutton.width, frameHeight4 };
    
    
    float frameHeight5 = (float)level1button.height / NUM_FRAMES;
    Rectangle sourceRec5 = { 0, 0, (float)level1button.width, frameHeight5 };    

  
    float frameHeight6 = (float)level2button.height / NUM_FRAMES;
    Rectangle sourceRec6 = { 0, 0, (float)level2button.width, frameHeight6 };    

   
    float frameHeight7 = (float)level3button.height / NUM_FRAMES;
    Rectangle sourceRec7 = { 0, 0, (float)level3button.width, frameHeight7 };   

   
    float frameHeight8 = (float)level4button.height / NUM_FRAMES;
    Rectangle sourceRec8 = { 0, 0, (float)level4button.width, frameHeight8 };    

    
    float frameHeight9 = (float)backButton.height / NUM_FRAMES;
    Rectangle sourceRec9 = { 0, 0, (float)backButton.width, frameHeight9 };
    
   
    Rectangle btnBounds = { SCREEN_WIDTH/2.0f - startbutton.width/2.0f, 200 , (float)startbutton.width, frameHeight };
    Rectangle btnBounds2 = { SCREEN_WIDTH/2.0f - howtoplaybutton.width/2.0f,310, (float)howtoplaybutton.width, frameHeight2 };
    Rectangle btnBounds3 = { SCREEN_WIDTH/2.0f - creditsbutton.width/2.0f,420, (float)creditsbutton.width, frameHeight3 };
    Rectangle btnBounds4 = { SCREEN_WIDTH/2.0f - exitbutton.width/2.0f,530, (float)exitbutton.width, frameHeight4 };
    Rectangle btnBounds5 = { SCREEN_WIDTH / 2.0f - level1button.width / 2.0f, 100, (float)level1button.width, frameHeight5 };
    Rectangle btnBounds6 = { SCREEN_WIDTH / 2.0f - level2button.width / 2.0f, 200, (float)level2button.width, frameHeight6 };
    Rectangle btnBounds7 = { SCREEN_WIDTH / 2.0f - level3button.width / 2.0f, 300, (float)level3button.width, frameHeight7 };
    Rectangle btnBounds8 = { SCREEN_WIDTH / 2.0f - level4button.width / 2.0f,400, (float)level4button.width, frameHeight8 };
    Rectangle btnBounds9 = { SCREEN_WIDTH / 2.0f - backButton.width / 2.0f, 500, (float)backButton.width, frameHeight9 }; 
    
    
    
    int btnState = 0;               
    bool btnAction = false;  
    
     int btnState2 = 0;               
    bool btnAction2 = false;  
    
     int btnState3 = 0;               
    bool btnAction3 = false;  
    
     int btnState4 = 0;               
    bool btnAction4 = false;

    int btnState5 = 0;
    bool btnAction5 = false;
    
    int btnState6 = 0;
    bool btnAction6 = false;
    
    int btnState7 = 0;
    bool btnAction7 = false;
    
    int btnState8 = 0;
    bool btnAction8 = false;
    
    int btnState9 = 0;
    bool btnAction9 = false;
    
    
    Vector2 mousePoint = { 0.0f, 0.0f };
    Vector2 mousePoint2 = { 0.0f, 0.0f }; 
    Vector2 mousePoint3 = { 0.0f, 0.0f };
    Vector2 mousePoint4 = { 0.0f, 0.0f };
    Vector2 mousePoint5 = { 0.0f, 0.0f };
    Vector2 mousePoint6 = { 0.0f, 0.0f };
    Vector2 mousePoint7 = { 0.0f, 0.0f };
    Vector2 mousePoint8 = { 0.0f, 0.0f };
    Vector2 mousePoint9 = { 0.0f, 0.0f };
    
    float backgroundX = -1000.0f;
    float backgroundY = 0.0f; 
     
    float creditsbackgroundX = -500.0f;
    float creditsbackgroundY = 0.0f; 
    
    float howtoplaybackgroundX = -500.0f;
    float howtoplaybackgroundY = 0.0f; 
    
    
   
    
    
    
    int state = 0;
    int framesCounter = 0;
    int topSideRecWidth = 16;
    int leftSideRecHeight = 16;
    int bottomSideRecWidth = 16;
    int rightSideRecHeight = 16;
    int lettersCount = 0;
    float alpha = 1.0f;
    int logoPositionX = (SCREEN_WIDTH -256 ) / 2; 
    int logoPositionY = (SCREEN_WIDTH-575 ) / 2; 
    int blinkDelay = 10; // blinking speed of the black boxes
    
    int blurPosx = 0;
    
    Color blur = (Color){255, 255, 255, 128};
    Color BIGBOX = (Color){34, 119, 34, 255};    
    Color SMALLBOX = (Color){255, 165, 0, 255};
    
   
    Rectangle backbefore = {276,416, 100,50};
    Rectangle playbefore = {616,416, 100,50};
    Rectangle pauselevel = {884,10, 32,32};
    Rectangle restartlevel = {938,10, 32,32};
    Rectangle undomove = {830,10, 32,32};
    
    
    int pausedLevel = -1;
    
    while (!WindowShouldClose()) {
        
    
        
        switch (currentScreen) {
            case PAUSE:
            {    
                
                mousePoint3 = GetMousePosition();
                btnAction3 = false;

                mousePoint2 = GetMousePosition();
                btnAction2 = false;            
                
                
                
                if (CheckCollisionPointRec(mousePoint2, btnBounds2))
                {
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState2 = 2;
                    else btnState2 = 1;

                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction2 = true;
                }
                else btnState2 = 0;

                if (btnAction2)
                {
                    double currentPauseTime = GetTime();
                    pauseTime = currentPauseTime - startPauseTime ;
                    startTime = (int)(startTime + pauseTime);
                    switch(pausedLevel) {
                        case LEVELONE:
                            currentScreen = LEVELONE;
                            break;
                        case LEVELTWO:
                            currentScreen = LEVELTWO;
                            break;
                        case LEVELTHREE:
                            currentScreen = LEVELTHREE;
                            break;
                        case LEVELFOUR:
                            currentScreen = LEVELFOUR;
                            break;    
                        default:
                            currentScreen = MAIN_MENU;
                            break;
                    }
                    
                }

                sourceRec2.y = btnState2 * frameHeight;
                 if (CheckCollisionPointRec(mousePoint3, btnBounds3))
                {
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState3 = 2;
                    else btnState3 = 1;

                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction3 = true;
                }
                else btnState3 = 0;

                if (btnAction3)
                {
                    currentScreen = MAIN_MENU;
                }

                sourceRec3.y = btnState3 * frameHeight;                
           
            } break;
            case HOW_TO_PLAY:
            {
            
              if(IsKeyPressed(KEY_SPACE))
               { 
                currentScreen = MAIN_MENU;
               }
             
            }break;
            case CREDITS:
            {
            
                            
              if(IsKeyPressed(KEY_SPACE))
               { 
                currentScreen = MAIN_MENU;
               }
             
            }break;   
            case MAIN_MENU:
            {
                mousePoint = GetMousePosition();
                btnAction = false;

                mousePoint2 = GetMousePosition();
                btnAction2 = false;

                mousePoint3 = GetMousePosition();
                btnAction3 = false;

                mousePoint4 = GetMousePosition();
                btnAction4 = false;

                if (CheckCollisionPointRec(mousePoint, btnBounds))
                {
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
                    else btnState = 1;

                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
                }
                else btnState = 0;

                if (btnAction)
                {
                    currentScreen = LEVEL_SCREEN;
                }
                sourceRec.y = btnState * frameHeight;

                if (CheckCollisionPointRec(mousePoint2, btnBounds2))
                {
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState2 = 2;
                    else btnState2 = 1;

                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction2 = true;
                }
                else btnState2 = 0;

                if (btnAction2)
                {
                    currentScreen = HOW_TO_PLAY;
                }

                sourceRec2.y = btnState2 * frameHeight;

                if (CheckCollisionPointRec(mousePoint3, btnBounds3))
                {
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState3 = 2;
                    else btnState3 = 1;

                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction3 = true;
                }
                else btnState3 = 0;

                if (btnAction3)
                {
                    currentScreen = CREDITS;
                }

                sourceRec3.y = btnState3 * frameHeight;

                if (CheckCollisionPointRec(mousePoint4, btnBounds4))
                {
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState4 = 2;
                    else btnState4 = 1;

                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction4 = true;
                }
                else btnState4 = 0;

                if (btnAction4)
                {
                    CloseWindow();
                }

                sourceRec4.y = btnState4 * frameHeight;
            } break;
            case LEVEL_SCREEN:
            {
                mousePoint5 = GetMousePosition();
                btnAction5 = false;

                mousePoint6 = GetMousePosition();
                btnAction6 = false;

                mousePoint7 = GetMousePosition();
                btnAction7 = false;

                mousePoint8 = GetMousePosition();
                btnAction8 = false;

                mousePoint9 = GetMousePosition();
                btnAction9 = false;

                if (CheckCollisionPointRec(mousePoint5, btnBounds5))
                {
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState5 = 2;
                    else btnState5 = 1;

                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction5 = true;
                }
                else btnState5 = 0;

                if (btnAction5)
                {
                    pausedLevel = LEVELONE;
                    playerPosX = 17*32;
                    playerPosY = 13*32;
                    playerTexture = textures['D']; // Frog starts looking up
                    boxes[0].posX = 32 * 11;
                    boxes[0].posY = 32 * 12;
                    boxes[0].onTarget = 0;

                    boxes[1].posX = 32 * 8;
                    boxes[1].posY = 32 * 12;
                    boxes[1].onTarget = 0;

                    boxes[2].posX = 32 * 11;
                    boxes[2].posY = 32 * 9;
                    boxes[2].onTarget = 0;

                    boxes[3].posX = 32 * 11;
                    boxes[3].posY = 32 * 7;
                    boxes[3].onTarget = 0;

                    boxes[4].posX = 32 * 13;
                    boxes[4].posY = 32 * 8;
                    boxes[4].onTarget = 0;

                    boxes[5].posX = 32 * 13;
                    boxes[5].posY = 32 * 9;
                    boxes[5].onTarget = 0;

                                        
                                        
                   
                    currentScreen = BEFOREGAME;
                }

                sourceRec6.y = btnState6 * frameHeight;
                if (CheckCollisionPointRec(mousePoint6, btnBounds6))
                {
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState6 = 2;
                    else btnState6 = 1;

                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction6 = true;
                }
                else btnState6 = 0;

                if (btnAction6)
                {
                    pausedLevel = LEVELTWO;
                    player2PosX = 21*32;
                    player2PosY = 12*32;
                    player2Texture = textures['D']; 
                    
                    boxes2[0].posX = 32 * 16;
                    boxes2[0].posY = 32 * 11;
                    boxes2[0].onTarget = 0;

                    boxes2[1].posX = 32 * 17;
                    boxes2[1].posY = 32 * 10;
                    boxes2[1].onTarget = 0;

                    boxes2[2].posX = 32 * 16;
                    boxes2[2].posY = 32 * 12;
                    boxes2[2].onTarget = 0;

                    boxes2[3].posX = 32 * 17;
                    boxes2[3].posY = 32 * 14;
                    boxes2[3].onTarget = 0;

                    boxes2[4].posX = 32 * 18;
                    boxes2[4].posY = 32 * 7;
                    boxes2[4].onTarget = 0;

                    boxes2[5].posX = 32 * 18;
                    boxes2[5].posY = 32 * 11;
                    boxes2[5].onTarget = 0;

                    boxes2[6].posX = 32 * 19;
                    boxes2[6].posY = 32 * 12;
                    boxes2[6].onTarget = 0;

                    boxes2[7].posX = 32 * 18;
                    boxes2[7].posY = 32 * 13;
                    boxes2[7].onTarget = 0;

                    boxes2[8].posX = 32 * 19;
                    boxes2[8].posY = 32 * 14;
                    boxes2[8].onTarget = 0;

                    boxes2[9].posX = 32 * 19;
                    boxes2[9].posY = 32 * 11;
                    boxes2[9].onTarget = 0;

                    boxes2[10].posX = 32 * 20;
                    boxes2[10].posY = 32 * 10;
                    boxes2[10].onTarget = 0;

                    boxes2[11].posX = 32 * 21;
                    boxes2[11].posY = 32 * 8;
                    boxes2[11].onTarget = 0;

                    
                    
                    currentScreen = BEFOREGAME;
                }

                sourceRec6.y = btnState6 * frameHeight;
                
                if (CheckCollisionPointRec(mousePoint7, btnBounds7))
                {
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState7 = 2;
                    else btnState7 = 1;

                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction7 = true;
                }
                else btnState7 = 0;

                if (btnAction7)
                {
                    pausedLevel = LEVELTHREE;
                    player3Texture = textures['D']; 
                    player3PosX = 14*32;
                    player3PosY =  6*32;
                    boxes3[0].posX = 32 * 18;
                    boxes3[0].posY = 32 * 6;
                    boxes3[0].onTarget = 0;

                    boxes3[1].posX = 32 * 18;
                    boxes3[1].posY = 32 * 9;
                    boxes3[1].onTarget = 0;

                    boxes3[2].posX = 32 * 19;
                    boxes3[2].posY = 32 * 6;
                    boxes3[2].onTarget = 0;

                    boxes3[3].posX = 32 * 14;
                    boxes3[3].posY = 32 * 7;
                    boxes3[3].onTarget = 0;

                    boxes3[4].posX = 32 * 12;
                    boxes3[4].posY = 32 * 8;
                    boxes3[4].onTarget = 0;

                    boxes3[5].posX = 32 * 15;
                    boxes3[5].posY = 32 * 11;
                    boxes3[5].onTarget = 0;

                    boxes3[6].posX = 32 * 13;
                    boxes3[6].posY = 32 * 11;
                    boxes3[6].onTarget = 0;

                    boxes3[7].posX = 32 * 11;
                    boxes3[7].posY = 32 * 11;
                    boxes3[7].onTarget = 0;

                    boxes3[8].posX = 32 * 11;
                    boxes3[8].posY = 32 * 10;
                    boxes3[8].onTarget = 0;

                    boxes3[9].posX = 32 * 11;
                    boxes3[9].posY = 32 * 13;
                    boxes3[9].onTarget = 0;

                    boxes3[10].posX = 32 * 12;
                    boxes3[10].posY = 32 * 13;
                    boxes3[10].onTarget = 0;

                    currentScreen = BEFOREGAME;
                }

                sourceRec7.y = btnState7 * frameHeight;
                 if (CheckCollisionPointRec(mousePoint8, btnBounds8))
                {
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState8 = 2;
                    else btnState8 = 1;

                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction8 = true;
                }
                else btnState8 = 0;

                if (btnAction8)
                {
                    pausedLevel = LEVELFOUR;
                    player4Texture = textures['D']; 
                    player4PosX = 12*32;
                    player4PosY =  8*32;
                    boxes4[0].posX = 32 * 12;
                    boxes4[0].posY = 32 * 9;
                    boxes4[0].onTarget = 0;

                    boxes4[1].posX = 32 * 12;
                    boxes4[1].posY = 32 * 7;
                    boxes4[1].onTarget = 0;

                    boxes4[2].posX = 32 * 13;
                    boxes4[2].posY = 32 * 8;
                    boxes4[2].onTarget = 0;

                    boxes4[3].posX = 32 * 13;
                    boxes4[3].posY = 32 * 10;
                    boxes4[3].onTarget = 0;

                    boxes4[4].posX = 32 * 9;
                    boxes4[4].posY = 32 * 7;
                    boxes4[4].onTarget = 0;

                    boxes4[5].posX = 32 * 10;
                    boxes4[5].posY = 32 * 8;
                    boxes4[5].onTarget = 0;

                    boxes4[6].posX = 32 * 8;
                    boxes4[6].posY = 32 * 10;
                    boxes4[6].onTarget = 0;

                    boxes4[7].posX = 32 * 16;
                    boxes4[7].posY = 32 * 11;
                    boxes4[7].onTarget = 0;

                    boxes4[8].posX = 32 * 18;
                    boxes4[8].posY = 32 * 11;
                    boxes4[8].onTarget = 0;

                    boxes4[9].posX = 32 * 8;
                    boxes4[9].posY = 32 * 12;
                    boxes4[9].onTarget = 0;

                    boxes4[10].posX = 32 * 18;
                    boxes4[10].posY = 32 * 12;
                    boxes4[10].onTarget = 0;

                    boxes4[11].posX = 32 * 9;
                    boxes4[11].posY = 32 * 13;
                    boxes4[11].onTarget = 0;

                    boxes4[12].posX = 32 * 12;
                    boxes4[12].posY = 32 * 13;
                    boxes4[12].onTarget = 0;

                    boxes4[13].posX = 32 * 16;
                    boxes4[13].posY = 32 * 13;
                    boxes4[13].onTarget = 0;

                    boxes4[14].posX = 32 * 19;
                    boxes4[14].posY = 32 * 13;
                    boxes4[14].onTarget = 0;

                    boxes4[15].posX = 32 * 8;
                    boxes4[15].posY = 32 * 14;
                    boxes4[15].onTarget = 0;

                   
                    currentScreen = BEFOREGAME;
                }

                sourceRec8.y = btnState8 * frameHeight;
                 if (CheckCollisionPointRec(mousePoint9, btnBounds9))
                {
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState9 = 2;
                    else btnState9 = 1;

                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction9 = true;
                }
                else btnState9 = 0;

                if (btnAction9)
                {
                    currentScreen = MAIN_MENU;
                }

                sourceRec9.y = btnState9 * frameHeight;


            } break;
            case ENDING:
            {    
                mousePoint3 = GetMousePosition();
                btnAction3 = false;

                            
                
                
                
                
                 if (CheckCollisionPointRec(mousePoint3, btnBounds3))
                {
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState3 = 2;
                    else btnState3 = 1;

                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction3 = true;
                }
                else btnState3 = 0;

                if (btnAction3)
                {
                    currentScreen = MAIN_MENU;
                }

                sourceRec3.y = btnState3 * frameHeight;                
           
            } break;
            case BEFOREGAME:
             {
               
               if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
               { 
           
                    if(CheckCollisionPointRec(GetMousePosition(),playbefore))
                    {
                        switch(pausedLevel) {
                                case LEVELONE:
                                    ClearMoveStacks();
                                    startTime = GetTime();
                                    moveCount = 0;
                                    currentScreen = LEVELONE;
                                    break;
                                case LEVELTWO:
                                    ClearMoveStacks();
                                    startTime = GetTime();
                                    moveCount = 0;
                                    currentScreen = LEVELTWO;
                                    break;
                                case LEVELTHREE:
                                    ClearMoveStacks();
                                    startTime = GetTime();
                                    moveCount = 0;
                                    currentScreen = LEVELTHREE;
                                    break;
                                case LEVELFOUR:
                                    ClearMoveStacks();
                                    startTime = GetTime();
                                    moveCount = 0;
                                    currentScreen = LEVELFOUR;
                                    break;    
                                default:
                                    currentScreen = MAIN_MENU;
                                    break;
                            }
                    }     
                
                    if(CheckCollisionPointRec(GetMousePosition(),backbefore)){
                        currentScreen = LEVEL_SCREEN;
                    }
                }  
             }break;          
        }

        
        
        
         BeginDrawing();
            
            ClearBackground(RAYWHITE);
            
            

           switch(currentScreen)
            {   
                case BEFOREGAME:
                {
                       if (!IsSoundPlaying(menuS))
                    {
                        StopSound(gameS);
                      PlaySound(menuS);
                    }
                DrawTextureEx(background, (Vector2){ backgroundX + 500, backgroundY }, 0.0f, 0.8f, WHITE);
                DrawTextureEx(background, (Vector2){ backgroundX + background.width * 1.0f, backgroundY }, 0.0f, 0.8f, WHITE);
    
                backgroundX -= BACKGROUND_MOVE_SPEED * GetFrameTime();
    
                if (backgroundX <= -background.width)
                {
                    backgroundX = 0;
                }
                
                DrawTextureRec(level1button, sourceRec, (Vector2){ btnBounds5.x, btnBounds5.y  }, WHITE);
                DrawTextureRec(level2button, sourceRec2, (Vector2){ btnBounds6.x, btnBounds6.y }, WHITE);
                DrawTextureRec(level3button, sourceRec3, (Vector2){ btnBounds7.x, btnBounds7.y }, WHITE);
                DrawTextureRec(level4button, sourceRec4, (Vector2){ btnBounds8.x, btnBounds8.y }, WHITE);
                DrawTextureRec(backButton, sourceRec4, (Vector2){ btnBounds9.x, btnBounds9.y }, WHITE);
                   
                    DrawRectangle(blurPosx,0, 992,672,blur);
                    DrawRectangle(246,136, 500,350,BIGBOX);
                    DrawRectangle(276,416, 100,50,SMALLBOX);
                    DrawRectangle(616,416, 100,50,SMALLBOX);
                    DrawText("BACK",285,425, 30,WHITE);
                    DrawText("PLAY",625,425,30,WHITE);
                    
                    switch(pausedLevel) {
                        case LEVELONE:
                            DrawTexture(levelonepre,321,166, WHITE);
                             drawRecord(1);
                            break;
                        case LEVELTWO:
                            DrawTexture(leveltwopre,321,166, WHITE);
                             drawRecord(2);
                            break;
                        case LEVELTHREE:
                            DrawTexture(levelthreepre,321,166, WHITE);
                             drawRecord(3);
                            break;
                        case LEVELFOUR:
                            DrawTexture(levelfourpre,321,166, WHITE);
                             drawRecord(4);
                            break;    
                        default:
                            currentScreen = MAIN_MENU;
                            break;
                    }
                    DrawText("BEST RESULT",385,385,30,WHITE);
                   
                    
                    
                }break;
                case LEVELONE:
                {   
                         
                      if (!IsSoundPlaying(gameS))
                          {
                                StopSound(menuS);
                                PlaySound(gameS);
                          }
                      
                            
                            
                           
                        if(IsKeyPressed(KEY_T) || ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))&& CheckCollisionPointRec(GetMousePosition(),restartlevel))){
                            
                            ClearMoveStacks();
                            startTime = GetTime();
                            moveCount =0;
                            playerPosX = 17*32;
                            playerPosY = 13*32;
                            playerTexture = textures['D']; // Frog starts looking up
                            boxes[0].posX = 32 * 11;
                            boxes[0].posY = 32 * 12;
                            boxes[0].onTarget = 0;

                            boxes[1].posX = 32 * 8;
                            boxes[1].posY = 32 * 12;
                            boxes[1].onTarget = 0;

                            boxes[2].posX = 32 * 11;
                            boxes[2].posY = 32 * 9;
                            boxes[2].onTarget = 0;

                            boxes[3].posX = 32 * 11;
                            boxes[3].posY = 32 * 7;
                            boxes[3].onTarget = 0;

                            boxes[4].posX = 32 * 13;
                            boxes[4].posY = 32 * 8;
                            boxes[4].onTarget = 0;

                            boxes[5].posX = 32 * 13;
                            boxes[5].posY = 32 * 9;
                            boxes[5].onTarget = 0;
                            
                        }
                           
                        if(IsKeyPressed(KEY_P) || ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))&& CheckCollisionPointRec(GetMousePosition(),pauselevel)))
                         {
                             pausedLevel = LEVELONE;
                             startPauseTime = GetTime();
                             currentScreen = PAUSE;
                         }    
                         

                        if (UpdateWinCondition(boxes, numBoxes, map))
                        {
                            int bestTime = 0, bestMoves = 0;
                            kaydetSkorlar(gameTime, moveCount);
                            checkAndUpdateRecord(&bestTime, &bestMoves, gameTime, moveCount , 1 );
                            
                            WaitTime(1);
                            currentScreen = ENDING;
                           
                             
                             break;
                        }        
                        
                        else  
                        {
                            if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W))
                            {
                                playerTexture = textures['U'];
                                SaveMove(&playerMoveStack, playerPosX, playerPosY);
                                for (int i = 0; i < numBoxes; i++) {
                                    SaveMove(&boxMoveStacks[i], boxes[i].posX, boxes[i].posY);
                                }
                                bool boxPushed = false , l = false;
                                int k=0; 
                               
                                
                                for (int i = 0; i < numBoxes; i++)
                                {
                                    if (boxes[i].posX == playerPosX && boxes[i].posY == playerPosY - 32)
                                    {
                                        if (map[(int)((boxes[i].posY - 32) / 32)][(int)(boxes[i].posX / 32)] != 'W')
                                        {
                                            for (int j = 0; j < numBoxes; j++)
                                            {
                                                if (boxes[j].posX == playerPosX && boxes[j].posY == playerPosY - 64)
                                                {
                                                    boxPushed = true;
                                                    k = j;
                                                    break;
                                                }
                                            }

                                            if (!boxPushed)
                                            {
                                                boxes[i].posY -= 32;
                                                if (map[(int)(boxes[i].posY / 32)][(int)(boxes[i].posX / 32)] == 'T')
                                                {
                                                    boxes[i].onTarget = true;
                                                }
                                                else
                                                {
                                                    boxes[i].onTarget = false;
                                                }
                                            }
                                            
                                        }
                                        k = i;
                                        break; 
                                    }
                                }

                                if (!boxPushed)
                                {
                                    bool deneme = true;
                                    while (deneme){
                                        
                                        if((map[(int)((playerPosY - 64) / 32)][(int)(playerPosX / 32)] == 'W') && (boxes[k].posX == playerPosX && boxes[k].posY == playerPosY - 32))
                                        {
                                            deneme = false;
                                            continue;
                                            
                                        } 
                                        else if (map[(int)((playerPosY - 32) / 32)][(int)(playerPosX / 32)] != 'W')
                                        {
                                            
                                            playerPosY -= 32;
                                            PlaySound(jump);
                                            moveCount++;
                                            l = true;
                                            

                                        }
                                        
                                        deneme = false;
                                    }
                                }
                                if (l != 1){
                                            UndoMove(&playerMoveStack, &playerPosX, &playerPosY);
                                            for (int i = 0; i < numBoxes; i++) {
                                                UndoMove(&boxMoveStacks[i], &boxes[i].posX, &boxes[i].posY);
                                            }
                                        }
                            }
                            else if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S))
                            {
                                playerTexture = textures['D'];
                                SaveMove(&playerMoveStack, playerPosX, playerPosY);
                                for (int i = 0; i < numBoxes; i++) {
                                    SaveMove(&boxMoveStacks[i], boxes[i].posX, boxes[i].posY);
                                }

                                bool boxPushed = false , l = false;
                                int k = 0;

                                for (int i = 0; i < numBoxes; i++)
                                {
                                    if (boxes[i].posX == playerPosX && boxes[i].posY == playerPosY + 32)
                                    {
                                        if (map[(int)((boxes[i].posY + 32) / 32)][(int)(boxes[i].posX / 32)] != 'W')
                                        {
                                            for (int j = 0; j < numBoxes; j++)
                                            {
                                                if (boxes[j].posX == playerPosX && boxes[j].posY == playerPosY + 64)
                                                {
                                                    boxPushed = true;
                                                    k = j;
                                                    break;
                                                }
                                            }

                                            if (!boxPushed)
                                            {
                                                boxes[i].posY += 32;
                                                if (map[(int)(boxes[i].posY / 32)][(int)(boxes[i].posX / 32)] == 'T')
                                                {
                                                    boxes[i].onTarget = true;
                                                }
                                                else
                                                {
                                                    boxes[i].onTarget = false;
                                                }
                                            }

                                        }
                                        k = i;
                                        break; 
                                    }
                                }

                                
                                if (!boxPushed)
                                {
                                    bool deneme = true;
                                    while (deneme){
                                        
                                        if ((map[(int)((playerPosY + 64) / 32)][(int)(playerPosX / 32)] == 'W') && (boxes[k].posX == playerPosX && boxes[k].posY == playerPosY + 32))
                                        {
                                            deneme = false;
                                            continue;

                                        }
                                        else if (map[(int)((playerPosY + 32) / 32)][(int)(playerPosX / 32)] != 'W')
                                        {
                                            
                                            playerPosY += 32;
                                            PlaySound(jump);
                                            moveCount++;
                                            l = true;
                                        }
                                        deneme = false;
                                    }
                                }
                                 if (l != 1){
                                            UndoMove(&playerMoveStack, &playerPosX, &playerPosY);
                                            for (int i = 0; i < numBoxes; i++) {
                                                UndoMove(&boxMoveStacks[i], &boxes[i].posX, &boxes[i].posY);
                                            }
                                            }
                                        
                            }
                            else if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A))
                            {
                                playerTexture = textures['L'];
                                SaveMove(&playerMoveStack, playerPosX, playerPosY);
                                for (int i = 0; i < numBoxes; i++) {
                                    SaveMove(&boxMoveStacks[i], boxes[i].posX, boxes[i].posY);
                                }

                                bool boxPushed = false , l = false;
                                int k = 0;

                                for (int i = 0; i < numBoxes; i++)
                                {
                                    if (boxes[i].posX == playerPosX - 32 && boxes[i].posY == playerPosY)
                                    {
                                        if (map[(int)(boxes[i].posY / 32)][(int)((boxes[i].posX - 32) / 32)] != 'W')
                                        {
                                            for (int j = 0; j < numBoxes; j++)
                                            {
                                                if (boxes[j].posX == playerPosX - 64 && boxes[j].posY == playerPosY)
                                                {
                                                    boxPushed = true;
                                                    k = j;
                                                    break;
                                                }
                                            }

                                            if (!boxPushed)
                                            {
                                                boxes[i].posX -= 32;
                                                if (map[(int)(boxes[i].posY / 32)][(int)(boxes[i].posX / 32)] == 'T')
                                                {
                                                    boxes[i].onTarget = true;
                                                }
                                                else
                                                {
                                                    boxes[i].onTarget = false;
                                                }
                                            }

                                        }
                                        k = i;
                                        break; 
                                    }
                                }

                                if (!boxPushed)
                                {
                                    bool deneme = true;
                                    while (deneme){

                                        if ((map[(int)(playerPosY / 32)][(int)((playerPosX - 64) / 32)] == 'W') && (boxes[k].posX == playerPosX - 32 && boxes[k].posY == playerPosY))
                                        {
                                            deneme = false;
                                            continue;

                                        }
                                        else if (map[(int)(playerPosY / 32)][(int)((playerPosX - 32) / 32)] != 'W')
                                        {
                                            
                                            playerPosX -= 32;
                                            PlaySound(jump);
                                            moveCount++;
                                            l = true;
                                        }
                                            
                                        deneme = false;
                                    }    

                                } 
                                if (l != 1){UndoMove(&playerMoveStack, &playerPosX, &playerPosY);
                                            for (int i = 0; i < numBoxes; i++) {
                                                UndoMove(&boxMoveStacks[i], &boxes[i].posX, &boxes[i].posY);
                                            }
                                        }
                            }
                            else if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D))
                            {
                                playerTexture = textures['R'];
                                SaveMove(&playerMoveStack, playerPosX, playerPosY);
                                for (int i = 0; i < numBoxes; i++) {
                                    SaveMove(&boxMoveStacks[i], boxes[i].posX, boxes[i].posY);
                                }

                                bool boxPushed = false , l = false;
                                int k = 0;

                                for (int i = 0; i < numBoxes; i++)
                                {
                                    if (boxes[i].posX == playerPosX + 32 && boxes[i].posY == playerPosY)
                                    {
                                        if (map[(int)(boxes[i].posY / 32)][(int)((boxes[i].posX + 32) / 32)] != 'W')
                                        {
                                            for (int j = 0; j < numBoxes; j++)
                                            {
                                                if (boxes[j].posX == playerPosX + 64 && boxes[j].posY == playerPosY)
                                                {
                                                    
                                                    boxPushed = true;
                                                    k = j;
                                                    break;
                                                }
                                            }

                                          
                                            if (!boxPushed)
                                            {
                                                boxes[i].posX += 32;
                                                if (map[(int)(boxes[i].posY / 32)][(int)(boxes[i].posX / 32)] == 'T')
                                                {
                                                    boxes[i].onTarget = true;
                                                }
                                                else
                                                {
                                                    boxes[i].onTarget = false;
                                                }
                                            }

                                        }
                                        k = i;
                                        break;
                                    }
                                }

                                if (!boxPushed)
                                {
                                    bool deneme = true;
                                    while (deneme){

                                        if ((map[(int)(playerPosY / 32)][(int)((playerPosX + 64) / 32)] == 'W') && (boxes[k].posX == playerPosX + 32 && boxes[k].posY == playerPosY))
                                        {
                                            deneme = false;
                                            continue;

                                        }
                                        else if (map[(int)(playerPosY / 32)][(int)((playerPosX + 32) / 32)] != 'W')
                                        {
                                            
                                            playerPosX += 32;
                                            PlaySound(jump);
                                            moveCount++;
                                            l = true;
                                        }
                                            
                                        deneme = false;
                                    }
                                } 
                                if (l != 1){UndoMove(&playerMoveStack, &playerPosX, &playerPosY);
                                            for (int i = 0; i < numBoxes; i++) {
                                                UndoMove(&boxMoveStacks[i], &boxes[i].posX, &boxes[i].posY);
                                            }
                                        }
                            }
                            if(IsKeyPressed(KEY_R) || ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))&& CheckCollisionPointRec(GetMousePosition(),undomove)))
                            {
                                UndoMove(&playerMoveStack, &playerPosX, &playerPosY);
                                for (int i = 0; i < numBoxes; i++) {
                                    UndoMove(&boxMoveStacks[i], &boxes[i].posX, &boxes[i].posY);
                                }
                                if(moveCount>0){
                                    moveCount--;
                                }
                            }

                        
                        
                        for (int y = 0; y < MAP_HEIGHT; y++) {
                            for (int x = 0; x < MAP_WIDTH; x++) {
                                int cell = map[y][x];
                                if (textures[cell].id != 0) {
                                    DrawTexture(textures[cell], x * CELL_SIZE, y * CELL_SIZE, WHITE);
                                }
                            }
                        }
                        DrawTexture(pausebutton,884,10, WHITE);
                        DrawTexture(undobutton,830,10, WHITE);
                        DrawTexture(restartbutton,938,10, WHITE);
                        DrawText(TextFormat("Time: %02d:%02d", gameTime / 60, gameTime % 60), 10, 10, 20, DARKBLUE);
                        DrawText(TextFormat("Moves: %d", moveCount), 10, 40, 20, DARKBLUE);
                        
                        if (!UpdateWinCondition(boxes, numBoxes , map)) {
                            double currentTime = GetTime();
                            gameTime = (int)(currentTime - startTime );
                            
                        }
                        DrawTexture(playerTexture, playerPosX, playerPosY, WHITE);
                        
                        
                        for (int i = 0; i < numBoxes; i++) {
                            Box *box = &boxes[i];
                            if (box->onTarget) {
                                DrawTexture(textures['t'], box->posX, box->posY, WHITE);
                            } else {
                                DrawTexture(textures['B'], box->posX, box->posY, WHITE);
                            }
                        }
                         
                         
                        
                        } 
                         
                        
                } break;
                case LEVELTWO:
                {   
                     if (!IsSoundPlaying(gameS))
                          {
                            StopSound(menuS);
                            PlaySound(gameS);
                          }
                                
                         
                           
                        if(IsKeyPressed(KEY_T) || ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))&& CheckCollisionPointRec(GetMousePosition(),restartlevel))){
                            
                            ClearMoveStacks();
                            startTime = GetTime();
                            moveCount =0;
                            player2PosX = 21*32;
                            player2PosY = 12*32;
                            player2Texture = textures['D'];  
                            
                            boxes2[0].posX = 32 * 16;
                            boxes2[0].posY = 32 * 11;
                            boxes2[0].onTarget = 0;

                            boxes2[1].posX = 32 * 17;
                            boxes2[1].posY = 32 * 10;
                            boxes2[1].onTarget = 0;

                            boxes2[2].posX = 32 * 16;
                            boxes2[2].posY = 32 * 12;
                            boxes2[2].onTarget = 0;

                            boxes2[3].posX = 32 * 17;
                            boxes2[3].posY = 32 * 14;
                            boxes2[3].onTarget = 0;

                            boxes2[4].posX = 32 * 18;
                            boxes2[4].posY = 32 * 7;
                            boxes2[4].onTarget = 0;

                            boxes2[5].posX = 32 * 18;
                            boxes2[5].posY = 32 * 11;
                            boxes2[5].onTarget = 0;

                            boxes2[6].posX = 32 * 19;
                            boxes2[6].posY = 32 * 12;
                            boxes2[6].onTarget = 0;

                            boxes2[7].posX = 32 * 18;
                            boxes2[7].posY = 32 * 13;
                            boxes2[7].onTarget = 0;

                            boxes2[8].posX = 32 * 19;
                            boxes2[8].posY = 32 * 14;
                            boxes2[8].onTarget = 0;

                            boxes2[9].posX = 32 * 19;
                            boxes2[9].posY = 32 * 11;
                            boxes2[9].onTarget = 0;

                            boxes2[10].posX = 32 * 20;
                            boxes2[10].posY = 32 * 10;
                            boxes2[10].onTarget = 0;

                            boxes2[11].posX = 32 * 21;
                            boxes2[11].posY = 32 * 8;
                            boxes2[11].onTarget = 0;
                                    
                            
                            
                            
                        }
                      if(IsKeyPressed(KEY_P) || ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))&& CheckCollisionPointRec(GetMousePosition(),pauselevel)))
                    {
                        startPauseTime = GetTime();
                        pausedLevel = LEVELTWO;
                        currentScreen = PAUSE;
                    }
                    
                    
                        //UpdateMusicStream(sokoban);

                        if (UpdateWinCondition(boxes2, numBoxes2 , map2))
                        {
                          
                            int bestTime = 0, bestMoves = 0;
                            kaydetSkorlar(gameTime, moveCount);
                            checkAndUpdateRecord(&bestTime, &bestMoves, gameTime, moveCount , 2 );
                            
                            WaitTime(1);
                            currentScreen = ENDING;
                           
                             
                             break;
                        }        
                        
                        else  
                        {
                            if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W))
                            {
                                
                                player2Texture = textures['U'];
                                SaveMove(&playerMoveStack, player2PosX, player2PosY);
                                for (int i = 0; i < numBoxes2; i++) {
                                    SaveMove(&boxMoveStacks[i], boxes2[i].posX, boxes2[i].posY);
                                }
                                bool boxPushed = false , l = false;
                                int k=0;
                                
                                for (int i = 0; i < numBoxes2; i++)
                                {
                                    if (boxes2[i].posX == player2PosX && boxes2[i].posY == player2PosY - 32)
                                    {
                                        if (map2[(int)((boxes2[i].posY - 32) / 32)][(int)(boxes2[i].posX / 32)] != 'W')
                                        {
                                            for (int j = 0; j < numBoxes2; j++)
                                            {
                                                if (boxes2[j].posX == player2PosX && boxes2[j].posY == player2PosY - 64)
                                                {
                                                    boxPushed = true;
                                                    k = j;
                                                    break;
                                                }
                                            }

                                            if (!boxPushed)
                                            {
                                                boxes2[i].posY -= 32;
                                                if (map2[(int)(boxes2[i].posY / 32)][(int)(boxes2[i].posX / 32)] == 'T')
                                                {
                                                    boxes2[i].onTarget = true;
                                                }
                                                else
                                                {
                                                    boxes2[i].onTarget = false;
                                                }
                                            }
                                            
                                        }
                                        k = i;
                                        break; 
                                    }
                                }

                                if (!boxPushed)
                                {
                                    bool deneme = true;
                                    while (deneme){
                                        
                                        if((map2[(int)((player2PosY - 64) / 32)][(int)(player2PosX / 32)] == 'W') && (boxes2[k].posX == player2PosX && boxes2[k].posY == player2PosY - 32))
                                        {
                                            deneme = false;
                                            continue;
                                            
                                        } 
                                        else if (map2[(int)((player2PosY - 32) / 32)][(int)(player2PosX / 32)] != 'W')
                                        {
                                            
                                            player2PosY -= 32;
                                            PlaySound(jump);
                                            moveCount++;
                                            l = true;
                                        }
                                        deneme = false;
                                    }
                                }
                                 if (l != 1){
                                            UndoMove(&playerMoveStack, &player2PosX, &player2PosY);
                                            for (int i = 0; i < numBoxes2; i++) {
                                                UndoMove(&boxMoveStacks[i], &boxes2[i].posX, &boxes2[i].posY);
                                            }
                                        }
                            }
                            else if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S))
                            {
                                player2Texture = textures['D'];
                                SaveMove(&playerMoveStack, player2PosX, player2PosY);
                                for (int i = 0; i < numBoxes2; i++) {
                                    SaveMove(&boxMoveStacks[i], boxes2[i].posX, boxes2[i].posY);
                                }

                                bool boxPushed = false , l = false;
                                int k = 0;

                                for (int i = 0; i < numBoxes2; i++)
                                {
                                    if (boxes2[i].posX == player2PosX && boxes2[i].posY == player2PosY + 32)
                                    {
                                        if (map2[(int)((boxes2[i].posY + 32) / 32)][(int)(boxes2[i].posX / 32)] != 'W')
                                        {
                                            for (int j = 0; j < numBoxes2; j++)
                                            {
                                                if (boxes2[j].posX == player2PosX && boxes2[j].posY == player2PosY + 64)
                                                {
                                                    boxPushed = true;
                                                    k = j;
                                                    break;
                                                }
                                            }

                                            if (!boxPushed)
                                            {
                                                boxes2[i].posY += 32;
                                                if (map2[(int)(boxes2[i].posY / 32)][(int)(boxes2[i].posX / 32)] == 'T')
                                                {
                                                    boxes2[i].onTarget = true;
                                                }
                                                else
                                                {
                                                    boxes2[i].onTarget = false;
                                                }
                                            }

                                        }
                                        k = i;
                                        break; 
                                    }
                                }

                                if (!boxPushed)
                                {
                                    bool deneme = true;
                                    while (deneme){
                                        
                                        if ((map2[(int)((player2PosY + 64) / 32)][(int)(player2PosX / 32)] == 'W') && (boxes2[k].posX == player2PosX && boxes2[k].posY == player2PosY + 32))
                                        {
                                            deneme = false;
                                            continue;

                                        }
                                        else if (map2[(int)((player2PosY + 32) / 32)][(int)(player2PosX / 32)] != 'W')
                                        {
                                            
                                            player2PosY += 32;
                                            PlaySound(jump);
                                            moveCount++;
                                            l = true;
                                        }
                                        deneme = false;
                                    }
                                }
                                 if (l != 1){
                                            UndoMove(&playerMoveStack, &player2PosX, &player2PosY);
                                            for (int i = 0; i < numBoxes2; i++) {
                                                UndoMove(&boxMoveStacks[i], &boxes2[i].posX, &boxes2[i].posY);
                                            }
                                        }
                            }
                            else if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A))
                            {
                                player2Texture = textures['L'];
                                SaveMove(&playerMoveStack, player2PosX, player2PosY);
                                for (int i = 0; i < numBoxes2; i++) {
                                    SaveMove(&boxMoveStacks[i], boxes2[i].posX, boxes2[i].posY);
                                }

                                bool boxPushed = false , l = false;
                                int k = 0;

                                for (int i = 0; i < numBoxes2; i++)
                                {
                                    if (boxes2[i].posX == player2PosX - 32 && boxes2[i].posY == player2PosY)
                                    {
                                        if (map2[(int)(boxes2[i].posY / 32)][(int)((boxes2[i].posX - 32) / 32)] != 'W')
                                        {
                                            for (int j = 0; j < numBoxes2; j++)
                                            {
                                                if (boxes2[j].posX == player2PosX - 64 && boxes2[j].posY == player2PosY)
                                                {
                                                    boxPushed = true;
                                                    k = j;
                                                    break;
                                                }
                                            }

                                            if (!boxPushed)
                                            {
                                                boxes2[i].posX -= 32;
                                                if (map2[(int)(boxes2[i].posY / 32)][(int)(boxes2[i].posX / 32)] == 'T')
                                                {
                                                    boxes2[i].onTarget = true;
                                                }
                                                else
                                                {
                                                    boxes2[i].onTarget = false;
                                                }
                                            }

                                        }
                                        k = i;
                                        break; 
                                    }
                                }

                                if (!boxPushed)
                                {
                                    bool deneme = true;
                                    while (deneme){

                                        if ((map2[(int)(player2PosY / 32)][(int)((player2PosX - 64) / 32)] == 'W') && (boxes2[k].posX == player2PosX - 32 && boxes2[k].posY == player2PosY))
                                        {
                                            deneme = false;
                                            continue;

                                        }
                                        else if (map2[(int)(player2PosY / 32)][(int)((player2PosX - 32) / 32)] != 'W')
                                        {
                                            
                                            player2PosX -= 32;
                                            PlaySound(jump);
                                            moveCount++;
                                            l = true;
                                        }
                                        deneme = false;
                                    }    

                                }
                                 if (l != 1){
                                            UndoMove(&playerMoveStack, &player2PosX, &player2PosY);
                                            for (int i = 0; i < numBoxes2; i++) {
                                                UndoMove(&boxMoveStacks[i], &boxes2[i].posX, &boxes2[i].posY);
                                            }
                                        }
                            }
                            else if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D))
                            {
                                player2Texture = textures['R'];
                                SaveMove(&playerMoveStack, player2PosX, player2PosY);
                                for (int i = 0; i < numBoxes2; i++) {
                                    SaveMove(&boxMoveStacks[i], boxes2[i].posX, boxes2[i].posY);
                                }

                                bool boxPushed = false , l = false;
                                int k = 0;

                                for (int i = 0; i < numBoxes2; i++)
                                {
                                    if (boxes2[i].posX == player2PosX + 32 && boxes2[i].posY == player2PosY)
                                    {
                                        if (map2[(int)(boxes2[i].posY / 32)][(int)((boxes2[i].posX + 32) / 32)] != 'W')
                                        {
                                            for (int j = 0; j < numBoxes2; j++)
                                            {
                                                if (boxes2[j].posX == player2PosX + 64 && boxes2[j].posY == player2PosY)
                                                {
                                                    boxPushed = true;
                                                    k = j;
                                                    break;
                                                }
                                            }

                                            if (!boxPushed)
                                            {
                                                boxes2[i].posX += 32;
                                                if (map2[(int)(boxes2[i].posY / 32)][(int)(boxes2[i].posX / 32)] == 'T')
                                                {
                                                    boxes2[i].onTarget = true;
                                                }
                                                else
                                                {
                                                    boxes2[i].onTarget = false;
                                                }
                                            }

                                        }
                                        k = i;
                                        break; 
                                    }
                                }

                                if (!boxPushed)
                                {
                                    bool deneme = true;
                                    while (deneme){

                                        if ((map2[(int)(player2PosY / 32)][(int)((player2PosX + 64) / 32)] == 'W') && (boxes2[k].posX == player2PosX + 32 && boxes2[k].posY == player2PosY))
                                        {
                                            deneme = false;
                                            continue;

                                        }
                                        else if (map2[(int)(player2PosY / 32)][(int)((player2PosX + 32) / 32)] != 'W')
                                        {
                                            
                                            player2PosX += 32;
                                            PlaySound(jump);
                                            moveCount++;
                                            l = true;
                                        }
                                        deneme = false;
                                    }
                                }
                                 if (l != 1){
                                            UndoMove(&playerMoveStack, &player2PosX, &player2PosY);
                                            for (int i = 0; i < numBoxes2; i++) {
                                                UndoMove(&boxMoveStacks[i], &boxes2[i].posX, &boxes2[i].posY);
                                            }
                                        }
                            }
                            if(IsKeyPressed(KEY_R) || ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))&& CheckCollisionPointRec(GetMousePosition(),undomove)))
                            {
                                UndoMove(&playerMoveStack, &player2PosX, &player2PosY);
                                for (int i = 0; i < numBoxes2; i++) {
                                    UndoMove(&boxMoveStacks[i], &boxes2[i].posX, &boxes2[i].posY);
                                }
                                if(moveCount>0){
                                    moveCount--;
                                }

                            }

                        
                        
                        
                        for (int y = 0; y < MAP_HEIGHT; y++) {
                            for (int x = 0; x < MAP_WIDTH; x++) {
                                int cell = map2[y][x];
                                if (textures[cell].id != 0) {
                                    DrawTexture(textures[cell], x * CELL_SIZE, y * CELL_SIZE, WHITE);
                                }
                            }
                        }
                        DrawTexture(pausebutton,884,10, WHITE);
                        DrawTexture(undobutton,830,10, WHITE);
                        DrawTexture(restartbutton,938,10, WHITE);
                        DrawText(TextFormat("Time: %02d:%02d", gameTime / 60, gameTime % 60), 10, 10, 20, DARKBLUE);
                        DrawText(TextFormat("Moves: %d", moveCount), 10, 40, 20, DARKBLUE);
                        
                        if (!UpdateWinCondition(boxes2, numBoxes2,map2)) {
                            double currentTime = GetTime();
                            gameTime = (int)(currentTime - startTime);
                            
                        }
                        DrawTexture(player2Texture, player2PosX, player2PosY, WHITE);
                        
                        
                        for (int i = 0; i < numBoxes2; i++) {
                            Box *box = &boxes2[i];
                            if (box->onTarget) {
                                DrawTexture(textures['t'], box->posX, box->posY, WHITE);
                            } else {
                                DrawTexture(textures['B'], box->posX, box->posY, WHITE);
                            }
                        }
                         
                         
                        
                        } 
                        
                    
                } break;
                case LEVELTHREE:
                {   
                     if (!IsSoundPlaying(gameS))
                            {
                                StopSound(menuS);
                                PlaySound(gameS);
                            }
                           
                        if(IsKeyPressed(KEY_T) || ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))&& CheckCollisionPointRec(GetMousePosition(),restartlevel))){
                            
                            ClearMoveStacks();
                            startTime = GetTime();
                            moveCount =0;
                            player3Texture = textures['D']; 
                            player3PosX = 14*32;
                            player3PosY =  6*32;
                            boxes3[0].posX = 32 * 18;
                            boxes3[0].posY = 32 * 6;
                            boxes3[0].onTarget = 0;

                            boxes3[1].posX = 32 * 18;
                            boxes3[1].posY = 32 * 9;
                            boxes3[1].onTarget = 0;

                            boxes3[2].posX = 32 * 19;
                            boxes3[2].posY = 32 * 6;
                            boxes3[2].onTarget = 0;

                            boxes3[3].posX = 32 * 14;
                            boxes3[3].posY = 32 * 7;
                            boxes3[3].onTarget = 0;

                            boxes3[4].posX = 32 * 12;
                            boxes3[4].posY = 32 * 8;
                            boxes3[4].onTarget = 0;

                            boxes3[5].posX = 32 * 15;
                            boxes3[5].posY = 32 * 11;
                            boxes3[5].onTarget = 0;

                            boxes3[6].posX = 32 * 13;
                            boxes3[6].posY = 32 * 11;
                            boxes3[6].onTarget = 0;

                            boxes3[7].posX = 32 * 11;
                            boxes3[7].posY = 32 * 11;
                            boxes3[7].onTarget = 0;

                            boxes3[8].posX = 32 * 11;
                            boxes3[8].posY = 32 * 10;
                            boxes3[8].onTarget = 0;

                            boxes3[9].posX = 32 * 11;
                            boxes3[9].posY = 32 * 13;
                            boxes3[9].onTarget = 0;

                            boxes3[10].posX = 32 * 12;
                            boxes3[10].posY = 32 * 13;
                            boxes3[10].onTarget = 0;

                            
                        }
                      if(IsKeyPressed(KEY_P) || ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))&& CheckCollisionPointRec(GetMousePosition(),pauselevel)))
                    {
                        pausedLevel = LEVELTHREE;
                        startPauseTime = GetTime();
                        currentScreen = PAUSE;
                    }
                        if (UpdateWinCondition(boxes3, numBoxes3, map3 ))
                        {
                          
                           int bestTime = 0, bestMoves = 0;
                            kaydetSkorlar(gameTime, moveCount);
                            checkAndUpdateRecord(&bestTime, &bestMoves, gameTime, moveCount , 3 );
                            
                            WaitTime(1);
                            currentScreen = ENDING;
                           
                             
                             break;
                             
                        }        
                        
                        else  
                        {
                            if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W))
                            {
                                player3Texture = textures['U'];
                                SaveMove(&playerMoveStack, player3PosX, player3PosY);
                                for (int i = 0; i < numBoxes3; i++) {
                                    SaveMove(&boxMoveStacks[i], boxes3[i].posX, boxes3[i].posY);
                                }
                                bool boxPushed = false , l = false;
                                int k=0;
                                
                                for (int i = 0; i < numBoxes3; i++)
                                {
                                    if (boxes3[i].posX == player3PosX && boxes3[i].posY == player3PosY - 32)
                                    {
                                        if (map3[(int)((boxes3[i].posY - 32) / 32)][(int)(boxes3[i].posX / 32)] != 'W')
                                        {
                                            for (int j = 0; j < numBoxes3; j++)
                                            {
                                                if (boxes3[j].posX == player3PosX && boxes3[j].posY == player3PosY - 64)
                                                {
                                                    boxPushed = true;
                                                    k = j;
                                                    break;
                                                }
                                            }

                                            if (!boxPushed)
                                            {
                                                boxes3[i].posY -= 32;
                                                if (map3[(int)(boxes3[i].posY / 32)][(int)(boxes3[i].posX / 32)] == 'T')
                                                {
                                                    boxes3[i].onTarget = true;
                                                }
                                                else
                                                {
                                                    boxes3[i].onTarget = false;
                                                }
                                            }
                                            
                                        }
                                        k = i;
                                        break; 
                                    }
                                }

                                if (!boxPushed)
                                {
                                    bool deneme = true;
                                    while (deneme){
                                        
                                        if((map3[(int)((player3PosY - 64) / 32)][(int)(player3PosX / 32)] == 'W') && (boxes3[k].posX == player3PosX && boxes3[k].posY == player3PosY - 32))
                                        {
                                            deneme = false;
                                            continue;
                                            
                                        } 
                                        else if (map3[(int)((player3PosY - 32) / 32)][(int)(player3PosX / 32)] != 'W')
                                        {
                                            
                                            player3PosY -= 32;
                                            PlaySound(jump);
                                            moveCount++;
                                            l = true;
                                        }
                                        deneme = false;
                                    }
                                }
                                 if (l != 1){
                                            UndoMove(&playerMoveStack, &player3PosX, &player3PosY);
                                            for (int i = 0; i < numBoxes3; i++) {
                                                UndoMove(&boxMoveStacks[i], &boxes3[i].posX, &boxes3[i].posY);
                                            }
                                        }
                            }
                            else if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S))
                            {
                                player3Texture = textures['D'];
                                SaveMove(&playerMoveStack, player3PosX, player3PosY);
                                for (int i = 0; i < numBoxes3; i++) {
                                    SaveMove(&boxMoveStacks[i], boxes3[i].posX, boxes3[i].posY);
                                }

                                bool boxPushed = false , l = false;
                                int k = 0;

                                for (int i = 0; i < numBoxes3; i++)
                                {
                                    if (boxes3[i].posX == player3PosX && boxes3[i].posY == player3PosY + 32)
                                    {
                                        if (map3[(int)((boxes3[i].posY + 32) / 32)][(int)(boxes3[i].posX / 32)] != 'W')
                                        {
                                            for (int j = 0; j < numBoxes3; j++)
                                            {
                                                if (boxes3[j].posX == player3PosX && boxes3[j].posY == player3PosY + 64)
                                                {
                                                    boxPushed = true;
                                                    k = j;
                                                    break;
                                                }
                                            }

                                            if (!boxPushed)
                                            {
                                                boxes3[i].posY += 32;
                                                if (map3[(int)(boxes3[i].posY / 32)][(int)(boxes3[i].posX / 32)] == 'T')
                                                {
                                                    boxes3[i].onTarget = true;
                                                }
                                                else
                                                {
                                                    boxes3[i].onTarget = false;
                                                }
                                            }

                                        }
                                        k = i;
                                        break; 
                                    }
                                }

                                if (!boxPushed)
                                {
                                    bool deneme = true;
                                    while (deneme){
                                        
                                        if ((map3[(int)((player3PosY + 64) / 32)][(int)(player3PosX / 32)] == 'W') && (boxes3[k].posX == player3PosX && boxes3[k].posY == player3PosY + 32))
                                        {
                                            deneme = false;
                                            continue;

                                        }
                                        else if (map3[(int)((player3PosY + 32) / 32)][(int)(player3PosX / 32)] != 'W')
                                        {
                                            
                                            player3PosY += 32;
                                            PlaySound(jump);
                                            moveCount++;
                                            l = true;
                                        }
                                        deneme = false;
                                    }
                                }
                                 if (l != 1){
                                            UndoMove(&playerMoveStack, &player3PosX, &player3PosY);
                                            for (int i = 0; i < numBoxes3; i++) {
                                                UndoMove(&boxMoveStacks[i], &boxes3[i].posX, &boxes3[i].posY);
                                            }
                                        }
                            }
                            else if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A))
                            {
                                player3Texture = textures['L'];
                                SaveMove(&playerMoveStack, player3PosX, player3PosY);
                                for (int i = 0; i < numBoxes3; i++) {
                                    SaveMove(&boxMoveStacks[i], boxes3[i].posX, boxes3[i].posY);
                                }

                                bool boxPushed = false , l = false;
                                int k = 0;

                                for (int i = 0; i < numBoxes3; i++)
                                {
                                    if (boxes3[i].posX == player3PosX - 32 && boxes3[i].posY == player3PosY)
                                    {
                                        if (map3[(int)(boxes3[i].posY / 32)][(int)((boxes3[i].posX - 32) / 32)] != 'W')
                                        {
                                            for (int j = 0; j < numBoxes3; j++)
                                            {
                                                if (boxes3[j].posX == player3PosX - 64 && boxes3[j].posY == player3PosY)
                                                {
                                                    boxPushed = true;
                                                    k = j;
                                                    break;
                                                }
                                            }

                                            if (!boxPushed)
                                            {
                                                boxes3[i].posX -= 32;
                                                if (map3[(int)(boxes3[i].posY / 32)][(int)(boxes3[i].posX / 32)] == 'T')
                                                {
                                                    boxes3[i].onTarget = true;
                                                }
                                                else
                                                {
                                                    boxes3[i].onTarget = false;
                                                }
                                            }

                                        }
                                        k = i;
                                        break; 
                                    }
                                }

                                if (!boxPushed)
                                {
                                    bool deneme = true;
                                    while (deneme){

                                        if ((map3[(int)(player3PosY / 32)][(int)((player3PosX - 64) / 32)] == 'W') && (boxes3[k].posX == player3PosX - 32 && boxes3[k].posY == player3PosY))
                                        {
                                            deneme = false;
                                            continue;

                                        }
                                        else if (map3[(int)(player3PosY / 32)][(int)((player3PosX - 32) / 32)] != 'W')
                                        {
                                            
                                            player3PosX -= 32;
                                            PlaySound(jump);
                                            moveCount++;
                                            l = true;
                                        }
                                        deneme = false;
                                    }    

                                }
                                 if (l != 1){
                                            UndoMove(&playerMoveStack, &player3PosX, &player3PosY);
                                            for (int i = 0; i < numBoxes3; i++) {
                                                UndoMove(&boxMoveStacks[i], &boxes3[i].posX, &boxes3[i].posY);
                                            }
                                        }
                            }
                            else if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D))
                            {
                                player3Texture = textures['R'];
                                SaveMove(&playerMoveStack, player3PosX, player3PosY);
                                for (int i = 0; i < numBoxes3; i++) {
                                    SaveMove(&boxMoveStacks[i], boxes3[i].posX, boxes3[i].posY);
                                }

                                bool boxPushed = false , l = false;
                                int k = 0;

                                for (int i = 0; i < numBoxes3; i++)
                                {
                                    if (boxes3[i].posX == player3PosX + 32 && boxes3[i].posY == player3PosY)
                                    {
                                        if (map3[(int)(boxes3[i].posY / 32)][(int)((boxes3[i].posX + 32) / 32)] != 'W')
                                        {
                                            for (int j = 0; j < numBoxes3; j++)
                                            {
                                                if (boxes3[j].posX == player3PosX + 64 && boxes3[j].posY == player3PosY)
                                                {
                                                    boxPushed = true;
                                                    k = j;
                                                    break;
                                                }
                                            }

                                            if (!boxPushed)
                                            {
                                                boxes3[i].posX += 32;
                                                if (map3[(int)(boxes3[i].posY / 32)][(int)(boxes3[i].posX / 32)] == 'T')
                                                {
                                                    boxes3[i].onTarget = true;
                                                }
                                                else
                                                {
                                                    boxes3[i].onTarget = false;
                                                }
                                            }

                                        }
                                        k = i;
                                        break; 
                                    }
                                }

                                if (!boxPushed)
                                {
                                    bool deneme = true;
                                    while (deneme){

                                        if ((map3[(int)(player3PosY / 32)][(int)((player3PosX + 64) / 32)] == 'W') && (boxes3[k].posX == player3PosX + 32 && boxes3[k].posY == player3PosY))
                                        {
                                            deneme = false;
                                            continue;

                                        }
                                        else if (map3[(int)(player3PosY / 32)][(int)((player3PosX + 32) / 32)] != 'W')
                                        {
                                            
                                            player3PosX += 32;
                                            PlaySound(jump);
                                            moveCount++;
                                            l = true;
                                        }
                                        deneme = false;
                                    }
                                }
                                 if (l != 1){
                                            UndoMove(&playerMoveStack, &player3PosX, &player3PosY);
                                            for (int i = 0; i < numBoxes3; i++) {
                                                UndoMove(&boxMoveStacks[i], &boxes3[i].posX, &boxes3[i].posY);
                                            }
                                        }
                            }
                            if(IsKeyPressed(KEY_R) || ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))&& CheckCollisionPointRec(GetMousePosition(),undomove))){
                                UndoMove(&playerMoveStack, &player3PosX, &player3PosY);
                                for (int i = 0; i < numBoxes3; i++) {
                                    UndoMove(&boxMoveStacks[i], &boxes3[i].posX, &boxes3[i].posY);
                                }
                                if(moveCount>0){
                                    moveCount--;
                                }

                            }

                        
                        
                        
                        for (int y = 0; y < MAP_HEIGHT; y++) {
                            for (int x = 0; x < MAP_WIDTH; x++) {
                                int cell = map3[y][x];
                                if (textures[cell].id != 0) {
                                    DrawTexture(textures[cell], x * CELL_SIZE, y * CELL_SIZE, WHITE);
                                }
                            }
                        }
                        DrawTexture(pausebutton,884,10, WHITE);
                        DrawTexture(undobutton,830,10, WHITE);
                        DrawTexture(restartbutton,938,10, WHITE);
                        DrawText(TextFormat("Time: %02d:%02d", gameTime / 60, gameTime % 60), 10, 10, 20, DARKBLUE);
                        DrawText(TextFormat("Moves: %d", moveCount), 10, 40, 20, DARKBLUE);
                        
                        if (!UpdateWinCondition(boxes3, numBoxes3, map3)) {
                            double currentTime = GetTime();
                            gameTime = (int)(currentTime - startTime);
                          
                        }
                        DrawTexture(player3Texture, player3PosX, player3PosY, WHITE);
                        
                        
                        for (int i = 0; i < numBoxes3; i++) {
                            Box *box = &boxes3[i];
                            if (box->onTarget) {
                                DrawTexture(textures['t'], box->posX, box->posY, WHITE);
                            } else {
                                DrawTexture(textures['B'], box->posX, box->posY, WHITE);
                            }
                        }
                         
                         
                        
                        } 
                      
                } break;
                case LEVELFOUR:
                {   
                     if (!IsSoundPlaying(gameS))
                          {
                              StopSound(menuS);
                              PlaySound(gameS);
                          }
                           
                        if(IsKeyPressed(KEY_T) || ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))&& CheckCollisionPointRec(GetMousePosition(),restartlevel))){
                            
                            ClearMoveStacks();
                            startTime = GetTime();
                            moveCount =0;
                            player4Texture = textures['D']; 
                            player4PosX = 12*32;
                            player4PosY =  8*32;
                            boxes4[0].posX = 32 * 12;
                            boxes4[0].posY = 32 * 9;
                            boxes4[0].onTarget = 0;

                            boxes4[1].posX = 32 * 12;
                            boxes4[1].posY = 32 * 7;
                            boxes4[1].onTarget = 0;

                            boxes4[2].posX = 32 * 13;
                            boxes4[2].posY = 32 * 8;
                            boxes4[2].onTarget = 0;

                            boxes4[3].posX = 32 * 13;
                            boxes4[3].posY = 32 * 10;
                            boxes4[3].onTarget = 0;

                            boxes4[4].posX = 32 * 9;
                            boxes4[4].posY = 32 * 7;
                            boxes4[4].onTarget = 0;

                            boxes4[5].posX = 32 * 10;
                            boxes4[5].posY = 32 * 8;
                            boxes4[5].onTarget = 0;

                            boxes4[6].posX = 32 * 8;
                            boxes4[6].posY = 32 * 10;
                            boxes4[6].onTarget = 0;

                            boxes4[7].posX = 32 * 16;
                            boxes4[7].posY = 32 * 11;
                            boxes4[7].onTarget = 0;

                            boxes4[8].posX = 32 * 18;
                            boxes4[8].posY = 32 * 11;
                            boxes4[8].onTarget = 0;

                            boxes4[9].posX = 32 * 8;
                            boxes4[9].posY = 32 * 12;
                            boxes4[9].onTarget = 0;

                            boxes4[10].posX = 32 * 18;
                            boxes4[10].posY = 32 * 12;
                            boxes4[10].onTarget = 0;

                            boxes4[11].posX = 32 * 9;
                            boxes4[11].posY = 32 * 13;
                            boxes4[11].onTarget = 0;

                            boxes4[12].posX = 32 * 12;
                            boxes4[12].posY = 32 * 13;
                            boxes4[12].onTarget = 0;

                            boxes4[13].posX = 32 * 16;
                            boxes4[13].posY = 32 * 13;
                            boxes4[13].onTarget = 0;

                            boxes4[14].posX = 32 * 19;
                            boxes4[14].posY = 32 * 13;
                            boxes4[14].onTarget = 0;

                            boxes4[15].posX = 32 * 8;
                            boxes4[15].posY = 32 * 14;
                            boxes4[15].onTarget = 0;

                            
                        }
                      if(IsKeyPressed(KEY_P) || ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))&& CheckCollisionPointRec(GetMousePosition(),pauselevel)))
                    {
                        pausedLevel = LEVELFOUR;
                        startPauseTime = GetTime();
                        currentScreen = PAUSE;
                    }
                    
                        if (UpdateWinCondition(boxes4, numBoxes4 , map4))
                        {
                          
                            int bestTime = 0, bestMoves = 0;
                            kaydetSkorlar(gameTime, moveCount);
                            checkAndUpdateRecord(&bestTime, &bestMoves, gameTime, moveCount , 4 );
                            
                            WaitTime(1);
                            currentScreen = ENDING;
                           
                             
                             break;
                        }        
                        
                        else  
                        {
                            if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W))
                            {
                                player4Texture = textures['U'];
                                SaveMove(&playerMoveStack, player4PosX, player4PosY);
                                for (int i = 0; i < numBoxes4; i++) {
                                    SaveMove(&boxMoveStacks[i], boxes4[i].posX, boxes4[i].posY);
                                }
                                bool boxPushed = false , l = false;
                                int k=0;
                                
                                for (int i = 0; i < numBoxes4; i++)
                                {
                                    if (boxes4[i].posX == player4PosX && boxes4[i].posY == player4PosY - 32)
                                    {
                                        if (map4[(int)((boxes4[i].posY - 32) / 32)][(int)(boxes4[i].posX / 32)] != 'W')
                                        {
                                            for (int j = 0; j < numBoxes4; j++)
                                            {
                                                if (boxes4[j].posX == player4PosX && boxes4[j].posY == player4PosY - 64)
                                                {
                                                    boxPushed = true;
                                                    k = j;
                                                    break;
                                                }
                                            }

                                            if (!boxPushed)
                                            {
                                                boxes4[i].posY -= 32;
                                                if (map4[(int)(boxes4[i].posY / 32)][(int)(boxes4[i].posX / 32)] == 'T')
                                                {
                                                    boxes4[i].onTarget = true;
                                                }
                                                else
                                                {
                                                    boxes4[i].onTarget = false;
                                                }
                                            }
                                            
                                        }
                                        k = i;
                                        break; 
                                    }
                                }

                                if (!boxPushed)
                                {
                                    bool deneme = true;
                                    while (deneme){
                                        
                                        if((map4[(int)((player4PosY - 64) / 32)][(int)(player4PosX / 32)] == 'W') && (boxes4[k].posX == player4PosX && boxes4[k].posY == player4PosY - 32))
                                        {
                                            deneme = false;
                                            continue;
                                            
                                        } 
                                        else if (map4[(int)((player4PosY - 32) / 32)][(int)(player4PosX / 32)] != 'W')
                                        {
                                            
                                            player4PosY -= 32;
                                            PlaySound(jump);
                                            moveCount++;
                                            l = true;
                                        }                               

                            
                                        deneme = false;
                                    }
                                }
                                 if (l != 1){
                                            UndoMove(&playerMoveStack, &player4PosX, &player4PosY);
                                            for (int i = 0; i < numBoxes4; i++) {
                                                UndoMove(&boxMoveStacks[i], &boxes4[i].posX, &boxes4[i].posY);
                                            }
                                        } 
                            }
                            else if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S))
                            {
                                player4Texture = textures['D'];
                                SaveMove(&playerMoveStack, player4PosX, player4PosY);
                                for (int i = 0; i < numBoxes4; i++) {
                                    SaveMove(&boxMoveStacks[i], boxes4[i].posX, boxes4[i].posY);
                                }

                                bool boxPushed = false , l = false;
                                int k = 0;

                                for (int i = 0; i < numBoxes4; i++)
                                {
                                    if (boxes4[i].posX == player4PosX && boxes4[i].posY == player4PosY + 32)
                                    {
                                        if (map4[(int)((boxes4[i].posY + 32) / 32)][(int)(boxes4[i].posX / 32)] != 'W')
                                        {
                                            for (int j = 0; j < numBoxes4; j++)
                                            {
                                                if (boxes4[j].posX == player4PosX && boxes4[j].posY == player4PosY + 64)
                                                {
                                                    boxPushed = true;
                                                    k = j;
                                                    break;
                                                }
                                            }

                                            if (!boxPushed)
                                            {
                                                boxes4[i].posY += 32;
                                                if (map4[(int)(boxes4[i].posY / 32)][(int)(boxes4[i].posX / 32)] == 'T')
                                                {
                                                    boxes4[i].onTarget = true;
                                                }
                                                else
                                                {
                                                    boxes4[i].onTarget = false;
                                                }
                                            }

                                        }
                                        k = i;
                                        break; 
                                    }
                                }

                                if (!boxPushed)
                                {
                                    bool deneme = true;
                                    while (deneme){
                                        
                                        if ((map4[(int)((player4PosY + 64) / 32)][(int)(player4PosX / 32)] == 'W') && (boxes4[k].posX == player4PosX && boxes4[k].posY == player4PosY + 32))
                                        {
                                            deneme = false;
                                            continue;

                                        }
                                        else if (map4[(int)((player4PosY + 32) / 32)][(int)(player4PosX / 32)] != 'W')
                                        {
                                            
                                            player4PosY += 32;
                                            PlaySound(jump);
                                            moveCount++;
                                            l = true;
                                        }
                                        deneme = false;
                                    }
                                }
                                 if (l != 1){
                                            UndoMove(&playerMoveStack, &player4PosX, &player4PosY);
                                            for (int i = 0; i < numBoxes4; i++) {
                                                UndoMove(&boxMoveStacks[i], &boxes4[i].posX, &boxes4[i].posY);
                                            }
                                        }
                            }
                            else if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A))
                            {
                                player4Texture = textures['L'];
                                SaveMove(&playerMoveStack, player4PosX, player4PosY);
                                for (int i = 0; i < numBoxes4; i++) {
                                    SaveMove(&boxMoveStacks[i], boxes4[i].posX, boxes4[i].posY);
                                }

                                bool boxPushed = false , l = false;
                                int k = 0;

                                for (int i = 0; i < numBoxes4; i++)
                                {
                                    if (boxes4[i].posX == player4PosX - 32 && boxes4[i].posY == player4PosY)
                                    {
                                        if (map4[(int)(boxes4[i].posY / 32)][(int)((boxes4[i].posX - 32) / 32)] != 'W')
                                        {
                                            for (int j = 0; j < numBoxes4; j++)
                                            {
                                                if (boxes4[j].posX == player4PosX - 64 && boxes4[j].posY == player4PosY)
                                                {
                                                    boxPushed = true;
                                                    k = j;
                                                    break;
                                                }
                                            }

                                            if (!boxPushed)
                                            {
                                                boxes4[i].posX -= 32;
                                                if (map4[(int)(boxes4[i].posY / 32)][(int)(boxes4[i].posX / 32)] == 'T')
                                                {
                                                    boxes4[i].onTarget = true;
                                                }
                                                else
                                                {
                                                    boxes4[i].onTarget = false;
                                                }
                                            }

                                        }
                                        k = i;
                                        break; 
                                    }
                                }

                                if (!boxPushed)
                                {
                                    bool deneme = true;
                                    while (deneme){

                                        if ((map4[(int)(player4PosY / 32)][(int)((player4PosX - 64) / 32)] == 'W') && (boxes4[k].posX == player4PosX - 32 && boxes4[k].posY == player4PosY))
                                        {
                                            deneme = false;
                                            continue;

                                        }
                                        else if (map4[(int)(player4PosY / 32)][(int)((player4PosX - 32) / 32)] != 'W')
                                        {
                                            
                                            player4PosX -= 32;
                                            PlaySound(jump);
                                            moveCount++;
                                            l = true;
                                        }
                                        deneme = false;
                                    }    

                                }
                                 if (l != 1){
                                            UndoMove(&playerMoveStack, &player4PosX, &player4PosY);
                                            for (int i = 0; i < numBoxes4; i++) {
                                                UndoMove(&boxMoveStacks[i], &boxes4[i].posX, &boxes4[i].posY);
                                            }
                                        }
                            }
                            else if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D))
                            {
                                player4Texture = textures['R'];
                                SaveMove(&playerMoveStack, player4PosX, player4PosY);
                                for (int i = 0; i < numBoxes4; i++) {
                                    SaveMove(&boxMoveStacks[i], boxes4[i].posX, boxes4[i].posY);
                                }

                                bool boxPushed = false , l = false;
                                int k = 0;

                                for (int i = 0; i < numBoxes4; i++)
                                {
                                    if (boxes4[i].posX == player4PosX + 32 && boxes4[i].posY == player4PosY)
                                    {
                                        if (map4[(int)(boxes4[i].posY / 32)][(int)((boxes4[i].posX + 32) / 32)] != 'W')
                                        {
                                            for (int j = 0; j < numBoxes4; j++)
                                            {
                                                if (boxes4[j].posX == player4PosX + 64 && boxes4[j].posY == player4PosY)
                                                {
                                                    boxPushed = true;
                                                    k = j;
                                                    break;
                                                }
                                            }

                                            if (!boxPushed)
                                            {
                                                boxes4[i].posX += 32;
                                                if (map4[(int)(boxes4[i].posY / 32)][(int)(boxes4[i].posX / 32)] == 'T')
                                                {
                                                    boxes4[i].onTarget = true;
                                                }
                                                else
                                                {
                                                    boxes4[i].onTarget = false;
                                                }
                                            }

                                        }
                                        k = i;
                                        break; 
                                    }
                                }

                                if (!boxPushed)
                                {
                                    bool deneme = true;
                                    while (deneme){

                                        if ((map4[(int)(player4PosY / 32)][(int)((player4PosX + 64) / 32)] == 'W') && (boxes4[k].posX == player4PosX + 32 && boxes4[k].posY == player4PosY))
                                        {
                                            deneme = false;
                                            continue;

                                        }
                                        else if (map4[(int)(player4PosY / 32)][(int)((player4PosX + 32) / 32)] != 'W')
                                        {
                                            
                                            player4PosX += 32;
                                            PlaySound(jump);
                                            moveCount++;
                                            l = true;
                                        }
                                        deneme = false;
                                    }
                                }
                                 if (l != 1){
                                            UndoMove(&playerMoveStack, &player4PosX, &player4PosY);
                                            for (int i = 0; i < numBoxes4; i++) {
                                                UndoMove(&boxMoveStacks[i], &boxes4[i].posX, &boxes4[i].posY);
                                            }
                                        }
                            }
                            if(IsKeyPressed(KEY_R) || ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))&& CheckCollisionPointRec(GetMousePosition(),undomove))){
                                UndoMove(&playerMoveStack, &player4PosX, &player4PosY);
                                for (int i = 0; i < numBoxes4; i++) {
                                    UndoMove(&boxMoveStacks[i], &boxes4[i].posX, &boxes4[i].posY);
                                }
                                if(moveCount>0){
                                    moveCount--;
                                }

                            }

                        
                        
                        for (int y = 0; y < MAP_HEIGHT; y++) {
                            for (int x = 0; x < MAP_WIDTH; x++) {
                                int cell = map4[y][x];
                                if (textures[cell].id != 0) {
                                    DrawTexture(textures[cell], x * CELL_SIZE, y * CELL_SIZE, WHITE);
                                }
                            }
                        }
                        DrawTexture(pausebutton,884,10, WHITE);
                        DrawTexture(undobutton,830,10, WHITE);
                        DrawTexture(restartbutton,938,10, WHITE);
                        DrawText(TextFormat("Time: %02d:%02d", gameTime / 60, gameTime % 60), 10, 10, 20, DARKBLUE);
                        DrawText(TextFormat("Moves: %d", moveCount), 10, 40, 20, DARKBLUE);
                        
                        if (!UpdateWinCondition(boxes4, numBoxes4 , map4)) {
                            double currentTime = GetTime();
                            gameTime = (int)(currentTime - startTime);
                            
                        }
                        DrawTexture(player4Texture, player4PosX, player4PosY, WHITE);
                        
                        
                        for (int i = 0; i < numBoxes4; i++) {
                            Box *box = &boxes4[i];
                            if (box->onTarget) {
                                DrawTexture(textures['t'], box->posX, box->posY, WHITE);
                            } else {
                                DrawTexture(textures['B'], box->posX, box->posY, WHITE);
                            }
                        }
                         
                         
                        
                        } 
                      
                } break;
                case HOW_TO_PLAY:
                {
               
                 if (!IsSoundPlaying(menuS))
                { 
                    StopSound(gameS);
                    PlaySound(menuS);
                }
                DrawTextureEx(background, (Vector2){ howtoplaybackgroundX + 500, howtoplaybackgroundY }, 0.0f, 0.8f, WHITE);
                DrawTextureEx(background, (Vector2){ howtoplaybackgroundX + background.width * 1.0f, howtoplaybackgroundY }, 0.0f, 0.8f, WHITE);
    
                howtoplaybackgroundX -= BACKGROUND_MOVE_SPEED * GetFrameTime();
    
                if (howtoplaybackgroundX <= -background.width)
                {
                    howtoplaybackgroundX = 0;
                }
                
                DrawText("HOW TO PLAY",100,50,60,DARKBLUE);
                DrawText("Press 'LEFT' or 'A' to move left",130,120,40,BLACK);
                DrawText("Press 'RIGHT' or 'D' to move right",130,170,40,BLACK);
                DrawText("Press 'UP' or 'W' to move up",130,220,40,BLACK);
                DrawText("Press 'DOWN' or 'S' to move down",130,270,40,BLACK);
                DrawText("Press 'R' or use 'UNDO BUTTON' to undo a movement",130,320,30,BLACK);
                DrawText("Press 'P' or use 'PAUSE BUTTON' to pause level",130,370,30,BLACK);
                DrawText("Press 'T' or use 'RESTART BUTTON' to restart level",130,420,30,BLACK);
                DrawText("Press space to return to main menu",100,620,20,DARKBLUE);
             
                   
                                 
            
               }break;
                case PAUSE:
                {
                    if (!IsSoundPlaying(menuS))
                    {
                        StopSound(gameS);                        
                        PlaySound(menuS);
                    }
                    DrawTextureEx(background, (Vector2){ backgroundX + 500, backgroundY }, 0.0f, 0.8f, WHITE);
                    DrawTextureEx(background, (Vector2){ backgroundX + background.width * 1.0f, backgroundY }, 0.0f, 0.8f, WHITE);
        
                    backgroundX -= BACKGROUND_MOVE_SPEED * GetFrameTime();
        
                    if (backgroundX <= -background.width)
                    {
                        backgroundX = 0;
                    }
                    DrawText("PAUSE SCREEN", 100, 200, 100, DARKBLUE);
                    DrawTextureRec(backButton, sourceRec2, (Vector2){ btnBounds2.x, btnBounds2.y }, WHITE);
                    DrawTextureRec(exitbutton, sourceRec3, (Vector2){ btnBounds3.x, btnBounds3.y }, WHITE);
                    
                } break;
                case CREDITS:
                {
                  
                if (!IsSoundPlaying(menuS))
                {
                    StopSound(gameS);
                  PlaySound(menuS);
                }
                  
                DrawTextureEx(background, (Vector2){ creditsbackgroundX + 500, creditsbackgroundY }, 0.0f, 0.8f, WHITE);
                DrawTextureEx(background, (Vector2){ creditsbackgroundX + background.width * 1.0f, creditsbackgroundY }, 0.0f, 0.8f, WHITE);
    
                creditsbackgroundX -= BACKGROUND_MOVE_SPEED * GetFrameTime();
    
                if (creditsbackgroundX <= -background.width)
                {
                    creditsbackgroundX = 0;
                }
                
                DrawText("CREDITS",50,40,50,BLACK);
               
                DrawText("Backgrounds and objects;",50,100,40,BLACK);
                DrawText(" https://youtube.com",150,150,40,BLACK);
                DrawText(" https://www.raylib.com/examples.html ",150,200,40,BLACK);
                DrawText(" My Own Aseprite Pixel Drawings",150,250,40,BLACK);
                DrawText(" https://gleao.itch.io",150,300,40,BLACK);    
                DrawText(" https://www.freepik.com",150,350,40,BLACK);
                
                
                DrawText("Resources;",50,400,40,BLACK);
                DrawText("https://www.raylib.com/examples.html",150,440,40,BLACK);
                DrawText("https://www.chat.openai.com",150,500,40,BLACK);
                
                DrawText("Press space to return to main menu",120,620,20,BLACK);
                    
                    
                } break;
                case MAIN_MENU:
                {
                if (!IsSoundPlaying(menuS))
                {
                    StopSound(gameS);
                  PlaySound(menuS);
                }
               
                DrawTextureEx(background, (Vector2){ backgroundX + 500, backgroundY }, 0.0f, 0.8f, WHITE);
                DrawTextureEx(background, (Vector2){ backgroundX + background.width * 1.0f, backgroundY }, 0.0f, 0.8f, WHITE);
    
                backgroundX -= BACKGROUND_MOVE_SPEED * GetFrameTime();
    
                if (backgroundX <= -background.width)
                {
                    backgroundX = 0;
                }
                
                DrawTextureRec(startbutton, sourceRec, (Vector2){ btnBounds.x, btnBounds.y  }, WHITE);
                DrawTextureRec(howtoplaybutton, sourceRec2, (Vector2){ btnBounds2.x, btnBounds2.y }, WHITE);
                DrawTextureRec(creditsbutton, sourceRec3, (Vector2){ btnBounds3.x, btnBounds3.y }, WHITE);
                DrawTextureRec(exitbutton, sourceRec4, (Vector2){ btnBounds4.x, btnBounds4.y }, WHITE);
                
                DrawText("SOKOBAN GAME", 100, 100, 100, MAROON);
                DrawText("Follow my GitHub for more Game ",15,640,30,BLACK);
                DrawText("github.com/PrintOzgurFurkan ",520,635,30,WHITE);
              
                }break;
                case LOGO: 
                {
                    if (state == 0) {
                        framesCounter++;
                        if (framesCounter == 120) {
                            state = 1;
                            framesCounter = 0; 
                        }
                        
                    } else if (state == 1) {
                        topSideRecWidth += 4;
                        leftSideRecHeight += 4;
                        
                        framesCounter++;
                if (framesCounter % blinkDelay == 0 && topSideRecWidth < 256) {
                    topSideRecWidth += 4;
                    leftSideRecHeight += 4;
                }

                        
                        if (topSideRecWidth == 256) state = 2;
                               
                    } else if (state == 2) {
                        bottomSideRecWidth += 4;
                        rightSideRecHeight += 4;
                        
                        framesCounter++;
                if (framesCounter % blinkDelay == 0 && bottomSideRecWidth < 256) {
                    bottomSideRecWidth += 4;
                    rightSideRecHeight += 4;
                }
                        
                        if (bottomSideRecWidth == 256) state = 3;
                                
                    } else if (state == 3) {
                        framesCounter++;
                        if (framesCounter % 12 == 0) {
                            lettersCount++;
                            
                        }
                        if (lettersCount >= 10) {
                            alpha -= 0.02f;
                            if (alpha <= 0.0f) {
                                alpha = 0.0f;
                                currentScreen = MAIN_MENU;
                            }
                        }
                    }

                   

                    if (state == 0) {
                        if ((framesCounter / blinkDelay) % 2 == 0) {
                    DrawRectangle(logoPositionX, logoPositionY, 16, 16, Fade(BLACK, alpha+10)); 
                }
                    } else if (state == 1) {
                        DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, BLACK);
                        DrawRectangle(logoPositionX, logoPositionY, 16, leftSideRecHeight, BLACK);
                    } else if (state == 2) {
                        DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, BLACK);
                        DrawRectangle(logoPositionX, logoPositionY, 16, leftSideRecHeight, BLACK);
                        DrawRectangle(logoPositionX + 240, logoPositionY, 16, rightSideRecHeight, BLACK);
                        DrawRectangle(logoPositionX, logoPositionY + 240, bottomSideRecWidth, 16, BLACK);
                    } else if (state == 3) {
                        DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, Fade(BLACK, alpha));
                        DrawRectangle(logoPositionX, logoPositionY + 16, 16, leftSideRecHeight - 32, Fade(BLACK, alpha));
                        DrawRectangle(logoPositionX + 240, logoPositionY + 16, 16, rightSideRecHeight - 32, Fade(BLACK, alpha));
                        DrawRectangle(logoPositionX, logoPositionY + 240, bottomSideRecWidth, 16, Fade(BLACK, alpha));
                        DrawRectangle(GetScreenWidth() / 2 - 112, GetScreenHeight() / 2 - 112, 224, 224, Fade(GRAY, alpha));
                        DrawText(TextSubtext("raylib", 0, lettersCount), GetScreenWidth() / 2 - 44, GetScreenHeight() / 2 + 48, 50, Fade(BLACK, alpha));
                    }

                  
                } break;   
                case LEVEL_SCREEN:
                {
                    if (!IsSoundPlaying(menuS))
                    {
                        StopSound(gameS);
                      PlaySound(menuS);
                    }
                DrawTextureEx(background, (Vector2){ backgroundX + 500, backgroundY }, 0.0f, 0.8f, WHITE);
                DrawTextureEx(background, (Vector2){ backgroundX + background.width * 1.0f, backgroundY }, 0.0f, 0.8f, WHITE);
    
                backgroundX -= BACKGROUND_MOVE_SPEED * GetFrameTime();
    
                if (backgroundX <= -background.width)
                {
                    backgroundX = 0;
                }
                
                DrawTextureRec(level1button, sourceRec, (Vector2){ btnBounds5.x, btnBounds5.y  }, WHITE);
                DrawTextureRec(level2button, sourceRec2, (Vector2){ btnBounds6.x, btnBounds6.y }, WHITE);
                DrawTextureRec(level3button, sourceRec3, (Vector2){ btnBounds7.x, btnBounds7.y }, WHITE);
                DrawTextureRec(level4button, sourceRec4, (Vector2){ btnBounds8.x, btnBounds8.y }, WHITE);
                DrawTextureRec(backButton, sourceRec4, (Vector2){ btnBounds9.x, btnBounds9.y }, WHITE);
                
                
              
                }break;
                case ENDING:
                {
                    if (!IsSoundPlaying(menuS))
                    {
                        StopSound(gameS);                        
                        PlaySound(menuS);
                    }
                    DrawTextureEx(background, (Vector2){ backgroundX + 500, backgroundY }, 0.0f, 0.8f, WHITE);
                    DrawTextureEx(background, (Vector2){ backgroundX + background.width * 1.0f, backgroundY }, 0.0f, 0.8f, WHITE);
        
                    backgroundX -= BACKGROUND_MOVE_SPEED * GetFrameTime();
        
                    if (backgroundX <= -background.width)
                    {
                        backgroundX = 0;
                    }
                    DrawText("YOU WON", 270, 200, 100, DARKBLUE);
                    DrawTextureRec(exitbutton, sourceRec3, (Vector2){ btnBounds3.x, btnBounds3.y }, WHITE);
                    skorlariCiz();
                    ClearMoveStacks();
                    
                } break;
            }



        

        EndDrawing();
    
    }
    UnloadSound(gameS);
    UnloadSound(menuS);
    
    CloseAudioDevice();
    
    CloseWindow();
    return 0;
}