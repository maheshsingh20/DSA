#include <bits/stdc++.h>
using namespace std;


// cross product of two points
int crossProduct(int x1, int x2, int y1,int  y2){
  return x1*y2 - x2*y1;
}
//cross product using three points

int crossProductThree(int x1, int x2, int x3, int y1, int y2, int y3){
  return (x1-x2)*(y2-y3) - (x2-x3)*(y1-y2);
}

//Area od triangle formed with three points

int areaOfTriangle(int x1, int x2, int x3, int y1, int y2, int y3){
  int num= x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2);
  int den = 2;
  return abs(num/den);
}

//int orientation
int orientation(int x1, int x2, int x3, int y1, int y2, int y3){
  int val = crossProductThree(x1,x2,x3,y1,y2,y3);
  if(val==0) return 0;
  else if(val>0) return 1;
  else return 2;
}

int main(){
  int x1 = 0, y1 = 0;
  int x2 = 4, y2 = 4;
  int x3 = 1, y3 = 2;
  // cout<<crossProduct(x1,x2,y1,y2)<<endl;
  // cout<<areaOfTriangle(x1,x2,x3,y1,y2,y3)<<endl;

  int o = orientation(x1,x2,x3,y1,y2,y3);
  if(o==0) cout<<"Collinear"<<endl;
  else if(o==1) cout<<"Clockwise"<<endl;
  else cout<<"Counter Clockwise"<<endl;
  
  return 0;
}
