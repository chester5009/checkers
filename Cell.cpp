

#include "Cell.h"

Cell::Cell(int x,int y, int val) {
    this->x=x;
    this->y=y;
    this->value=val;
}



Cell::~Cell() {
}

void Cell::setValue(int val) {
    this->value=val;
}

