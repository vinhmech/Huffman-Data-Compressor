#include "HuffTree.h"

int main() {
	cout << "\nNhap vao chuoi: ";
	string chuoi;
	getline(cin, chuoi);
	vector<pair<int, char>> bangTanSo = taoBangTanSo(chuoi);
	inBangTanSo(bangTanSo);

	sort(bangTanSo.begin(), bangTanSo.end());
	cout << endl;
	inBangTanSo(bangTanSo);

	
	Node* root = taoCayHuffman(bangTanSo);
	map<char, string> bangMa;
	taoBangMa(root, "", bangMa);
	cout << endl;
	cout << "\nDay la bang ma" << endl;
	inBangMa(bangMa);

	string matMa = vietMa(chuoi, bangMa);
	cout << "\n" << chuoi;
	cout << "\n" << matMa;

	string maSauKhiGiai = "";
	int size = matMa.length();
	for (int i = 0; i < size;) {
		maSauKhiGiai += giaiMa(root, matMa, i);
	}
	cout << "\n" << maSauKhiGiai;
	return 0;
}