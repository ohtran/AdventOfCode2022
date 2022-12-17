#include <iostream>
#include <fstream>
#include <vector>

bool up(int tree, int x, int y, std::vector<std::vector<int>> v){
	for(int i = 0; i < x; i++)
		if (tree < v[i][y]) return false;
	return true;
}

bool down(int tree, int x, int y, std::vector<std::vector<int>> v){
	for(int i = x; i <v.size(); i++)
		if (tree < v[i][y]) return false;
	return true;
}

bool left(int tree, int x, int y, std::vector<std::vector<int>> v){
	for (int i = 0; i<y; i++)
		if (tree < v[x][i]) return false;
	return true;
}

bool right(int tree, int x, int y, std::vector<std::vector<int>> v){
	for (int i = y; i< v[x].size(); i++)	
		if (tree < v[x][y+1]) return false; 
	return true;
}

int visible_tree(std::vector<std::vector<int>> v){
	int total = 0;
	for(size_t i = 1; i < v.size()-1; i++){
		for(size_t j =1; j < v[i].size()-1; j++){
			int tree = v[i][j];
			if (up(tree, i,j,v)){ 
				total++;
				std::cout << tree;
			}
			else if (down(tree, i,j,v)) {
				total++;
				std::cout << tree;
			}
			else if (left(tree, i,j,v)) {
				total++;
				std::cout << tree;
			}
			else if (right(tree, i,j,v)) {
				total++;
				std::cout << tree;
			}
		}
		std::cout << std::endl;
	}
	return total;
}

int main() {
	std::ifstream file("input8_short");
	std::string s;
	std::vector<std::vector<int>> vec;
	while(getline(file, s)){
		std::vector<int> temp;
		for(char c: s){
			temp.push_back(c - 48);
		}
		vec.push_back(temp);
	}

	int total_vis_tree = vec.size()*2 + vec[0].size()*2 - 4 + visible_tree(vec);
	std::cout << total_vis_tree << std::endl;
}
