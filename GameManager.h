#include <vector>
#include <iostream>
#include "Cell.h"
#include "string.h"
#include "stdio.h"
#include "Actions.h"
#include "time.h"

using namespace std;

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

class GameManager {
public:
    GameManager();
    virtual ~GameManager();
    
    bool isGame;
    
    void render();
    void update();
    void input();
    
    
    void gameCycle();
private:
    void createField();
    vector<Cell>*field=new vector<Cell>();
    Actions actions;
};

#endif /* GAMEMANAGER_H */

