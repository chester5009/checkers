
#ifndef CELL_H
#define CELL_H

class Cell {
public:
    Cell(int x,int y,int val);

    virtual ~Cell();
    
    int value; 
    //0-'.' ( белая) 
    //1-'-'(черная) 
    //2-'w' (с белой шашкой) 
    //3-'W' (белая дамка)
    //4-'b' (черная шашка)
    //5-'B' (черная дамка)
    int x;
    int y;
    void setValue(int val);
private:

};

#endif /* CELL_H */

