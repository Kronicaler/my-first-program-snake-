#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }

void delay(float number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds) 
        ; 
} 

int main(){
	char input=' ',polje[50][50]={' '};
	int x=10,y=10,i,j,duzina=5,a,bodovi=0;
	int zadnji_dio[50][50]={0};
	//postavlja zidove
	for(i=0;i<50;i++){
		polje[0][i]='X';
		polje[49][i]='X';
		polje[i][0]='X';
		polje[i][49]='X';
	}
	printf("sto vise imas bliskih sudara to ces vise imati bodova");
	polje[x][y]='#';//igrac
	for(;;){//crta igru
		gotoxy(0,1);
		for(i=0;i<50;i++){
			for(j=0;j<50;j++){
				printf("%c",polje[i][j]);
				//provjera repa igraca
				if(polje[i][j]=='#'){
					zadnji_dio[i][j]++;
					if(zadnji_dio[i][j]>duzina){
						polje[i][j]=' ';
						zadnji_dio[i][j]=0;
					}
				}
			}
			printf("\n");
		}
		if(input==' '){
			x++;
			if(polje[y-1][x]=='X'||polje[y-1][x]=='#'){
				bodovi++;
			}
			polje[y][x]='#';
		}
		if(kbhit()){
            input = getch();
        }
        zadnji_dio[y][x]++;
        if(zadnji_dio[y][x]>5){
        	polje[y][x]=' ';
		}
		if(input=='w'){
			//polje[y][x]=' ';
			y--;
			if(polje[y][x]=='X'||polje[y][x]=='#'){
				gotoxy(0,51);
				printf("GAME OVER! imao si %d boda",bodovi);
				delay(2);
				return 0;
			}
			if(polje[y-1][x]=='X'||polje[y-1][x]=='#'){
				bodovi++;
			}
			polje[y][x]='#';
			//input=' ';
		}
		if(input=='s'){
			//polje[y][x]=' ';
			
			y++;
			if(polje[y][x]=='X'||polje[y][x]=='#'){
				gotoxy(0,51);
				printf("GAME OVER! imao si %d boda",bodovi);
				delay(2);
				return 0;
			}
			if(polje[y+1][x]=='X'||polje[y+1][x]=='#'){
				bodovi++;
			}
			polje[y][x]='#';
			//input=' ';
		}
		if(input=='a'){
			//polje[y][x]=' ';
			x--;
			if(polje[y][x]=='X'||polje[y][x]=='#'){
				gotoxy(0,51);
				printf("GAME OVER! imao si %d boda",bodovi);
				delay(2);
				return 0;
			}
			if(polje[y][x-1]=='X'||polje[y][x-1]=='#'){
				bodovi++;
			}
			polje[y][x]='#';
			//input=' ';
		}
		if(input=='d'){
			//polje[y][x]=' ';
			x++;
			if(polje[y][x]=='X'||polje[y][x]=='#'){
				gotoxy(0,51);
				printf("GAME OVER! imao si %d boda",bodovi);
				delay(2);
				return 0;
			}
			if(polje[y][x+1]=='X'||polje[y][x+1]=='#'){
				bodovi++;
			}
			polje[y][x]='#';
			//input=' ';
		}
		
		a++;
		if(a>5){
			a=0;
			duzina++;
		}
	}
}
