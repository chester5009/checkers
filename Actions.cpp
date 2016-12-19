
#include <cstdlib>
#include <string.h>

#include "Actions.h"


Actions::Actions() {
    x1=-1;
    y1=-1;
    x2=-1;
    y2=-1;
}

Actions::Actions(const Actions& orig) {
}

Actions::~Actions() {
}

void Actions::stepInput(char* input) {
    cout<<"inp "<<input<<endl;
    char *inp=input;
    for (int i=0;i<strlen(inp);i++){
        if(inp[i]==' '){
            inp[i]='_';
        }
    }
    
    x1=inp[0]-48;
    y1=inp[1]-48;
    x2=inp[3]-48;
    y2=inp[4]-48;
    

    cout<<x1<<" ";
    cout<<y1<<" ";
    cout<<x2<<" ";
    cout<<y2<<" \n";
}

void Actions::setCellValue(int i, int value,vector<Cell>*field) {
    field->at(i).value=value;
}

int Actions::getIndexByCoord(int x, int y, vector<Cell>* field) {
    for(int i=0;i<field->size();i++){
        if(field->at(i).x==x && field->at(i).y==y){
            return i;
        }
    }
    return -1;
}

void Actions::ai(vector<Cell>*field) {
    bool step=false;
    vector<int>*blacks=new vector<int>();
    for(int i=0;i<field->size();++i){
            if(field->at(i).value==1){
                blacks->push_back(i);
            }
        }
    while(!step){
        
        //int i=rand()%blacks.size();
        //Cell cell=field.at(i);
         
        
    }
}


bool Actions::stepAi(int x1,int y1,int x2,int y2 ,vector<Cell>*field) {
    Cell *start,*finish;
    int indexOnField1=-1;
    int indexOnField2=-1;
    int dx=-10,dy=-10;
    for(int i=0;i<field->size();i++){
        if(field->at(i).x==x1 && field->at(i).y==y1){
           start=&field->at(i);
           indexOnField1=i;
        }
        if(field->at(i).x==x2 && field->at(i).y==y2){
           finish=&field->at(i);
           indexOnField2=i;
        }
    }
    cout<<"indeces "<<indexOnField1<<" "<<indexOnField2<<endl;
    if(finish->value==1){ // если конечная клетка пустая черная
        
        if(start->value==2){ // шашка белая
            
            if(start->y-1==finish->y && abs(start->x-finish->x)==1){// ходит
                setCellValue(indexOnField1,1,field);
                setCellValue(indexOnField2,2,field);
                cout<<"STEP"<<endl;
            }
            if(start->y-2==finish->y && abs(start->x-finish->x)==2){ // ест
                
                dx=(finish->x-start->x)/2;
                dy=(finish->y-start->y)/2;
                int indexOfMiddleCell=getIndexByCoord(start->x+dx,start->y+dy,field);
                int val=field->at(indexOfMiddleCell).value;
                if(val==4 || val==5){
                    setCellValue(indexOnField1,1,field);
                    setCellValue(indexOfMiddleCell,1,field);
                    setCellValue(indexOnField2,2,field);
                }
                
            }
           
        }else if(start->value==3){// дамка белая
            if(abs(start->y-finish->y)==1 && abs(start->x-finish->x)==1){// ходит
                setCellValue(indexOnField1,1,field);
                setCellValue(indexOnField2,2,field);
                cout<<"STEP"<<endl;
            }
            if(abs(start->y-finish->y)==2 && abs(start->x-finish->x)==2){ // ест
                
                dx=(finish->x-start->x)/2;
                dy=(finish->y-start->y)/2;
                int indexOfMiddleCell=getIndexByCoord(start->x+dx,start->y+dy,field);
                int val=field->at(indexOfMiddleCell).value;
                if(val==4 || val==5){
                    setCellValue(indexOnField1,1,field);
                    setCellValue(indexOfMiddleCell,1,field);
                    setCellValue(indexOnField2,2,field);
                }
                
            }
        } 
    }
}


bool Actions::checkOnEat(int team,vector<Cell>*field) {
    int dx=10,dy=10;
    Cell *start,*finish,*middle;
    int opponent=-1;
    if(team==4){
        dy=1;
        opponent=2;
    }else if(team==2){
        dy=-1;
        opponent=4;
    }
    for(int i=0;i<field->size();++i){   // для шашки
        if(field->at(i).value==team){
            start=&field->at(i);
            for(int j=0;j<field->size();++j){
                if(abs(field->at(j).x-start->x)==1 && field->at(j).y-start->y==dy){
                    middle=&field->at(j);
                    if(middle->value=opponent){
                        for(int m=0;m<field->size();++m){
                        if(abs(field->at(j).x-middle->x)==1 && field->at(j).y-middle->y==dy*2){
                                finish=&field->at(m);
                                if(finish->value==1){
                                    return true;
                                }
                           }
                        } 
                    }
                    
                }
            }
        }
        else if(field->at(i).value==team+1){  //для дамки
            start=&field->at(i);
            for(int j=0;j<field->size();++j){
                if(abs(field->at(j).x-start->x)==1 && abs(field->at(j).y-start->y)==dy){
                    middle=&field->at(j);
                    if(middle->value=opponent){
                        for(int m=0;m<field->size();++m){
                        if(abs(field->at(j).x-middle->x)==1 && abs(field->at(j).y-middle->y)==dy*2){
                                finish=&field->at(m);
                                if(finish->value==1){
                                    return true;
                                }
                           }
                        } 
                    }
                    
                }
            }
        }
    }
    return false;
}



void Actions::stepAction(vector<Cell>*field) {
    Cell *start,*finish;
    int indexOnField1=-1;
    int indexOnField2=-1;
    int dx=-10,dy=-10;
    for(int i=0;i<field->size();i++){
        if(field->at(i).x==x1 && field->at(i).y==y1){
           start=&field->at(i);
           indexOnField1=i;
        }
        if(field->at(i).x==x2 && field->at(i).y==y2){
           finish=&field->at(i);
           indexOnField2=i;
        }
    }
    cout<<"indeces "<<indexOnField1<<" "<<indexOnField2<<endl;
    if(finish->value==1){ // если конечная клетка пустая черная
        
        if(start->value==2){ // шашка белая
            
            if(start->y-1==finish->y && abs(start->x-finish->x)==1){// ходит
                setCellValue(indexOnField1,1,field);
                setCellValue(indexOnField2,2,field);
                cout<<"STEP"<<endl;
            }
            if(start->y-2==finish->y && abs(start->x-finish->x)==2){ // ест
                
                dx=(finish->x-start->x)/2;
                dy=(finish->y-start->y)/2;
                int indexOfMiddleCell=getIndexByCoord(start->x+dx,start->y+dy,field);
                int val=field->at(indexOfMiddleCell).value;
                if(val==4 || val==5){
                    setCellValue(indexOnField1,1,field);
                    setCellValue(indexOfMiddleCell,1,field);
                    setCellValue(indexOnField2,2,field);
                }
                
            }
           
        }else if(start->value==3){// дамка белая
            if(abs(start->y-finish->y)==1 && abs(start->x-finish->x)==1){// ходит
                setCellValue(indexOnField1,1,field);
                setCellValue(indexOnField2,2,field);
                cout<<"STEP"<<endl;
            }
            if(abs(start->y-finish->y)==2 && abs(start->x-finish->x)==2){ // ест
                
                dx=(finish->x-start->x)/2;
                dy=(finish->y-start->y)/2;
                int indexOfMiddleCell=getIndexByCoord(start->x+dx,start->y+dy,field);
                int val=field->at(indexOfMiddleCell).value;
                if(val==4 || val==5){
                    setCellValue(indexOnField1,1,field);
                    setCellValue(indexOfMiddleCell,1,field);
                    setCellValue(indexOnField2,2,field);
                }
                
            }
        } 
    }
   
}



