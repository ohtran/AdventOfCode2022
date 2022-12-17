#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

int get_priority(char c){
	if(isupper(c)) {
		return c -38;
	}
	return c -96;
}

int main(){
	std::ifstream file("input3");
	std::string line;
	int sum = 0;
	
	/* ----------PART 1 ----------------------
	while(getline(file, line)){
		std::vector<char> common;
		std::string first_half = line.substr(0, line.size()/2),
					second_half = line.substr(line.size()/2, line.size());
	
		for(size_t i = 0; i<first_half.size(); i++){
			for(size_t j = 0; j<second_half.size(); j++){
				if(first_half[i] == second_half[j]){
					common.push_back(first_half[i]);
					break;
				}
			}
		}

		auto it = std::unique(common.begin(), common.end());
		common.resize(distance(common.begin(),it));
		
		for(size_t i =0;i < common.size(); i++){
			sum+= get_priority(common[i]);
		}
	}
	std::cout << sum << "\n";
	*/

	//PART 2
	std::vector<std::string> rucksacks;
	while(getline(file,line)){
		rucksacks.push_back(line);
		if (rucksacks.size() == 3){
			int64_t bitfield = 0;
			std::vector<char> common;
			for(size_t i =0; i <rucksacks[0].size(); i++){
				for(size_t j =0; j <rucksacks[1].size(); j++){
					for(size_t k =0; k <rucksacks[2].size(); k++){
						if(rucksacks[0][i] == rucksacks[1][j]){
							if(rucksacks[0][i] == rucksacks[2][k]){
								/*
								if ((bitfield & get_priority(rucksacks[0][i])) == 0) {
									sum += get_priority(rucksacks[0][i]);
									bitfield |= get_priority(rucksacks[0][i]);
									std::cout << bitfield << "\n";
								}
								*/
								common.push_back(rucksacks[0][i]);
							}
						}
					}
				}
			}
			
			rucksacks.clear();
			auto it = std::unique(common.begin(), common.end());
			common.resize(distance(common.begin(),it));
		
			for(size_t i =0;i < common.size(); i++){
				sum+= get_priority(common[i]);
			}
			
		}
	}
	std::cout << sum << "\n";
}
