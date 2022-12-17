#include <iostream>
#include <fstream>
#include <string>

#define ROCK_1 		'A'
#define PAPER_1 	'B'
#define SCISSOR_1 	'C'

#define ROCK_2 		'X'
#define PAPER_2 	'Y'
#define SCISSOR_2 	'Z'

#define WIN 		6
#define LOSS 		0
#define TIE 		3

int get_shape_score(char a){
	if (a == ROCK_1 || a == ROCK_2) 
		return 1;
	if (a == PAPER_1 || a == PAPER_2)
		return 2;
	if (a == SCISSOR_1 || a == SCISSOR_2) 
		return 3; 
}

int get_outcome(char pl_1, char pl_2){
	if (pl_2 == ROCK_2 && pl_1 == ROCK_1) 		return TIE;
	if (pl_2 == ROCK_2 && pl_1 == PAPER_1) 		return LOSS;
	if (pl_2 == ROCK_2 && pl_1 == SCISSOR_1)	return WIN;

	if (pl_2 == PAPER_2 && pl_1 == ROCK_1) 		return WIN;
	if (pl_2 == PAPER_2 && pl_1 == PAPER_1) 	return TIE;
	if (pl_2 == PAPER_2 && pl_1 == SCISSOR_1) 	return LOSS;

	if (pl_2 == SCISSOR_2 && pl_1 == ROCK_1) 	return LOSS;
	if (pl_2 == SCISSOR_2 && pl_1 == PAPER_1) 	return WIN;
	if (pl_2 == SCISSOR_2 && pl_1 == SCISSOR_1)	return TIE;
}

char get_shape(char pl_1, char pl_2){
	switch(pl_1){
		case ROCK_1:
			switch(pl_2){
				case 'X':
					return SCISSOR_2;
				case 'Y':
					return ROCK_2;
				case 'Z':
					return PAPER_2;
			}
			break;
		case PAPER_1:
			switch(pl_2){
				case 'X':
					return ROCK_2;
				case 'Y':
					return PAPER_2;
				case 'Z':
					return SCISSOR_2;
			}
			break;
		case SCISSOR_1:
			switch(pl_2){
				case 'X':
					return PAPER_2;
				case 'Y':
					return SCISSOR_2;
				case 'Z':
					return ROCK_2;
			}
			break;
	}
}

int main(){
	std::ifstream file("input2");
	std::string line;
	int total = 0;

	while(getline (file, line)){
		//std::cout << line.at(1) << " " << line.at(3) << "\n";
		char shape = get_shape(line[1], line[3]);
		total += get_shape_score(shape) + get_outcome(line[1], shape);
	}
	std::cout << total << "\n";
}
