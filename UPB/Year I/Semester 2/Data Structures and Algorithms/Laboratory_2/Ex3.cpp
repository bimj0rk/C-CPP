//3
#include <iostream>
using namespace std;

struct Point { 
    public: 
        int coord_x, coord_y;

    void reset(){ 
         coord_x = coord_y = 0;
    } 
    
    void moveX(int x = 1){
        this->coord_x += x;
    } 
    
    void moveY(int y = 1){
        this->coord_y += y;
    } 
    
    void moveXY(int x = 1, int y = 1){
        this->coord_x += x;
        this->coord_y += y;
    }
}; 

int main(){
    Point point;
    int x, y;
    cout << "Write the coordinates for X and Y" << endl;
    cin >> x >> y;
    point.coord_x = x;
    point.coord_y = y;
    int n, noOfMoves, i = 1;
    cout << "Select the rectangle size" << endl;
    cin >> n;
    cout << "Select the number of moves" << endl;
    cin >> noOfMoves;

    while(i <= noOfMoves){
        int move;
        cout << "Select the type of movement: 1 - horizontally, 2 - vertically, 3 - diagonally" << endl;
        cin >> move;
        switch(move){
            case 1:
                if(point.coord_y < n) point.moveY();
                else cout << "Move invalid: point leaves the rectangle" << endl;
                cout << "X: " << point.coord_x << " Y: " << point.coord_y << endl;
                break;

            case 2:
                if(point.coord_x < n) point.moveX(); 
                else cout << "Move invalid: point leaves the rectangle" << endl;
                cout << "X: " << point.coord_x << " Y: " << point.coord_y << endl;
                break;

            case 3:
                if(point.coord_x < n && point.coord_y < n) point.moveXY();
                else cout << "Move invalid: point leaves the rectangle" << endl;
                cout << "X: " << point.coord_x << " Y: " << point.coord_y << endl;
                break;

            default:
                cout << "Type of movement invalid";   
        }
        i++;
    }  
    
    cout << "Final position of the point: X: " << point.coord_x << " Y: " << point.coord_y << endl;
    return 0;
}