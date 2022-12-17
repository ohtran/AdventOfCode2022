#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void get_num(std::string s, int &first, int &second){
	std::stringstream ss(s);
	std::string f, se;
	getline(ss, f, '-');
	getline(ss, se, '-');
	first = stoi(f);
	second = stoi(se);
}

int main(){
	std::ifstream file("inputs/input4");
	std::string line;
	int contain = 0;
	int overlap = 0;
	while(getline(file,line)){
		std::stringstream ss(line);
		std::string first, second;
		getline(ss, first, ',');
		getline(ss, second, ',');
		
		int first_1 =0, first_2 =0;
		int sec_1 =0, sec_2 = 0;

		get_num(first, first_1, first_2);
		get_num(second , sec_1, sec_2);

		//--------PART 1 -------------
		if(first_1 <= sec_1 && first_2 >= sec_2) {
			contain++;
			overlap++;
			//std::cout << first_1 << "<" << sec_1 <<"\t" << first_2 << ">" << sec_2 << "\n";
		}
		else if(sec_1 <= first_1 && sec_2 >= first_2) {
			contain++;
			//std::cout << first << "," << second <<"\n";
			overlap++;
		}
		//------PART 2 --------------
		else if((sec_1 > first_1 && sec_1 < first_2) || (sec_2 > first_1 && sec_2 < first_2)){
			overlap++;
		}
		else if(sec_1 == first_2 || first_1 == sec_2) {
			overlap++;
		}

	}
	std::cout << contain << "\n";
	std::cout << overlap << "\n";
}
