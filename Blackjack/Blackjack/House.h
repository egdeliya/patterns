#pragma once

#ifndef _HEADER_H
#define _HEADER_H

#include "Header.h"
#endif

#include "GenericPlayer.h"

class House: public GenericPlayer {
	public:
		House(const string& name="House");
		virtual ~House();
		
		// показывает, хочет ли дилер продолжать брать карты
		virtual bool isHitting() const override;

		// переворачивает первую карту
		void flipFirstCard();
};

inline House::House(const string& name): GenericPlayer(name) {}

inline House::~House() {}

inline bool House::isHitting() const {
	return (getTotal() <= 16);
}

inline void House::flipFirstCard() {
	if (!cards_.empty())
		cards_[0]->flip();
	else
		cout << "No card to flip!\n";
}


