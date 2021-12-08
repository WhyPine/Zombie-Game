#pragma once

class save
{
private:

public:
	bool newPlayer;
	double damageP;
	int health;
	int bulletAdd;
	double regenM;
	double speedM;
	int skillPoints;
	int totalSkillPoints;
	save() {
		this->newPlayer = false;
		this->damageP = 1.0;
		this->health = 20;
		this->bulletAdd = 0;
		this->regenM = 1.0;
		this->speedM = 1.0;
		this->skillPoints = 0;
		this->totalSkillPoints = 0;
	}

	save(bool newPlayer, double damageP, int health, int bulletAdd, double regenM, double speedM, int skillPoints, int totalSkillPoints) {
		this->newPlayer = newPlayer;
		this->damageP = damageP;
		this->health = health;
		this->bulletAdd = bulletAdd;
		this->regenM = regenM;
		this->speedM = speedM;
		this->skillPoints = skillPoints;
		this->totalSkillPoints = totalSkillPoints;
	}

	void resetSkillPoints() {
		this->damageP = 1.0;
		this->health = 20;
		this->bulletAdd = 0;
		this->regenM = 1.0;
		this->speedM = 1.0;
		this->skillPoints = this->totalSkillPoints;
	}
};

