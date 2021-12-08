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
	save() {
		this->newPlayer = false;
		this->damageP = 1.0;
		this->health = 20;
		this->bulletAdd = 0;
		this->regenM = 1.0;
		this->speedM = 1.0;
		this->skillPoints = 0;
	}

	save(bool newPlayer, double damageP, int health, int bulletAdd, double regenM, double speedM, int skillPoints) {
		this->newPlayer = newPlayer;
		this->damageP = damageP;
		this->health = health;
		this->bulletAdd = bulletAdd;
		this->regenM = regenM;
		this->speedM = speedM;
		this->skillPoints = skillPoints;
	}

	void resetSkillPoints() {
		while (this->damageP != 1.0) {
			this->damageP += 0.1;
			this->skillPoints++;
		}
		while (this->health != 20) {
			this->health -= 2;
			this->skillPoints++;
		}
		while (this->bulletAdd != 0) {
			this->bulletAdd--;
			this->skillPoints += 2;
		}
		while (this->regenM != 1.0) {
			this->regenM += 0.05;
			this->skillPoints++;
		}
		while (this->speedM != 1.0) {
			this->speedM -= 0.1;
			this->skillPoints++;
		}
	}
};

