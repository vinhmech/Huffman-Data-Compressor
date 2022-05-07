#include "HuffTree.h"

// Tao va tra bang tan so kieu du lieu vector
vector<pair<int, char>> taoBangTanSo(string chuoi) {
	int size = chuoi.length();
	map<char, int> mapBangTanSo;
	for (int i = 0; i < size; i++) {
		mapBangTanSo[chuoi[i]]++;
	}

	vector<pair<int, char>> bangTanSo;
	for (int i = 0; i < size; i++) {
		if (mapBangTanSo[chuoi[i]] != 0) {
			bangTanSo.push_back(make_pair(mapBangTanSo[chuoi[i]], chuoi[i]));
			mapBangTanSo[chuoi[i]] = 0;
		}
	}

	return bangTanSo;
}

// Ham in vector bang tan so
void inBangTanSo(vector<pair<int, char>> bangTanSo) {
	int size = bangTanSo.size();
	for (int i = 0; i < size; i++) {
		cout << bangTanSo[i].first << " : " << bangTanSo[i].second << endl;
	}
}


// Khoi tao mac dinh node cho cay huffman
Node::Node(int freq, char letter) {
	this->kyTu = letter;
	this->tanSo = freq;
	this->left = NULL;
	this->right = NULL;
}


// Ham in thu tu ra cua hang doi uu tien
void inHangDoi(priority_queue<Node*, vector<Node*>, Compare> & hangDoi) {
	while (hangDoi.size()) {
		cout << hangDoi.top()->tanSo << " : " << hangDoi.top()->kyTu << endl;
		hangDoi.pop();
	}
}

// Tao va tra ve cay Huffman
Node* taoCayHuffman(vector<pair<int, char>> & bangTanSo) {
	priority_queue<Node*, vector<Node*>, Compare> hangDoi;
	int size = bangTanSo.size();
	for (int i = 0; i < size; i++) {
		Node* nodeMoi = new Node(bangTanSo[i].first, bangTanSo[i].second);
		hangDoi.push(nodeMoi);
	}
	//inHangDoi(hangDoi);

	while (hangDoi.size() > 1) {
		Node* trai = hangDoi.top();
		hangDoi.pop();
		Node* phai = hangDoi.top();
		hangDoi.pop();
		Node* cha = new Node(trai->tanSo + phai->tanSo, '~');
		cha->left = trai;
		cha->right = phai;
		hangDoi.push(cha);
	}
	return hangDoi.top();
}


// Tao bang ma tu cay Huffman
void taoBangMa(Node* root, string s, map<char, string>& bangMa) {
	if (!root) {
		return;
	}
	if (root->kyTu != '~') {
		bangMa[root->kyTu] = s;
		return;
	}
	else {
		taoBangMa(root->left, s + '0', bangMa);
		taoBangMa(root->right, s + '1', bangMa);
	}
}


// In bang ma cay Huffman
void inBangMa(map<char, string> bangMa) {
	for (auto it : bangMa) {
		cout << it.first << " : " << it.second << endl;
	}
}


// Viet ma tu bang ma
string vietMa(string chuoi, map<char, string> bangMa) {
	string matMa = "";
	for (auto it : chuoi) {
		matMa += bangMa[it];
	}
	return matMa;
}


// Giai ma
string giaiMa(Node* root, string matMa, int &i) {
	string maSauKhiGiai = "";
	int size = matMa.length();
	while (i <= size) {
		if (root->kyTu != '~') {
			maSauKhiGiai += root->kyTu;
			return maSauKhiGiai;
		}
		else if (matMa[i] == '0') {
			if (root->left) {
				root = root->left;
				i++;
			}
			else {
				return maSauKhiGiai;
			}
		}
		else if (matMa[i] == '1') {
			if (root->right) {
				root = root->right;
				i++;
			}
			else {
				return maSauKhiGiai;
			}
		}
		else {
			return maSauKhiGiai;
		}
	}
}