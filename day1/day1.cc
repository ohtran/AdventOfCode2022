#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
#include <algorithm>

int main(){
	std::ifstream file("input");
	std::string calories;	
	std::vector<int> elf_calories;
	int sum =0;
	while(getline (file, calories)){
		if (calories.empty()){
			elf_calories.push_back(sum);
			sum = 0;
			continue;
		}
		sum += std::stoi(calories);
	}
	std::cout << "give me the high score: " << *std::max_element(elf_calories.begin(), elf_calories.end()) << std::endl;

	int total = 0;
	for(int i =0; i <3; i++){
		int max =	*std::max_element(elf_calories.begin(), elf_calories.end());  
		auto it = find(elf_calories.begin(), elf_calories.end(), max);
		total += max;
		elf_calories.erase(it);
	}
	std::cout << total << std::endl;
}
