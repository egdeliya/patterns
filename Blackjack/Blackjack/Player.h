#pragma once

#ifndef _HEADER_H
#define _HEADER_H

#include "Header.h"
#endif

#include "GenericPlayer.h"

class Player: public GenericPlayer {
	public:
		explicit Player(const string& name="Player");
		virtual ~Player();

		// показывает, хочет ли игрок брать карты
		virtual bool isHitting() const override;

		// объявляет, что игрок победил
		void win() const;

		// объявляет, что игрок проиграл
		void lose() const;

		// объявляет ничью
		void push() const;
};

inline Player::Player(const string& name): GenericPlayer(name) {}

inline Player::~Player() {}

inline bool Player::isHitting() const {
	cout << name_ << ", do you want to hit? (Y/N): ";
	char response;
	cin >> response;
	return (response == 'Y' || response == 'y');
}

inline void Player::win() const {
	cout << name_ << " wins!\n";
}

inline void Player::lose() const {
	cout << name_ << "loses :(\n";
}

inline void Player::push() const {
	cout << name_ << " pushes\n";
}






