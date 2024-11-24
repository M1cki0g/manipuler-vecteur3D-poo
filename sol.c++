#include <iostream>
#include <math.h>
using namespace std;

class vecteur3d{
int x;
int y;
int z;
public:
    vecteur3d (int x=0,int y=0,int z=0){
     this->x=x;
     this->y=y;
     this->z=z;
    }

    vecteur3d(const vecteur3d& v){
    x = v.x;
    y = v.y;
    z = v.z;
    }

    void affichage(){
    cout<<"x= "<<x<<endl;
    cout<<"y= "<<y<<endl;
    cout<<"z= "<<z<<endl;
    }

    vecteur3d operator+(vecteur3d& v2){
    vecteur3d temp;
    temp.x = x+v2.x;
    temp.y = y+v2.y;
    temp.z = z+v2.z;
    return temp;
    }

    vecteur3d operator*(vecteur3d& v2){
    vecteur3d temp;
    temp.x = (x*v2.x)+(x*v2.y)+(x*v2.z);
    temp.y = (y*v2.x)+(y*v2.y)+(y*v2.z);
    temp.z = (z*v2.x)+(z*v2.y)+(z*v2.z);
    return temp;
    }

    bool operator == (vecteur3d& v2){
    return (x==v2.x && y==v2.y && z==v2.z);
    }

    float norme (){
    return sqrt((x*x)+(y*y)+(z*z));
    }

//-------------PAR VALEUR
    vecteur3d normax(vecteur3d v2){
    if(this->norme()>v2.norme())
        return *this;
        //cout<<"grand vecteur (par valeur):"<<v1.x<<v1.y<<v1.z<<endl;
    else
        return v2;
        //cout<<"grand vecteur (par valeur):"<<v2.x<<v2.y<<v2.z<<endl;
    }
//--------------PAR REFERENCE
    vecteur3d normaxR(vecteur3d &v2){

    if(this->norme()>v2.norme())
        return *this;
        //cout<<"grand vecteur (par valeur):"<<v1.x<<v1.y<<v1.z<<endl;
    else
        return v2;
        //cout<<"grand vecteur (par valeur):"<<v2.x<<v2.y<<v2.z<<endl;
    }
//--------------PAR ADRESSE
    vecteur3d* normax(vecteur3d* v2){

    if(this->norme()>v2->norme())
        return this;
        //cout<<"grand vecteur (par valeur):"<<v1.x<<v1.y<<v1.z<<endl;
    else
        return v2;
        //cout<<"grand vecteur (par valeur):"<<v2.x<<v2.y<<v2.z<<endl;
    }
};

int main()
{
vecteur3d v1(1,2,3);
v1.affichage();
vecteur3d v2(5,6,7);
v2.affichage();
vecteur3d res1 = v1+v2;
cout<<"La somme de v1 et v2"<<endl;
res1.affichage();
vecteur3d res2 = v1*v2;
cout<<"Le produit scalaire de v1 et v2"<<endl;
res2.affichage();
cout<<"copier v1 dans v3"<<endl;
vecteur3d v3(v1);
v3.affichage();
if(v1==v3)
    cout<<"les vecteurs v1 et v3 coincident"<<endl;
else
    cout<<"les vecteurs v1 et v3 different"<<endl;

cout<<"le vecteurs gd par valeur"<<endl;
v2.normax(v3).affichage();
cout<<"le vecteurs gd par adresse"<<endl;
v2.normax(&v3)->affichage();
cout<<"le vecteurs gd par reference"<<endl;
v2.normaxR(v3).affichage();

return 0;
}
