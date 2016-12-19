
#include "GameManager.h"
#include "Actions.h"

GameManager::GameManager() {
    this->actions=Actions();
    isGame=false;
    createField();
}



GameManager::~GameManager() {
    
}

void GameManager::render(){
    string row="";
    for(int i=0;i<field->size();i++){
        int v=field->at(i).value;
        
        char cell=' ';
        if(v==0){
            cell='.';
        }
        if(v==1){
            cell='-';
        }
        if(v==2){
            cell='w';
        }
        if(v==3){
            cell='W';
        }
        if(v==4){
            cell='b';
        }
        if(v==5){
            cell='B';
        }
        row+=cell;
        if(row.size()==8){
            cout<<row<<endl;
            row="";
        }
    }
}

void GameManager::input(){
    char*input=new char[100];
    cin>>input;
    actions.stepInput(input);
    actions.stepAction(field);
    //cout<<actions.checkOnEat(4,field)<<endl;
}

void GameManager::update(){
    
}

void GameManager::gameCycle(){
    while(isGame){
        render();
        input();
        update();
        //isGame=false;
    }
}

void GameManager::createField() {
    
   
    for(int i=0;i<8;i++){
        int val;
        if(i==0 || i%2==0){
            val=0;
        }
        else{
            val=1;
        }
        for(int j=0;j<8;j++){
            //cout<<val<<endl;
            Cell newCell=Cell(j,i,val);
            if(val==1) {val=0;}
            else if(val==0) {val=1;}
            field->push_back(newCell);
            
        }
    }
    //set checkers
    for(int i=0;i<field->size();i++){
        int row=field->at(i).y;
        int col=field->at(i).x;
        if(field->at(i).value==1){
            if(row<3){
                field->at(i).value=4;
            }
            else if( row >4){
                field->at(i).value=2;
            }
        }
    }
    isGame=true;
}

