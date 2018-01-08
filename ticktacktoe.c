#include <stdio.h>
char a[][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
void print() {
	printf(" --- --- ---\n");
	printf("| %c | %c | %c |\n",a[0][0],a[0][1],a[0][2]);
	printf(" --- --- ---\n");
	printf("| %c | %c | %c |\n",a[1][0],a[1][1],a[1][2]);
	printf(" --- --- ---\n");
	printf("| %c | %c | %c |\n",a[2][0],a[2][1],a[2][2]);
	printf(" --- --- ---\n");
}
int main () {
	int x,y,b=0,z,mod,count,e=1; // x and y are rows and colums of array
	print();
	while(e){
		mod=b%2;
		printf("Input the row and column of the place you want to choose.\n");
		printf("Player %d: ",mod+1);
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
			printf("Player %d won!!",mod+1);
			e=0;
		}
		count=0;
		for (int r=0; r<=2; r++) {
			if ((a[r][0]==z && a[r][1]==z && a[r][2]==z) || (a[0][r]==z && a[1][r]==z && a[2][r]==z)) {
				printf("Player %d won!!",mod+1);
				e=0;
			}
			for (int c=0;c<=2;c++) {
				if (a[r][c]!=' ') {
					count++;
				}
			}
		if(count==9){
			printf("Draw!!");
			e=0;
		}
		b++;
		}
	}
	return 0;
	}
