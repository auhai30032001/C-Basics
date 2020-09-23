#include<iostream>
#include<cmath>

using namespace std;

class PhanSo{
private:
int Mauso;
int Tuso;
private:
int UCLN(int a,int b);
public:
PhanSo();
PhanSo(int tuso, int mauso);
PhanSo(const int &b);
void Nhap();
void Xuat();
int GetTuso();
int GetMauso();
void set(int a,int b);
PhanSo Nghichdao();
PhanSo Rutgon();
PhanSo Cong(PhanSo b);
PhanSo Tru(PhanSo b);
PhanSo Chia(PhanSo b);
PhanSo Nhan(PhanSo b);
int SoSanh(PhanSo b);
~PhanSo();
};

void PhanSo ::Nhap()
{
    cout << " Nhap tu so :"; cin >> Tuso;
    do
    {
    cout << "Nhap mau so :"; cin >> Mauso;
    } while (Mauso != 0);
}

void PhanSo ::Xuat()
    {
        if(Tuso == 0)
        {
            cout <<Tuso;
        }
        else 
        cout << Tuso << "/" << Mauso << endl;
    }

void PhanSo ::set(int a,int b)
{
Tuso = a;
Mauso = b;
}

int PhanSo:: UCLN(int a,int b)
{
    if(a == 0 || b == 0)
    return a+b;
    while(a!=b)
    {
        if(a > b)
        {
            a = a - b;
        }
        else 
            b = b - a;
    }
    return a;
}

PhanSo PhanSo :: Rutgon()
{
	if(Tuso == Mauso)
	{
		return 1;
	}
	else
	{
    int a = UCLN( Tuso , Mauso);
    Mauso = Mauso / a;
    Tuso = Tuso / a;
    return PhanSo(Tuso,Mauso);
}
}    

int PhanSo :: GetTuso()
{
    return this -> Tuso;
}

int PhanSo :: GetMauso()
{
    return this -> Mauso;
}   

PhanSo :: PhanSo()
{
 Tuso = 0;
 Mauso = 1;
}

PhanSo :: PhanSo(int tuso , int mauso)
{
Tuso = tuso;
Mauso = mauso;
}


PhanSo :: PhanSo(const int &b)
{
    Tuso = b;
    Mauso = b;
}
PhanSo ::~PhanSo()
{   
}

PhanSo PhanSo :: Nghichdao()
{   
    if(Tuso != 0)
    {
        return PhanSo(Mauso,Tuso);
    }
    else
    {
        return PhanSo(Tuso,Mauso);
    }
    
}

PhanSo PhanSo :: Cong(PhanSo b)
{
    return PhanSo((Tuso*b.Mauso + Mauso*b.Tuso) , b.Mauso*Mauso);
}

PhanSo PhanSo :: Tru(PhanSo b)
{
return PhanSo((Tuso*b.Mauso - Mauso*b.Tuso), Mauso*b.Mauso);
}

PhanSo PhanSo :: Nhan(PhanSo b)
{
    return PhanSo( this -> Tuso*b.Tuso,this -> Mauso*b.Mauso);
}

PhanSo PhanSo :: Chia(PhanSo b)
{
    return PhanSo(this -> Tuso*b.Mauso,this -> Mauso*b.Tuso);
}
int PhanSo ::SoSanh(PhanSo b)
{
int X = this -> Tuso / this -> Mauso;
int Y = b.Tuso / b.Mauso;
if(X > Y)
{
    return 1;
}
else if ( Y > X)
{
    return -1;
}
else return 0;
}


int main()
{
    PhanSo a(-4,7),b(4,7),c(2,4);
    //b = a.Nghichdao();
    //b = a.Rutgon();
    //c= a.Cong(b);
    //c= a.Tru(b);
    //c = a.Chia(b);
    //c= a.Nhan(b);
    //c= c.Rutgon();
    c = a.SoSanh(b);
    c.Xuat();
}


