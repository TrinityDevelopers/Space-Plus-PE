#include "IDGenSP.h"

int IDGenSP::findNextItemID() {
    int id = 0;
	while(Item::items[id] != NULL) {
		id++;
	}
	return id;
}
