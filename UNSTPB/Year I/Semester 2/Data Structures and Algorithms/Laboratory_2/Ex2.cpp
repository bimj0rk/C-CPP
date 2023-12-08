//2
#include <iostream>
using namespace std;

struct date{
    unsigned int day;
    unsigned int month;
    unsigned int year;
    char name_day[4];
    char name_year[4];

    bool isDateValid(){
        bool valid = false;
        if(this->year < 9999 && this->year >= 1000){
            valid = true;
            switch(this->month){
                case 0:
                    valid = false;
                    break;

                case 1:
                    if(this->day >= 1 && this->day <= 31) valid = true;
                    else valid = false;
                    break;

                case 2:
                    if(this->day >= 1 && this->day <= 28) valid = true;
                    else valid = false;
                    break;

                default:
                    if(this->month%2 == 0){
                        if(this->day >= 1 && this->day <= 30) valid = true;
                        else valid = false;
                    }else{
                        if(this->day >= 1 && this->day <= 31) valid = true;
                        else valid = false;
                    }
                    break;

            }
        } else valid = false;
        return valid;
    }

    date getTomorrow(){
        date aux;
        if(this->month%2 == 0 && this->day == 30){
            aux.day = 1;
            aux.month = this->month++;
        } else if(this->month%2 == 1 && this->day == 31){
            aux.day = 1;
            aux.month = this->month++;
        }else if(this->month == 2 && this->day == 28){
            aux.day = 1;
            aux.month = this->month++;
        }else{
            aux.day = this->day+1;
            aux.month = this->month;
        }

        if(this->month == 12 && this->day == 30) aux.year = this->year++;
        else aux.year = this->year;
        return aux;
    }
};

int main(){
    int day, m, y;
    date d, tomorrow;
    cout << "Enter the day, month and year: " << endl;
    cin >> day >> m >> y;
    d.day = day; d.month = m; d.year = y;
    if(d.isDateValid()){
        cout << "Date is valid" << endl;
        tomorrow = d.getTomorrow();
        cout << "Next day is: " << tomorrow.day << "." << tomorrow.month << "." << tomorrow.year;
    } 
    else cout << "Date is not valid" << endl;
    return 0;
}