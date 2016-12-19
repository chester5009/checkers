/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Actions.h
 * Author: chester
 *
 * Created on 18 декабря 2016 г., 15:30
 */

#ifndef ACTIONS_H
#define ACTIONS_H

#include "Cell.h"
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;
class Actions {
public:
    Actions();
    Actions(const Actions& orig);
    virtual ~Actions();
    
    int x1,x2,y1,y2;
    void stepInput(char* input);
    void stepAction(vector<Cell>*field);
    void setCellValue(int i,int  value,vector<Cell>*field);
    int getIndexByCoord(int x,int y,vector<Cell>*field);
    bool checkOnEat(int team,vector<Cell>*field); //4-black 2- white
    void ai(vector<Cell>*field);
    bool stepAi(int x1,int y1,int x2,int y2,vector<Cell>*field);
private:
    
};

#endif /* ACTIONS_H */

