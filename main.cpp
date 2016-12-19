/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chester
 *
 * Created on 18 декабря 2016 г., 12:33
 */

#include <cstdlib>

#include "GameManager.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    GameManager *gm=new GameManager();
    
    gm->gameCycle();
    return 0;
}

