#include <stdio.h>
#include <string.h>

#define MAX_NODE 20
#define MAX_CHARNAME 30

typedef struct {
    char name[MAX_CHARNAME];
    int type;
    int credit;
    int energy;
} smmObject_t;

static smmObject_t boardnode[MAX_NODE];
static int smmObj_noNode = 0;

void smmObj_genNode(const char *name, int type,
                    int credit, int energy) {
    int i = smmObj_noNode;

    strcpy(boardnode[i].name, name);
    boardnode[i].type = type;
    boardnode[i].credit = credit;
    boardnode[i].energy = energy;

    smmObj_noNode++;
}

const char *smmObj_getTypeName(int type) {
    switch (type) {
        case 0: return "Home";
        case 1: return "Lecture";
        case 2: return "Restaurant";
        default: return "Unknown";
    }
}

int smmObj_getNodeType(int i) {
    return boardnode[i].type;
}

int smmObj_getNodeCredit(int i) {
    return boardnode[i].credit;
}

int smmObj_getNodeEnergy(int i) {
    return boardnode[i].energy;
}

int main(void) {
    smmObj_genNode("Home", 0, 0, 5);
    smmObj_genNode("Programming", 1, 3, -2);
    smmObj_genNode("Restaurant", 2, 0, 3);
    smmObj_genNode("Mathematics", 1, 3, -2);

    printf("===== Sookmyung Marble Board =====\n");

    for (int i = 0; i < smmObj_noNode; i++) {
        printf("\nNode %d\n", i);
        printf("Name   : %s\n", boardnode[i].name);
        printf("Type   : %s\n",
            smmObj_getTypeName(smmObj_getNodeType(i)));
        printf("Credit : %d\n", smmObj_getNodeCredit(i));
        printf("Energy : %d\n", smmObj_getNodeEnergy(i));
    }

    return 0;
}