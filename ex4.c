/******************
Name:
ID:
Assignment:
*******************/
#include <stdio.h>
#include <string.h>

#define CHEER_FLOORS 5
#define CHESS_MAX_SIZE 20

#define CWORD_MAX_GRID_SIZE 30
#define CWORD_MAX_SLOTS     100
#define CWORD_MAX_WORDS     100
#define CWORD_MAX_WORD_LEN   15


void task1RobotPaths();
void task2HumanPyramid();
void task3ParenthesisValidator();
void task4QueensBattle();
void task5CrosswordGenerator();
int ParenthesesNext(char lastOpen, int isFirst);

int robotpaths1(int row, int col);
float humanPyramid(int level, int column, float inputWeight[CHEER_FLOORS][CHEER_FLOORS]);
void task4QueensBattle();

int queenPlacer(int board[CHESS_MAX_SIZE][CHESS_MAX_SIZE], char kingdoms[CHESS_MAX_SIZE][CHESS_MAX_SIZE],
                char occupied[CHESS_MAX_SIZE], int boardSize, int row);
int squarePossible(int board[CHESS_MAX_SIZE][CHESS_MAX_SIZE], char kingdoms[CHESS_MAX_SIZE][CHESS_MAX_SIZE],
                    char occupied[CHESS_MAX_SIZE], int boardSize, int row, int col);
int colIsClear(int board[CHESS_MAX_SIZE][CHESS_MAX_SIZE], int col);
int kingdomIsClear(char occupied[CHESS_MAX_SIZE], char kingdoms, int index, int boardSize);
int rowPlacer(int board[CHESS_MAX_SIZE][CHESS_MAX_SIZE], char kingdoms[CHESS_MAX_SIZE][CHESS_MAX_SIZE], char occupied[CHESS_MAX_SIZE],
                int boardSize, int row, int col);
void boardPrinter(int board[CHESS_MAX_SIZE][CHESS_MAX_SIZE], int boardSize);


typedef struct{
    int row;
    int col;
    int len;
    int type;   //0 - horizontal, 1 - vertical
} CWORD_SLOT;

int match(CWORD_SLOT slot, char word[], char cwordGridArr[CWORD_MAX_GRID_SIZE][CWORD_MAX_GRID_SIZE]);
void fill(CWORD_SLOT slot, char word[], char cwordGridArr[CWORD_MAX_GRID_SIZE][CWORD_MAX_GRID_SIZE]);
void copyWord(CWORD_SLOT slot, char destWord[], char cwordGridArr[CWORD_MAX_GRID_SIZE][CWORD_MAX_GRID_SIZE]);
void printGrid(int gridSize, char cwordGridArr[CWORD_MAX_GRID_SIZE][CWORD_MAX_GRID_SIZE]);
int findWordForSlot(int slotsCnt, int wordCnt, int currWord, int currSlot, CWORD_SLOT slotArray[CWORD_MAX_SLOTS],
                    char wordArray[CWORD_MAX_WORDS][CWORD_MAX_WORD_LEN+1], char cwordGridArr[CWORD_MAX_GRID_SIZE][CWORD_MAX_GRID_SIZE]);
int crosswordGen(int slotsCnt, int wordCnt, CWORD_SLOT slotArray[CWORD_MAX_SLOTS],
                 char wordArray[CWORD_MAX_WORDS][CWORD_MAX_WORD_LEN+1], char cwordGridArr[CWORD_MAX_GRID_SIZE][CWORD_MAX_GRID_SIZE]);

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

        if (scanf(" %d", &task)){
            switch (task)
            {
            case 6:
                printf("Goodbye!\n");
                break;
            case 1:
                task1RobotPaths(); /*done*/
                break;
            case 2:
                task2HumanPyramid(); /*done*/
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
            scanf(" %*s");
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

float humanPyramid(int level, int column, float inputWeight[CHEER_FLOORS][CHEER_FLOORS]){
    float cheerWeight = inputWeight[level][column];
    float totalAbove, result;
    
    if(column == 0 && column == level){
        totalAbove = 0;
    }
    if(column == 0 && column != level){
        totalAbove = humanPyramid(level - 1, column, inputWeight);
    } 
    if(column != 0 && column == level){
        totalAbove = humanPyramid(level - 1, column - 1, inputWeight);
    } 
    if(column != 0 && column != level){
        totalAbove = humanPyramid(level - 1, column, inputWeight) + humanPyramid(level - 1, column - 1, inputWeight);
    }

    printf("CALLED humanPyramid(%d,%d), cheerWeight = %f, totalAbove = %f\n",level,column, cheerWeight, totalAbove);

    float cheerTotalAbove = totalAbove / 2;
    result = cheerWeight + cheerTotalAbove;
    return result;

}

void task2HumanPyramid(){
    float clWeights[CHEER_FLOORS][CHEER_FLOORS];
    float cheerledersCalc[CHEER_FLOORS][CHEER_FLOORS];
    printf("Please enter the weights of the cheerleaders:\n");
    for(int i = 0 ; i < CHEER_FLOORS ; i++)
    {
        for(int j = 0 ; j <= i ; j++)
        {
            scanf(" %f", &clWeights[i][j]);
            if(clWeights[i][j] < 0){
                printf("Negative weights are not supported.\n");
                return;
            }
        }
    }

    for(int i = 0 ; i <  CHEER_FLOORS; i++){
        for(int j = 0 ; j <= i ; j++)
        {
            cheerledersCalc[i][j] = humanPyramid(i, j, clWeights);
        }
    }

    printf("The total weight on each cheerleader is:\n");
    for (int i = 0 ; i < CHEER_FLOORS ; i++)
    {
        for(int j = 0 ; j <= i ; j++)
        {
            printf("%.2f ", cheerledersCalc[i][j]);
        }
        printf("\n");
    }
}


int IsOpenParentheses(char c)
{
    if(c == '{' || c == '[' || c == '(' || c == '<')
    {
        return 1;
    }
    return 0;
}

int IsCloseParentheses(char c)
{
    if(c == '}' || c == ']' || c == ')' || c == '>')
    {
        return 1;
    }
    return 0;
}

int IsMatching(char open, char close)
{
    if((open == '{' && close == '}') || (open == '[' && close == ']') || (open == '(' && close == ')') || (open == '<' && close == '>'))
    {
        return 1;
    }
    return 0;
}

//Returns 1 if success and 0 if failure.
int ParenthesesNext(char lastOpen, int isFirst)
{
    char c;
    int res = 1;
    if(isFirst){
        scanf(" %c", &c);
    }
    else{
        scanf("%c", &c);
    }    

    //This is an enter - end of input
    if((int)c == 10 || c == '\0')
    {

        if(IsOpenParentheses(lastOpen))
        {
            res = 0;
        }
        return res;
    }
    if(IsOpenParentheses(c))
    {
        res = ParenthesesNext(c, 0);
    }
    if(IsCloseParentheses(c))
    {
        return IsMatching(lastOpen, c);
    }

    return res && ParenthesesNext(lastOpen, 0);
}

int ParethesesValidator(void)
{
    return ParenthesesNext('\0', 1);
}

void task3ParenthesisValidator(){
    printf("Please enter a term for validation:\n");
    if(ParethesesValidator()){
        printf("The parentheses are balanced correctly.\n");
    }
    else
    {
        printf("The parentheses are not balanced correctly.\n");
    }
}

void task4QueensBattle(){
    int boardSize;
    int board[CHESS_MAX_SIZE][CHESS_MAX_SIZE] = {0};
    char kingdoms[CHESS_MAX_SIZE][CHESS_MAX_SIZE];
    char occupied[CHESS_MAX_SIZE];
    char kingdomScanner;
    printf("Please enter the board dimensions:\n");
    scanf(" %d", &boardSize);
    printf("Please enter a %d*%d puzzle board:\n", boardSize, boardSize);
    for(int i = 0; i < boardSize; i++){
        for(int t = 0; t < boardSize; t++){
            scanf(" %c", &kingdomScanner);
            kingdoms[i][t] = kingdomScanner;
        }
    }
    int queenPlacerTrue = queenPlacer(board, kingdoms, occupied, boardSize, 0);
    if(queenPlacerTrue){
        boardPrinter(board, boardSize);
    }
    else{
        printf("This puzzle cannot be solved.\n");
    }
}

int queenPlacer(int board[CHESS_MAX_SIZE][CHESS_MAX_SIZE], char kingdoms[CHESS_MAX_SIZE][CHESS_MAX_SIZE], char occupied[CHESS_MAX_SIZE], int boardSize, int row){
    if(row >= boardSize){
        return 1;
    }

    return rowPlacer(board, kingdoms, occupied, boardSize, row, 0);
}

int CheckColPossible(int board[CHESS_MAX_SIZE][CHESS_MAX_SIZE], int rowStartIndex, int col, int count)
{
    //Cases for "possible"
    if(col < 0 || col >= CHESS_MAX_SIZE || count <= 0)
    {
        return 1;
    }

    int rowToCheck = rowStartIndex + count - 1;
    //A queen exist in this square, return "not possible"
    if(rowToCheck >= 0 && rowToCheck < CHESS_MAX_SIZE && board[rowToCheck][col])
    {
        return 0;
    }
    else
    {
        return CheckColPossible(board, rowStartIndex, col, count - 1);
    }
}

int CheckRowPossible(int board[CHESS_MAX_SIZE][CHESS_MAX_SIZE], int row, int colStartIndex, int count)
{
    //Cases for "possible"
    if(row < 0 || row >= CHESS_MAX_SIZE || count <= 0)
    {
        return 1;
    }

    int colToCheck = colStartIndex + count - 1;
    //A queen exist in this square, return "not possible"
    if(colToCheck >= 0 && colToCheck < CHESS_MAX_SIZE && board[row][colToCheck])
    {
        return 0;
    }
    else
    {
        return CheckColPossible(board, row, colStartIndex, count - 1);
    }
}

int squarePossible(int board[CHESS_MAX_SIZE][CHESS_MAX_SIZE], char kingdoms[CHESS_MAX_SIZE][CHESS_MAX_SIZE], char occupied[CHESS_MAX_SIZE], int boardSize, int row, int col){
    int QueenIsNotTouching;      
    //Check row up and down and column right and left.
    if(CheckColPossible(board, row - 1, col - 1, 3) && 
       CheckColPossible(board, row - 1, col + 1, 3) && 
       CheckRowPossible(board, row - 1, col - 1, 3) && 
       CheckRowPossible(board, row + 1, col - 1, 3) && 
       colIsClear(board, col)) {
        QueenIsNotTouching = 1;
    }
  
    int KingdomClear = kingdomIsClear(occupied, kingdoms[row][col], 0, boardSize);

    return KingdomClear && QueenIsNotTouching;

}

int colIsClear(int board[CHESS_MAX_SIZE][CHESS_MAX_SIZE], int col)
{
    return CheckColPossible(board, 0, col, CHESS_MAX_SIZE);
}


int kingdomIsClear(char occupied[CHESS_MAX_SIZE], char kingdoms, int index, int boardSize){
    if(index > boardSize) {
        return 1;
    }
    else{ 
        if(kingdoms == occupied[index]) {
        return 0;
        }
    }
    return kingdomIsClear(occupied, kingdoms, index + 1, boardSize);
}

int rowPlacer(int board[CHESS_MAX_SIZE][CHESS_MAX_SIZE], char kingdoms[CHESS_MAX_SIZE][CHESS_MAX_SIZE],
              char occupied[CHESS_MAX_SIZE], int boardSize, int row, int col){
    if(col >= boardSize){
        return 0;
    }
    int queenIsPossible = squarePossible(board, kingdoms, occupied, boardSize, row, col);
    if(queenIsPossible){
        board[row][col] = 1;
        occupied[row] = kingdoms[row][col];
        int doesQueenPlacer = queenPlacer(board, kingdoms, occupied, boardSize, row);
        if(doesQueenPlacer){
            return 1;
        }
        board[row][col] = 0;
        occupied[row] = 0;
    }
    return rowPlacer(board, kingdoms, occupied, boardSize, row, col +1);
}

void boardPrinter(int board[CHESS_MAX_SIZE][CHESS_MAX_SIZE], int boardSize){
    printf("Solution:\n");
    for(int i = 0; i < boardSize; i++) {
        for(int t = 0; t < boardSize; t++) {
            int boardPrinting = board[i][t];
            if(boardPrinting){
                printf("X ");
            } 
            else{
                printf("* ");
            }
        }
        printf("\n");
    }
}
void task5CrosswordGenerator(){
       int gridSize, slotsCnt, wordCnt;
    CWORD_SLOT slotArray[CWORD_MAX_SLOTS];
    char wordArray[CWORD_MAX_WORDS][CWORD_MAX_WORD_LEN+1];
    char cwordGridArr[CWORD_MAX_GRID_SIZE][CWORD_MAX_GRID_SIZE];

    for(int i = 0 ; i < CWORD_MAX_GRID_SIZE ; i++){
        for(int j = 0 ; j < CWORD_MAX_GRID_SIZE ; j++){
            cwordGridArr[i][j] = '#';
        }
    }
    // ///////////////////////////////// INPUT ////////////////////////////////////////////////
    printf("Please enter the dimensions of the crossword grid:\n");
    scanf(" %d", &gridSize);

    printf("Please enter the number of slots in the crossword:\n");
    scanf(" %d", &slotsCnt);

    printf("Please enter the details for each slot (Row, Column, Length, Direction):\n");
    for(int i = 0 ; i < slotsCnt ; i++){
        char direction;
        scanf(" %d %d %d %c", &slotArray[i].row, &slotArray[i].col, &slotArray[i].len, &direction);
        slotArray[i].type = (direction == 'H' ? 0 : 1);
    }

    wordCnt = slotsCnt; //For the first print
    do{
        if(wordCnt >= slotsCnt){
            printf("Please enter the number of words in the dictionary:\n");
        }
        else{
            printf("The dictionary must contain at least %d words. Please enter a valid dictionary size:\n", slotsCnt);
        }
        scanf(" %d", &wordCnt);        
    } while(wordCnt < slotsCnt);
    if(wordCnt > CWORD_MAX_WORDS){
        wordCnt = CWORD_MAX_WORDS;
    }
    printf("Please enter the words for the dictionary:\n");
    for(int i = 0 ; i < wordCnt ; i++){
        scanf(" %s", wordArray[i]);
    }

    ///////////////////////////////// PROCESS ////////////////////////////////////////////////

    int res = crosswordGen(slotsCnt, wordCnt, slotArray, wordArray, cwordGridArr);

    ///////////////////////////////// OUTPUT ////////////////////////////////////////////////
 
    if(res == 1){
        // printf("SUCESS!!\n");
        printGrid(gridSize, cwordGridArr);
    }
    else{
        printf("This crossword cannot be solved.\n");
    }
}


//Checks for a match in a horizontal or vertical slot with some word. returns 1 for success, 0 for failure
int match(CWORD_SLOT slot, char word[], char cwordGridArr[CWORD_MAX_GRID_SIZE][CWORD_MAX_GRID_SIZE]){
    //End of word and slot - success!
    if(slot.len == 0 && word[0] == '\0'){
        return 1;
    }
    //We didn't reach the end of slot, but we reached the end of word - failure
    if(word[0] == '\0'){
        return 0;
    }
    //In case that the current letter on the grid is not free, check for match with current word
    if(cwordGridArr[slot.row][slot.col] != '#' && cwordGridArr[slot.row][slot.col] != word[0]){
        return 0;
    }

    slot.row += slot.type == 1 ? 1 : 0;
    slot.col += slot.type == 0 ? 1 : 0;
    slot.len -= 1;
    return match(slot, word + 1, cwordGridArr);
}

//Fills a horizontal or vertical slot with some word
void fill(CWORD_SLOT slot, char word[], char cwordGridArr[CWORD_MAX_GRID_SIZE][CWORD_MAX_GRID_SIZE]){
    if(slot.len == 0){
        return;
    }
    cwordGridArr[slot.row][slot.col] = word[0];
    //Fill Next char
    slot.row += slot.type == 1 ? 1 : 0;
    slot.col += slot.type == 0 ? 1 : 0;
    slot.len -= 1;
    fill(slot, word + 1, cwordGridArr);
}

//Copy some word from the grid to a buffer
void copyWord(CWORD_SLOT slot, char destWord[], char cwordGridArr[CWORD_MAX_GRID_SIZE][CWORD_MAX_GRID_SIZE]){
    if(slot.len == 0){
        return;
    }

    destWord[0] = cwordGridArr[slot.row][slot.col];
    //Get Next char
    slot.row += slot.type == 1 ? 1 : 0;
    slot.col += slot.type == 0 ? 1 : 0;
    slot.len -= 1;
    copyWord(slot, destWord + 1, cwordGridArr);
}

//Prints the grid as wanted
void printGrid(int gridSize, char cwordGridArr[CWORD_MAX_GRID_SIZE][CWORD_MAX_GRID_SIZE]){
    for(int i = 0 ; i < gridSize ; i++){
        printf("|");
        for(int j = 0 ; j < gridSize ; j++){
            printf(" %c |", cwordGridArr[i][j]);
        }
        printf("\n");
    }
}

int findWordForSlot(int slotsCnt, int wordCnt, int currWord, int currSlot, CWORD_SLOT slotArray[CWORD_MAX_SLOTS],
                    char wordArray[CWORD_MAX_WORDS][CWORD_MAX_WORD_LEN+1], char cwordGridArr[CWORD_MAX_GRID_SIZE][CWORD_MAX_GRID_SIZE]){
    //All slots were matched with a word - success!
    if(slotsCnt == currSlot){
        return 1;
    }
    //No more words in the dictionary to find - this is a failure
    if(currWord == wordCnt){
        return 0;
    }
    //Check the current word
    if(match(slotArray[currSlot], wordArray[currWord], cwordGridArr) == 1){
        char orig[CWORD_MAX_WORD_LEN+1] = {0};
        copyWord(slotArray[currSlot], orig, cwordGridArr);
        //Match success - continue to next slot
        fill(slotArray[currSlot], wordArray[currWord], cwordGridArr);
        char wordFirstLetter = wordArray[currWord][0];
        //Mark the current word as taken (for not be used again)
        wordArray[currWord][0] = '\0';
        int res = findWordForSlot(slotsCnt, wordCnt, 0, currSlot + 1, slotArray, wordArray, cwordGridArr);
        //Success in the algorithm
        if(res == 1){
            return 1;
        }
        //No success - return the original word to the grid and return the word to the dictionary
        {
            wordArray[currWord][0] = wordFirstLetter;
            fill(slotArray[currSlot], orig, cwordGridArr);
        }
    }
    //No match - check the next word for this slot
    return findWordForSlot(slotsCnt, wordCnt, currWord + 1, currSlot, slotArray, wordArray, cwordGridArr);
}

int crosswordGen(int slotsCnt, int wordCnt, CWORD_SLOT slotArray[CWORD_MAX_SLOTS],
                 char wordArray[CWORD_MAX_WORDS][CWORD_MAX_WORD_LEN+1], char cwordGridArr[CWORD_MAX_GRID_SIZE][CWORD_MAX_GRID_SIZE]){
    return findWordForSlot(slotsCnt, wordCnt, 0, 0, slotArray, wordArray, cwordGridArr);
}

void crosswordGeneratorExercise(void){
 
}

// int main(void){
//     crosswordGeneratorExercise();
//     return 0;
// }



