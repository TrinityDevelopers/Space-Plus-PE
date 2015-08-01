#include "IDGenSP.h"

int IDGenSP::ID = 0;

int IDGenSP::findNextItemID() {
	while(Item::items[IDGenSP::ID + 256] != NULL) {
		IDGenSP::ID++;
	}
	return IDGenSP::ID;
}
