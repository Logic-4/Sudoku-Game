#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int sudoku[9][9];
void solvesudoku(int,int);
int checkrow(int row,int num)//checking row
{
    int column;
    for(column=0;column<9;column++)
        if(sudoku[row][column]==num)
            return 0 ;
    return 1;
}
int checkcolumn(int column,int num)//checking column
{
    int row;
    for(row=0;row<9;row++)
        if(sudoku[row][column]==num)
            return 0;
    return 1;
}
int checkgrid(int row,int column,int num)//checking grid
{
    row=(row/3)*3 ;
    column=(column/3)*3;
    int r,c;
    for(r=0;r<3;r++)
        for(c=0;c<3;c++)
            if(sudoku[row+r][column+c]==num)
                return 0;
return 1;
}
void navigate(int row,int column)//moves to next, if each cell is filled
{
    if(column<8)
        solvesudoku(row,column+1);
    else
       solvesudoku(row+1,0);
}
void display()//to display on terminal
{
    int row,column;
    printf("\nTHE SOLVED SUDOKU \n\n");
    for(row=0;row<9;row++)
        {
            for(column=0;column<9;column++)
                printf("%d ",sudoku[row][column]);
                printf("\n");
        }
    getch();
}
void solvesudoku(int row,int column)//main solver
{
    if(row>8)//if all are filled
    display();
    if(sudoku[row][column]!=0)
    navigate(row,column);//if the value filled is not zero and with number, we navigate further
    else
    {
        int ctr;//counter to check whether is filled with some number and zero and move forward
        for(ctr=1;ctr<=9;ctr++)
        {
        if((checkrow(row,ctr)==1)&&(checkcolumn(column,ctr)==1)&&(checkgrid(row,column,ctr)==1))//checking
        {
            sudoku[row][column]=ctr;
            navigate(row,column);
        }
        }
        sudoku[row][column]=0;
    }
    
}
void question_part()
{
    printf("\n\n\t\tGAME MODE\n");
    printf("Enter toughness: EASY for easy TOUGH for tough\n");
    char user1[20];
    char str2[]="EASY";
    scanf("%s",user1);
    int value1;
    value1 = strcmp(str2,user1);
    if (value1 == 0)
        {
            printf("\t\nLevel EASY\n\n");
            time_t start = time(NULL);
            printf("1| | |4| | |6| |2\n | |5| | | | |4| \n |8| | | | |1|7| \n |4|3| | |6| | | \n | |1|8| | | | | \n | |6|7| | |8| | \n4| | | | |3|2|5|6\n |7| | |5| |9|8| \n | | |6| | | | | ");
            printf("\n\nYour time starts now! Good luck!!");
            int question[9][9]={{1,3,7,4,8,5,6,9,2},{9,6,5,2,1,7,3,4,8},{8,4,3,5,6,9,1,7,5},{8,4,3,5,9,6,7,2,1},{7,9,1,8,3,2,5,6,4},{5,2,6,7,4,1,8,3,9},{4,1,8,9,7,3,2,5,6},{6,7,2,1,5,4,9,8,3},{3,5,9,6,2,8,4,1,7}};
            int answer[9][9];
            printf("\n\nEnter the solved sudoku (Enter spaces between the numbers):\n");
            for (int i = 0;i<9;i++)
            {
                for (int j=0;j<9;j++)
                {
                    scanf("%d",&answer[i][j]);
                } 
            }
            int count = 0;
            for (int i = 0;i<9;i++)
            {
                for (int j=0;j<9;j++)
                {
                    if (question[i][j] == answer[i][j])
                    {
                        count = 1;
                    }
                    else
                    {
                        count = 2;
                    }
                }
            }
            if (count == 1)
            {
                printf("\n\nYou have solved the puzzle correctly\nGood Job!!\n");
                printf("The answer is\n");
                printf("1 3 7 4 8 5 6 9 2\n9 6 5 2 1 7 3 4 8\n2 8 4 3 6 9 1 7 5\n8 4 3 5 9 6 7 2 1\n7 9 1 8 3 2 5 6 4\n5 2 6 7 4 1 8 3 9\n4 1 8 9 7 3 2 5 6\n6 7 2 1 5 4 9 8 3\n3 5 9 6 2 8 4 1 7");
            }
            else
            {
                printf("\n\nWrong answer!!\n");
                printf("\n\nThe correct answer is\n");
                printf("\n\n1 3 7 4 8 5 6 9 2\n9 6 5 2 1 7 3 4 8\n2 8 4 3 6 9 1 7 5\n8 4 3 5 9 6 7 2 1\n7 9 1 8 3 2 5 6 4\n5 2 6 7 4 1 8 3 9\n4 1 8 9 7 3 2 5 6\n6 7 2 1 5 4 9 8 3\n3 5 9 6 2 8 4 1 7");
            }

            time_t end = time(NULL);

            int time_taken = difftime(end,start);
            int time_minutes = time_taken/60;
            int time_seconds = time_taken%60;

            printf("\n\nTIME ELAPSED : %d minutes %d seconds\n\n",time_minutes,time_seconds);
            printf("Better luck next time!!");
        }
        else
        {
            time_t start = time(NULL);
            printf("\t\nLevel TOUGH\n\n");
            printf(" | | |8| | | | | \n7|8|9| |1| | | |6\n | | | | |6|1| | \n | |7| | | | |5| \n5| |8|7| |9|3| |4\n |4| | | | |2| | \n | |3|2| | | | | \n8| | | |7| |4|3|9\n | | | | |1| | | \n");
            printf("\n\nYour time starts now! Good luck!!");
            int question1[9][9]={{1,6,5,8,4,7,9,2,3},{7,8,9,3,1,2,5,4,6},{4,3,2,5,9,6,1,7,8},{2,9,7,4,6,3,8,5,1},{5,1,8,7,2,9,3,6,4},{3,4,6,1,5,8,2,9,7},{9,7,3,2,8,4,6,1,5},{8,2,1,6,7,5,4,3,9},{6,5,4,9,3,1,7,8,2}};
            int answer1[9][9];
            printf("\n\nEnter the solved sudoku (Enter spaces between the numbers):\n");
            for (int i = 0;i<9;i++)
            {
                for (int j=0;j<9;j++)
                {
                    scanf("%d",&answer1[i][j]);
                }
            }
            int count1 = 0;
            for (int i = 0;i<9;i++)
            {
                for (int j=0;j<9;j++)
                {
                    if (question1[i][j] == answer1[i][j])
                    {
                        count1 = 1;
                    }
                    else
                    {
                        count1 = 2;
                    }
                }
            }
            if (count1==1)
            {
                printf("\n\nYou have solved the puzzle correctly\nGood Job!!\n");
                printf("The answer is\n");
                printf("1 6 5 8 4 7 9 2 3\n7 8 9 3 1 2 5 4 6\n4 3 2 5 9 6 1 7 8\n2 9 7 4 6 3 8 5 1\n5 1 8 7 2 9 3 6 4\n3 4 6 1 5 8 2 9 7\n9 7 3 2 8 4 6 1 5\n8 2 1 6 7 5 4 3 9\n6 5 4 9 3 1 7 8 2");
            }
            else
            {
                printf("\n\nWrong answer!!\n");
                printf("\n\nThe correct answer is\n");
                printf("\n\n1 6 5 8 4 7 9 2 3\n7 8 9 3 1 2 5 4 6\n4 3 2 5 9 6 1 7 8\n2 9 7 4 6 3 8 5 1\n5 1 8 7 2 9 3 6 4\n3 4 6 1 5 8 2 9 7\n9 7 3 2 8 4 6 1 5\n8 2 1 6 7 5 4 3 9\n6 5 4 9 3 1 7 8 2");
            }
            time_t end = time(NULL);

            int time_taken = difftime(end,start);
            int time_minutes = time_taken/60;
            int time_seconds = time_taken%60;

            printf("\n\nTIME ELAPSED : %d minutes %d seconds\n\n",time_minutes,time_seconds);
            printf("Better luck next time!!");
        }
    } 

int main()
{
    printf("\t\t\t    SUDOKU SOLVER AND GAME MODE\n\n");
    printf("Enter SOLVER for the computer to solve the entered SUDUKO or Enter QUESTION to solve yourself!!\n");
    char user[20];
    char str1[]="SOLVER";
    scanf("%s",user);
    int value;
    value = strcmp(str1,user);
    if (value == 0)
    {
        printf("Entered solving\n");
        int row,column;
        printf("Enter the desired sudoku and enter 0 for unknown entries\n");
        for(row=0;row<9;row++)
            for(column=0;column<9;column++)
                scanf("%d",&sudoku[row][column]);
                    solvesudoku(0,0);
    }
    else
    {
        question_part();    
    }
    return 0;
}