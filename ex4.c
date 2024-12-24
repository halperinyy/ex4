/******************
Name:
ID:
Assignment:
*******************/
#include <stdio.h>
#include <string.h>

#define CHEER_FLOORS 5

void task1RobotPaths();
void task2HumanPyramid();
void task3ParenthesisValidator();
void task4QueensBattle();
void task5CrosswordGenerator();

int robotpaths1(int row, int col);
int robotpaths2(int row, int col);
float HumanPyramid(int level, int column, float inputWeight[CHEER_FLOORS][CHEER_FLOORS]);


int main()
{
    int task = -1;
    do
    {
        printf("Choose an option:\n"
               "1. Robot Paths\n"
               "2. The Human Pyramid\n"
               "3. Parenthesis Validation\n"
               "4. Queens Battle\n"
               "5. Crossword Generator\n"
               "6. Exit\n");

        if (scanf("%d", &task))
        {
            switch (task)
            {
            case 6:
                printf("Goodbye!\n");
                break;
            case 1:
                task1RobotPaths();
                break;
            case 2:
                task2HumanPyramid();
                break;
            case 3:
                task3ParenthesisValidator();
                break;
            case 4:
                task4QueensBattle();
                break;
            case 5:
                task5CrosswordGenerator();
                break;
            default:
                printf("Please choose a task number from the list.\n");
                break;
            }
        }
        else
        {
            scanf("%*s");
        }

    } while (task != 6);
}

int robotpaths1(int row, int col)
{
    if(row == 0 && col == 0){ 
        return 1;
    }
    else if(row < 0 || col < 0){
         return 0;
    }
    else{
        return robotpaths1(row - 1, col) + robotpaths1(row, col - 1);
    }
}

void task1RobotPaths()
{
    int row, col;
    printf("Please enter the coordinates of the robot (column, row):\n"); //printing and scanning
    scanf(" %d %d", &row, &col);
    int numOfWays = robotpaths1(row, col); //using a function of mine for calculating, and the printing as requested
    printf("The total number of paths the robot can take to reach home is: %d\n", numOfWays);    
}

float HumanPyramid(int level, int column, float inputWeight[CHEER_FLOORS][CHEER_FLOORS])
{
    (void)level;
    (void)column;
    (void)inputWeight;
    return 0;   // TODO
}

void task2HumanPyramid()
{
    float clWeights[CHEER_FLOORS][CHEER_FLOORS];
    float cheerledersCalc[CHEER_FLOORS][CHEER_FLOORS];

    printf("Please enter the weights of the cheerleaders:\n");
    // scanf(" %f"            , &cl[0][0]);
    // scanf(" %f %f"         , &cl[1][0], &cl[1][1]);
    // scanf(" %f %f %f"      , &cl[2][0], &cl[2][1], &cl[2][2]);
    // scanf(" %f %f %f %f"   , &cl[3][0], &cl[3][1], &cl[3][2], &cl[3][3]);
    // scanf(" %f %f %f %f %f", &cl[4][0], &cl[4][1], &cl[4][2], &cl[4][3], &cl[4][4]);
    for(int i = 0;i < 5;i++)
    {
        for(int j = 0 ; j < i ; j++)
        {
            scanf(" %f", &clWeights[i][j]);
        }
    }


    for(int i = 0 ; i < CHEER_FLOORS; i++)
    {
        for(int j = 0 ; j < i ; j++)
        {
            cheerledersCalc[i][j] = HumanPyramid(i, j, clWeights);
        }
    }

    printf("The total weight on each cheerleader is:");
    for (int i = 0 ; i < CHEER_FLOORS ; i++)
    {
        for(int j = 0 ; j <= i ; j++)
        {
            printf("%.2f ", cheerledersCalc[i][j]);
        }
        printf("\n");
    }
}

void task3ParenthesisValidator()
{
    // Todo
}

void task4QueensBattle()
{
    // Todo
}

void task5CrosswordGenerator()
{
    // Todo
}

