/*  Программа "Списки":
    Версия: 1.0
    Год: 2023
    Разработчик: Хусаинов А.С.
    Группа: ИНБб-1301
Задание:
1.)	Составить программу, которая содержит текущую информацию о наличии товара на складе.
Сведения о товаре включают:
•	название товара;
•	название магазина, в котором продается товар;
•	стоимость товара в рублях.
•	номер партии товара.
2.)	Программа должна обеспечивать:
•	хранение сведений обо всех товарах в виде односвязного списка (очередь);
•	добавление данных о новых товарах;
•	удаление данных о товаре, номер которого введен с клавиатуры;
•	вывод сведений обо всех товарах;
•	по запросу выводятся сведения о товаре, название которого введено с клавиатуры.
3.)	Программа должна обеспечивать диалог с помощью меню.
*/

#include <iostream>
#include <string>
#include "windows.h"
#include <iomanip>

using namespace std;

struct storage
{
	string sName;
	string sShopName;
	string sPrice;
	int sNumber;

	storage* next;
}; storage* head = NULL;

void storage_push_back(string sName, string sShopName, string sPrice, int sNumber) {
	storage* Node = new storage;
	storage* current = NULL;
	storage* previous = NULL;
	if (head == NULL) {
		Node->sName = sName;
		Node->sShopName = sShopName;
		Node->sPrice = sPrice;
		Node->sNumber = sNumber;

		head = Node;
		head->next = NULL;
	} else {
		current = head;
		while (current) {
			previous = current;
			current = current->next;
		}
		Node->sName = sName;
		Node->sShopName = sShopName;
		Node->sPrice = sPrice;
		Node->sNumber = sNumber;
		
		Node->next = NULL;
		previous->next = Node;
	}
}

void storage_remove(int iNumber) {
	storage* previous = 0;
	storage* current = head;
	bool stop = false;
	int n;
	if (head != NULL) {
		while (stop != true) {
			if (current != NULL) {
				if (current->sNumber == iNumber) {
					cout << setw(28) << "           Товар            " << "|" << setw(29) << "           Магазин           " << "|" << setw(16) << "      Цена      " << "|" << setw(16) << "  Номер партии  " << "|\n";
					cout << setw(28) << left << current->sName << "|" << setw(29) << current->sShopName << "|" << right << setw(16) << current->sPrice << "|" << setw(16) << current->sNumber << "|\n";
					cout << "Вы желаете удалить данный товар или продолжить поиск (1=Да/2=Нет/3=Продолжить поиск). Введите ответ: ";
					cin >> n;
					switch (n) {
					case 1:
						if (current == head) {
							head = head->next;
							free(current);
							cout << endl << "Успешно удалено." << endl << endl;
							stop = true;
						}
						else {
							previous->next = current->next;
							free(current);
							cout << endl << "Успешно удалено." << endl << endl;
							stop = true;
						}
						break;
					case 2:
						cout << endl << "Вы отменили удаление." << endl << endl;
						stop = true;
						break;
					case 3:
						system("cls");
						cout << endl << "Продолжаем поиск..." << endl << endl;
						break;
					}
				}
			} else {
				cout << endl << "Товара с таким номером партии нет." << endl << endl;
				stop = true;
			}
			if (stop == false)
			{
				if (current != NULL)
				{
					previous = current;
					current = current->next;
				}
				else {
					cout << endl << "Товара с таким номером партии нет." << endl << endl;
					stop = true;
				}
			}
		}
	}
	else 
		cout << "Данных не обнаружено." << endl;
}

void storage_output(){
	cout << "|" << setw(3) << " № " << "|" << setw(28) << "           Товар            " << "|" << setw(29) << "           Магазин           " << "|" << setw(16) << "      Цена      " << "|" << setw(16) << "  Номер партии  " << "|\n";
	int n = 1;
	if (head == NULL) {
		cout << "\n\n";
		cout << "!!! Данных не обнаружено!!!\n\n";
	}
	else {
		storage* current = head;
		while (current != NULL) {
			cout << "|" << setw(3) << right << n << "|" << setw(28) << left << current->sName << "|" << setw(29) << current->sShopName << "|" << right << setw(16) << current->sPrice << "|" << setw(16) << current->sNumber << "|\n";
			current = current->next; n++;
		}
		cout << "\n\n";
	}
}

void storage_find(string Input) {
	storage* current = head;
	bool find = false;
	int n = 1;
	if (head != NULL) {
		cout << "|" << setw(3) << " № " << "|" << setw(28) << "           Товар            " << "|" << setw(29) << "           Магазин           " << "|" << setw(16) << "      Цена      " << "|" << setw(16) << "  Номер партии  " << "|\n";
		while (current != NULL) {
			if (current->sName == Input) {
				cout << "|" << setw(3) << right << n << "|" << setw(28) << left << current->sName << "|" << setw(29) << current->sShopName << "|" << right << setw(16) << current->sPrice << "|" << setw(16) << current->sNumber << "|\n";
				find = true;
			}
			n++;
			current = current->next;
		}
		if (find == false) {
			cout << "Совпадений нет." << endl << endl;
		}
	}
	else cout << "Список пуст!" << endl << endl;
}

int iMenu() {
	int iMenu;
	system("cls");
	cout << "Меню:" << endl;
	cout << "1. Добавление нового товара." << endl;
	cout << "2. Вывод списка всех товаров." << endl;
	cout << "3. Удаление товара по номеру партии." << endl;
	cout << "4. Поиск товара по названию." << endl;
	cout << "5. Справка о программе." << endl;
	cout << "6. Выход." << endl;
	cout << "Введите пункт меню: ";
	cin >> iMenu;
	system("cls");

	return iMenu;
}

int main() {
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	string Name, ShopName, Price, Input;
	storage* current = NULL;
	storage* previous = NULL;
	int iM, Number;
	
	do {
		iM = iMenu();
		switch (iM) {
		case 1:
			cout << "Введите название товара: ";
			cin.get(); getline(cin, Name);
			cout << "Введите название магазина: ";
			getline(cin, ShopName);
			cout << "Введите цену товара: ";
			getline(cin, Price);
			cout << "Введите номер партии товара: ";
			cin >> Number;
			storage_push_back(Name, ShopName, Price, Number);
			break;
		case 2:
			storage_output();
			system("pause");
			break;
		case 3:
			int iNumber;
			cout << "Введите номер товара в партии: ";
			cin >> iNumber;
			storage_remove(iNumber);

			system("pause");
			break;
		case 4:
			cout << "Введите название товара для поиска: ";
			cin.get(); getline(cin, Input);
			storage_find(Input);
			system("pause");
			break;
		case 5:
			cout << "Программа: 'Списки'" << endl;
			cout << "Версия: 1.0" << endl;
			cout << "Год: 2023" << endl;
			cout << "Разработчик: Хусаинов А.С." << endl;
			cout << "Группа: ИНБб - 1301" << endl;
			system("pause");
			break;
		case 6:
			current = head;
			if (head != NULL)
				if (head->next == NULL) {
					free(head);
				}
				else {
					while (current)
					{
						previous = current;
						current = current->next;
						free(previous);
					}
				}
			cout << "Память очищена. Выходим из программы." << endl;
			break;
		default:
			cout << "Некорректный ввод. Попробуйте ещё." << endl;
			cin.clear();
			system("pause");
			break;
		}

	} while (iM != 6);
}
