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
// }
 // cout << "iam here at resize1"<<endl;
//      bool r_b;
//      bool c_b;
//      if(row>=rowB){ //down down
//    rowB+=(row - rowB)+1+ len;
//    cout<<"curr rowB = "<<rowB <<endl;
//     r_b = !r_b;
//     //cout<<"iam at row>rowB"<<endl;
//      }
//    //cout << "current rowB is" <<rowB<<endl;
//    if(col>=colB){ // >>
//    cout <<"current col is ** "<<colB<<endl;
//    colB+=((col-colB)+1+len);
//    c_b = !c_b;
//     cout<<"iam at col>colB"<<endl;
//    }
//   if((std::abs((int)(colB - col))+1)<=len){ //horgim mealuah im mila le zarih abs
//    cout<<"colB before = "<<colB<<"curr len is = "<<len<<endl;
//    uint res = std::abs((int)((col-colB) +len));
//    //cout<<"res is = "<<res<<endl;
//    colB+= res; //prev = new - old + len
//    c_b = !c_b;
//     cout<<"iam at((colB - col)+1)<=len "<<" colB is="<<colB<<endl;
//   }
//   //down down down
//   if((std::abs((int)(rowB - row)+1))<=len){ //horgim mealuah im mila le zarih abs
//    cout<<"rowB before = "<<rowB<<"curr len is = "<<len<<endl;
//    uint res = std::abs((int)((row-rowB) +len));
//    //cout<<"res is = "<<res<<endl;
//    rowB+= (uint)res; //prev = new - old + len
//    r_b = !r_b;
//     cout<<"iam at((colB - col)+1)<=len "<<" rowB is="<<rowB<<endl;
//   }
//    //cout << "current colB is" <<colB<<endl;
//    //tofer et 2 hamikrim mehuz lemata ve gam rak lemata
//    //ROZIM LEAGDIL LE SHAM >>
//    if(r_b){ //be mida ve rak be shurot gadalnu be amudot le
//    cout<<"iam resizing down down current coll is ="<<colB<<endl;
//   board.resize(rowB); //magdil pointer shura
// for (uint i = 0; i < rowB; i++){
//     board[i].resize(colB,'_'); //tagdil be kol shura godel amuda
// }
// }

// //r_b == false
//    else 
//    { 
//        //ROZIM LEAGDIL LEMATAMATA
//         board.resize(colB);
//        cout<<"iam at else resize1 "<<endl;
//        cout<<"iam at else resize1 and rowB is  "<<rowB<<endl;
//        cout<<"curr colB = "<<colB <<endl;
//       for (uint i = 0; i < colB; i++){
//     board[i].resize(rowB,'_'); //tagdil be kol shura godel amuda
// }
//    }
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
    
   
   
   





