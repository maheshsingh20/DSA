#include <bits/stdc++.h>
using namespace std;

int areaofRectangle(int length, int breadth){
  return length * breadth;
}

int areaOfIntersection(int x1, int x2,int x3, int x4, int y1, int y2, int y3, int y4){
  int tx = max(x2, x4);
  int ty = max(y2, y4);
  int bx = max(x1, x3);
  int by = max(y1, y3);
  int area = abs(tx - bx) * abs(ty - by);
  return area;
}

int main(){
  int length = 16;
  int breadth = 8;
  cout << "Area of rectangle is : " << areaofRectangle(length, breadth);

}
