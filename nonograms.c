#include <stdio.h>
#include <stdlib.h>


#define SIZE 5
//starting point - solving 5x5s - at most 3
//characters for crosses and yes



struct Nonogram{
    int size;

};

struct queueNode {
    int data; // define data as a char
    struct queueNode *nextPtr; // queueNode pointer
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

int dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, int value);
void searchNode(int nodeVal, int dim);
int isEmpty(QueueNodePtr headPtr);



int main(int argc, char *argv[]){

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (file == 0) {
    printf("I can’t open the file for reading.\n");
    return -1;
    }
    int c;
    int count = 0;
    int rowcount = 0;
    char string[SIZE*2][SIZE];
    for (int i=0;i<SIZE*2;i++){
        for (int j=0;j<SIZE;j++){
            char b = '0';
            string[i][j] = b;
        }
    }
    while ((c = fgetc(file)) != EOF) {
        char a = c;
        if(c != 'n'){
            string[count][rowcount] = a;
            rowcount++;
        }else{
            rowcount = 0;
            count++;
        }
    }

    //make grid
    char *grid[SIZE][SIZE];
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            grid[i][j] = "0";
            printf("%s",grid[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    int gap = 0;
    int val = 0;
    int gridwalk = 0;
    //first iteration rows
    for (int j=0; j < SIZE*2; j++)
    {
        gap = SIZE+1;
        for(int k=0; k < SIZE; k++){
            val = *(*(string+j)+k) - '0';
            if (val > 0){
            gap -= (val+1);
            }
        }
        printf("%d\n\n",gap);
        gridwalk = gap;
        for(int k=0; k < SIZE; k++){
            val = *(*(string+j)+k) - '0'-gap;
            printf("%d\n",val);
            for(int v=0;v<val;v++){
                if(j<SIZE){
                    grid[j][gridwalk] = "1";
                }else{
                    grid[gridwalk][j-SIZE] = "1";
                }
                gridwalk++;
            }
            gridwalk+=(gap+1);
        }
    }
    
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            printf("%s",grid[i][j]);
        }
        printf("\n");
    }


    return 0;
}