// Este arquivo contém a função 'main'. A execução do programa começa e termina aqui.

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Space.h"
#include "HUD.h"

void showConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}

int main()
{
	char key;
	bool exit = false;
	showConsoleCursor(false);
	ScreenLimit limit(128, 45);
	Space space(1, limit);
	int arrowMainScreen = 0;
	int arrowDifficulty;
	bool exitDifficulty;
	HUD().printMainScreen(limit);
	while (!exit) {
		switch (arrowMainScreen) {
			case 0:
				HUD().printArrowNewGame(limit);
				key = _getch();
				switch (key) {
					case 's': // down arrow
						HUD().unprintArrowNewGame(limit);
						arrowMainScreen = 1;
						break;
					case 'j': // select difficulty
						arrowDifficulty = 1;
						exitDifficulty = false;
						HUD().printDifficultySelection(limit);
						while (!exitDifficulty) {
							switch (arrowDifficulty) {
								case 0: // easy
									HUD().printDifficultyArrowEasy(limit);
									key = _getch();
									switch (key) {
										case 's': // go down
											HUD().unprintDifficultyArrowEasy(limit);
											arrowDifficulty++;
											break;
										case 'j': // start game
											space.game(arrowDifficulty, limit);
											HUD().printDifficultySelection(limit);
											break;
										case 'h': // show help page
											HUD().printHelp(limit);
											HUD().printDifficultySelection(limit);
											break;
									}
									break;
								case 1: // normal
									HUD().printDifficultyArrowNormal(limit);
									key = _getch();
									switch (key) {
										case 'w': // go up
											HUD().unprintDifficultyArrowNormal(limit);
											arrowDifficulty--;
											break;
										case 's': // go down
											HUD().unprintDifficultyArrowNormal(limit);
											arrowDifficulty++;
											break;
										case 'j': // start game
											space.game(arrowDifficulty, limit);
											HUD().printDifficultySelection(limit);
											break;
										case 'h': // show help page
											HUD().printHelp(limit);
											HUD().printDifficultySelection(limit);
											break;
									}
									break;
								case 2: // hard
									HUD().printDifficultyArrowHard(limit);
									key = _getch();
									switch (key) {
										case 'w': // go up
											HUD().unprintDifficultyArrowHard(limit);
											arrowDifficulty--;
											break;
										case 's': // go down
											HUD().unprintDifficultyArrowHard(limit);
											arrowDifficulty++;
											break;
										case 'j': // start game
											space.game(arrowDifficulty, limit);
											HUD().printDifficultySelection(limit);
											break;
										case 'h': // show help page
											HUD().printHelp(limit);
											HUD().printDifficultySelection(limit);
											break;
									}
									break;
								case 3: // extreme
									HUD().printDifficultyArrowExtreme(limit);
									key = _getch();
									switch (key) {
										case 'w': // go up
											HUD().unprintDifficultyArrowExtreme(limit);
											arrowDifficulty--;
											break;
										case 's': // go down
											HUD().unprintDifficultyArrowExtreme(limit);
											arrowDifficulty++;
											break;
										case 'j': // start game
											space.game(arrowDifficulty, limit);
											HUD().printDifficultySelection(limit);
											break;
										case 'h': // show help page
											HUD().printHelp(limit);
											HUD().printDifficultySelection(limit);
											break;
									}
									break;
								case 4: // back
									HUD().printDifficultyArrowBack(limit);
									key = _getch();
									switch (key) {
										case 'w': // go up
											HUD().unprintDifficultyArrowBack(limit);
											arrowDifficulty--;
											break;
										case 'j': // go back
											exitDifficulty = true;
											HUD().printMainScreen(limit);
											break;
										case 'h': // show help page
											HUD().printHelp(limit);
											HUD().printDifficultySelection(limit);
											break;
									}
									break;
							}
						}
						break;
					case 'h': // show help page
						HUD().printHelp(limit);
						HUD().printMainScreen(limit);
						break;
				}
				break;
			case 1:
				HUD().printArrowExit(limit);
				key = _getch();
				switch (key) {
					case 'w': // up arrow
						HUD().unprintArrowExit(limit);
						arrowMainScreen = 0;
						break;
					case 'j': // exit
						exit = true;
						break;
					case 'h': // show help page
						HUD().printHelp(limit);
						HUD().printMainScreen(limit);
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
