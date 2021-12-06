#include "buyBox.h"

bool buyBox::canBuy(Player& p1) {
	bool result = false;
	float x1 = this->walls->left + this->walls->width / 2;
	float y1 = this->walls->top + this->walls->height / 2;
	if (sqrt(pow(p1.getPosition().x - x1, 2) + pow(p1.getPosition().y - y1, 2)) < 64 && clock()-lastBought > 5000) {
		result = true;
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