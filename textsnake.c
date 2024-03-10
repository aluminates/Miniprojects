
/*
1. The game will begin with any dice value.
2. If a 6 appears, then a chance is awarded to that player.
3. Only the location of current player is shown on the board, the location of other player is mentioned below the board.
4. Snakes - 99 to  1, 65 to 40, 25 to 9.
5. Ladder - 70 to 93, 60 to 83, 13 to 42.
*/

#include<stdio.h>
#include<stdlib.h>

// randomizes dice value
int rd()
{
	int rem;
	A: rem=rand()%7;
	if(rem==0)
		goto A;
	else
		return rem;
}

// changes the position of player on the board
void displaychart(int curp,char player[4])
{
	int i,j,t,c,x=0,sqnum,pos1,pos2;
	
	// condition executed if either player wins
	if(curp==100)
		{
			printf(" CONGRATULATIONS \n\n PLAYER %s wins\n",player);
			scanf("%*s"); // enter character to exit
			exit(0);
		}
	
	// displays board
	for(i=10;i>0;i--)
	{
		t=i-1;
		if((x%2)==0)
		{
			c=0;
			for(j=10;j>=1;j--)
			{
				sqnum=(i*j)+(t*c++);
				
				if(curp==sqnum)
					printf("%s\t",player);
				else
				printf("%d\t",sqnum);
		
			}
			x++;
		}
		else
		{
			c=9;
			for(j=1;j<=10;j++)
			{
				sqnum=(i*j)+(t*c--);
				
				if(curp==sqnum)
					printf("%s\t",player);
				else
					printf("%d\t",sqnum);
			}
		
			
			x++;
		}
		printf("\n\n");
	}
	printf("--------------------------------------------------------------------------\n");
}

// the main function, execution starts from here
void main()
{
	printf("		** TEXT-BASED SNAKES & LADDERS ** \n");
	int i,dice,cur_pos1=0,cur_pos2=0;
	char ch;
	while(1)
	{	
		printf("Snakes:- 25 to 9,\t 65 to 40,\t 99 to  1.\nLadder:- 13 to 42,\t 60 to 83,\t 70 to 93.\n");
		printf("Choose your option and enter a number:\n");
		printf("1. Player 1 plays.\n");
		printf("2. Player 2 plays.\n");
		printf("3. Exit game.\n");
		scanf("%s",&ch);
	
		switch(ch)
		{
			// handling player 1
			case '1':
			dice=rd();
			system("cls");
					printf("\t\t\t\tDice = %d\n\n",dice);
					if(dice==6)
					printf("Dice=6: You have earned the chance to play one more time.\n");
					cur_pos1=dice+cur_pos1;
					if(cur_pos1<101)
					{
						if(cur_pos1==99)
						{
						displaychart(1,"$P1$"); //snake
						}
						if(cur_pos1==65)
						{
						displaychart(40,"$P1$"); //snake
						}
						if(cur_pos1==25)
						{
						displaychart(9,"$P1$"); //snake
						}
						if(cur_pos1==70)
						{
						displaychart(93,"$P1$"); //ladder
						}
						if(cur_pos1==60)
						{
						displaychart(83,"$P1$"); //ladder
						}
						if(cur_pos1==13)
						{
						displaychart(42,"$P1$"); //ladder
						}
						else
						{
							displaychart(cur_pos1,"$P1$");
						}	
					}
					else
					{
						cur_pos1=cur_pos1-dice;
						printf("Player1 range exceeded.\n");
						displaychart(cur_pos1,"$P1$");
					}
					printf("Player 2 position is %d.\n",cur_pos2);
				break;
			
			// handling player 2
			case '2':
			dice=rd();
			system("cls");
					printf("\t\t\t\tDice = %d\n\n",dice);
					cur_pos2=dice+cur_pos2;
					if(cur_pos2<101)
					{
						if(cur_pos2==99)	//snake
						{
						displaychart(1,"$P2$");
						}
						if(cur_pos2==65)	//snake
						{
						displaychart(40,"$P2$");
						}
						if(cur_pos2==25)	//snake
						{
						displaychart(9,"$P2$");
						}
						if(cur_pos2==70)	//ladder
						{
						displaychart(93,"$P2$");
						}
						if(cur_pos2==60)	//ladder
						{
						displaychart(83,"$P2$");
						}
						if(cur_pos2==13) 	//ladder
						{
						displaychart(42,"$P2$");
						}
						else
						{
						displaychart(cur_pos2,"$P2$");
						}
					}		
					else
					{
						cur_pos2=cur_pos2-dice;
						printf("Player 2 range exceeded.\n");
						displaychart(cur_pos2,"$P2$");
					}
					printf("Player 1 position is %d.\n",cur_pos1);
				break;
				
			// terminates the program
			case '3':
				exit(0);
				break;
			
			// default case
			default:
				printf("Incorrect choice. Try again!\n");		
		}
	}
}