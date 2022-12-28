#include <conio.h>
#include <iostream>
#include <algorithm>  // Библ. для transform()
#include <fstream>  // Библ. для работы с файлами
#include <windows.h>  // Библ. для ввода/вывода в консоль 
#include <string>  // Библ. для работы со строками
#include <ctime>  // Библ. для таймера
#include <map>  // Библ. для словарей
#include <set>  // Библ. для сет
#include <vector>
using namespace std;

// Функции меню
void prog_name() {
	cout << "		<=============================================>" << endl << endl;
	cout << "		                 TEXT ANALYZER" << endl << endl;
	cout << "		<=============================================>" << endl;
}

void nav_menu() {
	cout << "		<=============================================>" << endl << endl;
	cout << "			МЕНЮ НАВИГАЦИИ" << endl;
	cout << "		   1. Выбор файла" << endl;
	cout << "		   2. Настройки регистра" << endl;
	cout << "		   3. Настройки нежелательных символов" << endl;
	cout << "		   4. Настройки нежелательных слов" << endl;
	cout << "		   5. Режим сортировки" << endl << endl;
	cout << "		   ? - чтобы узнать инструкцию" << endl << endl;
	cout << "		<=============================================>" << endl;
}

int file_menu() {
	string answer;
	cout << "		<=============================================>" << endl << endl;
	cout << "			ВЫБЕРИТЕ ФАЙЛ" << endl;
	cout << "		   1. Песни ГрОба" << endl;
	cout << "		   2. Тоже что-то" << endl;
	cout << "		   3. Какие-то книги" << endl << endl;
	cout << "		   !help чтобы получить список всех команд" << endl << endl;
	cout << "		<=============================================>" << endl;
	cin >> answer;
	if (int(answer[0]) >= 49 && int(answer[0]) <= 51) {
		system("cls");
		return int(answer[0]) - 48;
	}
	else {
		cout << "Вы ввели некорректное значение. Попробуйте снова.";
		Sleep(2500);
		system("cls");
		file_menu();
	}
}

int font_menu() {
	string answer;
	cout << "		<=============================================>" << endl << endl;
	cout << "			ВЫБЕРИТЕ РЕГИСТР" << endl;
	cout << "		   1. Нижний" << endl;
	cout << "		   2. Верхний" << endl;
	cout << "		   3. Не менять регистр" << endl << endl;
	cout << "		   !help чтобы получить список всех команд" << endl << endl;
	cout << "		<=============================================>" << endl;
	cin >> answer;
	if (int(answer[0]) >= 49 && int(answer[0]) <= 51) {
		system("cls");
		return int(answer[0]) - 48;
	}
	else {
		cout << "Вы ввели некорректное значение. Попробуйте снова.";
		Sleep(2500);
		system("cls");
		font_menu();
	}
}

int symb_menu() {
	string answer;
	cout << "		<=============================================>" << endl << endl;
	cout << "			ВЫБЕРИТЕ НАСТРОЙКУ УДАЛЕНИЯ СИМВОЛОВ" << endl;
	cout << "		   1. Заготовленный набор символов" << endl;
	cout << "		   2. Создать свой набор" << endl;
	cout << "		   3. Не удалять символы" << endl << endl;
	cout << "		   !help чтобы получить список всех команд" << endl << endl;
	cout << "		<=============================================>" << endl;
	cin >> answer;
	if (int(answer[0]) >= 49 && int(answer[0]) <= 51) {
		system("cls");
		return int(answer[0]) - 48;
	}
	else {
		cout << "Вы ввели некорректное значение. Попробуйте снова.";
		Sleep(2500);
		system("cls");
		symb_menu();
	}

}

int word_menu() {
	string answer;
	cout << "		<=============================================>" << endl << endl;
	cout << "			ВЫБЕРИТЕ НАСТРОЙКУ УДАЛЕНИЯ СЛОВ" << endl;
	cout << "		   1. Заготовленный набор слов" << endl;
	cout << "		   2. Создать свой набор" << endl;
	cout << "		   3. Не удалять слова" << endl << endl;
	cout << "		   !help чтобы получить список всех команд" << endl << endl;
	cout << "		<=============================================>" << endl;
	cin >> answer;
	if (int(answer[0]) >= 49 && int(answer[0]) <= 51) {
		system("cls");
		return int(answer[0]) - 48;
	}
	else {
		cout << "Вы ввели некорректное значение. Попробуйте снова.";
		Sleep(2500);
		system("cls");
		word_menu();
	}
}

int sort_menu() {
	string answer;
	cout << "		<=============================================>" << endl << endl;
	cout << "			ВЫБЕРИТЕ СОРТИРОВКУ" << endl;
	cout << "		   1. Алфавитный порядок" << endl;
	cout << "		   2. В порядке по убыванию" << endl;
	cout << "		   3. В порядке по возрастанию" << endl << endl;
	cout << "		   !help чтобы получить список всех команд" << endl << endl;
	cout << "		<=============================================>" << endl;
	cin >> answer;
	if (int(answer[0]) >= 49 && int(answer[0]) <= 51) {
		system("cls");
		return int(answer[0]) - 48;
	}
	else {
		cout << "Вы ввели некорректное значение. Попробуйте снова.";
		Sleep(2500);
		system("cls");
		sort_menu();
	}
}

void help() { // памагити
	cout << "		<=============================================>" << endl << endl;
	cout << "			СПИСОК КОМАНД" << endl << endl;
	cout << "		   !navmenu - меню навигации по настройкам" << endl;
	cout << "		   !exit - выход из программы" << endl;
	cout << "		   !start - запуск анализатора" << endl;
	cout << "		   !findword - поиск по слову" << endl;
	cout << "		   !settings - узнать выбранные настройки" << endl << endl;
	cout << "		<=============================================>" << endl;
	_getch();
	system("cls");
}

// Функции программы



void main() {

	string answer;

	int file_menu_answer = 0;
	int font_menu_answer = 0;
	int symb_menu_answer = 0;
	int word_menu_answer = 0;
	int sort_menu_answer = 0;

	setlocale(LC_ALL, "ru");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	prog_name();
	cout << endl << endl;
	_getch();
	system("cls");

	
	while (true) {
		nav_menu();
		cin >> answer;
		switch (int(answer[0])) {
		case(49):
			system("cls");
			file_menu_answer = file_menu();
			break;
		case(50):
			system("cls");
			font_menu_answer = font_menu();
			break;
		case(51):
			system("cls");
			symb_menu_answer = symb_menu();
			break;
		case(52):
			system("cls");
			word_menu_answer = word_menu();
			break;
		case(53):
			system("cls");
			sort_menu_answer = sort_menu();
			break;
		case(63):
			system("cls");
			help();
			break;
		default:
			cout << "Нет такой функции" << endl;
			Sleep(750);
			system("cls");
			break;
		}
		if (answer == "!exit") {
			break;
		}
		if (file_menu_answer && font_menu_answer && symb_menu_answer && word_menu_answer && sort_menu_answer) {
			cout << "Вы большой молодец!!!";
			break;
		}
	}
	
}