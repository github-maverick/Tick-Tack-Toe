#include <stdio.h>
#include <stdlib.h>
char a[][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
void print() {
	system("clear");
	for(int i=0;i<3;i++)
	{
	printf(" --- --- ---\n");
	printf("| %c | %c | %c |\n",a[i][0],a[i][1],a[i][2]);
	}
	printf(" --- --- ---\n");
}
int main () {
	char player[2][10];
	printf("Input name of 1st player: ");
	scanf("%s",player[0]);
	printf("Input name of 2nd player: ");
	scanf("%s",player[1]);
	int x,y,b=0,z,mod,count,e=1; // x and y are rows and colums of array
	print();
	while(e){
		mod=b%2;
		printf("Input the row and column of the place you want to choose.\n");
		printf("Player %s: ",player[mod]);
		scanf("%d %d",&x,&y);
		if (mod)
			z='X';
		else
			z='O';
		if (a[x-1][y-1]!=' ') {
			printf("Sorry the place is already occupied.\n");
			continue;
		}
		else
			a[x-1][y-1]=z;
		print();
		if ((a[0][0]==z && a[1][1]==z && a[2][2]==z) || (a[0][2]==z && a[1][1]==z && a[2][0]==z)){
			printf("Player %s won!!",player[mod]);
			e=0;
		}
		count=0;
		for (int r=0; r<=2; r++) {
			if ((a[r][0]==z && a[r][1]==z && a[r][2]==z) || (a[0][r]==z && a[1][r]==z && a[2][r]==z)) {
				printf("Player %s won!!",player[mod]);
				e=0;
			}
			for (int c=0;c<=2;c++) {
				if (a[r][c]!=' ') {
					count++;
				}
			}
		}
		if(count==9 && e!=0){
			printf("Draw!!");
			e=0;
		}
		b++;
	}
	return 0;
	}
