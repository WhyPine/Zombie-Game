#pragma once
#include "save.h"
#include <fstream>
#include <string>

class savefiles {
public:
	save files[3];
	savefiles();
};

savefiles::savefiles() {
	bool newPlayer;
	double damageP;
	int health;
	int bulletAdd;
	double regenM;
	std::fstream file;
	file.open("save1.txt", std::ios::in);
	std::string line;
	getline(file, line);
	if (line.compare("True")) {
		newPlayer = true;
	}
	else { newPlayer = false; }
	getline(file, line);
	damageP = stod(line);
	getline(file, line);
	health = stoi(line);
	getline(file, line);
	bulletAdd = stoi(line);
	getline(file, line);
	regenM = stod(line);
	save save1(newPlayer, damageP, health, bulletAdd, regenM);
	files[0] = save1;
	file.close();
	file.open("save2.txt", std::ios::in);
	getline(file, line);
	if (line.compare("True")) {
		newPlayer = true;
	}
	else { newPlayer = false; }
	getline(file, line);
	damageP = stod(line);
	getline(file, line);
	health = stoi(line);
	getline(file, line);
	bulletAdd = stoi(line);
	getline(file, line);
	regenM = stod(line);
	save save2(newPlayer, damageP, health, bulletAdd, regenM);
	files[1] = save2;
	file.close();
	file.open("save3.txt", std::ios::in);
	getline(file, line);
	if (line.compare("True")) {
		newPlayer = true;
	}
	else { newPlayer = false; }
	getline(file, line);
	damageP = stod(line);
	getline(file, line);
	health = stoi(line);
	getline(file, line);
	bulletAdd = stoi(line);
	getline(file, line);
	regenM = stod(line);
	save save3(newPlayer, damageP, health, bulletAdd, regenM);
	files[2] = save3;
	file.close();
}