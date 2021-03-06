#pragma once

#ifndef _HEADER_H
#define _HEADER_H
#include "Header.h"
#endif

#include "Deck.h"
#include "House.h"
#include "Player.h"

class Game {
	public:
		Game(const vector<string>& names);
		~Game();

		// механизм игры Blackjack
		void play();
	private:
		Deck deck_;
		House house_;
		vector<Player> players_;
};

inline Game::Game(const vector<string>& names) {
	// создает вектор игроков из вектора с именами
	vector<string>::const_iterator iter;
	for (iter = names.begin() ; iter != names.end(); ++iter) {
		players_.push_back(Player(*iter));
	}
	// запускает генератор случайных чисел
	srand(static_cast<unsigned int>(time(nullptr)));
	deck_.populate();
	deck_.shuffle();
}

inline Game::~Game() {}

inline void Game::play() {
	// раздаёт каждому игроку по две стартовые карты
	vector<Player>::iterator player;
	for (size_t i = 0; i < 2; i++) {
		for (player = players_.begin(); player != players_.end(); ++player)
			deck_.deal(*player);
		deck_.deal(house_);
	}

	// прячет первую карту дилера
	house_.flipFirstCard();

	// открывает руки всех игроков
	for (player = players_.begin(); player != players_.end(); ++ player)
		cout << *player << endl;

	// раздаёт игрокам дополнительные карты
	for (player = players_.begin(); player != players_.end(); ++player)
		deck_.additionalCards(*player);

	// показывает первую карту дилера
	house_.flipFirstCard();
	cout << house_ << endl;

	// раздаёт дилеру дополнительные карты
	deck_.additionalCards(house_);
	if (house_.isBusted()) {
		// все, кто остался в игре - побеждают
		for (player = players_.begin(); player != players_.end(); ++player)
			if (! player->isBusted())
				player->win();
	} else { 
		// сравниваем сумму очков всех оставшихся с суммой очков дилера
		for (player = players_.begin(); player != players_.end(); ++player) 
			if (!player->isBusted()) {
				if (player->getTotal() > house_.getTotal()) {
					player->win();
				} else {
					if (player->getTotal() < house_.getTotal()) {
						player->lose();
					} else {
						player->push();
					}
				}
			} else {
				player->lose();
			}
	}

	// очищает руки всех игроков
	for (player = players_.begin(); player != players_.end(); ++player)
		player->clear();
	house_.clear();	
}




