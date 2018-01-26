#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <time.h>
/*
 board[25]={
	 -,-,-,-,-,
	 -,X,O,X,-,
	 -,X,-,O,-,
	 -,X,O,X,-,
	 -,-,-,-,-
 }
*/
int board[25];
enum{ZERO,CROSS,BORDER,EMPTY};
const int convert[]={6,7,8,11,12,13,16,17,18};
const char pce[]="OX|-";
const int direction[]={1,4,5,6};
const int corners[]={0,2,6,8};
char name[20];
int a,b;

void Initialize() {
	int i;
	for(i=0;i<25;i++)
		board[i]=BORDER;
	for (i=0;i<9;i++)
		board[convert[i]]=EMPTY;
}

void Print()
{
	printf("\nThe Board:\n\n");
	for(int i=0;i<9;i++){
		if(i!=0 && i%3==0)
			printf("\n\n");
		printf("%4c",pce[board[convert[i]]]);
	}
	printf("\n");
}

int HasEmpty() {
	for(int i=0;i<9;i++){
		if(board[convert[i]]==EMPTY)
			return 1;
	}
	return 0;
}

int numberofdir(int square,int dir,int side){
	int found=0;
	while(board[square]!=BORDER){
		if(board[square]!=side)
			break;
		found++;
		square+=dir;
	}
	return found;
}

int findthree(int square,int side)
{
	int threecount=1;
	for(int i=0;i<4;i++)
	{
		int dir=direction[i];
		threecount+=numberofdir(square+dir,dir,side);
		threecount+=numberofdir(square-dir,-dir,side);
		if (threecount==3)
			break;
		threecount=1;
	}
	return threecount;
}

void MakeMove(const int move, const int side)
{
	board[move]=side;
}


int PlayerMove() {
	char a[4];
	int moveOK=1;
	int move;
	while(moveOK)
	{
		printf("Input the number from 1-9 for the position to input: ");
		fgets(a,3,stdin);
		__fpurge(stdin);//used instead of fflush(stdin)
		if(strlen(a)!=2){
			printf("Invalid strlen().\n");
			continue;
		}
		if(sscanf(a,"%d",&move)!=1){
			printf("Invalid sscanf().\n");
			continue;
		}
		if (move<1 || move>9){
			printf("Invalid Range.\n");
			continue;
		}
		move--; //converting min move from 1 to 0
		if(board[convert[move]]!=EMPTY){
			printf("Place not available.\n");
			continue;
		}
		moveOK=0;
	}
	return convert[move];
}

int NextBest() {
	if (board[convert[4]]==EMPTY)
		return convert[4];
	for(int i=0;i<4;i++)
	{
		if(board[convert[corners[i]]]==EMPTY)
			return convert[corners[i]];
	}
	return -1;
}

int WinningMove(int side)
{
	int move,win=0;
	for(int i=0;i<9;i++)
	{
		if(board[convert[i]]==EMPTY){
			move=convert[i];
			board[move]=side;
			if(findthree(move,side)==3)
				win=1;
			board[move]=EMPTY;
			if(win==1)
				return move;
		}
	}
	return -1;
}

int ComputerMove(int side) {
	int available[9],free=0,Randmove;
	Randmove=WinningMove(side);
	if(Randmove!=-1)
		return Randmove;

	Randmove=WinningMove(side^1);
	if(Randmove!=-1)
		return Randmove;

	Randmove=NextBest();
	if(Randmove!=-1)
		return Randmove;

	for (int i=0;i<9;i++)
	{
		if (board[convert[i]]==EMPTY)
			available[free++]=convert[i];
	}
	Randmove=(rand() % free);
	return(available[Randmove]);
}

void RunGame(){
	int side,LastMove=0;
	if (b)
		side=a^1;
	else
		side=a;
	while(1) {
		if (side==a){
			LastMove=PlayerMove(side);
			MakeMove(LastMove,side);
			side=side^1;
		}
		else {
			LastMove=ComputerMove(side);
			MakeMove(LastMove,side);
			side=side^1;
			system("clear");
			Print();
		}
		if(findthree(LastMove,side^1)==3)
		{
			printf("\nGame Over!!\n");
			if(side!=a)
				printf("%s Wins.\n",name);
			else
				printf("Computer Wins.\n");
			break;
		}

		if(!HasEmpty()){
			printf("\nGame Over!!\nIts a draw.\n");
			break;
		}
	}
	}

void check(int * p)
{
	char a[4];
	int OK=1;
	while(OK)
	{
		fgets(a,3,stdin);
		__fpurge(stdin);//used instead of fflush(stdin)
		if(strlen(a)!=2){
			printf("Invalid strlen().\n");
			continue;
		}
		if(sscanf(a,"%d",p)!=1){
			printf("Invalid sscanf().\n");
			continue;
		}
		if (*p!=0 && *p!=1){
			printf("Invalid Range.\n");
			continue;
		}
		OK=0;
	}
}

int main()
{
	srand(time(NULL));
	Initialize();
	printf("Input your name: ");
	scanf("%[^\n]",name);
	getchar();
	printf("Input 0 for Zero and 1 for Crosses: ");
	check(&a);
	printf("Input 0 to play first and 1 to play second.");
	check(&b);
	Print();
	RunGame();

}
