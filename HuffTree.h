#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

// Tao va tra bang tan so kieu du lieu vector
vector<pair<int, char>> taoBangTanSo(string);

// Ham in vector bang tan so
void inBangTanSo(vector<pair<int, char>>);


// Tao node cho cay Huffman
struct Node {
	char kyTu;
	int tanSo;
	struct Node* left;
	struct Node* right;
	Node(int, char);
};
typedef struct Node Node;


// Dinh nghia cach sap xep cac phan tu trong hang doi uu tien
struct Compare {
	bool operator() (Node* a, Node* b) {
		if (a->tanSo > b->tanSo) {
			return true;
		}
		else if (a->tanSo == b->tanSo && a->kyTu > b->kyTu) {
			return true;
		}
		else {
			return false;
		}
	}
};
typedef struct Compare Compare;


// Ham in thu tu ra cua hang doi uu tien
void inHangDoi(priority_queue<Node*, vector<Node*>, Compare> &);


// Tao va tra ve cay Huffman
Node* taoCayHuffman(vector<pair<int, char>> &);


// Tao bang ma tu cay Huffman
void taoBangMa(Node*, string, map<char, string>&);


// In bang ma cay Huffman
void inBangMa(map<char, string>);

// Viet ma tu bang ma
string vietMa(string, map<char, string>);

// Giai ma
string giaiMa(Node*, string, int &);
