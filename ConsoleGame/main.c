#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <time.h>

int current_position=32;
int obsticle_x=22;
int obsticle_y=80;
int obsticle_value=2;
int prime_or_not = 0;
int score = 0;
const int primes[] = {2,3,5,7};
const int not_primes[] = {0,1,4,6,8,9};

void game_menu(){
	printf("  ,ad8888ba,              88 88                                  \n");    
    printf(" d8''    `'8b             88 88                         ,d       \n");
	printf("d8'                       88 88                         88       \n");
	printf("88             ,adPPYba,  88 88  ,adPPYba,  ,adPPYba, MM88MMM    \n");
	printf("88            a8'     ''a 88 88 a8P_____88 a8'     ''   88       \n");
	printf("Y8,           8b       d8 88 88 8PP''''''' 8b           88       \n");
	printf(" Y8a.    .a8P '8a,   ,a8' 88 88 '8b,   ,aa '8a,   ,aa   88,      \n");
	printf("  `'Y8888Y''   `'YbbdP''  88 88  `''Ybbd8''  `'Ybbd8''  ''Y888   \n");
	printf("                                                                 \n\n");
	printf(" 88888888ba              88                                         \n");
	printf(" 88      'b              ''                                         \n");
	printf(" 88      ,8P                                                        \n");
	printf(" 88aaaaaa8P' 8b,dPPYba,  88  88,dPYba,,adPYba,   ,adPPYba, ,adPPYba,\n");
	printf(" 88'''''''   88P'   'Y8  88  88P'   '88'    '8a a8P_____88 I8[    ''\n");
	printf(" 88          88          88  88      88      88 8PP'''''''  `'Y8ba, \n");
	printf(" 88          88          88  88      88      88 '8b,   ,aa aa    ]8I\n");
	printf(" 88          88          88  88      88      88  `'Ybbd8''' `'YbbdP''\n\n\n");
	
	printf("       \"A\" - Left     \"D\" - Right    \"Space\" - Pause\\Resume \n");
	printf("        Press 'Space' to Start                                    \n");
  
    char menu_c;
    while(1){
    	menu_c = getch();
    	if(menu_c == ' '){
    		break;
		}
    	printf("\r");
	}
	
	start_game();
}

void delay(int tens_of_mil_secods){
    int milli_seconds = 10 * tens_of_mil_secods;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}
 
void print_position(void){
	printf("\n                                Score: %d \n\n", score);
	int counter = 0;
	
	while(counter != 71){
		if(counter == current_position){
			printf("O");
		}else{
			printf(" ");
		}
		++counter;
	}
	
	int j=0;
	while(j != 20){
		if(j == obsticle_y/5 +1){
			int a=0;
			while(a != 70){
	          if(a == obsticle_x){
		     	printf("%d",obsticle_value);
	    	}else{
		    	printf(" ");
	     	} 
		++a;
	}
		}else{
			printf("\n");
		}
        ++j;
	}
	
	--obsticle_y;
	if(obsticle_y==0){
		obsticle_y=60;
		obsticle_x = rand() % 65;
		prime_or_not = rand() % 2;
		if(prime_or_not == 0){
			obsticle_value = primes[rand() % 3];
		}else{
			obsticle_value = not_primes[rand() % 5];
		}
	}else if(obsticle_y == 1 && obsticle_x == current_position){//player catches a number
		if(prime_or_not == 0){ // increase score if prime, decrease score if not
			score+=obsticle_value;
		}else{
			score-=obsticle_value;
		}
	}
}

void start_game(void){
	char ch;
	print_position();
	while(1){
		if(kbhit()){
			ch=getch();
			if(ch == 97 || ch == 75){
				--current_position;
			}else if(ch == 100 || ch == 77){
				++current_position;
			}else if(ch == ' '){//if pressed pause
				while(1){
					ch=getch();
					if(ch == ' '){
						break;// resume game
					}
				}
			}else if(ch == 'z' || ch ==  '\033'){
				break;
			}
		}
		
		if(current_position == 1){
			current_position = 69;
		}else if(current_position ==70){
			current_position = 1;
		}
		// new frame
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

		print_position();
		delay(11);
	}
}


int main(int argc, char *argv[]) {
	game_menu();
	return 0;
}
