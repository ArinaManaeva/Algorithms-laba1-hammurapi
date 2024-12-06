#include <iostream>
#include <fstream>

using namespace std;

int population = 100;
int wheat = 2800;
int acreLand = 1000;
int numberRound = 0;
int deadedPeopleOfHunger = 0;
int arrivedPeople = 0;
bool isPlague = false;
float purchasedAcres = 0;
float soldedAcres = 0;
float wheatForEat = 0;
float acreForPlanted = 0;
int wheatWasHarvested = 0;
int	wheatFromAcre = 0;
int wheatEatenByRats = 0;
int priceOfAcre = 0;
float ratEatenPercent = 0;
bool isEndGame = false;
int acreForPerson = 0;
int percentOfDeadedRound = 0;
int percentOfDeaded = 0;

bool Round();
void Start();
void EndGame();


void SaveMaking()
{
	ofstream file("savedGame.txt", ios::trunc);

	if (file.is_open())
	{
		file << population << "\n"
			<< wheat << "\n"
			<< acreLand << "\n"
			<< numberRound << "\n"
			<< deadedPeopleOfHunger << "\n"
			<< arrivedPeople << "\n"
			<< isPlague << "\n"
			<< purchasedAcres << "\n"
			<< soldedAcres << "\n"
			<< wheatForEat << "\n"
			<< acreForPlanted << "\n"
			<< wheatWasHarvested << "\n"
			<< wheatFromAcre << "\n"
			<< wheatEatenByRats << "\n"
			<< priceOfAcre << "\n";

		file.close();
	}

	else
	{
		cout << "Не удалось открыть файл для сохранения." << endl;
	}
}


void UploadingSave()
{
	ifstream file("savedGame.txt", ios::ate);

	if (file.is_open())
	{
		bool isEmpty = (file.tellg() == 0);

		if (isEmpty)
		{
			cout << "Сохранение ненайдено." << endl;
		}

		else
		{
			bool userAnswer;
			cout << "Найдено сохранение. Желаете его загрузить? 1 - да, 0 - нет: ";

			while (!(cin >> userAnswer))
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				cout << "Неправильный ввод. Пожалуйста, введите 1 (да) или 0 (нет): " << endl;
			}

			if (userAnswer == 1)
			{
				file.seekg(0, ios::beg);

				file >> population;
				file >> wheat;
				file >> acreLand;
				file >> numberRound;
				file >> deadedPeopleOfHunger;
				file >> arrivedPeople;
				file >> isPlague;
				file >> purchasedAcres;
				file >> soldedAcres;
				file >> wheatForEat;
				file >> acreForPlanted;
				file >> wheatWasHarvested;
				file >> wheatFromAcre;
				file >> wheatEatenByRats;
				file >> priceOfAcre;

				cout << "Сохранение успешно прочитано." << endl << endl;
			}
		}

		file.close();
	}

	else
	{
		cout << "Файл не найден или файл не удалось открыть." << endl << endl;
	}
}


bool Round()
{
	Start();

	while (numberRound <= 10)
	{

		priceOfAcre = rand() % 10 + 17;

		cout << "Сколько акров земли повелеваешь купить? " << endl;
		while (true)
		{
			cin >> purchasedAcres;

			if (cin.fail() || purchasedAcres < 0)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Не корректное значение." << endl;
				cout << "Сколько акров земли повелеваешь купить? " << endl;
				continue;
			}

			if (purchasedAcres * priceOfAcre > wheat)
			{
				cout << "Не хватает пшеницы для покупки. " << endl;
				cout << "Сколько акров земли повелеваешь купить? " << endl;
				cin >> purchasedAcres;
			}
			else
			{
				break;
			}
		}
		acreLand += purchasedAcres;
		wheat -= priceOfAcre * purchasedAcres;

		cout << "Сколько акров земли повелеваешь продать? " << endl;
		while (true)
		{
			cin >> soldedAcres;

			if (cin.fail() || soldedAcres < 0)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Не корректное значение." << endl;
				cout << "Сколько акров земли повелеваешь продать? " << endl;
				continue;
			}

			if (soldedAcres > acreLand)
			{
				cout << "Не хватает земли для продажи. " << endl << "Сколько акров земли повелеваешь продать? " << endl;
				cin >> soldedAcres;
			}
			else
			{
				break;
			}
		}
		acreLand -= soldedAcres;
		wheat += priceOfAcre * soldedAcres;

		cout << "Сколько бушелей пшеницы повелеваешь съесть? " << endl;
		while (true)
		{
			cin >> wheatForEat;

			if (cin.fail() || wheatForEat < 0)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Не корректное значение." << endl;
				cout << "Сколько бушелей пшеницы повелеваешь съесть? " << endl;
				continue;
			}

			if (wheatForEat > wheat)
			{
				cout << "Не хватает пшеницы. " << endl << "Сколько бушелей пшеницы повелеваешь съесть? " << endl;
				cin >> wheatForEat;
			}
			else
			{
				break;
			}
		}
		wheat -= wheatForEat;

		cout << "Сколько акров земли повелеваешь засеять? " << endl;
		while (true)
		{
			cin >> acreForPlanted;

			if (cin.fail() || wheatForEat < 0)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Не корректное значение." << endl;
				cout << "Сколько акров земли повелеваешь засеять? " << endl;
				continue;
			}

			if (acreForPlanted > wheat)
			{
				cout << "Не хватает пшеницы. " << endl << "Сколько акров земли повелеваешь засеять? " << endl;
				cin >> acreForPlanted;
			}
			else
			{
				break;
			}
		}
		wheat -= acreForPlanted;

		// Harvested wheat from round
		wheatWasHarvested = 0;
		wheatFromAcre = rand() % 6 + 1;
		//cout << wheatFromAcre << endl;
		wheatWasHarvested += acreForPlanted * wheatFromAcre;
		wheat += wheatWasHarvested;

		// Wheat eaten by rats
		int wheatBeforeRatEaten = wheat;
		ratEatenPercent = (rand() % (7 - 0 + 1) + 0) / 100.0f;
		//cout << ratEatenPercent << endl;
		wheat -= (wheat * ratEatenPercent);
		wheatEatenByRats = wheatBeforeRatEaten - wheat;

		// Feeded people
		float feededPopulation = wheatForEat / 20;
		//cout << feededPopulation << endl;
		if (feededPopulation < population) {
			deadedPeopleOfHunger = population - feededPopulation;
			percentOfDeadedRound = deadedPeopleOfHunger / population * 100;
			percentOfDeaded += percentOfDeadedRound;
			if ((population - deadedPeopleOfHunger) / population < 0.45f) {
				isEndGame = true;
			}
			population -= deadedPeopleOfHunger;
		}

		// Arrived people
		arrivedPeople = deadedPeopleOfHunger / 2 + (5 - wheatFromAcre) * wheat / 600 + 1;
		//cout << arrivedPeople << endl;
		if (arrivedPeople > 50)
		{
			arrivedPeople = 50;
		}

		else if (arrivedPeople < 0)
		{
			arrivedPeople = 0;
		}
		population += arrivedPeople;

		if (rand() % 100 < 15)
		{
			isPlague = true;
			population = floor(population / 2);
		}

		if (isEndGame)
		{
			cout << "Вы проиграли!" << endl;
			cout << "Номер раунда: " << numberRound << endl;
			cout << "Умерло людей от голода за раунд: " << deadedPeopleOfHunger << endl;
			if (isPlague)
			{
				cout << "Чума была." << endl;
			}

			else
			{
				cout << "Чумы не было." << endl;
			}
			cout << "Текущее население города: " << population << endl;
			cout << "Пшеницы было собрано: " << wheatWasHarvested << endl;
			cout << "Пшеницы было получено с акра: " << wheatFromAcre << endl;
			cout << "Пшеницы уничтожили крысы: " << wheatEatenByRats << endl;
			return false;
		}

		++numberRound;

		SaveMaking();
		Start();
	}
	if (numberRound == 10)
	{
		EndGame();
	}

	return 0;
}


void Start()
{
	if (numberRound > 0 && numberRound <= 10) {
		cout << "Мой повелитель, соизволь поведать тебе. В году " << numberRound << " твоего высочайшего правления " << deadedPeopleOfHunger << " человек умерли с голоду, и "
			<< arrivedPeople << " человек прибыли в наш великий город; " << endl;
		if (isPlague)
		{
			cout << "Чума уничтожила половину населения;" << endl;
		}
		cout << "Население города сейчас составляет: " << population << " человек; " << endl <<
			"Мы собрали " << wheatWasHarvested << " бушелей пшеницы, по " << wheatFromAcre << " бушеля с акра; "
			<< endl << "Крысы истребили " << wheatEatenByRats << " бушелей пшеницы, оставив " << wheat << " бушеля в амбарах; "
			<< endl << "Город сейчас занимает " << acreLand << " акров;" << endl <<
			"1 акр земли стоит сейчас " << priceOfAcre << " бушель." << endl <<
			"Что пожелаешь, повелитель ?" << endl;
	}

	if (numberRound == 10)
	{
		cout << "Население: " << population << endl << " Пшеница: " << wheat << endl << " Количество земли: " << acreLand << endl;
		EndGame();
	}

	else
	{
		cout << "Население: " << population << endl << " Пшеница: " << wheat << endl << " Количество земли: " << acreLand << endl;
	}
}


void EndGame()
{
	cout << "Игра закончена!" << endl;
	acreForPerson = acreLand / population;
	percentOfDeaded = percentOfDeaded / 10;

	if (percentOfDeaded > 33 && acreForPerson < 7)
	{
		cout << "Из-за вашей некомпетентности в управлении, народ устроил бунт, и изгнал вас их города. " << endl <<
			"Теперь вы вынуждены влачить жалкое существование в изгнании." << endl;
	}

	if (percentOfDeaded > 10 && acreForPerson < 9)
	{
		cout << "Вы правили железной рукой, подобно Нерону и Ивану Грозному. " << endl <<
			"Народ вздохнул с облегчением, и никто больше не желает видеть вас правителем." << endl;
	}

	if (percentOfDeaded > 3 && acreForPerson < 10)
	{
		cout << "Вы справились вполне неплохо, у вас, конечно, есть недоброжелатели, " << endl <<
			"но многие хотели бы увидеть вас во главе города снова." << endl;
	}

	else
	{
		cout << "Фантастика! Карл Великий, Дизраэли и Джефферсон вместе не справились бы лучше. " << endl;
	}

}


int main()
{
	setlocale(LC_ALL, "rus");
	srand(static_cast<unsigned int>(time(0)));

	UploadingSave();

	Round();

	return 0;
}