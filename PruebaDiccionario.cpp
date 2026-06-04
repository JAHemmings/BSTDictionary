#include <iostream>
#include <string>
#include "BSTDictionary.h"

using namespace std;

int main() {
    BSTDictionary<int, string>* diccionario1 = new BSTDictionary<int, string>();
    BSTDictionary<int, string>* diccionario2 = new BSTDictionary<int, string>();

    int option = -1;

    while (option != 0) {
        cout << endl;

        cout << "DICCIONARIO 1 " << endl;
        diccionario1->print();
        cout << endl;

        cout << "DICCIONARIO 2" << endl;
        diccionario2->print();
        cout << endl;

        cout << "1. Insert" << endl;
        cout << "2. Remove" << endl;
        cout << "3. Get Value" << endl;
        cout << "4. Set Value" << endl;
        cout << "5. Contains" << endl;
        cout << "6. Clear" << endl;
        cout << "7. Get Keys" << endl;
        cout << "8. Get Values" << endl;
        cout << "9. Update" << endl;
        cout << "10. Zip" << endl;
        cout << "0. Salir" << endl;

        cout << "Opcion: ";
        cin >> option;

        try {
            int numDic;
            int key;
            string value;
            BSTDictionary<int, string>* D = nullptr;

            if (option != 0) {
                cout << "Diccionario (1 o 2): ";
                cin >> numDic;

                if (numDic == 1)
                    D = diccionario1;
                else if (numDic == 2)
                    D = diccionario2;
                else
                    throw runtime_error("Diccionario invalido.");
            }

            if (option == 1) {
                cout << "Llave: ";
                cin >> key;
                cout << "Valor: ";
                cin >> value;
                D->insert(key, value);
            }

            else if (option == 2) {
                cout << "Llave: ";
                cin >> key;
                cout << "Valor eliminado: " << D->remove(key) << endl;
            }

            else if (option == 3) {
                cout << "Llave: ";
                cin >> key;
                cout << "Valor: " << D->getValue(key) << endl;
            }

            else if (option == 4) {
                cout << "Llave: ";
                cin >> key;
                cout << "Nuevo valor: ";
                cin >> value;
                D->setValue(key, value);
            }

            else if (option == 5) {

                cout << "Llave: ";
                cin >> key;

                if (D->contains(key))
                    cout << "La llave existe" << endl;
                else
                    cout << "La llave no existe" << endl;
            }

            else if (option == 6) {
                D->clear();
                cout << "Diccionario vaciado" << endl;
            }

            else if (option == 7) {
                List<int>* keys = D->getKeys();
                keys->goToStart();
                while (!keys->atEnd()) {
                    cout << keys->getElement() << " ";
                    keys->next();
                }
                cout << endl;
                delete keys;
            }

            else if (option == 8) {
                List<string>* values = D->getValues();
                values->goToStart();
                while (!values->atEnd()) {
                    cout << values->getElement() << " ";
                    values->next();
                }
                cout << endl;
                delete values;
            }

            else if (option == 9) {
                if (D == diccionario1)
                    diccionario1->update(diccionario2);
                else
                    diccionario2->update(diccionario1);
                cout << "Update realizado" << endl;
            }

            else if (option == 10) {
                int n;
                cout << "Cantidad de elementos: ";
                cin >> n;
                List<int>* keys = new DLinkedList<int>();
                List<string>* values = new DLinkedList<string>();
                for (int i = 0; i < n; i++) {
                    cout << "Llave #" << i + 1 << ": ";
                    cin >> key;
                    keys->append(key);
                }
                for (int i = 0; i < n; i++) {
                    cout << "Valor #" << i + 1 << ": ";
                    cin >> value;
                    values->append(value);
                }
                D->zip(keys, values);
                delete keys;
                delete values;
                cout << "Zip realizado" << endl;
            }

            else if (option == 0) {
                cout << "Saliendo" << endl;
            }

            else {
                cout << "Opcion invalida" << endl;
            }
        }
        catch (runtime_error& e) {
            cout << "ERROR: " << e.what() << endl;
        }
    }

    delete diccionario1;
    delete diccionario2;

    return 0;
}