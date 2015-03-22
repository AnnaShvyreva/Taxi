// Taxi.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include "Car.h"
#include "Bus.h" 
#include "Minibus.h"
#include <locale>
#include "Passenger.h"
#include "Station.h"
//#include <windows.h>
//#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void KeeEnter(Car* car, size_t i)
{
	char c;
	do
	{
		size_t begin=0, end=0;
		std::string name="";
		do 
		{
			std:: cout<<"Введите имя пассажира\n";
			std :: cin >> name;
			std:: cout<<"Всего в маршруте "<< i<<" остановок, выберите остановку, на которой появится этот пассажир\n";
			std:: cin >> begin;
		} while (begin < 1 || begin > i) ;
		do
		{
			std:: cout<<"Выберите остановку, до которой ему надо доехать\n";
			std:: cin >> end;
		} while (end < 1 || end > i || begin == end);
		Passenger *pas = new Passenger(name, end-1);
		car ->get_route()->ReturnStation(begin-1) -> AddPasseger(pas);
			
		std:: cout<<"Ввeсти еще пассажира? Y - да, N - нет\n";
		std:: cin >> c;	
		} while (c != 'N' && c!= 'n');
}

void RandomGen(Car* car, size_t i)
{
	//randomize();
	//size_t n = random(1974)% 10;
	size_t n = rand()% 10;
	char *Pass_name[] = {"Pass1", "Pass2", "Pass3", "Pass4", "Pass5", "Pass6", "Pass7"};
	size_t begin, end;
	std::string name;

	for (size_t k = 0; k<n ; k++)
	{
		name = Pass_name[rand()%7];
		begin = rand()%i+1;
		end = rand()%i+1;

		if ((begin==end)&&(end!=i)) end++;
		else if (begin==end&&end==i) end--;
		Passenger *pas = new Passenger(name, end-1);
		car ->get_route()->ReturnStation(begin-1) -> AddPasseger(pas);
	}
}

void AddPass (Car *car, size_t i)
{
	char c;
	do
	{
		std:: cout<<"Ввести пассажиров для каждой остановки с заданием конечной станции вручную? Y - да, N - нет\n";
		std:: cin >> c;
	} while (c != 'Y' && c!= 'N' && c != 'y' && c!= 'n');

	if (c == 'Y' || c == 'y') KeeEnter(car, i);
	else RandomGen(car, i);
}

void Processing (Car *car, size_t i)//процесс на остановке
{
	if(car ->Going_Away(i)) //если кто-то выходит, удаляем из вектора машины
		car -> delete_inCar(i);
	
	car->get_route()->ReturnStation(i)->TakePasseger(car); //берем пассажиров с остановки
}

int main() {
	setlocale( LC_ALL,"Russian" );

	size_t i; //doing = 0;
	Car *car = nullptr;

	do 
	{
		std:: cout<<"Выберите тип машины: Minibus - введите 1, Bus - введите - 2 \n";
		std:: cin >> i;
	} while ((i!=1)&&(i!=2));

	if (i==1) car = new Minibus();
	if (i==2) car = new Bus();

	system("cls");
	std:: cout<<"Введите количество остановок в маршруте \n";
	std:: cin >> i;

	car -> set_route(i); //генерируем маршрут
	car -> nowStation = 0;
	car ->direction = UP;

	i=car ->get_route()->ReturnRoudLength(); //длина маршрута - количество остановок

	//AddPass(car, i); //начальная генерация пассажиров
	//RandomGen(car, i);
	
	

	do
	{
		//doing ++;
		//system("cls");

		// добавление новых пассажиров
		char c;
		do
		{
			std:: cout<<"Добавить новых пассажиров? Y - да, N - нет\n";
			std:: cin >> c;
		} while (c != 'Y' && c!= 'N' && c != 'y' && c!= 'n');

		if (c == 'Y' || c == 'y') AddPass(car, i);
		/////////////////////////
		system("cls");

		// изменеие направления движения такси и перемещение по станциям на каждый шаг цикла
		std:: cout<<"Свободных мест: "<< car ->Available_Seat() <<"\n";
		if (car ->direction == DOWN && car ->nowStation < i)
		{
			car ->nowStation++;
		}
		else if (car ->direction == DOWN && car ->nowStation == i)
		{
			//car ->direction = UP;
			car ->nowStation--;
		}
		else if (car ->direction == UP && (car ->nowStation == 1 || car ->nowStation == 0))
		{
			//car ->direction = DOWN;
			car ->nowStation++;
		}
		else if (car ->direction == UP && car ->nowStation > 1)
		{
			car ->nowStation--;
		}

		if ((car->nowStation == 1)||(car->nowStation==i))
		{
			if (car ->direction == DOWN) car ->direction = UP;
			else car->direction = DOWN;
		}

		for (size_t j = 0; j < i; j++) //вывод на экран
		{
			//если никто не выходит и мест нет, пропускаем остановку
			if (!car ->Available_Seat() && !car ->Going_Away(j)) 
				break;
			if (j == i-1)
			{
				if (car ->nowStation == j+1)
				{
					std::cout << "(*) ";
					car ->get_route()->ReturnStation(j) ->WritingPass();
					std:: cout << "  \n";
					Processing(car, j);/////////////////////////////////////////////////////////////////

				}
				else
				{
					std::cout << "("<<j+1<<") ";
					car ->get_route()->ReturnStation(j) ->WritingPass();
					std:: cout << "  \n";
					//Processing(car, j);/////////////////////////////////////////////////////////////////
				}
			}
			else
			{
				if (car ->nowStation == j+1)
				{
					std::cout << "(*) ";
					car ->get_route()->ReturnStation(j) ->WritingPass();
					std:: cout << "  \n | \n | \n | \n";
					Processing(car, j);/////////////////////////////////////////////////////////////////
				}
				else
				{
					std::cout << "("<<j+1<<") ";
					car ->get_route()->ReturnStation(j) ->WritingPass();
					std:: cout << "  \n | \n | \n | \n";
					//Processing(car, j);/////////////////////////////////////////////////////////////////
				}
			}
		}

		// забор пассажиров

		//таймер, чтоб картинка была видима
//		while (true)
//		{
//			clock_t time = clock();
//			if (double(time)/ CLOCKS_PER_SEC >= 5*doing)
//			break;
//		}
		//Sleep (3000);

		//system("PAUSE");
	}while (true);


	system("PAUSE");
	return 0;
}