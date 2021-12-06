#include "buyBox.h"

buyBox::buyBox(float x, float y, int newPrice, int newType) : wall(x, y, 64, 32) {

	this->type = newType;
	if (this->type == 0) {
		this->name = "Pistol";
		if (!boxTexture.loadFromFile("pistolbox.png")) {
			std::cout << "Pistol Box texture failed to load" << std::endl;
		}
	}
	else if (this->type == 1) {
		this->name = "Rifle";
		if (!boxTexture.loadFromFile("riflebox.png")) {
			std::cout << "Rifle Box texture failed to load" << std::endl;
		}
	}
	else if (this->type == 2) {
		this->name = "Shotgun";
		if (!boxTexture.loadFromFile("shotgunbox.png")) {
			std::cout << "Shotgun Box texture failed to load" << std::endl;
		}
	}
	else if (this->type == 3) {
		this->name = "HellFire Launcher";
		if (!boxTexture.loadFromFile("shotgunbox.png")) {
			std::cout << "Hell Fire Launcher box texture failed to load" << std::endl;
		}
	}
	else if (this->type == 11) {
		this->name = "Second Wind";
		if (!boxTexture.loadFromFile("swBox.png")) {
			std::cout << "Second Wind box texture failed to load";
		}
	}
	else if (this->type == 12) {
		this->name = "Contingency Response";
		if (!boxTexture.loadFromFile("rbBox.png")) {
			std::cout << "Contingenct Response box texture failed to load";
		}
	}
	else if (this->type == 13) {
		this->name = "Hollow Point Rounds";
		if (!boxTexture.loadFromFile("ddBox.png")) {
			std::cout << "Hollow Point box texture failed to load";
		}
	}
	else if (this->type == 14) {
		this->name = "Extended Mag";
		if (!boxTexture.loadFromFile("dmBox.png")) {
			std::cout << "Extended Mag box texture failed to load";
		}
	}

	this->box = new sf::RectangleShape(sf::Vector2f((float)this->walls->width / 4800, (float)this->walls->height / 4800));
	this->box->setPosition(x, y);
	this->box->setSize(sf::Vector2f(64, 32));
	this->boxPrice = newPrice;
	this->box->setTexture(&boxTexture);
	this->lastBought = 0;
}

bool buyBox::canBuy(Player& p1) {
	bool result = false;
	float x1 = this->walls->left + this->walls->width / 2;
	float y1 = this->walls->top + this->walls->height / 2;
	//if they're close enough
	if (sqrt(pow(p1.getPosition().x - x1, 2) + pow(p1.getPosition().y - y1, 2)) < 64 && clock() - lastBought > 5000) {
		result = true;
		//checking if the player already has the item being sold
		if (this->type == 0) {
			std::cout << "Type 0" << std::endl;
			if (p1.getGun()->getMaxReload() == 12 || p1.getGun()->getMaxReload() == 24) {
				result = false; //pistol
			}
		}
		else if (this->type == 1) {
			std::cout << "Type 1" << std::endl;
			if (p1.getGun()->getMaxReload() == 30 || p1.getGun()->getMaxReload() == 60) {
				result = false; //rifle
			}
		}
		else if (this->type == 2) {
			std::cout << "Type 2" << std::endl;
			if (p1.getGun()->getMaxReload() == 6 || p1.getGun()->getMaxReload() == 14) {
				result = false; //shotgun
			}
		}
		else if (this->type == 3) {
			std::cout << "Type 3" << std::endl;
			if (p1.getGun()->getMaxReload() == 2 || p1.getGun()->getMaxReload() == 5) {
				result = false; //rocket
			}
		}
		//if (this->type == 4) if (p1.getGun()->getMaxReload() == 36 || p1.getGun()->getMaxReload() == 72) result = false; //burst
		//if (this->type == 5) if (p1.getGun()->getMaxReload() == 4 || p1.getGun()->getMaxReload() == 10) result = false; //sniper
		else if (this->type == 11) {
			if (p1.getSecondWind()) {
				result = false;
			}
		}
		else if (this->type == 12) {
			if (p1.getReloadBoom()) {
				result = false;
			}
		}
		else if (this->type == 13) {
			if (p1.getDoubleDamage()) {
				result = false;
			}
		}
		else if (this->type == 14) {
			if (p1.getDoubleMag()) {
				result = false;
			}
		}
	}
	return result;
}


void buyBox::buy(Player& p1) {

	//std::cout << clock() - lastBought << std::endl;

	if (this->type == 0) {
		if (p1.setGun(new Gun(p1.getPosition(), p1.getSize(), p1.getBulletHealth()))) {
			p1.setMoney(p1.getMoney() - this->boxPrice);
		}
	}
	else if (this->type == 1) {
		if (p1.setGun(new Rifle(p1.getPosition(), p1.getSize(), p1.getBulletHealth()))) {
			p1.setMoney(p1.getMoney() - this->boxPrice);
		}
	}
	else if (this->type == 2) {
		if (p1.setGun(new Shotgun(p1.getPosition(), p1.getSize(), p1.getBulletHealth()))) {
			p1.setMoney(p1.getMoney() - this->boxPrice);
		}
	}
	else if (this->type == 3) {
		if (p1.setGun(new RPG(p1.getPosition(), p1.getSize(), p1.getBulletHealth()))) {
			p1.setMoney(p1.getMoney() - this->boxPrice);
		}
	}
	else if (this->type == 11) {
		if (!p1.getSecondWind()) {
			p1.setSecondWind(true);
			p1.setMoney(p1.getMoney() - this->boxPrice);
		}
	}
	else if (this->type == 12) {
		if (!p1.getReloadBoom()) {
			p1.setReloadBoom(true);
			p1.setMoney(p1.getMoney() - this->boxPrice);
		}
	}
	else if (this->type == 13) {
		if (!p1.getDoubleDamage()) {
			p1.setDoubleDamage(true);
			p1.setMoney(p1.getMoney() - this->boxPrice);
		}
	}
	else if (this->type == 14) {
		if (!p1.getDoubleMag()) {
			p1.setDoubleMag(true);
			p1.setMoney(p1.getMoney() - this->boxPrice);
		}
	}
	lastBought = clock();

}

void buyBox::drawBox(sf::RenderWindow& window) {
	window.draw(*this->box);
}

std::string buyBox::getName() {
	return this->name;
}

int buyBox::getPrice() {
	return this->boxPrice;
}