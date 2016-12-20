
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

int Actions::getIndexSymb(char c) {
    for(int i=0;i<8;++i){
        if(symbols[i]==c){
            return i;
        }
    }
    return -1;
}

void Actions::stepInput(char* input) {
    cout<<"inp "<<input<<endl;
    char *inp=input;
    char st1,st2,f1,f2;
    st1=inp[0];
    st2=inp[1];
    f1=inp[3];
    f2=inp[4];
    /*for (int i=0;i<strlen(inp);i++){
        cout<<inp[i]<<endl;
        if(inp[i]==' '){
            inp[i]='_';
        }
        if(i==0){
            inp[i]=getIndexSymb(inp[i]);
            cout<<"SWAP "<<i<<" "<<inp[i]<<endl;
        }
        if(i==3){
            inp[i]=getIndexSymb(inp[i]);
            cout<<"SWAP "<<i<<" "<<inp[i]<<endl;
        }
       
    }*/
    
    cout<<"inp "<<input<<endl;
    /*x1=inp[0];
    y1=inp[1]-48;
    x2=inp[3]-97;
    y2=inp[4]-48;*/
    x1=getIndexSymb(st1);
    y1=st2-48;
    x2=getIndexSymb(f1);
    y2=f2-48;
    

    /*cout<<x1<<" ";
    cout<<y1<<" ";
    cout<<x2<<" ";
    cout<<y2<<" \n";*/
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
    cout<<"blacks ";
    for(int i=0;i<field->size();i++){
            if(field->at(i).value==4){
                blacks->push_back(i);
                cout<<i<<" "<<field->at(i).value<<",";
            }
        }
    cout<<endl;
    
    for(int j=0;j<blacks->size();j++){
        Cell *black=&field->at(blacks->at(j));
        cout<<black->value<<endl;
        
        int dx=1; int dy=1;
        int finish=getIndexByCoord(black->x+dx,black->y+dy, field);
        if(finish!=-1){
                Cell end = field->at(finish);
                if(end.value==1){
                    setCellValue(finish,4,field);
                    setCellValue(blacks->at(j),1,field);
                    break;
                }
                finish=getIndexByCoord(black->x-dx,black->y+dy, field);
                if(finish!=-1){
                Cell end = field->at(finish);
                if(end.value==1){
                    setCellValue(finish,4,field);
                    setCellValue(blacks->at(j),1,field);
                    break;
                }
            
            }
        }
    }
    
        
}
    




/*bool Actions::checkOnEat(int team,vector<Cell>*field) {
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
}*/



bool Actions::stepAction(vector<Cell>*field) {
    Cell *start,*finish;
    int indexOnField1=-1;
    int indexOnField2=-1;
    int dx=-10,dy=-10;
    for(int i=0;i<field->size();i++){
        if(field->at(i).x==x1 && field->at(i).y==y1){
           start=&field->at(i);
           indexOnField1=i;
           //cout<<"start "<<indexOnField1;
        }
        if(field->at(i).x==x2 && field->at(i).y==y2){
           finish=&field->at(i);
           indexOnField2=i;
           //cout<<"finish "<<indexOnField2;
        }
    }
    //cout<<"indeces "<<indexOnField1<<" "<<indexOnField2<<endl;
    if(finish->value==1){ // если конечная клетка пустая черная
        
        if(start->value==2){ // шашка белая
            
            if(start->y-1==finish->y && abs(start->x-finish->x)==1){// ходит
                setCellValue(indexOnField1,1,field);
                setCellValue(indexOnField2,2,field);
                cout<<"STEP"<<endl;
                return true;
            }
            if(start->y-2==finish->y && abs(start->x-finish->x)==2){ // ест
                
                dx=(finish->x-start->x)/2;
                dy=(finish->y-start->y)/2;
                int indexOfMiddleCell=getIndexByCoord(start->x+dx,start->y+dy,field);
                //cout<<"middle "<<indexOfMiddleCell<<endl;
                int val=field->at(indexOfMiddleCell).value;
                //cout<<"VAL "<<val<<endl;
                if(val==4 || val==5){
                    setCellValue(indexOnField1,1,field);
                    setCellValue(indexOfMiddleCell,1,field);
                    setCellValue(indexOnField2,2,field);
                    
                    /*cout<<"EAt"<<start->x<<" "
                            <<start->y<<" "
                            <<finish->x<<" "
                            <<finish->y<<" "
                            <<dx<<" "
                            <<dy<<" "
                            <<endl;*/
                    return true;
                }
                
            }
           
        }else if(start->value==3){// дамка белая
            if(abs(start->y-finish->y)==1 && abs(start->x-finish->x)==1){// ходит
                setCellValue(indexOnField1,1,field);
                setCellValue(indexOnField2,2,field);
                cout<<"STEP"<<endl;
                return true;
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
                    return true;
                }
                
            }
        } 
    }
    return false;
}



