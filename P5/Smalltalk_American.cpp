/*
 * Smalltalk_American.cpp
 *
 *  Created on: Nov 8, 2017
 *      Author: Brady
 */


#include "./includes/Smalltalk_American.h"
#include "./includes/constants.h"

Smalltalk_American::Smalltalk_American(int iPerson)
	: Smalltalk(AMERICAN, iPerson) {

	populatePhrases();
}

Smalltalk_American::Smalltalk_American(std::string myNationality, int iPerson)
	: Smalltalk(myNationality, iPerson) {
}

Smalltalk_American::~Smalltalk_American(void) {
}

void Smalltalk_American::populatePhrases() {

	mySmallTalk.push_back(AMERICAN_PHRASE_1);
	mySmallTalk.push_back(AMERICAN_PHRASE_2);
	mySmallTalk.push_back(AMERICAN_PHRASE_3);
	mySmallTalk.push_back(AMERICAN_PHRASE_4);
	mySmallTalk.push_back(AMERICAN_PHRASE_5);
}
