//4
#include <iostream>
using namespace std;

class Point{
    private:
        int coord_x, coord_y;
    
    public:
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

        int getX(){
            return coord_x;
        }

        int getY(){
            return coord_y;
        }

        void setX(int x){
            this->coord_x = x; 
        }

        void setY(int y){
            this->coord_y = y;
        }
};

int main(){
    Point point;
    int x, y;
    cout << "Write the coordinates for X and Y" << endl;
    cin >> x >> y;
    point.setX(x);
    point.setY(y);
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
                if(point.getY() < n) point.moveY();
                else cout << "Move invalid: point leaves the rectangle" << endl;
                cout << "X: " << point.getX() << " Y: " << point.getY() << endl;
                break;

            case 2:
                if(point.getX() < n) point.moveX(); 
                else cout << "Move invalid: point leaves the rectangle" << endl;
                cout << "X: " << point.getX() << " Y: " << point.getY() << endl;
                break;

            case 3:
                if(point.getX() < n && point.getY() < n) point.moveXY();
                else cout << "Move invalid: point leaves the rectangle" << endl;
                cout << "X: " << point.getX() << " Y: " << point.getY() << endl;
                break;

            default:
                cout << "Type of movement invalid" << endl;   
        }
        i++;
    }  
    
    cout << "Final position of the point: X: " << point.getX() << " Y: " << point.getY() << endl;
    return 0;
}