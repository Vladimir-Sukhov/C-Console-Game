#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <time.h>

struct game_state {
	int current_position;
	int current_position_y;
	int obsticle_x;
	int obsticle_y;
	int prime_or_not;
	int score ;
	const int primes[4];
	const int not_primes[6];
	int obsticle_value;
	int move_counter;
};


void delay(int tens_of_mil_secods){
    int milli_seconds = 10 * tens_of_mil_secods;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

void new_obsticle(struct game_state *game1){
	    game1->obsticle_y=18;
		game1->obsticle_x = rand() % 65;
		game1->prime_or_not = rand() % 2;
		int arr_ind;
		if(game1->prime_or_not == 0){
			arr_ind = rand() % 3;
			game1->obsticle_value = game1->primes[arr_ind];
		}else{
			arr_ind =  rand() % 5;
			game1->obsticle_value = game1->not_primes[arr_ind];
		}
}

void print_position(struct game_state *game1){
	printf("\n Collect Primes  \'w\'-up   \'s\'-down  \'a\'-left  \'d\'-right           SCORE: %d \n\n",game1->score);
	int counter = 0;
	
	int j=0;
	while(j != 20){
		
		if((j == game1->obsticle_y) && (j == game1->current_position_y)){
	      int a=0;
			while(a != 65){
	          if(a == game1->current_position){
	          	printf("O");
			  }else if(a == game1->obsticle_x){
		     	printf("%d",game1->obsticle_value);
	    	  }else{
		    	printf(" ");
			  }
		    ++a;
		    }
		}else if((j == game1->obsticle_y)){
			int a=0;
			while(a != 65){
	          if(a == game1->obsticle_x){
		     	printf("%d",game1->obsticle_value);
		     	break;
	    	  }else{
		    	printf(" ");
			  }
		    ++a;
		    }
		}else if(j == game1->current_position_y){
			while(counter != 71){
				if(counter == (game1->current_position)){
					printf("O");
					break;
				}else{
					printf(" ");
				}
				++counter;
			}	
		}
			printf("\n");
	

        ++j;
	}
	
	--game1->move_counter;
	if(game1->move_counter == 0){
      --(game1->obsticle_y);
      game1->move_counter=5;
}
	
	if(game1->obsticle_y==0){
       new_obsticle(game1);
	}else if(game1->obsticle_y == game1->current_position_y && game1->obsticle_x == game1->current_position){//player catches a number
		if(game1->prime_or_not == 0){ // increase score if prime, decrease score if not
			game1->score+= 2 * game1->obsticle_value;
		}else{
			game1->score-=game1->obsticle_value;
		}
		new_obsticle(game1);
	}
}

void start_game(struct game_state *game1){
	char ch;
	print_position(game1);
	while(1){
		if(kbhit()){
			ch=getch();
			if(ch == 97 || ch == 75){
				--(game1->current_position);
			}else if(ch == 100 || ch == 77){
				++(game1->current_position);
			}else if(ch == 119){
				--(game1->current_position_y);
			}else if(ch == 115){
				++(game1->current_position_y);
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
		
		if((game1->current_position) == 1){
			game1->current_position = 69;
		}else if((game1->current_position) ==70){
			game1->current_position = 1;
		}else if((game1->current_position_y) > 18){
			game1->current_position_y = 18;
		}else if((game1->current_position_y) < 0 ){
			game1->current_position_y = 0;
		}
		// new frame
		//printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        system("cls");
		print_position(game1);
		delay(11);
	}
}

void game_menu(struct game_state *game1){
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
	
	printf("     \"w\"-up   \"s\"-down  \"a\"-left  \"d\"-right    \"Space\" - Pause\\Resume \n");
	printf("        Press 'Space' to Start                                    \n");
  
    char menu_c;
    while(1){
    	menu_c = getch();
    	if(menu_c == ' '){
    		break;
		}
    	printf("\r");
	}
	
	start_game(game1);
}

int main(int argc, char *argv[]) {
	struct game_state game1 = {
	32,0,22,13,0,0,{2,3,5,7},{0,1,4,6,8,9},3,5};
	game_menu(&game1);
	return 0;
}
