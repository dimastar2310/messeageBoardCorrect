//using namespace std;
//she le yatehelu shuv
#pragma once   
#include <iostream>
#include <string>
#include <vector>//le 2b
#include <algorithm>//le 2b
#include <string> 
#include "Direction.hpp"
#include <array>
#include <climits>
#include <cmath>
//using ariel::Direction;
//typedef unsigned int uint; //kvar kayam be cpp

namespace ariel{
       
       class Board { //hazhara
     //maxR,maxC
     uint rowB,colB,minR,minC;
     std::vector<std::vector<char>> board;
     void resize1(uint row,uint col,uint len);
      

//typedef struct Board Board;
 public:
    Board(){
             rowB = 5;
             colB = 5;
             minR = UINT_MAX;
             minC = UINT_MAX;
             board = std::vector<std::vector<char>>(rowB,std::vector<char>(colB,'_'));
    }
   
    


void post(uint row,uint col,Direction dir, const std::string &abc); //mekabelet shura ve amuda hiuviim ve madbika et ha post i 3 rida
std::string read(uint row ,uint col,Direction dir ,uint vol);

void show(); //ze funkzia le 2b
       };
}
