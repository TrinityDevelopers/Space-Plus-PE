#include "IDGenSP.h"

int IDGenSP::findNextItemID() {
    int id = 0;
	while(Item::items[id + 256] == NULL) {
		id++;
	}
	return id;
}
