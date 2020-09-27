#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

class  Coordinates{
    private :
    double x; // hoanh do
    double y; // tung do
    public :
    Coordinates();
    Coordinates(int a, int b);
    Coordinates(const int a);
    void Input();
    void Output();
    friend double Length(Coordinates &d1,Coordinates &d2);
    friend double Perimeter(Coordinates &d1, Coordinates &d2, Coordinates &d3);
    friend double Acreage(Coordinates &d1, Coordinates &d2, Coordinates &d3);
    ~Coordinates();

};

Coordinates :: Coordinates()
{
    x = 1;
    y = 1;
}

Coordinates :: Coordinates(int a , int b)
{
    x = a;
    y = b;
}

Coordinates :: Coordinates(const int a)
{
    x = a;
    y = a; 
}

void Coordinates :: Input()
{
    cout<<"Nhap hoanh do :";
    cin>>x;
    cout<<"Nhap tung do :";
    cin>>y;
}

void Coordinates :: Output()
{
    cout<<"(" << x << "," << y << ")" << endl;
}

double Length(Coordinates &d1,Coordinates &d2)
{
    double length;
    length = sqrt(double(pow(d2.x - d1.x,2) +pow(d2.y - d1.y,2)));
    return length;
}


double Perimeter( Coordinates &d1, Coordinates &d2, Coordinates &d3)
{
    double CV;
    CV = Length(d1,d2) + Length(d2,d3) + Length(d1,d3);
    return CV;
}
double Acreage(Coordinates &d1, Coordinates &d2, Coordinates &d3)
{
    double DT ;
    if(Length(d1,d2) == Length(d2,d3))
    {
        return DT = (sqrt(pow(Length(d1,d2),2) - pow((Length(d1,d3))/2,2)) * Length(d1,d3))/2;
    }else if(Length(d1,d2) == Length(d1,d3))
    {
        return DT = (sqrt(pow(Length(d1,d2),2) - pow((Length(d2,d3))/2,2)) * Length(d2,d3))/2;
    }else if(Length(d2,d3) == Length(d1,d3))
    {
        return DT = (sqrt(pow(Length(d1,d3),2) - pow((Length(d1,d2))/2,2)) * Length(d1,d2))/2;
    }
}
Coordinates :: ~Coordinates()
{
}

int main()
{
Coordinates d1(-1,1),d2(2,3),d3(1,4);
/*cout<<"Nhap Toa Do Diem d1  :" << endl;
d1.Input();
cout<<"Nhap Toa Do Diem d2  : " << endl;
d2.Input();
cout<<"Nhap Toa Do Diem d3 :" << endl;
d3.Input();
cout<<endl;

cout<<"Diem d1";
d1.Output();
cout<<"Diem d2";
d2.Output();
cout<<"Diem d3";
d3.Output();
cout<<endl;*/

cout<<"Khoang cach (d1,d2)la:" << setprecision(2)<< Length(d1,d2) << endl;
cout<<"Khoang cach (d2,d3)la:" << setprecision(2)<< Length(d2,d3) << endl;
cout<<"Khoang cach (d1,d3)la:" << setprecision(2)<< Length(d1,d3) << endl;
cout<<endl;

double kc1 = Length(d1,d2);
double kc2 = Length(d2,d3);
double kc3 = Length(d1,d3);
cout<<endl;

if(kc1 == kc2 || kc1 == kc3 || kc2 == kc3)
{
    cout<<"Tam giac nay can" << endl;
    cout<<"Chu vi tam giac can nay la :" << Perimeter(d1,d2,d3) << endl;
    cout<<"Dien tich tam giac can la :" << Acreage(d1,d2,d3) << endl;
}
else
{
    cout<<"Tam giac nay khong can";
}
}
