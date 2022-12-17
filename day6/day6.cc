#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>

#define POS 14
using namespace std;

bool is_unique(queue<char> q){
	vector<char> vec;
	while (q.empty() == false){
		vec.push_back(q.front());
		q.pop();
	}
	
	sort(vec.begin(), vec.end());
	auto rm = unique(vec.begin(), vec.end());
	vec.erase(rm, vec.end());
	
	if (vec.size() == POS) {
		for (char i :vec) cout << i;
		cout << endl;
		return true;
	}
	return false;
}

int main() {
	ifstream file("input6");
	char c;
	int count = 0;
	queue<char> queue;
	while (file.get(c)){
		if (queue.size() == POS){
			queue.pop();
		}
		queue.push(c);
		count++;
		if (is_unique(queue) && queue.size() == POS){
			break;
		}
	}
	cout << count << "\n";
}
