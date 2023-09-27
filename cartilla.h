#include <iostream>
#include <unordered_map>
#include <iostream>
#include <vector>

//Saber si está un número: O(1)
//Saber cambiar "no apareció" a "apareció": O(1)
//Determinar si ganó: O(1) -> utilizando un contador a parte

using namespace std;

const int NUMEROS_TOTALES = 24;

class Cartilla{
private:
    int numeros_aparecidos=0;
    unordered_map<int,bool>aparecidos;
public:
    int id;
    Cartilla(){
        id = -1;
    }

    Cartilla(std::vector<int>nums, int id){
        for(int i=0;i<nums.size();i++)
            aparecidos.insert(make_pair(nums[i],false));

        this->id = id;
    }

    ~Cartilla(){
    }

    void marcar_numero(int num){
        if(aparecidos.count(num)>0){
            aparecidos[num] = true;
            numeros_aparecidos++;
        }
    }

    bool comprobar_victoria(){
        if(numeros_aparecidos==NUMEROS_TOTALES)
            return true;
        return false;
    }

    //debug
    void verMarcados(){
        int numElm = 1;
        for(const auto& par:aparecidos){
            cout << par.first << ": " << par.second << endl;
            numElm++;
        }
    }
    
};