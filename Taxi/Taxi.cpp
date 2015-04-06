// Taxi.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include "Car.h"
#include "Bus.h" 
#include "Minibus.h"
#include "Route.h"
#include <locale>
#include "Passenger.h"
#include "Station.h"
//#include <windows.h>
//#include <time.h>
#include <stdio.h>
#include <stdlib.h>

//void KeeEnter(Car* car, size_t i)
//{
//	std::string c="";
//	do
//	{
//		size_t begin=0, end=0;
//		std::string name="";
//		do 
//		{
//			std:: cout<<"Введите имя пассажира\n";
//			std :: cin >> name;
//			std:: cout<<"Всего в маршруте "<< i<<" остановок, выберите остановку, на которой появится этот пассажир\n";
//			std:: cin >> begin;
//		} while (begin < 1 || begin > i) ;
//		do
//		{
//			std:: cout<<"Выберите остановку, до которой ему надо доехать\n";
//			std:: cin >> end;
//		} while (end < 1 || end > i || begin == end);
//		Passenger *pas = new Passenger(name, end-1);
//		//car ->get_route()->get_station(begin-1) -> AddPasseger(pas);
//		car->get_route().get_station(begin-1).AddPasseger(pas);
//			
//		std:: cout<<"Ввeсти еще пассажира? Y - да, N - нет\n";
//		std:: cin >> c;	
//		} while (c != "N" && c!= "n");
//}

void KeeEnter(Route* route)
{
	std::string c="";
	do
	{
		size_t begin=0, end=0;
		std::string name="";
		do 
		{
			std:: cout<<"Введите имя пассажира\n";
			std :: cin >> name;
			std:: cout<<"Всего в маршруте "<< (*route).get_station_size()<<" остановок, выберите остановку, на которой появится этот пассажир\n";
			std:: cin >> begin;
		} while (begin < 1 || begin > (*route).get_station_size()) ;
		do
		{
			std:: cout<<"Выберите остановку, до которой ему надо доехать\n";
			std:: cin >> end;
		} while (end < 1 || end > (*route).get_station_size() || begin == end);
		Passenger *pas = new Passenger(name, end-1);
		//car ->get_route()->get_station(begin-1) -> AddPasseger(pas);
		(*route).get_station(begin-1).AddPasseger(pas);
			
		std:: cout<<"Ввeсти еще пассажира? Y - да, N - нет\n";
		std:: cin >> c;	
		} while (c != "N" && c!= "n");
}

void RandomGen(Route* route)
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
		begin = rand()%(*route).get_station_size()+1;
		end = rand()%(*route).get_station_size()+1;

		if ((begin==end)&&(end!=(*route).get_station_size())) end++;
		else if (begin==end&&end==(*route).get_station_size()) end--;
		Passenger *pas = new Passenger(name, end-1);
		//car ->get_route()->get_station(begin-1) -> AddPasseger(pas);
		(*route).get_station(begin-1).AddPasseger(pas);
	}
}

//void AddPass (Car *car, size_t i)
//{
//	std::string c="";
//	do
//	{
//		std:: cout<<"Ввести пассажиров для каждой остановки с заданием конечной станции вручную? Y - да, N - нет\n";
//		std:: cin >> c;
//	} while (c != "Y" && c!= "N" && c != "y" && c!= "n");
//
//	if (c == "Y" || c == "y") KeeEnter(car, i);
//	else RandomGen(car, i);
//}

void AddPass (Route* route, int i)
{
	std::string c="";
	do
	{
		std:: cout<<"Ввести пассажиров для каждой остановки маршрута No "<< i+1 <<"с заданием конечной станции вручную? Y - да, N - нет\n";
		std:: cin >> c;
	} while (c != "Y" && c!= "N" && c != "y" && c!= "n");

	if (c == "Y" || c == "y") KeeEnter(route);
	else RandomGen(route);
}

void Processing (Car *car, size_t i)//процесс на остановке
{
	if(car ->Going_Away(i)) //если кто-то выходит, удаляем из вектора машины
		car -> delete_inCar(i);
	
	//car->get_route()->get_station(i)->TakePasseger(car); //берем пассажиров с остановки
	car->get_route().get_station(i).TakePasseger(car); //берем пассажиров с остановки
}

//void CarGen (std::vector<Car*>* cars, std::vector<Route*>* routes)
void CarGen (std::vector<Route*>* routes)
{
	size_t i;

	do 
	{
		std:: cout<<"Выберите тип машины: Minibus - введите 1, Bus - введите - 2 \n";
		std:: cin >> i;
	} while ((i!=1)&&(i!=2));

	if (i==1) 
	{
		Car* newcar = new Minibus( (*routes)[(*routes).size()-1], (*routes)[(*routes).size()-1]->get_station_size());
		/*//////////////(*cars).push_back(newcar);*/
		(*routes)[(*routes).size()-1] -> AddCar(newcar);
	}
	if (i==2)
	{	
		Car* newcar = new Bus( (*routes)[(*routes).size()-1], (*routes)[(*routes).size()-1]->get_station_size());
		//(*cars).push_back(newcar);
		(*routes)[(*routes).size()-1] -> AddCar(newcar);
	}
}

//void RouteGen(std::vector<Car*>* cars, std::vector<Route*>* routes)
void RouteGen(std::vector<Route*>* routes)
{
	size_t i;
	std::string c="";

	std:: cout<<"Введите количество остановок в маршруте \n";
	std:: cin >> i;
	(*routes).push_back(new Route(i));

	//system("cls");

	do
	{
		do 
		{
			std:: cout<<"Добавить машину? Y - да, N - нет\n";
			std:: cin >> c;
		} while (c != "Y" && c!= "N" && c != "y" && c!= "n");

		if (c=="Y"|c=="y")
			//CarGen(cars, routes);
			CarGen(routes);
		else break;
	} while (c != "N" || c!= "n");

	//system("cls");
}



int main() {
	setlocale( LC_ALL,"Russian" );

	//size_t i; //doing = 0;
	std::string c="";
	//std::vector<Car*>* cars = new std::vector<Car*>;
	std::vector<Route*>* routes = new std::vector<Route*>;

	do
	{
		do 
		{
			std:: cout<<"Добавить маршрут? Y - да, N - нет\n";
			std:: cin >> c;
		} while (c != "Y" && c!= "N" && c != "y" && c!= "n");

		if (c=="Y"||c=="y")
			//RouteGen(cars, routes);
			RouteGen(routes);
		else break;
	} while (c!="N"||c!="n");

	//car -> set_route(i); //генерируем маршрут
	//car -> set_now_station(0);
	//car -> set_direction(UP);

	//i=car ->get_route()->ReturnRoudLength(); //длина маршрута - количество остановок
	//i=(*car).get_route().ReturnRoudLength(); //длина маршрута - количество остановок

	//AddPass(car, i); //начальная генерация пассажиров
	//RandomGen(car, i);
	
	do
	{
		//doing ++;
		//system("cls");

//		// изменеие направления движения такси и перемещение по станциям на каждый шаг цикла
//		for (size_t k=0; k<(*routes).size();k++)
//		{
//			std:: cout<<"Маршрут "<< k+1 <<".\n";
//			for (size_t kk=0; kk<(*routes)[k]->get_car_size();kk++)
//			{
//				//size_t i = (*cars)[k] ->get_route().get_station_size();
//				Car nowCar = (*routes)[k]->get_car(kk);
//
//				size_t i = (*routes)[k]->get_route_length();
//				std:: cout<<"Машина "<< kk+1 <<". Свободных мест: "<< nowCar.Available_Seat() <<"\n";
//
//				if (nowCar.get_direction()==DOWN)
//				{
//					nowCar.set_now_station( (nowCar.get_now_station()) + nowCar.get_step());
//
//					if (nowCar.get_now_station() > i)
//					{
//						nowCar.set_now_station( (nowCar.get_now_station()) - 2*nowCar.get_step());
//						nowCar.set_direction(UP);
//					}
//
//				}
//				else if (nowCar.get_direction() == UP)
//				{
//					nowCar.set_now_station( (nowCar.get_now_station()) - nowCar.get_step());
//
//					if (nowCar.get_now_station() < 0)
//					{
//						nowCar.set_now_station( (nowCar.get_now_station()) + 2*nowCar.get_step());
//						nowCar.set_direction(DOWN);
//					}
//				}
//
////				if (nowCar.get_direction() == DOWN && nowCar.get_now_station() < i)
////				{
////					nowCar.set_now_station( (nowCar.get_now_station()) + nowCar.get_step());
////				}
////				else if (nowCar.get_direction() == DOWN && nowCar.get_now_station() == i)
////				{
////					//car ->direction = UP;
////					nowCar.set_now_station( (nowCar.get_now_station()) - nowCar.get_step());
////				}
////				else if (nowCar.get_direction() == UP && (nowCar.get_now_station() == 1 || nowCar.get_now_station() == 0))
////				{
////					//car ->direction = DOWN;
////					nowCar.set_now_station( (nowCar.get_now_station()) + nowCar.get_step());
////				}
////				else if (nowCar.get_direction() == UP && nowCar.get_now_station() > 1)
////				{
////					//(*routes)[k]->get_car(kk).set_now_station( ((*routes)[k]->get_car(kk).get_now_station()) -1);
////					nowCar.set_now_station( (nowCar.get_now_station()) - nowCar.get_step());
////				}
//
//				if ((nowCar.get_now_station() == 1)||(nowCar.get_now_station()==i))
//				{
//					if (nowCar.get_direction() == DOWN) nowCar.set_direction(UP);
//					else nowCar.set_direction(DOWN);
//				}
//			}
//		}
		
		//std::string c="";
		for (size_t k=0; k<(*routes).size();k++) // проход по всем маршрутам
		{
			
			// добавление новых пассажиров
			do
			{
				std:: cout<<"Добавить новых пассажиров? Y - да, N - нет\n";
				std:: cin >> c;
			} while (c != "Y" && c!= "N" && c != "y" && c!= "n");

			//if (c == "Y" || c == "y") AddPass(car, i);
			if (c == "Y" || c == "y") AddPass((*routes)[k], k);
			/////////////////////////
			//system("cls");

			//вывод на экран
			for (size_t j = 0; j < (*routes)[k]->get_route_length(); j++) 
			{
//				//если никто не выходит и мест нет, пропускаем остановку
//
//				for (size_t kk=0; kk<(*routes)[k]->get_car_size();kk++)
//				{
//					if (!car ->Available_Seat() && !car ->Going_Away(j)) 
//						break;
//				}

				//if (j == (*routes)[k]->get_route_length()-1)// если последняя остановка
				//{

				std::cout << "("<<j+1<<") ";

					for (size_t kk=0; kk<(*routes)[k]->get_car_size();kk++)
					{
						if ((*routes)[k]->get_car(kk).get_now_station() == j+1)
						{
							std::cout << "(*"<<kk<<"*) ";
							//car ->get_route()->get_station(j) ->WritingPass();
							//(*routes)[k]->get_station(j).WritingPass();
							//car ->get_route().get_station(j).WritingPass();
							//std:: cout << "  \n";
							//Processing(&(*routes)[k]->get_car(kk),j);
							//Processing(car, j);/////////////////////////////////////////////////////////////////

						}
//						else
//						{
//							//std::cout << "("<<j+1<<") ";
//							//car ->get_route()->get_station(j) ->WritingPass();
//							//car ->get_route().get_station(j).WritingPass();
//							(*routes)[k]->get_station(j).WritingPass();
//							//std:: cout << "  \n";
//						}
					//}
//				}
//				else
//				{
//					for (size_t kk=0; kk<(*routes)[k]->get_car_size();kk++)
//					{
//						if ((*routes)[k]->get_car(kk).get_now_station() == j+1)
//						{
//							std::cout << "(*"<<kk<<"*) ";
//							//car ->get_route()->get_station(j) ->WritingPass();
//							//car ->get_route().get_station(j).WritingPass();
//							(*routes)[k]->get_station(j).WritingPass();
//							std:: cout << "  \n | \n | \n | \n";
//							Processing(&(*routes)[k]->get_car(kk),j);
//							//Processing(car, j);/////////////////////////////////////////////////////////////////
//						}
//						else
//						{
//							std::cout << "("<<j+1<<") ";
//							//car ->get_route()->get_station(j) ->WritingPass();
//							//car ->get_route().get_station(j).WritingPass();
//							(*routes)[k]->get_station(j).WritingPass();
//							std:: cout << "  \n | \n | \n | \n";
//						}
//					}

						
    			}
					(*routes)[k]->get_station(j).WritingPass();

					if (j == (*routes)[k]->get_route_length()-1)
					{
						std:: cout << "  \n";
					}
					else
					{
						std:: cout << "  \n | \n | \n | \n";
					}

			}
			for (size_t kk=0; kk<(*routes)[k]->get_car_size();kk++)
			{
				Processing(&(*routes)[k]->get_car(kk), (*routes)[k]->get_car(kk).get_now_station()-1);
			}
		}

		// изменеие направления движения такси и перемещение по станциям на каждый шаг цикла
		for (size_t k=0; k<(*routes).size();k++)
		{
			std:: cout<<"Маршрут "<< k+1 <<".\n";
			for (size_t kk=0; kk<(*routes)[k]->get_car_size();kk++)
			{
				//size_t i = (*cars)[k] ->get_route().get_station_size();
				Car& nowCar = (*routes)[k]->get_car(kk);

				size_t i = (*routes)[k]->get_route_length();
				std:: cout<<"Машина "<< kk+1 <<". Свободных мест: "<< nowCar.Available_Seat() <<"\n";

				if (nowCar.get_direction()==DOWN)
				{
					nowCar.set_now_station( (nowCar.get_now_station()) + nowCar.get_step());

					if (nowCar.get_now_station() > i)
					{
						nowCar.set_now_station( (nowCar.get_now_station()) - 2*nowCar.get_step());
						nowCar.set_direction(UP);
					}

				}
				else if (nowCar.get_direction() == UP)
				{
					nowCar.set_now_station( (nowCar.get_now_station()) - nowCar.get_step());

					if (nowCar.get_now_station() < 0)
					{
						nowCar.set_now_station( (nowCar.get_now_station()) + 2*nowCar.get_step());
						nowCar.set_direction(DOWN);
					}
				}

//				if (nowCar.get_direction() == DOWN && nowCar.get_now_station() < i)
//				{
//					nowCar.set_now_station( (nowCar.get_now_station()) + nowCar.get_step());
//				}
//				else if (nowCar.get_direction() == DOWN && nowCar.get_now_station() == i)
//				{
//					//car ->direction = UP;
//					nowCar.set_now_station( (nowCar.get_now_station()) - nowCar.get_step());
//				}
//				else if (nowCar.get_direction() == UP && (nowCar.get_now_station() == 1 || nowCar.get_now_station() == 0))
//				{
//					//car ->direction = DOWN;
//					nowCar.set_now_station( (nowCar.get_now_station()) + nowCar.get_step());
//				}
//				else if (nowCar.get_direction() == UP && nowCar.get_now_station() > 1)
//				{
//					//(*routes)[k]->get_car(kk).set_now_station( ((*routes)[k]->get_car(kk).get_now_station()) -1);
//					nowCar.set_now_station( (nowCar.get_now_station()) - nowCar.get_step());
//				}

				if ((nowCar.get_now_station() == 1)||(nowCar.get_now_station()==i))
				{
					if (nowCar.get_direction() == DOWN) nowCar.set_direction(UP);
					else nowCar.set_direction(DOWN);
				}
			}
		}

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

	//delete car->get_route();
	//delete car;
	//system("PAUSE");
	//return 0;
}