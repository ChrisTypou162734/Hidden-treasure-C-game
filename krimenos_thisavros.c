#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define ROWS 23
#define COLS 79
#define A 20
#define B 30

void empodia(int array_basic_operation[ROWS][COLS], int *p, int *o){
	int i,num_x,num_y,x=-1,y=-1;
	
	for(i=0; i<B; i++) {           
		
		do{
			num_x = rand() % (ROWS+1);
        	num_y = rand() % (COLS+1);
        }while(x==num_x || y==num_y || num_x>21 || num_y>77 || num_x<1 || num_y<1 || array_basic_operation[num_x][num_y]==1 || array_basic_operation[num_x+1][num_y]==1 || array_basic_operation[num_x][num_y+1]==1 || array_basic_operation[num_x+1][num_y+1]==1 || array_basic_operation[num_x-1][num_y-1]==1 || array_basic_operation[num_x+1][num_y-1]==1 || array_basic_operation[num_x-1][num_y+1]==1 || array_basic_operation[num_x-1][num_y]==1 || array_basic_operation[num_x][num_y-1]==1);
            
        x = num_x;
        y = num_y;
        array_basic_operation[num_x][num_y] = 1;
    }
    
    x=-1,y=-1;
    
	for(i=0; i<A; i++){

		do{
			num_x=rand()%(ROWS+1);
			num_y=rand()%(COLS+1);
		}while(array_basic_operation[num_x][num_y]==1 || x==num_x || y==num_y || num_x>21 || num_y>77 || num_x<1 || num_y<1 || array_basic_operation[num_x][num_y]==2 || array_basic_operation[num_x+1][num_y]==2 || array_basic_operation[num_x][num_y+1]==2 || array_basic_operation[num_x+1][num_y+1]==2 || array_basic_operation[num_x-1][num_y-1]==2 || array_basic_operation[num_x+1][num_y-1]==2 || array_basic_operation[num_x-1][num_y+1]==2 || array_basic_operation[num_x-1][num_y]==2 || array_basic_operation[num_x][num_y-1]==2);
		
		x=num_x;
		y=num_y;
		
		array_basic_operation[num_x][num_y]=2;
	}	
	
	do{
		num_x=rand()%(ROWS+1);
		num_y=rand()%(COLS+1);
	}while(array_basic_operation[num_x][num_y]==2 || array_basic_operation[num_x][num_y]==1 || num_x>22 || num_y>77 || num_x<1 || num_y<1);
	
	*p=num_x;
	*o=num_y;
	array_basic_operation[num_x][num_y]='O';	
}

void initializeBoard(int array_basic_operation[ROWS][COLS], int *z, int *c) {
	int i,j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            array_basic_operation[i][j]=0;
            if(j==78 || j==0 || i==0 || i==22){
            	array_basic_operation[i][j]=1;
			}
        }
    }
    
    empodia(array_basic_operation,z,c);
}

void printBoard(int array_basic_operation[ROWS][COLS]) {
	system("cls");
	int i,j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
        	if(array_basic_operation[i][j]=='O'){
        		printf("O");
			}else if(array_basic_operation[i][j]==0 || array_basic_operation[i][j]==2){
				printf(" ");
			}else if(array_basic_operation[i][j]==3){
				printf("#");
			}else{
				printf("X");
			}
        }
        printf("\n");
    }
}

int main() {
	int array_basic_operation[ROWS][COLS];
	int find=0,oliko=A;
	srand(time(0));
    int x,w;
    int y,z;
    char input;

    initializeBoard(array_basic_operation,&x,&y);
	w=x;
	z=y;
		
    printBoard(array_basic_operation);
    printf("you find %d tropeo you have akoma %d\n",find,oliko-find);

    while(1){
        input = getch();
        
        switch (input) {
            case 72:
                if (x > 0) x--;
                break;
            case 80:
                if (x < ROWS - 1) x++;
                break;
            case 75:
                if (y > 0) y--;
                break;
            case 77:
                if (y < COLS - 1) y++;
                break;
            case 27:
            	printf("try again\n");
            	printf("for close this window press enter\n");
                return 0;
        }
		
		if(array_basic_operation[x][y]==0){
			array_basic_operation[x][y]='O';
			if(array_basic_operation[w][z]==3){
				array_basic_operation[w][z]=3;
			}else{
				array_basic_operation[w][z]=0;
			}
        	printBoard(array_basic_operation);
        	printf("congruts you find %d tropeo you have akoma %d\n",find,oliko-find);
        	w=x;
        	z=y;
    	}else if(array_basic_operation[x][y]==2){
    		array_basic_operation[x][y]=3;
    		if(array_basic_operation[w][z]==3){
				array_basic_operation[w][z]=3;
			}else{
				array_basic_operation[w][z]=0;
			}
        	printBoard(array_basic_operation);
        	w=x;
        	z=y;
        	printf("congruts you find %d tropeo you have akoma %d\n",find,oliko-find);
        	find++;
		}else if (array_basic_operation[x][y]==1){
			printBoard(array_basic_operation);
			printf("congruts you find %d tropeo you have akoma %d\n",find,oliko-find);
    		printf("you find one empodio");
    		x=w;
    		y=z;
		}else if(array_basic_operation[x][y]==3){
			array_basic_operation[x][y]=3;
			if(array_basic_operation[w][z]==79){
				array_basic_operation[w][z]=0;
			}
			printBoard(array_basic_operation);
			printf("congruts you find %d tropeo you have akoma %d\n",find,oliko-find);
			w=x;
			z=y;
		}
		
		if(find==oliko){
        	printf("you find all tropea congruts\n");
        	printf("for close this window press enter\n");
        	return 0;
		}
    }

    return 0;
}
