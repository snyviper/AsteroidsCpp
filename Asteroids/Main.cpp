// Asteroids.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <Windows.h>
#include "Space.h"

void showConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void printMainScreen(HUD hud, Cursor cursor, ScreenLimit limit) {
	system("cls");
	cursor.goToNewGame(limit);
	std::cout << "New Game";
	cursor.goToExit(limit);
	std::cout << "Exit";
	hud.printHelpIcon(limit);
}
void printDifficultySelection(HUD hud, Cursor cursor, ScreenLimit limit) {
	system("cls");
	cursor.goToSelectDifficulty(limit);
	std::cout << "Select Difficulty";
	cursor.goToDifficultyEasy(limit);
	std::cout << "Easy";
	cursor.goToDifficultyNormal(limit);
	std::cout << "Normal";
	cursor.goToDifficultyHard(limit);
	std::cout << "Hard";
	cursor.goToDifficultyExtreme(limit);
	std::cout << "Extreme";
	cursor.goToDifficultyBack(limit);
	std::cout << "Back";
	hud.printHelpIcon(limit);
}

int main()
{
	const char ARROW = 175;
	char key;
	bool exit = false;
	showConsoleCursor(false);
	ScreenLimit limit(128, 45);
	Space space(1, limit);
	int arrowMainScreen = 0;
	int arrowDifficulty;
	bool exitDifficulty;
	printMainScreen(space.getHUD(), space.getCursor(), limit);
	while (!exit) {
		switch (arrowMainScreen) {
			case 0:
				space.getCursor().goToArrowNewGame(limit);
				std::cout << ARROW;
				key = _getch();
				switch (key) {
					case 's': // down arrow
						space.getCursor().goToArrowNewGame(limit);
						std::cout << ' ';
						arrowMainScreen = 1;
						break;
					case 'j': // select difficulty
						arrowDifficulty = 1;
						exitDifficulty = false;
						printDifficultySelection(space.getHUD(), space.getCursor(), limit);
						while (!exitDifficulty) {
							switch (arrowDifficulty) {
								case 0: // easy
									space.getCursor().goToDifficultyArrowEasy(limit);
									std::cout << ARROW;
									key = _getch();
									switch (key) {
										case 's': // go down
											space.getCursor().goToDifficultyArrowEasy(limit);
											std::cout << ' ';
											arrowDifficulty++;
											break;
										case 'j': // start game
											space.game(arrowDifficulty, limit);
											printDifficultySelection(space.getHUD(), space.getCursor(), limit);
											break;
										case 'h': // show help page
											space.getHUD().printHelp(limit);
											printDifficultySelection(space.getHUD(), space.getCursor(), limit);
											break;
									}
									break;
								case 1: // normal
									space.getCursor().goToDifficultyArrowNormal(limit);
									std::cout << ARROW;
									key = _getch();
									switch (key) {
										case 'w': // go up
											space.getCursor().goToDifficultyArrowNormal(limit);
											std::cout << ' ';
											arrowDifficulty--;
											break;
										case 's': // go down
											space.getCursor().goToDifficultyArrowNormal(limit);
											std::cout << ' ';
											arrowDifficulty++;
											break;
										case 'j': // start game
											space.game(arrowDifficulty, limit);
											printDifficultySelection(space.getHUD(), space.getCursor(), limit);
											break;
										case 'h': // show help page
											space.getHUD().printHelp(limit);
											printDifficultySelection(space.getHUD(), space.getCursor(), limit);
											break;
									}
									break;
								case 2: // hard
									space.getCursor().goToDifficultyArrowHard(limit);
									std::cout << ARROW;
									key = _getch();
									switch (key) {
										case 'w': // go up
											space.getCursor().goToDifficultyArrowHard(limit);
											std::cout << ' ';
											arrowDifficulty--;
											break;
										case 's': // go down
											space.getCursor().goToDifficultyArrowHard(limit);
											std::cout << ' ';
											arrowDifficulty++;
											break;
										case 'j': // start game
											space.game(arrowDifficulty, limit);
											printDifficultySelection(space.getHUD(), space.getCursor(), limit);
											break;
										case 'h': // show help page
											space.getHUD().printHelp(limit);
											printDifficultySelection(space.getHUD(), space.getCursor(), limit);
											break;
									}
									break;
								case 3: // extreme
									space.getCursor().goToDifficultyArrowExtreme(limit);
									std::cout << ARROW;
									key = _getch();
									switch (key) {
										case 'w': // go up
											space.getCursor().goToDifficultyArrowExtreme(limit);
											std::cout << ' ';
											arrowDifficulty--;
											break;
										case 's': // go down
											space.getCursor().goToDifficultyArrowExtreme(limit);
											std::cout << ' ';
											arrowDifficulty++;
											break;
										case 'j': // start game
											space.game(arrowDifficulty, limit);
											printDifficultySelection(space.getHUD(), space.getCursor(), limit);
											break;
										case 'h': // show help page
											space.getHUD().printHelp(limit);
											printDifficultySelection(space.getHUD(), space.getCursor(), limit);
											break;
									}
									break;
								case 4: // back
									space.getCursor().goToDifficultyArrowBack(limit);
									std::cout << ARROW;
									key = _getch();
									switch (key) {
										case 'w': // go up
											space.getCursor().goToDifficultyArrowBack(limit);
											std::cout << ' ';
											arrowDifficulty--;
											break;
										case 'j': // go back
											exitDifficulty = true;
											printMainScreen(space.getHUD(), space.getCursor(), limit);
											break;
										case 'h': // show help page
											space.getHUD().printHelp(limit);
											printDifficultySelection(space.getHUD(), space.getCursor(), limit);
											break;
									}
									break;
							}
						}
						break;
					case 'h': // show help page
						space.getHUD().printHelp(limit);
						printMainScreen(space.getHUD(), space.getCursor(), limit);
						break;
				}
				break;
			case 1:
				space.getCursor().goToArrowExit(limit);
				std::cout << ARROW;
				key = _getch();
				switch (key) {
					case 'w': // up arrow
						space.getCursor().goToArrowExit(limit);
						std::cout << ' ';
						arrowMainScreen = 0;
						break;
					case 'j': // exit
						exit = true;
						break;
					case 'h': // show help page
						space.getHUD().printHelp(limit);
						printMainScreen(space.getHUD(), space.getCursor(), limit);
						break;
				}
				break;
		}
	}
	/*while (exit == 0) {
		
	}*/
	/*cout << "Hello World!" << endl;
	std::cout << "Hello World!\n";
	int x = 0;
	float cash = 2.32;
	double credit = 32.32;
	char a = 'a';
	string sandwich = "ham";
	bool does_she_like_me = true;
	auto do_i_have_pants_on = false;
	auto blank_check = 200.00;
	cout << sandwich << endl;
	cin >> x;
	cout << x << endl;
	cout << "sandwich type: ";
	getline(cin, sandwich);
	cout << "Creating " << sandwich << " sandwich!" << endl;
	cout << "Press enter to exit...";
	getline(cin, sandwich);*/

	/*char x, y;
	int max_num_char = 100;
	x = cin.get();
	cin.ignore(max_num_char, ' ');
	y = cin.get();
	cin.ignore(max_num_char, '\n');
	cout << x << y << endl;
	string z;
	getline(cin, z);*/

	/*string ham = "Ham";
	string sandwich = "Sandwich";
	ham.swap(sandwich);
	ham.size();
	ham.find('a');
	ham[1];
	string x = ham + sandwich;
	sandwich += ham;*/

	// 5 > 4 ? std::cout << 'a' : std::cout << 'b';
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
