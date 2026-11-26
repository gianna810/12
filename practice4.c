#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYER 2
#define MAX_NODE 4

typedef struct {
    char name[30];
    int type;
    int credit;
    int energy;
} smmObject_t;

typedef struct {
    char name[30];
    int position;
    int energy;
    int credit;
    int graduated;
} smmPlayer_t;

static smmObject_t boardnode[MAX_NODE] = {
    {"Home", 0, 0, 5},
    {"Programming", 1, 3, -2},
    {"Restaurant", 2, 0, 3},
    {"Mathematics", 1, 3, -2}
};

static smmPlayer_t player[MAX_PLAYER];

void generate_player(int i, const char *name) {
    strcpy(player[i].name, name);
    player[i].position = 0;
    player[i].energy = 10;
    player[i].credit = 0;
    player[i].graduated = 0;
}

void stepForward(int i, int dice) {
    for (int j = 0; j < dice; j++) {
        player[i].position++;

        if (player[i].position >= MAX_NODE) {
            player[i].position = 0;
            player[i].energy += boardnode[0].energy;
        }
    }
}

void actionNode(int i) {
    int pos = player[i].position;

    if (boardnode[pos].type == 1) {
        if (player[i].energy >= -boardnode[pos].energy) {
            player[i].credit += boardnode[pos].credit;
            player[i].energy += boardnode[pos].energy;
        }
    }
    else if (boardnode[pos].type == 2) {
        player[i].energy += boardnode[pos].energy;
    }

    if (player[i].credit >= 12) {
        player[i].graduated = 1;
    }
}

int main(void) {
    srand((unsigned int)time(NULL));

    generate_player(0, "Player1");
    generate_player(1, "Player2");

    int turn = 0;

    printf("===== Sookmyung Marble Game =====\n");

    while (turn < 10) {
        int i = turn % MAX_PLAYER;

        if (player[i].graduated) {
            turn++;
            continue;
        }

        int dice = rand() % 6 + 1;

        stepForward(i, dice);
        actionNode(i);

        printf("\nTurn %d\n", turn + 1);
        printf("Player   : %s\n", player[i].name);
        printf("Dice     : %d\n", dice);
        printf("Position : %s\n",
               boardnode[player[i].position].name);
        printf("Credit   : %d\n", player[i].credit);
        printf("Energy   : %d\n", player[i].energy);
        printf("Graduated: %s\n",
               player[i].graduated ? "Yes" : "No");

        turn++;
    }

    printf("\n===== Game End =====\n");

    return 0;
}