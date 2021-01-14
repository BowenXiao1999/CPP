//
// Created by bowen on 2020/10/3.
//

class Point {

};

Point Global;

Point Test(Point a) { // copy construct
    Point b = a; // copy construct
    Point*c = new Point(a); // copy construct
    *c = b; // copy assignment
    Point d[2] = {b, *c};
    return *c;
}
