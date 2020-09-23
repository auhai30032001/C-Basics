#include<iostream>
#include<cmath>
using namespace std;

class SoPhuc{
    private :
    double Phanthuc;
    double Phanao;
    public :
    void Nhap();
    void Xuat();
    SoPhuc();
    SoPhuc(double phanthuc,double phanao);
    SoPhuc(const double &a);
    double GetThuc();
    double GetAo();
    void Gan(double a, double b);
    double Module();
    SoPhuc Cong(SoPhuc a);
    SoPhuc Tru(SoPhuc a);
    SoPhuc Nhan(SoPhuc a);
    SoPhuc Chia(SoPhuc a);
    int Sosanh(SoPhuc a);
    ~SoPhuc();
};

SoPhuc :: SoPhuc()
{
    Phanthuc = 1;
    Phanao = 1;
}

SoPhuc :: SoPhuc(double phanthuc, double phanao)
{
Phanthuc = phanthuc;
Phanao = phanao;
}

SoPhuc :: SoPhuc(const double &a)
{
    Phanthuc = a;
    Phanao = a;
}

double SoPhuc :: GetThuc()
{
    return this -> Phanthuc;
}

double SoPhuc :: GetAo()
{
    return this -> Phanao;
}

void SoPhuc :: Gan(double a, double b)
{
Phanthuc = a;
Phanao = b;
}

void SoPhuc :: Nhap()
{
    cout << " Nhap phan thuc = " << endl;
    cin >> Phanthuc ;
    cout << " Nhap phan ao = " << endl;
    cin >> Phanao ;
}

void SoPhuc ::Xuat()
{
    cout << Phanthuc << "+" <<  "(" << Phanao << ")"<<"i"<< endl;
}

double SoPhuc :: Module()
{
    if(Phanthuc == 0 || Phanao == 0)
    {
        return 0;
    }
    else 
    return (sqrt(pow(Phanthuc,2) + pow(Phanao,2)));
}

SoPhuc SoPhuc ::Cong(SoPhuc a)
{
    return SoPhuc((this -> Phanthuc + a.Phanthuc) , ( this -> Phanao + a.Phanao));
}

SoPhuc SoPhuc ::Tru(SoPhuc a)
{
    return SoPhuc((this -> Phanthuc - a.Phanthuc) , ( this -> Phanao - a.Phanao));
}

SoPhuc SoPhuc ::Chia(SoPhuc a)
{
    {
        SoPhuc c;
        c.Phanthuc = ( this ->Phanthuc*a.Phanthuc + this ->Phanao*a.Phanao) / (pow(a.Phanthuc,2) + pow(a.Phanao,2));
        c.Phanao = ( this ->Phanao*a.Phanthuc - this ->Phanthuc*a.Phanao) / (pow(a.Phanthuc,2) + pow(a.Phanao,2));
        return c;
    }
}

SoPhuc SoPhuc ::Nhan(SoPhuc a)
{
    {
        return SoPhuc( this -> Phanthuc*a.Phanthuc - this -> Phanao*a.Phanao , this -> Phanthuc*a.Phanao + this -> Phanao*a.Phanthuc );
    }
}

int SoPhuc :: Sosanh(SoPhuc a)
{    
    if( this ->Phanthuc == a.Phanthuc || this ->Phanao == a.Phanao)
    {
        return 1;
    }
    else 
    return 0;
}

SoPhuc ::~SoPhuc()
{}

int main()
{
    SoPhuc a(1,2),b(1,2),c,d;
    //c = b.Cong(a);
    //c = b.Tru(a);
    //c.Module();
    //cout << "Gia tri module la :" << c.Module() << endl;
    //c = b.Nhan(a);
    //c = b.Chia(a);
    // b.Sosanh(a);
    //d.Xuat();
}
