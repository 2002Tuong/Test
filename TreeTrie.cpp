#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

struct TrieNode {
	int ID;
	TrieNode* next[26];
};

void Insert(TrieNode*& Dic, string word, int ID, int index);
void createTrie(TrieNode*& Dic, string DicFile);
int lookUp(TrieNode* Dic, string word, int index);
vector <string> lookUpPrefix(TrieNode* Dic, string prefix);
void Remove(TrieNode* Dic, string word);




int main() {
	string DicFile = "HW6-dic.txt";
	TrieNode* root = new TrieNode;
	string word = "abcg";
	int ID = 55;
	Insert(root, word, ID, 0);

}

void Insert(TrieNode*& Dic, string word, int ID, int index) {
	if (word.length() == 0) {
		return;
	}
	else {
		if (word.length() == index) {
			Dic->ID = ID;
		}
		else {
			int position = word[index] - int('a');
			if (Dic->next[position] == NULL) {
				Dic->next[position] = new TrieNode;
				Dic->next[position]->ID = -1;
			}
			Insert(Dic->next[position], word, ID, index + 1);
		}
	}
}
void createTrie(TrieNode*& Dic, string DicFile) {
	fstream f;
	f.open(DicFile.c_str(), ios::in);
	string sID = "";
	int ID;
	string word = "";
	while (!f.eof()) {
		f >> sID;
		f >> word;
		sID = sID.erase(sID.length() - 1, 1);
		ID = atoi(sID.c_str());
		Insert(Dic, word, ID, 0);
	}
}
int lookUp(TrieNode* Dic, string word, int index) {
	return 0;
}
vector <string> lookUpPrefix(TrieNode* Dic, string prefix) {
	vector <string> result;
	return result;
}
void Remove(TrieNode* Dic, string word) {

}
