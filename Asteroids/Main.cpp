#include <conio.h>
#include <windows.h>
#include "Space.h"
#include "HUD.h"
#include "ScreenLimit.h"
#include "Sounds.h"

void showConsoleCursor(bool showFlag){
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void help() {
	Sounds::playHelpSound();
	HUD::printHelp();
	Sounds::playHelpSound();
}

int main()
{
	ScreenLimit::setLimits(128, 45);
	Space space;
	char key;
	bool exit = false;
	bool exitDifficulty;
	int arrowMainScreen = 0;
	int arrowDifficulty;
	showConsoleCursor(false);
	HUD::printMainScreen();
	while (!exit) {
		switch (arrowMainScreen) {
			case 0:
				HUD::printArrowNewGame();
				key = _getch();
				switch (key) {
					case 's': // down arrow
						HUD::unprintArrowNewGame();
						arrowMainScreen = 1;
						Sounds::playMenuSelectSound();
						break;
					case 'j': // select difficulty
						arrowDifficulty = 1;
						exitDifficulty = false;
						Sounds::playMenuHitSound();
						HUD::printDifficultySelection();
						while (!exitDifficulty) {
							switch (arrowDifficulty) {
								case 0: // easy
									HUD::printDifficultyArrowEasy();
									key = _getch();
									switch (key) {
										case 's': // go down
											HUD::unprintDifficultyArrowEasy();
											arrowDifficulty++;
											Sounds::playMenuSelectSound();
											break;
										case 'j': // start game
											space = Space(arrowDifficulty);
											Sounds::playMenuHitSound();
											space.game(arrowDifficulty);
											exitDifficulty = true;
											HUD::printMainScreen();
											break;
										case 'h': // show help page
											help();
											HUD::printDifficultySelection();
											break;
									}
									break;
								case 1: // normal
									HUD::printDifficultyArrowNormal();
									key = _getch();
									switch (key) {
										case 'w': // go up
											HUD::unprintDifficultyArrowNormal();
											arrowDifficulty--;
											Sounds::playMenuSelectSound();
											break;
										case 's': // go down
											HUD::unprintDifficultyArrowNormal();
											arrowDifficulty++;
											Sounds::playMenuSelectSound();
											break;
										case 'j': // start game
											space = Space(arrowDifficulty);
											Sounds::playMenuHitSound();
											space.game(arrowDifficulty);
											exitDifficulty = true;
											HUD::printMainScreen();
											break;
										case 'h': // show help page
											help();
											HUD::printDifficultySelection();
											break;
									}
									break;
								case 2: // hard
									HUD::printDifficultyArrowHard();
									key = _getch();
									switch (key) {
										case 'w': // go up
											HUD::unprintDifficultyArrowHard();
											arrowDifficulty--;
											Sounds::playMenuSelectSound();
											break;
										case 's': // go down
											HUD::unprintDifficultyArrowHard();
											arrowDifficulty++;
											Sounds::playMenuSelectSound();
											break;
										case 'j': // start game
											space = Space(arrowDifficulty);
											Sounds::playMenuHitSound();
											space.game(arrowDifficulty);
											exitDifficulty = true;
											HUD::printMainScreen();
											break;
										case 'h': // show help page
											help();
											HUD::printDifficultySelection();
											break;
									}
									break;
								case 3: // extreme
									HUD::printDifficultyArrowExtreme();
									key = _getch();
									switch (key) {
										case 'w': // go up
											HUD::unprintDifficultyArrowExtreme();
											arrowDifficulty--;
											Sounds::playMenuSelectSound();
											break;
										case 's': // go down
											HUD::unprintDifficultyArrowExtreme();
											arrowDifficulty++;
											Sounds::playMenuSelectSound();
											break;
										case 'j': // start game
											space = Space(arrowDifficulty);
											Sounds::playMenuHitSound();
											space.game(arrowDifficulty);
											exitDifficulty = true;
											HUD::printMainScreen();
											break;
										case 'h': // show help page
											help();
											HUD::printDifficultySelection();
											break;
									}
									break;
								case 4: // back
									HUD::printDifficultyArrowBack();
									key = _getch();
									switch (key) {
										case 'w': // go up
											HUD::unprintDifficultyArrowBack();
											arrowDifficulty--;
											Sounds::playMenuSelectSound();
											break;
										case 'j': // go back
											exitDifficulty = true;
											HUD::printMainScreen();
											Sounds::playMenuBackSound();
											break;
										case 'h': // show help page
											help();
											HUD::printDifficultySelection();
											break;
									}
									break;
							}
						}
						break;
					case 'h': // show help page
						help();
						HUD::printMainScreen();
						break;
				}
				break;
			case 1:
				HUD::printArrowExit();
				key = _getch();
				switch (key) {
					case 'w': // up arrow
						HUD::unprintArrowExit();
						arrowMainScreen = 0;
						Sounds::playMenuSelectSound();
						break;
					case 'j': // exit
						exit = true;
						Sounds::playMenuExitSound();
						break;
					case 'h': // show help page
						help();
						HUD::printMainScreen();
						break;
				}
				break;
		}
	}
}

/*using namespace std;
cout << "Hello World!" << endl;
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
sandwich += ham;

std::thread tPlayAsteroidExplosionSound(Sounds::playAsteroidExplosionSound);
tPlayAsteroidExplosionSound.detach();*/

// 5 > 4 ? std::cout << 'a' : std::cout << 'b';

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
