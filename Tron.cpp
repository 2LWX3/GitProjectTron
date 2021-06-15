#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <vector>
#include <conio.h>


using namespace std;

const int sizeVec = 30;

class Track {
private:
	string symbolTrack = "#", symbolBotTrack = "X";
	int coordTrackX = 0, coordTrackY = 0;
	int coordBotTrackX = 0, coordBotTrackY = 0;
public:
	void setCoordTrack(int x, int y) {
		this->coordTrackX = x;
		this->coordTrackY = y;
	}
	int getCoordTrackX() {
		return this->coordTrackX;
	}
	int getCoordTrackY() {
		return this->coordTrackY;
	}
	string getSymbolTrack() {
		return this->symbolTrack;
	}
	void setCoordBotTrack(int x, int y) {
		this->coordBotTrackX = x;
		this->coordBotTrackY = y;
	}
	int getCoordBotTrackX() {
		return this->coordBotTrackX;
	}
	int getCoordBotTrackY() {
		return this->coordBotTrackY;
	}
	string getSymbolBotTrack() {
		return this->symbolBotTrack;
	}
};

class Bike : public Track {
private:
	string direction;
	string bike = "v";
	int coordX = sizeVec / 2, coordY = sizeVec / 2;
public:
	int getCoordX() {
		return this->coordX;
	}
	int getCoordY() {
		return this->coordY;
	}
	string getSymbolBike() {
		return this->bike;
	}
	void directionBike(int direction) {
		if (direction == 162 || direction == 100)
			if (this->direction != "left")
				this->direction = "right";
		if (direction == 228 || direction == 97)
			if (this->direction != "right")
				this->direction = "left";
		if (direction == 63 || direction == 235 || direction == 115)
			if (this->direction != "up")
				this->direction = "down";
		if (direction == 230 || direction == 119)
			if (this->direction != "down")
				this->direction = "up";

	}
	void moveBike() {
		if (this->direction == "right") {
			setCoordTrack(coordX, coordY);
			bike = ">";
			coordX += 1;
		}
		if (this->direction == "left") {
			setCoordTrack(coordX, coordY);
			bike = "<";
			coordX -= 1;
		}
		if (this->direction == "down") {
			setCoordTrack(coordX, coordY);
			bike = "v";
			coordY += 1;
		}
		if (this->direction == "up") {
			setCoordTrack(coordX, coordY);
			bike = "^";
			coordY -= 1;
		}
	}
	string getDirection() {
		return this->direction;
	}
};

class Bot : public Bike {
private:
	string botDirection;
	string botBike = "~";
	int botCoordX = rand() % 10 + 3, botCoordY = rand() % 10 + 2;
public:
	int getBotCoordX() {
		return this->botCoordX;
	}
	int getBotCoordY() {
		return this->botCoordY;
	}
	string getSymbolBotBike() {
		return this->botBike;
	}
	void setBotDirection(string direction) {
		this->botDirection = direction;
	}
	string getBotDirection() {
		return this->botDirection;
	}
	void mindBot(int typeMind, int flag) {
		if (typeMind == 1) {
			if (this->botCoordX < getCoordX() && this->botCoordY < getCoordY()) {
				if (getDirection() == "up") {
					if (this->botDirection != "left")
						this->botDirection = "right";
				}
				if (getDirection() == "down") {
					if (this->botDirection != "up")
						this->botDirection = "down";
				}
				if (getDirection() == "left") {
					if (this->botDirection != "up")
						this->botDirection = "down";
				}
				if (getDirection() == "right") {
					if (this->botDirection != "left")
						this->botDirection = "right";
				}
			}
			if (this->botCoordX < getCoordX() && this->botCoordY > getCoordY()) {
				if (getDirection() == "up") {
					if (this->botDirection != "down")
						this->botDirection = "up";
				}
				if (getDirection() == "down") {
					if (this->botDirection != "left")
						this->botDirection = "right";
				}
				if (getDirection() == "left") {
					if (this->botDirection != "down")
						this->botDirection = "up";
				}
				if (getDirection() == "right") {
					if (this->botDirection != "left")
						this->botDirection = "right";
				}
			}
			if (this->botCoordX > getCoordX() && this->botCoordY > getCoordY()) {
				if (getDirection() == "up") {
					if (this->botDirection != "down")
						this->botDirection = "up";
				}
				if (getDirection() == "down") {
					if (this->botDirection != "right")
						this->botDirection = "left";
				}
				if (getDirection() == "left") {
					if (this->botDirection != "right")
						this->botDirection = "left";
				}
				if (getDirection() == "right") {
					if (this->botDirection != "down")
						this->botDirection = "up";
				}
			}
			if (this->botCoordX > getCoordX() && this->botCoordY < getCoordY()) {
				if (getDirection() == "up") {
					if (this->botDirection != "right")
						this->botDirection = "left";
				}
				if (getDirection() == "down") {
					if (this->botDirection != "up")
						this->botDirection = "down";
				}
				if (getDirection() == "left") {
					if (this->botDirection != "right")
						this->botDirection = "left";
				}
				if (getDirection() == "right") {
					if (this->botDirection != "up")
						this->botDirection = "down";
				}
			}
		}
		if (typeMind == 0) {
			if (flag == 0) {
				if (this->botDirection == "up") {
					this->botDirection = "left";
				}
				if (this->botDirection == "down") {
					this->botDirection = "left";
				}
				if (this->botDirection == "left") {
					this->botDirection = "up";
				}
				if (this->botDirection == "right") {
					this->botDirection = "up";
				}
			}
			if (flag == 1) {
				if (this->botDirection == "up") {
					this->botDirection = "right";
				}
				else if (this->botDirection == "down") {
					this->botDirection = "right";
				}
				else if (this->botDirection == "left") {
					this->botDirection = "down";
				}
				else if (this->botDirection == "right") {
					this->botDirection = "down";
				}
				else {
					throw 404;
				}
			}
		}
		if (typeMind == 2) {
			setBotDirection(getBotDirection());
		}
	}
	void moveBot() {
		if (this->botDirection == "right") {
			setCoordBotTrack(botCoordX, botCoordY);
			botBike = ")";
			botCoordX += 1;
		}
		if (this->botDirection == "left") {
			setCoordBotTrack(botCoordX, botCoordY);
			botBike = "(";
			botCoordX -= 1;
		}
		if (this->botDirection == "down") {
			setCoordBotTrack(botCoordX, botCoordY);
			botBike = "~";
			botCoordY += 1;
		}
		if (this->botDirection == "up") {
			setCoordBotTrack(botCoordX, botCoordY);
			botBike = "~";
			botCoordY -= 1;
		}
	}
};

class Arena : public Bot {
private:
	vector<vector<string>>arenaVector;
	int flagBot = 1, flagMindBot = 0;
public:
	Arena() {
		for (int i = 0; i < sizeVec; i++) {
			vector<string>tmpVector;
			for (int j = 0; j < sizeVec; j++) {
				tmpVector.push_back("");
			}
			arenaVector.push_back(tmpVector);
		}
	}
	void makeArena() {
		for (int i = 0; i < sizeVec; i++) {
			for (int j = 0; j < sizeVec; j++) {
				if (i == 0 || i == sizeVec - 1) {
					arenaVector[i][j] = "*";
				}
				else {
					if (j == 0 || j == sizeVec - 1) {
						arenaVector[i][j] = "*";
					}
					else {
						if (arenaVector[i][j] != "#" && arenaVector[i][j] != "X") {
							arenaVector[i][j] = " ";
						}
					}
				}
				if (getCoordTrackX() == j && getCoordTrackY() == i) {
					arenaVector[i][j] = getSymbolTrack();
				}
				if (getCoordBotTrackX() == j && getCoordBotTrackY() == i) {
					arenaVector[i][j] = getSymbolBotTrack();
				}

				if (getCoordX() == j && getCoordY() == i) {
					if (arenaVector[i][j] == "*") {
						throw 20;
					}
					else if (arenaVector[i][j] == getSymbolTrack() || arenaVector[i][j] == getSymbolBotTrack()) {
						throw 50;
					}
					else {
						arenaVector[i][j] = getSymbolBike();
					}
				}
				if (getBotCoordX() == j && getBotCoordY() == i) {
					if (arenaVector[i][j] == getSymbolBotTrack() || arenaVector[i][j] == "*" || arenaVector[i][j] == getSymbolTrack()) {
						throw 100;
					}
					else if (arenaVector[i][j] == getSymbolBike()) {
						throw 70;
					}
					else {
						arenaVector[i][j] = getSymbolBotBike();
					}
					if ((arenaVector[getBotCoordY() + 1][j] == "#" && arenaVector[i][getBotCoordX() + 1] == "#")
						|| (arenaVector[getBotCoordY() + 1][j] == "*" && arenaVector[i][getBotCoordX() + 1] == "*")
						|| (arenaVector[getBotCoordY() + 1][j] == "#" && arenaVector[i][getBotCoordX() + 1] == "*")
						|| (arenaVector[getBotCoordY() + 1][j] == "*" && arenaVector[i][getBotCoordX() + 1] == "#")
						|| (arenaVector[getBotCoordY() + 1][j] == "X" && arenaVector[i][getBotCoordX() + 1] == "X")) {
						if (getBotDirection() == "right") {
							this->flagBot = 0;
							this->flagMindBot = 0;
						}
						if (getBotDirection() == "down") {
							this->flagBot = 0;
							this->flagMindBot = 0;
						}
					}
					else if ((arenaVector[getBotCoordY() - 1][j] == "#" && arenaVector[i][getBotCoordX() - 1] == "#")
						|| (arenaVector[getBotCoordY() - 1][j] == "*" && arenaVector[i][getBotCoordX() - 1] == "*")
						|| (arenaVector[getBotCoordY() - 1][j] == "#" && arenaVector[i][getBotCoordX() - 1] == "*")
						|| (arenaVector[getBotCoordY() - 1][j] == "*" && arenaVector[i][getBotCoordX() - 1] == "#")
						|| (arenaVector[getBotCoordY() - 1][j] == "X" && arenaVector[i][getBotCoordX() - 1] == "X")) {
						if (getBotDirection() == "left") {
							this->flagBot = 0;
							this->flagMindBot = 1;
						}
						if (getBotDirection() == "up") {
							this->flagBot = 0;
							this->flagMindBot = 1;
						}
					}
					else if ((arenaVector[getBotCoordY() + 1][j] == "#" && arenaVector[i][getBotCoordX() - 1] == "#")
						|| (arenaVector[getBotCoordY() + 1][j] == "*" && arenaVector[i][getBotCoordX() - 1] == "*")
						|| (arenaVector[getBotCoordY() + 1][j] == "#" && arenaVector[i][getBotCoordX() - 1] == "*")
						|| (arenaVector[getBotCoordY() + 1][j] == "*" && arenaVector[i][getBotCoordX() - 1] == "#")
						|| (arenaVector[getBotCoordY() + 1][j] == "X" && arenaVector[i][getBotCoordX() - 1] == "X")) {
						if (getBotDirection() == "left") {
							this->flagBot = 0;
							this->flagMindBot = 0;
						}
						if (getBotDirection() == "down") {
							this->flagBot = 0;
							this->flagMindBot = 1;
						}
					}
					else if ((arenaVector[getBotCoordY() - 1][j] == "#" && arenaVector[i][getBotCoordX() + 1] == "#")
						|| (arenaVector[getBotCoordY() - 1][j] == "*" && arenaVector[i][getBotCoordX() + 1] == "*")
						|| (arenaVector[getBotCoordY() - 1][j] == "#" && arenaVector[i][getBotCoordX() + 1] == "*")
						|| (arenaVector[getBotCoordY() - 1][j] == "*" && arenaVector[i][getBotCoordX() + 1] == "#")
						|| (arenaVector[getBotCoordY() - 1][j] == "X" && arenaVector[i][getBotCoordX() + 1] == "X")) {
						if (getBotDirection() == "up") {
							this->flagBot = 0;
							this->flagMindBot = 0;
						}
						if (getBotDirection() == "right") {
							this->flagBot = 0;
							this->flagMindBot = 1;
						}
						
					}
					else if (arenaVector[getBotCoordY() + 1][j] == "#" || arenaVector[getBotCoordY() + 1][j] == "X" || arenaVector[getBotCoordY() + 1][j] == "*") {
						if (getBotDirection() == "down") {
							this->flagBot = 0;
							this->flagMindBot = 1;
						}
						else if (getBotDirection() == "up" || arenaVector[getBotCoordY() + 1][j] == "X") {}
						else {
							this->flagBot = 2;
							this->flagMindBot = 2;
						}
					}
					else if (arenaVector[getBotCoordY() - 1][j] == "#" || arenaVector[getBotCoordY() - 1][j] == "X" || arenaVector[getBotCoordY() - 1][j] == "*") {
						if (getBotDirection() == "up") {
							this->flagBot = 0;
							this->flagMindBot = 0;
						}
						else if (getBotDirection() == "down" || arenaVector[getBotCoordY() - 1][j] == "X") {}
						else {
							this->flagBot = 2;
							this->flagMindBot = 2;
						}
					}
					else if (arenaVector[i][getBotCoordX() + 1] == "#" || arenaVector[i][getBotCoordX() + 1] == "X" || arenaVector[i][getBotCoordX() + 1] == "*") {
						if (getBotDirection() == "right") {
							this->flagBot = 0;
							this->flagMindBot = 0;
						}
						else if (getBotDirection() == "left" || arenaVector[i][getBotCoordX() + 1] == "X") {}
						else {
							this->flagBot = 2;
							this->flagMindBot = 2;
						}
					}
					else if (arenaVector[i][getBotCoordX() - 1] == "#" || arenaVector[i][getBotCoordX() - 1] == "X" || arenaVector[i][getBotCoordX() - 1] == "*") {
						if (getBotDirection() == "left") {
							this->flagBot = 0;
							this->flagMindBot = 0;
						}
						else if (getBotDirection() == "right" || arenaVector[i][getBotCoordX() - 1] == "X") {}
						else {
							this->flagBot = 2;
							this->flagMindBot = 2;
						}
					}
					else {
						this->flagBot = 1;
						this->flagMindBot = 1;
					}
				}
			}
		}
	}
	void showArena() {
		system("cls");
		for (int i = 0; i < sizeVec; i++) {
			for (int j = 0; j < sizeVec; j++) {
				cout << arenaVector[i][j];
			}
			cout << endl;
		}
	}
	int getFlagBot() {
		return this->flagBot;
	}
	int getFlagMindBot() {
		return this->flagMindBot;
	}
};

void error(string errorText) {
	cout << "\n------------------------------------------\n   " << errorText << "\n------------------------------------------\n";
}

int main()
{
	try
	{
		setlocale(0, "rus");
		srand(time(0));

		int mindBot = 1, flagBot = 1;

		cout << "Правила:\nЕсли мотоцикл (v) коснётся стены (*), то игра окончится.\n" <<
			"Также за байком тянется след (#), коснувшись которого игра закончится.\nУправление на WASD.\n" <<
			"\nВсё ясно? Нажимай на Enter.\n";

		bool flagStart = false, flagGame = false;
		while (flagStart == false) {
			int pressStart = _getch();
			if (pressStart == 13) {
				flagStart = true;
			}
		}

		Arena obj;
		obj.makeArena();
		obj.showArena();

		while (flagGame == false) {
			flagBot = obj.getFlagMindBot();
			mindBot = obj.getFlagBot();
			if (_kbhit()) {
				obj.directionBike((int)_getch());
			}
			obj.mindBot(mindBot, flagBot);
			obj.moveBike();
			obj.moveBot();
			obj.makeArena();
			obj.showArena();
			flagBot = 1;
			mindBot = 0;
		}
	}

	catch (const int endNumber)
	{
		if (endNumber == 20) {
			system("cls");
			error("\nНу коснулись стены, игра окончена!\n");
		}
		else if (endNumber == 50) {
			system("cls");
			error("\nНу коснулись следа, игра окончена!\n");
		}
		else if (endNumber == 70) {
			system("cls");
			error("\nНичья! Ваши байки взорвались!\n");
		}
		else if (endNumber == 100) {
			system("cls");
			error("\nПротивник погиб! Победа!\n");
		}
		else {
			system("cls");
			error("\nЧто-то пошло не так!\n");
		}
	}
}

