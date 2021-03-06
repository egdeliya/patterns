#pragma once

#ifndef _HEADER_H
#define _HEADER_H

#include "Header.h"
#endif

#ifndef _HAND_H
#define _HAND_H
  #include "Hand.h"
#endif


class GenericPlayer: public Hand {
	friend ostream& operator<<(ostream& os, const GenericPlayer& generic_player);
	public:
		GenericPlayer(const string& name="");
		virtual ~GenericPlayer();

		// показывает, хочет ли игрок продолжать брать карты
		virtual bool isHitting() const = 0;

		// возвращает значение, если игрок имеет перебор
		bool isBusted() const;

		// объявляет, что игрок имеет перебор
		void Bust() const;

	protected:
		string name_;
};

inline GenericPlayer::GenericPlayer(const string& name): name_(name) {}

inline GenericPlayer::~GenericPlayer() {}

inline bool GenericPlayer::isBusted() const {
	return (getTotal() > 21);	
}

inline void GenericPlayer::Bust() const {
	cout << name_ << " busts.\n";
}

inline ostream& operator<<(ostream& os, const GenericPlayer& generic_player) {
	os << generic_player.name_ << ":\t";
	vector<Card*>::const_iterator card;
	if (!generic_player.cards_.empty())
		for (card = generic_player.cards_.begin(); 
			card != generic_player.cards_.end(); 
			++ card)
			os << *(*card) << "\t";
		if (generic_player.getTotal() != 0)
			cout << "(" << generic_player.getTotal() << ")";
	else
		os << "empty\n";
	return os;
}



