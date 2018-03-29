/*
 * Smalltalk.cpp
 *
 *      Author: Brady
 */

#include "./includes/Smalltalk.h"
#include "./includes/constants.h"


Smalltalk::Smalltalk(std::string myNationality, int iPerson) :
	nationality(myNationality),
	iPerson(iPerson),
	current_phrase(0),
	pWatch(NULL) {

}

Smalltalk::~Smalltalk(void) {

	if (pWatch != NULL) {
		delete pWatch;
		pWatch = NULL;
	}
}

std::string Smalltalk::saySomething() {
	std::string say(nationality + " " + std::to_string(iPerson) + ":");

	if (mySmallTalk.size() > 0) {
		current_phrase = (current_phrase + 1) % mySmallTalk.size();
		say += mySmallTalk[current_phrase];
	}

	return say;
}

std::string Smalltalk::getTime() {

	std::string str(nationality + " " + std::to_string(iPerson) + ":");

	if (pWatch == NULL) {
		str += I_DO_NOT_HAVE_A_WATCH;
	} else {
		str += pWatch->getTime();
	}

	return str;
}

Watch* Smalltalk::takeWatch() {

	Watch* p = this->pWatch;
	if (p != NULL) {
		this->pWatch = NULL;
	}
	return p;
}


bool Smalltalk::giveWatch(Watch * pWatch) {

	if (this->pWatch != NULL) {
		return false;
	} else {
		this->pWatch = pWatch;
		return true;
	}
}
