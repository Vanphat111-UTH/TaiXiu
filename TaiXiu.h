// TaiXiu.h

#include <iostream>
#include "Random.h"
#include <fstream>
#include <string>


// 3 xuc sac 
// 4 - 10 -> Xiu
// 11 - 17 -> Tai
class TaiXiu {
    private:
        int x1, x2 ,x3;
        float wallet;   
        bool checkWinLose(std::string input);
        void roll();
    public: 
        TaiXiu(float _wallet = 500);
        friend std::ostream& operator<<(std::ostream& out, TaiXiu& TaiXiu);
        friend std::istream& operator>>(std::istream& in, TaiXiu& TaiXiu);
        void start();
};