#include "IDGenSP.h"

int IDGenSP::ID = 256;

int IDGenSP::findNextItemID() {
	while(Item::items[IDGenSP::ID] != NULL) {
		IDGenSP::ID++;
	}
	return IDGenSP::ID - 256;
}
