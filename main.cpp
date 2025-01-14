#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 3;
const int MIN = 10000, MAX = 99999; 

class Chair 
    {
        private:
            int legs;
            double * prices;

        public:
            // constructors- changing the default constructor
            Chair() 
            {
                prices = new double[SIZE];
                legs = (rand() % (4 -3 + 1)) + 3;
                for (int i = 0; i < SIZE; i++)
                {
                    double price = (rand() % (MAX - MIN + 1) + MIN)/(double)100;
                    prices[i] = price;
                }
            }       
            //make parameter constructor accept an array of 3 doubles
            Chair(int l, double price []) 
            {
                prices = new double[SIZE];
                legs = l;
                for (int i = 0; i < SIZE; i++)
                prices[i] = price[i];
            }

            // setters and getters
            void setLegs(int l) { legs = l; }
            int getLegs() { return legs; }
            void setPrices(double p1, double p2, double p3) 
            {
                prices[0] = p1; prices[1] = p2; prices[2] = p3;
            }

            double getAveragePrices() 
            {
                double sum = 0;
                for (int i = 0; i < SIZE; i++)
                sum += prices[i];
                return sum / SIZE;
            }
            
            void print() 
            {
                cout << "CHAIR DATA - legs: " << legs << endl;
                cout << "Price history: " ;
                for (int i = 0; i < SIZE; i++)
                cout << prices[i] << " ";
                cout << endl << "Historical avg price: " << getAveragePrices();
                cout << endl << endl;
            }
    };

int main() {

    cout << fixed << setprecision(2);
    
    //using the parameter constructor-new one that accepts an int and an array of 3 doubles
    int l = (rand() % (4 -3 + 1)) + 3;
    double p [SIZE]; 
    for(int j = 0; j < SIZE; j++)
    {
        double cost = (rand() % (MAX - MIN + 1) + MIN)/(double)100;
        p[j] = cost;
    } 
    Chair * ch = new Chair(l, p); 
    ch->print();    
    

    /*//creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();*/

    /*//creating dynamic chair object with constructor
    Chair *livingChair = new Chair(3);
    livingChair->setPrices(525.25, 434.34, 252.52);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr; */

    //creating dynamic array of chair objects
    //use default constructor to populate it-part of assignment
    Chair *collection = new Chair[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        collection[i].print();
    }

    /*collection[0].setLegs(4);
    collection[0].setPrices(441.41, 552.52, 663.63);
    collection[1].setLegs(4);
    collection[1].setPrices(484.84, 959.59, 868.68);
    collection[2].setLegs(4);
    collection[2].setPrices(626.26, 515.15, 757.57);
    for (int i = 0; i < SIZE; i++)
    collection[i].print();*/
return 0;

}
