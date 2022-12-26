#include <iostream>
#include <algorithm>  // ����. ��� transform()
#include <fstream>  // ����. ��� ������ � �������
#include <windows.h>  // ����. ��� �����/������ � ������� 
#include <string>  // ����. ��� ������ �� ��������
#include <ctime>  // ����. ��� �������
#include <map>  // ����. ��� ��������
#include <set>  // ����. ��� ���
#include <vector>  // ����. ��� ��������
using namespace std;

struct comp  // ��� ����� ��� ���������� 
{
	template<typename T>
	bool operator()(const T& l, const T& r) const
	{
		if (l.second != r.second) {
			return l.second < r.second;  // < - ���������� �� �����������; > - �� ��������
		}

		return l.first < r.first;
	}
};

void main() {
	unsigned int start_time = clock();  // ��� ����� ������ ����� ������ ���������
	setlocale(LC_ALL, "ru");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	ifstream text("d:\\software_labs\\tetx_analizator\\grob_text.txt", ios::in);

	// �������� �� ������ �� ����
	if (!text) {
		cout << "���� �� ������\n";
	}
	else {
		cout << "��� ��! ���� ������!\n";
	}

	// ������ ������ � ������ ������
	string str, str_arr = " ";
	while (!text.eof()) {
		text >> str;
		str_arr += " " + str;
	}

	// ������������ �������� ��������
	string unwanted_symbols = ".!?,-:;()*'\"���";
	int unpos;  // ������� ��������� �������
	for (int i = 0; i < unwanted_symbols.length(); i++) {
		for (int j = 0; j < str_arr.length(); j++) {
			if (unwanted_symbols[i] == str_arr[j]) {
				str_arr[j] = ' ';
			}
		}
	}
	
	// ������� � ������ �������
	transform(str_arr.begin(), str_arr.end(), str_arr.begin(), tolower);

	// ��������� ���� 
	string temp;
	int count = 0;
	for (int i = 0; i < str_arr.length(); i++) {  // ������ ������� ���� 
		if (str_arr[i] != ' ' && str_arr[i + 1] == ' ')
			count++;
	}
	for (int j = 0; j < str_arr.length(); j++) {  // ������ ��������������� ��������
		if (str_arr[j] == ' ' && str_arr[j + 1] == ' ') {
			str_arr = str_arr.erase(j + 1, 1);
			j--;
		}
	}
	if (str_arr[0] == ' ') {  // ������ ������� ������
		str_arr = str_arr.erase(0, 1);
	}
	cout << "Slova: " << count << endl;
	string* out_str = new string[count];
	int i = 0;
	while (true) {
		temp = str_arr.substr(0, str_arr.find(' '));
		if (temp.size() == str_arr.size()) {
			break;
		}
		else {
			str_arr = str_arr.substr(temp.size() + 1);
		}
		if (temp != " ") {
			out_str[i] = temp;
			i++;
		}
	}

	// �������� ������� ���� "�����" - ���-�� ���������� (���������� ��� ���������� �� �������� �� � �� �)
	map <string, int> words_map;
	int str_len = count;
	int temp_word_count = 1;
	for (int j = 0; str_len != 0; ) {
		for (int i = 1; i < str_len; i++) {
			if (out_str[j] == out_str[i]) {
				temp_word_count++;
				for (; i < str_len - 1; i++) {
					out_str[i] = out_str[i + 1];
				}
				str_len--;
				i = 1;
			}
		}
		words_map.insert(make_pair(out_str[j], temp_word_count));
		for (int g = 0; g < str_len; g++) {
			out_str[g] = out_str[g + 1];
		}
		str_len--;
		temp_word_count = 1;
	}
	map <string, int> ::iterator it = words_map.begin();  // ����� �������
	for (int i = 0; it != words_map.end(); it++, i++) {
		cout << i << ") " << it->first << ", " << it->second << endl;
	}


	// ���������� �� �����������/��������
	set<pair<string, int>, comp> set(words_map.begin(), words_map.end());
	for (auto const& pair : set) {
		cout << pair.first << "\t\t" << pair.second << endl;
	}

	// ����� �����
	while (true) {
		bool word_flag = true;
		string word_for_finding;
		cin >> word_for_finding;
		map <string, int> ::iterator itt;
		for (itt = words_map.begin(); itt != words_map.end(); itt++) {
			if (itt->first == word_for_finding) {
				cout << itt->first << " | " << itt->second << endl;
				word_flag = false;
			}
		}
		if (word_flag) {
			cout << "��� ����������." << endl;
		}
	}
	
	// ����� ������ ���������
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << search_time;
}