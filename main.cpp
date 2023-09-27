#include <iostream>
#include "cartilla.h"
#include <vector>

using namespace std;

int main(){
    bool ganoAlguna = false;
    int id_cartilla_ganadora=-1;

    //Inicializar todas las cartillas manualmente
    vector<int>v_cartilla1 = {14,25,42,46,73,5,28,32,57,72,7,16,47,71,11,30,39,50,68,10,26,40,49,70};
    Cartilla cartilla1(v_cartilla1,3256); // Asignamos un id a cada cartilla para saber cuál ganó
    vector<int>v_cartilla2 = {14,17,33,59,63,2,23,32,60,64,15,28,56,68,13,30,41,51,74,6,24,38,55,66};
    Cartilla cartilla2(v_cartilla2,3255);
    vector<int>v_cartilla3 = {3,17,43,57,68,4,25,41,52,70,12,30,56,67,10,27,45,50,69,1,22,36,58,64};
    Cartilla cartilla3(v_cartilla3,3298);
    vector<int>v_cartilla4 = {14,26,42,52,69,4,19,43,59,73,7,24,54,62,10,21,39,53,70,8,20,37,60,67};
    Cartilla cartilla4(v_cartilla4,3251);
    vector<int>v_cartilla5 = {11,18,36,47,74,3,17,40,54,63,5,23,60,73,2,24,41,48,65,15,26,33,58,71};
    Cartilla cartilla5(v_cartilla5,3252);


    //Meter todas las cartillas a un vector
    vector<Cartilla>cartillas;
    cartillas.push_back(cartilla1);
    cartillas.push_back(cartilla2);
    cartillas.push_back(cartilla3);
    cartillas.push_back(cartilla4);
    cartillas.push_back(cartilla5);

    while(ganoAlguna==false){
        int nuevoNum;
        cout << "Ingrese nuevo numero:";cin>>nuevoNum;

        //Marcar todas las cartillas
        for(int i=0;i<cartillas.size();i++)
            cartillas[i].marcar_numero(nuevoNum);
    
        //Verificar si alguna cartilla ganó
        for(int i=0;i<cartillas.size();i++){
            if(cartillas[i].comprobar_victoria())
                ganoAlguna = true;
                id_cartilla_ganadora = cartillas[i].id;
        }     
    }

    // Imprimo cual cartilla ganó
    cout << "La cartilla ganadora fue la cartilla con id=" << id_cartilla_ganadora << endl;

}