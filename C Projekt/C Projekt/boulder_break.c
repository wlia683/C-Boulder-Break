/* ENGGEN131 C Project 2022 - Boulder Break */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define CAVE_SIZE 10

/***********************************************************/
/***********************************************************/
/******* ADD THE REQUIRED FUNCTIONS BELOW THIS POINT *******/
/***********************************************************/
/***********************************************************/
// Task One: InitialiseStory
void InitialiseStory(char* paragraph)
{
	char p[] = { "It is late September.\nYou are on a skiing trip with friends.\nEvening skis have been a highlight of the trip,\nas most of the crowd have gone home.\nLight snow pelts your forehead,\nas the last bit of sunlight disappears.\nYou decide to take an unfamiliar route\nand lose track of where everyone else is\nand where the cabins were located.\n\nYou call out to see if anyone can hear you.\n\nNo response.\n\nThe snowfall picks up.\nIt becomes increasingly hard to see anything in\nthe distance.\n\nYou call out again to your friends.\nNo reply again.\nYou hear a repetitive thumping sound in the\nbackground. It seems like it's getting closer\nand closer.\n\nYou call out to your friends again...\n\nNothing.\nThe snow falling now is so heavy you cannot see\nvery well. Suddenly, the repetitive noise stops.\n\n'Knock, knock.' says a voice right behind.\nYou turn around slowly and realize you don't\nrecognise the voice...\n\nA person wearing a yeti mask takes a swing at you\nwith an axe!\nS#!T! You turn around and run for your life.\nSurely this is a sick joke by one of your friends?\nYou stumble upon a strange cave,\n which you believe may provide a spot to hide,\ntil the morning, or at least until the blizzard dies\ndown. As you initially inspect the inside of the\ncave, you lose your footing and slip down a slope\ninside the cave.\n\nYou''ve lost your friends. It's freezing cold.\nSomeone in a yeti mask seems to be trying to kill\nyou and you're now stuck in a strange cave.\n\nIt surely can't get worse, or could it?" };
	int i = 0;
	while (p[i] != 0) {
		paragraph[i] = p[i];
		i++;
	}
	paragraph[i] = 0;
}

// Task Two: PrintCave
void PrintCave(int cave[CAVE_SIZE][CAVE_SIZE])
{
	// Inputs: cave = 2D array representing the cave
	// This function converts the information in 2D array representing the cave into its visual representation
	for (int i = 0; i < CAVE_SIZE; i++) {
		for (int j = 0; j < CAVE_SIZE; j++) {
			if ((cave[i][j] == 0) || (cave[i][j] == 'E')) {
				printf(" ");
			}
			else if (cave[i][j] == 1) {
				printf("#");
			}
			else if (cave[i][j] == '*') {
				printf("*");
			}
			else if (cave[i][j] == '+') {
				printf("+");
			}
			else if (cave[i][j] == 'O') {
				printf("O");
			}
			else if (cave[i][j] == 'X') {
				printf("X");
			}
			if (j == (CAVE_SIZE - 1)) {
				printf("\n");
			}
		}
	}

}

// Task Three: InitialiseCave
void InitialiseCave(int cave[CAVE_SIZE][CAVE_SIZE], char* layout)
{
	// Inputs: cave = 2D array representing the cave
	//		   layout = string with the specific information of the cave's layout
	// This function converts the information in the string representing the cave's layout into the 2D array
	int k = 0;
	for (int i = 0; i < CAVE_SIZE; i++) {
		for (int j = 0; j < CAVE_SIZE; j++) {
			if (layout[k] == 'E') {
				cave[i][j] = 'E';
			}
			if (layout[k] == '0') {
				cave[i][j] = 0;
			}
			if (layout[k] == '1') {
				cave[i][j] = 1;
			}
			k++;
		}
	}
}

// As you work on the other tasks, remove the comments below
// Task Four: IsBorderComplete
int IsBorderComplete(int cave[CAVE_SIZE][CAVE_SIZE])
{
	// This function checks along the borders of the map to see if there is anything other than walls or exit panel present.
	// It returns true if nothing is found, false if there is anything.
	int count = 0;
	for (int i = 0; i < CAVE_SIZE; i++) {
		for (int j = 0; j < CAVE_SIZE; j += (CAVE_SIZE - 1)) {
			if ((cave[i][j] != 1) && (cave[i][j] != 'E')) {
				count++;
			}
		}
	}
	for (int k = 0; k < CAVE_SIZE; k++) {
		for (int l = 0; l < CAVE_SIZE; l += (CAVE_SIZE - 1)) {
			if ((cave[l][k] != 1) && (cave[l][k] != 'E')) {
				count++;
			}
		}
	}
	if (count == 0) {
		return 1;
	}
	return 0;
}

// Task Five: IsExitUnique
int IsExitUnique(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int count = 0;
	for (int i = 0; i < CAVE_SIZE; i++) {
		for (int j = 0; j < CAVE_SIZE; j++) {
			if (cave[i][j] == 'E') {
				count++;
			}
		}
	}
	if (count == 1) {
		return 1;
	}
	return 0;
}

// Task Six: IsExitAccessible
int IsExitAccessible(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int count = 0;
	//Check corners
	for (int g = 0; g < CAVE_SIZE; g += (CAVE_SIZE - 1)) {
		for (int h = 0; h < CAVE_SIZE; h += (CAVE_SIZE - 1)) {
			if (cave[g][h] == 'E') {
				return 0;
			}
		}
	}
	//Check along borders if exit is accessible
	for (int i = 0; i < CAVE_SIZE; i += (CAVE_SIZE - 1)) {
		for (int j = 1; j < CAVE_SIZE - 1; j++) {
			if (cave[i][j] == 'E') {
				count++;
			}
		}
	}
	for (int k = 0; k < CAVE_SIZE; k += (CAVE_SIZE - 1)) {
		for (int l = 1; l < CAVE_SIZE - 1; l++) {
			if (cave[l][k] == 'E') {
				count++;
			}
		}
	}
	if (count < 1) {
		return 0;
	}
	return 1;
}

// Task Seven: AddItem
void AddItem(int cave[CAVE_SIZE][CAVE_SIZE], int row, int col, char* element)
{
	int count = 0;
	//Check if row or col entered are obviously out of bounds
	if (row >= CAVE_SIZE - 1 || col >= CAVE_SIZE - 1 || row <= 0 || col <= 0) {
		return;
	}
	//Check if player already added
	if (element[0] == 'p' && element[1] == 'l' && element[2] == 'a' && element[3] == 'y' && element[4] == 'e' && element[5] == 'r') {
		for (int i = 0; i < CAVE_SIZE; i++) {
			for (int j = 0; j < CAVE_SIZE; j++) {
				if (cave[i][j] == 'X') {
					count++;
				}
			}
		}
		// if no player and if valid tile, then add player
		if ((count < 1) && (cave[row][col] == 0)) {
			cave[row][col] = 'X';
		}
	}
	// Adding hole(s)
	if (element[0] == 'h' && element[1] == 'o' && element[2] == 'l' && element[3] == 'e' && cave[row][col] == 0) {
		cave[row][col] = '*';
	}
	if (element[0] == 't' && element[1] == 'r' && element[2] == 'e' && element[3] == 'a' && element[4] == 's' && element[5] == 'u' && element[6] == 'r' && element[7] == 'e' && cave[row][col] == 0) {
		cave[row][col] = '+';
	}
	if (element[0] == 'b' && element[1] == 'o' && element[2] == 'u' && element[3] == 'l' && element[4] == 'd' && element[5] == 'e' && element[6] == 'r' && cave[row][col] == 0) {
		cave[row][col] = 'O';
	}
}

//Task Eight: RotateCave
void RotateCave(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int tempCave[CAVE_SIZE][CAVE_SIZE] = {0};
	int i, j, k, l;
	for (i = 0; i < CAVE_SIZE; i++) {
		for (j = 0; j < CAVE_SIZE; j++) {
			tempCave[j][CAVE_SIZE - 1 - i] = cave[i][j];
		}
	}
	for (k = 0; k < CAVE_SIZE; k++) {
		for (l = 0; l < CAVE_SIZE; l++) {
			cave[k][l] = tempCave[k][l];
		}
	}
}

// Task Nine: MakeMove
// Task Nine Helper Function
void LocatePlayer(int cave[CAVE_SIZE][CAVE_SIZE], int* CurrentPos) {
	for (int i = 0; i < CAVE_SIZE; i++) {
		for (int j = 0; j < CAVE_SIZE; j++) {
			if (cave[i][j] == 'X') {
				CurrentPos[0] = i;
				CurrentPos[1] = j;
			}
		}
	}
	return;
}

int MakeMove(int cave[CAVE_SIZE][CAVE_SIZE], char move)
{
	//Locate player in map
	int CurrentPos[2];
	LocatePlayer(cave, CurrentPos);
	int i = CurrentPos[0];
	int j = CurrentPos[1];
	//Up Direction
	if (move == 'w') {
		//tile is empty
		if (cave[i - 1][j] == 0) {
			cave[i - 1][j] = 'X';
			cave[i][j] = 0;
			return 0;
		}
		//tile contains hole
		else if (cave[i - 1][j] == '*') {
			cave[i][j] = 0;
			return 1;
		}
		// tile contains boulder
		else if (cave[i - 1][j] == 'O') {
			// check tiles in front
			if (cave[i - 2][j] == '*') {
				cave[i - 1][j] = 0;
				cave[i - 2][j] = 0;
				return 0;
			}
			else if (cave[i - 2][j] != 0) {
				return 0;
			}
			for (int n = i - 2; n >= 0; n--) {
				if (cave[n][j] == '*') {
					cave[n][j] = 0;
					cave[i - 1][j] = 0;
					return 0;
				}
				else if (cave[n][j] != 0) {
					cave[n + 1][j] = 'O';
					cave[i - 1][j] = 0;
					return 0;
				}
			}
		}
		// tile contains treasure
		else if (cave[i - 1][j] == '+') {
			cave[i - 1][j] = 'X';
			cave[i][j] = 0;
			return 0;
		}
		//tile is exit
		else if (cave[i - 1][j] == 'E') {
			cave[i - 1][j] = 'X';
			cave[i][j] = 0;
			return 2;
		}
	}

	// Down direction
	int k = CurrentPos[0];
	int l = CurrentPos[1];
	if (move == 's') {
		//tile is empty
		if (cave[k + 1][l] == 0) {
			cave[k + 1][l] = 'X';
			cave[k][l] = 0;
			return 0;
		}
		//tile contains hole
		else if (cave[k + 1][l] == '*') {
			cave[k][l] = 0;
			return 1;
		}
		// tile contains boulder
		else if (cave[k + 1][l] == 'O') {
			// check tiles in front
			if (cave[k + 2][l] == '*') {
				cave[k + 1][l] = 0;
				cave[k + 2][l] = 0;
				return 0;
			}
			else if (cave[k + 2][l] != 0) {
				return 0;
			}
			for (int m = k + 2; m < CAVE_SIZE; m++) {
				if (cave[m][l] == '*') {
					cave[m][l] = 0;
					cave[k + 1][l] = 0;
					return 0;
				}
				else if (cave[m][l] != 0) {
					cave[m - 1][l] = 'O';
					cave[k + 1][l] = 0;
					return 0;
				}
			}
		}
		// tile contains treasure
		else if (cave[k + 1][l] == '+') {
			cave[k + 1][l] = 'X';
			cave[k][l] = 0;
			return 0;
		}
		//tile is exit
		else if (cave[k + 1][l] == 'E') {
			cave[k + 1][l] = 'X';
			cave[k][l] = 0;
			return 2;
		}
	}

	// Left direction
	int o = CurrentPos[0];
	int p = CurrentPos[1];
	if (move == 'a') {
		//tile is empty
		if (cave[o][p - 1] == 0) {
			cave[o][p - 1] = 'X';
			cave[o][p] = 0;
			return 0;
		}
		//tile contains hole
		else if (cave[o][p - 1] == '*') {
			cave[o][p] = 0;
			return 1;
		}
		// tile contains boulder
		else if (cave[o][p - 1] == 'O') {
			// check tiles in front
			if (cave[o][p - 2] == '*') {
				cave[o][p - 1] = 0;
				cave[o][p - 2] = 0;
				return 0;
			}
			else if (cave[o][p - 2] != 0) {
				return 0;
			}
			for (int a = p - 2; a >= 0; a--) {
				if (cave[o][a] == '*') {
					cave[o][a] = 0;
					cave[o][p - 1] = 0;
					return 0;
				}
				else if (cave[o][a] != 0) {
					cave[o][a + 1] = 'O';
					cave[o][p - 1] = 0;
					return 0;
				}
			}
		}
		// tile contains treasure
		else if (cave[o][p - 1] == '+') {
			cave[o][p - 1] = 'X';
			cave[o][p] = 0;
			return 0;
		}
		//tile is exit
		else if (cave[o][p - 1] == 'E') {
			cave[o][p - 1] = 'X';
			cave[o][p] = 0;
			return 2;
		}
	}

	// Right direction
	int x = CurrentPos[0];
	int y = CurrentPos[1];
	if (move == 'd') {
		//tile is empty
		if (cave[x][y + 1] == 0) {
			cave[x][y + 1] = 'X';
			cave[x][y] = 0;
			return 0;
		}
		//tile contains hole
		else if (cave[x][y + 1] == '*') {
			cave[x][y] = 0;
			return 1;
		}
		// tile contains boulder
		else if (cave[x][y + 1] == 'O') {
			// check tiles in front
			if (cave[x][y + 2] == '*') {
				cave[x][y + 1] = 0;
				cave[x][y + 2] = 0;
				return 0;
			}
			else if (cave[x][y + 2] != 0) {
				return 0;
			}
			for (int b = y + 2; b < CAVE_SIZE; b++) {
				if (cave[x][b] == '*') {
					cave[x][b] = 0;
					cave[x][y + 1] = 0;
					return 0;
				}
				else if (cave[x][b] != 0) {
					cave[x][b - 1] = 'O';
					cave[x][y + 1] = 0;
					return 0;
				}
			}
		}
		// tile contains treasure
		else if (cave[x][y + 1] == '+') {
			cave[x][y + 1] = 'X';
			cave[x][y] = 0;
			return 0;
		}
		//tile is exit
		else if (cave[x][y + 1] == 'E') {
			cave[x][y + 1] = 'X';
			cave[x][y] = 0;
			return 2;
		}
	}

	return 0;
}

/***********************************************************/
/***********************************************************/
/********* DO NOT MODIFY ANY CODE BELOW THIS POINT *********/
/***********************************************************/
/***********************************************************/

/* GetMove() returns the entered character. Invalid characters ignored */
char GetMove(void)
{
	char move;
	printf("\nEnter move: ");
	scanf("%c", &move);
	// Ignore any characters that are invalid
	while ((move != 'w') && (move != 'a') && (move != 's') && (move != 'd')) {
		scanf("%c", &move);
	}
	return move;
}

/* The Boulder Break simulation */
int main(void)
{
	char story[2000];
	char layout[200] = "1111111111100000000110000000011000000001100000000E100100000110000000011000000001100000000111111111111";
	int cave[CAVE_SIZE][CAVE_SIZE] = {0};
	InitialiseStory(story);
	int gameOver = 0;
	
	InitialiseCave(cave, layout);
	AddItem(cave, 2, 2, "boulder");
	AddItem(cave, 2, 1, "hole");
	AddItem(cave, 3, 1, "treasure");
	AddItem(cave, 5, 5, "player");
	AddItem(cave, 2, 2, "boulder");
	AddItem(cave, 3, 3, "hole");
	AddItem(cave, 6, 7, "boulder");
	AddItem(cave, 8, 6, "hole");
	AddItem(cave, 4, 4, "treasure");
	AddItem(cave, 5, 3, "boulder");
	AddItem(cave, 9, 7, "hole");
	AddItem(cave, 3, 7, "boulder");
	AddItem(cave, 3, 4, "boulder");
	AddItem(cave, 8, 3, "treasure");
	AddItem(cave, 3, 6, "hole");
	AddItem(cave, 7, 2, "boulder");
	AddItem(cave, 8, 2, "hole");

	PrintCave(cave);

	printf("ENGGEN131 - C Project 2022\n");
	printf("                          ... presents ...\n");
	printf("______   _____  _     _        ______  _______  ______\n");
	printf("|_____] |     | |     | |      |     \\ |______ |_____/\n");
	printf("|_____] |_____| |_____| |_____ |_____/ |______ |    \\_\n");
	printf("______   ______ _______ _______ _     _\n");
	printf("|_____] |_____/ |______ |_____| |____/ \n");
	printf("|_____] |    \\_ |______ |     | |    \\_\n");
	printf("\n");
	printf("%s\n", story);
	printf("\nMove the player (X) using the keys 'w', 'a', 's', 'd'\n");
	printf("Good luck!\n\n\n");

	/* Main game loop */
	PrintCave(cave);
	while (!gameOver) {
		gameOver = MakeMove(cave, GetMove());
		PrintCave(cave);
		if (gameOver == 1) {
			printf("\n\nGAME OVER!! \nYou died!\n\n");
		} else if (gameOver == 2) {
			printf("\n\nCONGRATULATIONS!! \nYou escaped!\n\n");
		}
	}

	return 0;
}