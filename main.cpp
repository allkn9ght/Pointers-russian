#include <iostream>
#include <windows.h>
#include <cstring>
using namespace std;


    struct Pizza {
    char Title[23];
    int Size;
    double Cost;
    };

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Программа иллюстрирующая работу с указателями \n\n";
    const int count_of_pizza = 3;
    Pizza Packet_of_Pizza[count_of_pizza];

    strncpy(Packet_of_Pizza[0].Title, "Neopolitano", 12);
    Packet_of_Pizza[0].Size = 20;
    Packet_of_Pizza[0].Cost = 555.55;

    Pizza *p_pizza = &Packet_of_Pizza[0];
    p_pizza++;

    strncpy((*p_pizza).Title, "Romana",7);
    p_pizza->Size = 25;
    p_pizza->Cost = 657.95;
    p_pizza++;

    strncpy(p_pizza->Title, "Calzone", 8);
    p_pizza->Size = 30;
    p_pizza->Cost = 777.77;

    const int *p_cop = &count_of_pizza;

    for(int i = 0; i<*p_cop; i++){
        cout << "Пицца №" << i+1 << endl
        << "Название - " << Packet_of_Pizza[i].Title;
        cout << ", Размер " << Packet_of_Pizza[i].Size << " см"
        << ", Стоимость " << Packet_of_Pizza[i].Cost << " руб. \n";
        cout << &Packet_of_Pizza[i] << " - адрес пиццы в памяти \n\n";
    }

    cout << "Адрес третьей пиццы в памяти: " << p_pizza << "\n";
    cout << sizeof(Pizza) << " - количество байт занимаемых одной пиццой в памяти.\n\n";
    cout << sizeof(p_pizza->Title) << " - количество байт занимаемых в названии пиццы.\n\n";
    cout << sizeof(p_pizza->Cost) << " - количество байт занимаемых в цене пиццы.\n\n";
    cout << sizeof(p_pizza->Size) << " - количество байт занимаемых в размере пиццы.\n\n";
    cout << p_cop << " - адрес переменной хранящей кол-во пицц\n";
    cout << *p_cop << " - значение вышеуказанной перменной\n";
    cout << endl << "Для выхода нажмите <Enter>..";

    fflush(stdin);
    cin.get();
    return 0;

}
