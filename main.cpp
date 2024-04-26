#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "plantillas.h"
using namespace std;

int main() {
    utec::pair<int, string> p1;
    utec::persona per1;
    utec::persona per2("Jose", "Perez");
    utec::persona per3("Maria", "Lopez", 10, 14, 20, 18);

    per1.set_promedio(10, 20, 15);
    per1.metodo_2<int>();
    std::cout << per1.get_nota() << std::endl;
    utec::punto pto1{10, 20};
    utec::punto pto2{50.5, 30.5};
    pto1 = pto2;
    std::cout << pto1.x << " " << pto1.y << std::endl;

    vector<int> v = {1, 2, 3, 4};
    deque<double> d = {10, 20, 30, 40};
    list<float> l = {100, 200, 300, 400};

    std::cout << utec::sumar(v) << std::endl;
    std::cout << utec::sumar(d);
    std::cout << utec::sumar(l);

    utec::Rectangulo<int> r{10, 20};
    utec::Triangulo<int> t{20, 40};

    std::cout << utec::suma_areas(r, t);
    std::cout << utec::suma_areas(t, r);

    int arr1[4] {1, 2, 3, 4};
    double arr2[3] {10, 20, 30};

    auto total1 = suma_arreglos(arr1);
    auto total1 = suma_arreglos(arr2);

    return 0;
}
