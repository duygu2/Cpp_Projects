#include <iostream>
#include <string>
#include <sstream>
#include <cmath>>
using namespace std;
class myPoint {
public:
    myPoint();
    myPoint(int, int);

    void setX(int);
    void setY(int);
    void setXY(int, int);
    int getX();
    int getY();
    void getXY(int[]);

    string toString();
    double distance(int, int);
    double distance(myPoint);
    double distance();
private:
    int x;
    int y;

};
class rectangle {
public:
   // rectangle();
    int rec_area(int,int);
    int rec_perimeter(int, int);
    bool kesisim(int,int,int,int,int,int,int,int);
private:
    int long_edge;
    int short_edge;
};

class circle {
public:
    //circle();
    int kesisim(int x1, int y1, int r1, int x2, int y2, int r2);
    int getr();
    void setr(int);
    double cir_area(int);
    double cir_perimeter(int);
private:
    int radius;
    
};



int rectangle::rec_perimeter(int short_edge, int long_edge) {
   
    return 2 * (short_edge)+2 * (long_edge);;
}

bool rectangle::kesisim(int p1x,int p1y, int p2x,int p2y, int p3x,int p3y, int p4x,int p4y)
{
   
        if (p1x >= p2x|| p3x>= p4x)
            return false;

        
        if (p1y <= p2y || p3y <= p4y)
            return false;

        return true;
    } 




int rectangle::rec_area(int short_edge, int long_edge) {
    return short_edge * long_edge;
}


double circle::cir_perimeter(int radius) {
    
     
    return 2 * (3.14 * radius);
}
int circle::kesisim(int x1, int y1, int r1, int x2, int y2, int r2)
{
    int A = (x1 - x2) * (x1 - x2) +(y1 - y2) * (y1 - y2);
    int B= (r1 + r2) * (r1 + r2);
    if (A == B)
        return 1;
    else if (A > B)
        return -1;
    else
        return 0;

}
int circle::getr()
{
    return radius;
}
void circle::setr(int)
{
    this->radius = radius;
}
double circle::cir_area(int radius) {
    return 3.14 * pow(radius,2);

}
myPoint::myPoint() {
    x = 0;
    y = 0;
}
myPoint::myPoint(int x, int y) {
    this->x = x;
    this->y = y;
}

void myPoint::setX(int x) {
    this->x = x;
}
void myPoint::setY(int y) {
    this->y = y;
}
void myPoint::setXY(int x, int y) {
    this->x = x;
    this->y = y;
}

int myPoint::getX() {
    return x;
}
int myPoint::getY() {
    return y;
}
void myPoint::getXY(int p[]) {
    p[0] = x;
    p[1] = y;
}

string myPoint::toString() {
    string str;
    str = "(" + to_string(x) + "," + to_string(y) + ")";
    return str;
}

double myPoint::distance(int x, int y) {
    int X = this->x - x;
    int Y = this->y - y;
    double result = sqrt(pow(X, 2) + pow(Y, 2));
    return result;
}

double myPoint::distance(myPoint p) {
    int X = this->x - p.x;
    int Y = this->y - p.y;
    double result = sqrt(pow(X, 2) + pow(Y, 2));
    return result;
}
double myPoint::distance() {
    double result = sqrt(pow(x, 2) + pow(y, 2));
    return result;
}



int main()
{
    myPoint p1(10, 10);//sol üst
    myPoint p2(30, 10);//sağ üst
    myPoint p3(10, 0);//sol alt
    myPoint p4(30, 0);//sağ alt

    //ikinci dikdörtgeni oluşturuyorum
    myPoint p5(0, 20); myPoint p6(40, 20);
    myPoint p7(0, 0); myPoint p8(40, 0);

    myPoint dairemerkez(20, 10);
    myPoint r;
    rectangle ca;
    circle daire;
    r.setX(10);//yarıçap uzunluğunu alıyoruz
    cout << "diktortgenin noktalari:" << endl;
    cout << p1.toString() << "\t" << p2.toString() << endl;
    cout << p3.toString() << "\t" << p4.toString() << endl<<endl;
    p1.distance();
    cout << "uzun kenar:" << p1.distance(p2) << "\t";
    p3.distance();
    cout << "kisa kenar:" << p1.distance(p3) << endl<<endl;


    cout << "diktortgenin cevresi:" << ca.rec_perimeter(p1.distance(p3), p1.distance(p2)) << endl<<endl;
    cout << "diktortgenin alani:" << ca.rec_area(p1.distance(p3), p1.distance(p2))<<endl<<endl;

    cout << "dairenin merkez noktasi:" << dairemerkez.toString()<<endl<<endl; 
    cout << "dairenin yaricapi:" << r.getX()<<endl<<endl;
    cout<<"dairenin alani:"<<daire.cir_area(r.getX())<<endl<<endl;
    cout<<"dairenin cevresi:"<<daire.cir_perimeter(r.getX())<<endl<<endl;
    
    cout << "diktortgen ve daire kesisim hesaplama:  ";
    if (p1.getX() <= dairemerkez.getX() && dairemerkez.getX() <= p2.getX())// diktörtgenin x koordinatı ile dairenin x koordinatını kontrol ediyorum
        if (p1.getY() >= dairemerkez.getY() && dairemerkez.getY() >= p3.getY())
            cout << "kesisir"<<endl<<endl;
    else
        cout << "kesismez"<<endl<<endl;


   
    circle daire2; myPoint dairemerkez2(10,30);
    daire2.setr(5);
    cout <<"kesisimi hesaplanan daire noktalari:"<<dairemerkez2.toString()<<"&"<<dairemerkez.toString()<<endl;
    int t;
    t=daire.kesisim(dairemerkez.getX(), dairemerkez.getY(), daire.getr(),dairemerkez2.getX(),dairemerkez2.getY(),daire2.getr() );
    
    if (t == 1)
        cout << "daireler birbirine dokunur(kesisirler)."<<endl<<endl;

    else if (t < 0)
        cout << "daireler birbiriyle kesismez"<<endl<<endl;

    else
        cout << "daireler birbiriyle kesisir"<<endl<<endl;
       

    //dikdörtgenlerin sol üst ve sağ alt koşelerini aldım.
    if (ca.kesisim(p1.getX(), p1.getY(), p4.getX(), p4.getY(), p5.getX(), p5.getY(), p8.getX(), p8.getY()))
        cout << "dikdortgenler kesisir."<<endl;
    else
        cout << "dikdortgenler kesismez."<<endl;
}

