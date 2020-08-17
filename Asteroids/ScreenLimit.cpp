#include "ScreenLimit.h"

namespace ScreenLimit
{
	namespace
	{
		int _x = 100;
		int _y = 25;
		std::string _cleanScreen = "";
		std::string _cleanSpace = "";
		std::string _topBorder = "";
		std::string _bottomBorder = "";
	}

	void setLimits(int x, int y) {
		if (x < 30)
			x = 30;
		if (y < 10)
			y = 10;
		const char BOTTOM_BORDER = 238;
		_x = x;
		_y = y;
		_cleanScreen = "";
		_cleanSpace = "";
		_topBorder = "";
		_bottomBorder = "";
		for (int i = 0; i < getSpaceY(); i++) {
			for (int j = 0; j < getSpaceX(); j++) {
				_cleanSpace += " ";
			}
			_cleanSpace += "\n";
		}
		for (int i = 0; i < getY(); i++) {
			for (int j = 0; j < getX(); j++) {
				_cleanScreen += " ";
			}
			_cleanScreen += "\n";
		}
		for (int i = 0; i < getSpaceX(); i++)
			_topBorder += "_";
		for (int i = 0; i < getSpaceX() - 9; i++)
			_bottomBorder += BOTTOM_BORDER;
	}

	int getSpaceX() { return _x; }
	int getSpaceY() { return _y - 3; }

	int getX() { return _x; }
	int getY() { return _y; }

	std::string getCleanScreen() { return _cleanScreen; }
	std::string getCleanSpace() { return _cleanSpace; }
	std::string getTopBorder() { return _topBorder; }
	std::string getBottomBorder() { return _bottomBorder; }
}