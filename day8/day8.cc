#include <iostream>
#include <fstream>
#include <vector>

int visible_tree(std::vector<vector<int>> v){
	int total = 0;
	for(size_t i = 0; i < v.size(); i++){
		for(size_t j =0; j < v[i].size(); j++){
			int tree
		}
	}
	return total;
}

int main() {
	std::ifstream file("inputs/input8");
	std::string s;
	std::vector<std::vector<int>> vec;
	while(getline(file, s)){
		std::vector<int> temp;
		for(char c: s){
			temp.push_back((int)c);
		}
		vec.push_back(temp);
	}
	int total_vis_tree = vec.size()*2 + vec[0].size()*2 - 4 + visible_tree(vec);
	std::cout << total_vis_tree << std::endl;
}
