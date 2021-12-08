#pragma once
#include "save.h"
#include <fstream>
#include <string>

class savefiles {
public:
	save files[3];
	savefiles() {
		bool newPlayer;
		double damageP;
		int health;
		int bulletAdd;
		double regenM;
		double speedM;
		int skillPoints;
		int totalSkillPoints;
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
		speedM = stoi(line);
		getline(file, line);
		bulletAdd = stoi(line);
		getline(file, line);
		regenM = stod(line);
		getline(file, line);
		skillPoints = stoi(line);
		getline(file, line);
		totalSkillPoints = stoi(line);
		save save1(newPlayer, damageP, health, bulletAdd, regenM, speedM, skillPoints, totalSkillPoints);
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
		speedM = stoi(line);
		getline(file, line);
		bulletAdd = stoi(line);
		getline(file, line);
		regenM = stod(line);
		getline(file, line);
		skillPoints = stoi(line);
		getline(file, line);
		totalSkillPoints = stoi(line);
		save save2(newPlayer, damageP, health, bulletAdd, regenM, speedM, skillPoints, totalSkillPoints);
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
		speedM = stoi(line);
		getline(file, line);
		bulletAdd = stoi(line);
		getline(file, line);
		regenM = stod(line);
		getline(file, line);
		skillPoints = stoi(line);
		getline(file, line);
		totalSkillPoints = stoi(line);
		save save3(newPlayer, damageP, health, bulletAdd, regenM, speedM, skillPoints, totalSkillPoints);
		files[2] = save3;
		file.close();
	}
	void saveToFile() {
		std::fstream file;
		file.open("save1.txt", std::ios::out);
		file << files[0].newPlayer << std::endl;
		file << files[0].damageP << std::endl;
		file << files[0].health << std::endl;
		file << files[0].speedM << std::endl;
		file << files[0].bulletAdd << std::endl;
		file << files[0].regenM << std::endl;
		file << files[0].skillPoints << std::endl;
		file << files[0].totalSkillPoints;
		file.close();
		file.open("save2.txt", std::ios::out);
		file << files[1].newPlayer << std::endl;
		file << files[1].damageP << std::endl;
		file << files[1].health << std::endl;
		file << files[1].speedM << std::endl;
		file << files[1].bulletAdd << std::endl;
		file << files[1].regenM << std::endl;
		file << files[1].skillPoints << std::endl;
		file << files[1].totalSkillPoints;
		file.close();
		file.open("save3.txt", std::ios::out);
		file << files[2].newPlayer << std::endl;
		file << files[2].damageP << std::endl;
		file << files[2].health << std::endl;
		file << files[2].speedM << std::endl;
		file << files[2].bulletAdd << std::endl;
		file << files[2].regenM << std::endl;
		file << files[2].skillPoints << std::endl;
		file << files[2].totalSkillPoints;
		file.close(); 
	}
};

