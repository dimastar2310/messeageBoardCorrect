#include "Board.hpp"
//#include <cmath>
using namespace std;

//typedef unsigned int uint;

namespace ariel{ //mimush

void printBoard();



void Board::resize1(uint row,uint col,uint len){

    rowB +=row + len;
  // cout << "current rowB is" <<rowB<<endl;
   colB+=col+len;
  // cout << "current colB is" <<colB<<endl;
  //uint max = std::abs(rowB,colB);
  board.resize(rowB);
for (uint i = 0; i < rowB; i++){
    board[i].resize(colB,'_'); //tagdil be kol shura godel amuda
}




void Board::post(uint row,uint col,Direction dir, const std::string &abc){ //mekabelet shura ve amuda ve madbika et ha
//row ve col nohehim shonim mihahdara
   //naase mikre she hakol beseder misham nasim
   //thumei hagdara
    if(row<minR){
        minR = row;
    }
    if(col<minC){
        minC = col;
    }
    string str1 (abc); //meathel obiekt
    uint len = str1.size();
    
   if(row>rowB || col>colB || (rowB-row)+1 <=len || (colB - col)+1<=len){//godel meduyak
       resize1(row,col,len);
   }
   //po hem kvar ihiue beseder
   if(row<rowB && col<colB){
       
   
switch(dir){ //zarih livnot et haclass haze
    case Direction::Horizontal: //>>>
    // indexForShow[0][0] = col; //
     //indexForShow[0][1] = (col + len)-1; //col mathilim mi 0
       
     for (uint i = col,j = 0; i < colB && j<len; i++,j++) {
            board[row][i] = str1[j];
            // if(i>maxC){
            //     maxC = i;
            // }
        }
            break;
        
        //nahnis ifim be mikre shel harigot
    case Direction::Vertical: //down down
    //indexForShow[1][0] = row;
     //indexForShow[1][1] = (row + len)-1; //col mathilim mi 0
     //cout<<"iam at vercticl"<<endl;
     for (uint i = row,j = 0; i < rowB && j<len; i++,j++) {
            board[i][col] = str1[j];
            // if(i>maxR){
            //     maxR = i;
            // }
        }
            break;
    default :
            break;
        }
    }


}






string Board::read(uint row ,uint col,Direction dir ,uint vol){ //aheret function overload
string res;
switch(dir){ //zarih livnot et haclass haze
    case Direction::Horizontal:{ //>>>
    //cout<<"iam at Horizontal read"<<endl;
    //colB hy mishtane dinami ze beseder

    int j = 0;
     for (uint i = col; i < colB && j<vol ; i++,j++) {
            //  if(i<=colB){
              res+=board[row][i];
              
            
        }
        //state that j is not done and the board is to small
        if(j<vol){
            for(int i = j ;i<vol ;i++){
            res+="_";
        }
        
        }
         // cout <<"Horizontal our string is = "<<res <<endl;
            break;
    }
        //nahnis ifim be mikre shel harigot
    case Direction::Vertical:{//down down
    
    // cout<<"Vertical iam at Vercticl read"<<endl;
     //rowB hie mishtane dinami az ze beseder
     int j =0;
     for (uint i = row ;i < rowB && j<vol; i++,j++) {
            res+=board[i][col];
           
           
        }
        //state that j is not done and the board is to small
     if(j<vol){
        for(int i = j ;i<vol ;i++){
         res+="_";
        }
        }
            break;
   
    } 
         
        //if want to get word that doesnt exist in some place
        //with sertain length
        if(res.size()==0 && vol>0){
           for(int i = 0;i<vol ;i++){
              res+='_'; //ein tamakom ba poal
           }
        }
       
    }
   return res;
}
void Board::show(){
      for(uint i = minR ;i<rowB;i++){
          for(uint j = minC ;j<colB;j++){
              cout<<board[i][j];
          }
          cout<<endl;
      }
    }
    

}

    

//im ani hoshev leathel et habanai kol paam
//az ani zarih od banai? she mimeno ani aatik
    
   
   
   





