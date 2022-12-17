#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stack>
#include <vector>
#include <string> 

using namespace std;

void get_num(std::string s, int &n, int &st_1, int &st_2){
	std::stringstream ss(s);
	std::string l, n1, n2, n3;
	getline(ss, l, ' ');
	getline(ss, n1, ' ');
	getline(ss, l, ' ');
	getline(ss, n2, ' ');
	getline(ss, l, ' ');
	getline(ss, n3, ' ');

	n = stoi(n1);
	st_1 = stoi(n2);
	st_2 = stoi(n3);
}

int main() {
	vector<stack<char>> container(10);

	container[0].push('B');
	container[0].push('W');
	container[0].push('N');

	container[1].push('L');
	container[1].push('Z');
	container[1].push('S');
	container[1].push('P');
	container[1].push('T');
	container[1].push('D');
	container[1].push('M');
	container[1].push('B');

	container[2].push('Q');
	container[2].push('H');
	container[2].push('Z');
	container[2].push('W');
	container[2].push('R');

	container[3].push('W');
	container[3].push('D');
	container[3].push('V');
	container[3].push('J');
	container[3].push('Z');
	container[3].push('R');

	container[4].push('S');
	container[4].push('H');
	container[4].push('M');
	container[4].push('B');

	container[5].push('L');
	container[5].push('G');
	container[5].push('N');
	container[5].push('J');
	container[5].push('H');
	container[5].push('V');
	container[5].push('P');
	container[5].push('B');

	container[6].push('J');
	container[6].push('Q');
	container[6].push('Z');
	container[6].push('F');
	container[6].push('H');
	container[6].push('D');
	container[6].push('L');
	container[6].push('S');

	container[7].push('W');
	container[7].push('S');
	container[7].push('F');
	container[7].push('J');
	container[7].push('G');
	container[7].push('Q');
	container[7].push('B');

	container[8].push('Z');
	container[8].push('W');
	container[8].push('M');
	container[8].push('S');
	container[8].push('C');
	container[8].push('D');
	container[8].push('J');

	ifstream file("input5");
	string line;
	while(getline(file,line)){
		stringstream ss(line);
		int num_of_pop = 0;
		int stack_1 = 0;
		int stack_2 = 0;
		get_num(line, num_of_pop, stack_1, stack_2);		
		//cout << num_of_pop << " " << stack_1 << " " << stack_2 << endl;
	
		/*
		//----------------Part 1 --------------------------
		//pop from stack_1 then push to stack_2
		for(int i =0;i < num_of_pop; i++){
			container[stack_2 -1].push(container[stack_1 -1].top());
			container[stack_1 -1].pop();
		}*/

		//---------------Part 2 ---------------------------
		string temp = "";
		for(int i =0;i < num_of_pop; i++){
			temp += container[stack_1 -1].top();
			container[stack_1 -1].pop();
		}
		for(size_t i =0; i < temp.size(); i++){
			container[stack_2 -1].push(temp[temp.size() -i -1]);
		}
	}
	for(size_t i =0; i < 9; i++){
		cout << container[i].top() << " " ;
	}
	cout << endl;
}
