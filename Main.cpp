#include <iostream>
#include <cstring>
#include <queue>
#include "MuhammetOzman.h"
#include<stdlib.h>

using namespace std;


	
int main (){
/*
int row,col;
cin>>row;
cin>>col;
MyMap* pot= new MyMap(row,col);
pot->SetSize(row,col);
pot->Show();
*/

MuhammetOzman::MyMap *sArr[]={new MuhammetOzman::MyMap(4,4)};
sArr[0]->SetSize(4,4);
sArr[0]->SetBorder(0,1);
sArr[0]->SetBorder(0,2);
sArr[0]->SetBorder(0,3);
sArr[0]->SetBorder(1,0);
sArr[0]->SetBorder(1,1);
sArr[0]->SetBorder(2,1);
sArr[0]->SetBorder(3,1);
sArr[0]->SetBorder(3,2);

sArr[0]->Show();
sArr[0]->ClearBorder(2,2);
sArr[0]->Show();
sArr[0]->IsBorder(1,2);
sArr[0]->IsBorder(2,2);



MuhammetOzman::MyZone* ztr=new MuhammetOzman::MyZone(sArr[0]);
ztr->Init(sArr[0]);
ztr->Solve();




}






