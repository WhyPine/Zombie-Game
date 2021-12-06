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
	save(bool newPlayer, double damageP, int health, int bulletAdd, double regenM);
	save();
};

save::save() {
	this->newPlayer = false;
	this->damageP = 0.0;
	this->health = 0;
	this->bulletAdd = 0;
	this->regenM = 0.0;
}

save::save(bool newPlayer, double damageP, int health, int bulletAdd, double regenM) {
	this->newPlayer = newPlayer;
	this->damageP = damageP;
	this->health = health;
	this->bulletAdd = bulletAdd;
	this->regenM = regenM;
}