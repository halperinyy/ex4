/******************
Name:
ID:
Assignment:
*******************/
#include <stdio.h>
#include <string.h>

void task1RobotPaths();
void task2HumanPyramid();
void task3ParenthesisValidator();
void task4QueensBattle();
void task5CrosswordGenerator();

int robotpaths1(int row, int col);
int robotpaths2(int row, int col);
int HumanPyramid(float cheer1, float cheer2, float cheer3, float cheer4, float cheer5, float cheer6, float cheer7, float cheer8, float cheer9, float cheer10, float cheer11, float cheer12, float cheer13, float cheer14, float cheer15 );







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
                printf("Please enter the weights of the cheerleaders:\n");

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

void task2HumanPyramid()
{
    printf("Please enter the weights of the cheerleaders:\n");
    for(int i = 0;i < 5;i++){

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

