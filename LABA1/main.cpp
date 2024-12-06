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
		cout << "�� ������� ������� ���� ��� ����������." << endl;
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
			cout << "���������� ���������." << endl;
		}

		else
		{
			bool userAnswer;
			cout << "������� ����������. ������� ��� ���������? 1 - ��, 0 - ���: ";

			while (!(cin >> userAnswer))
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				cout << "������������ ����. ����������, ������� 1 (��) ��� 0 (���): " << endl;
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

				cout << "���������� ������� ���������." << endl << endl;
			}
		}

		file.close();
	}

	else
	{
		cout << "���� �� ������ ��� ���� �� ������� �������." << endl << endl;
	}
}


bool Round()
{
	Start();

	while (numberRound <= 10)
	{

		priceOfAcre = rand() % 10 + 17;

		cout << "������� ����� ����� ����������� ������? " << endl;
		while (true)
		{
			cin >> purchasedAcres;

			if (cin.fail() || purchasedAcres < 0)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�� ���������� ��������." << endl;
				cout << "������� ����� ����� ����������� ������? " << endl;
				continue;
			}

			if (purchasedAcres * priceOfAcre > wheat)
			{
				cout << "�� ������� ������� ��� �������. " << endl;
				cout << "������� ����� ����� ����������� ������? " << endl;
				cin >> purchasedAcres;
			}
			else
			{
				break;
			}
		}
		acreLand += purchasedAcres;
		wheat -= priceOfAcre * purchasedAcres;

		cout << "������� ����� ����� ����������� �������? " << endl;
		while (true)
		{
			cin >> soldedAcres;

			if (cin.fail() || soldedAcres < 0)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�� ���������� ��������." << endl;
				cout << "������� ����� ����� ����������� �������? " << endl;
				continue;
			}

			if (soldedAcres > acreLand)
			{
				cout << "�� ������� ����� ��� �������. " << endl << "������� ����� ����� ����������� �������? " << endl;
				cin >> soldedAcres;
			}
			else
			{
				break;
			}
		}
		acreLand -= soldedAcres;
		wheat += priceOfAcre * soldedAcres;

		cout << "������� ������� ������� ����������� ������? " << endl;
		while (true)
		{
			cin >> wheatForEat;

			if (cin.fail() || wheatForEat < 0)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�� ���������� ��������." << endl;
				cout << "������� ������� ������� ����������� ������? " << endl;
				continue;
			}

			if (wheatForEat > wheat)
			{
				cout << "�� ������� �������. " << endl << "������� ������� ������� ����������� ������? " << endl;
				cin >> wheatForEat;
			}
			else
			{
				break;
			}
		}
		wheat -= wheatForEat;

		cout << "������� ����� ����� ����������� �������? " << endl;
		while (true)
		{
			cin >> acreForPlanted;

			if (cin.fail() || wheatForEat < 0)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�� ���������� ��������." << endl;
				cout << "������� ����� ����� ����������� �������? " << endl;
				continue;
			}

			if (acreForPlanted > wheat)
			{
				cout << "�� ������� �������. " << endl << "������� ����� ����� ����������� �������? " << endl;
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
			cout << "�� ���������!" << endl;
			cout << "����� ������: " << numberRound << endl;
			cout << "������ ����� �� ������ �� �����: " << deadedPeopleOfHunger << endl;
			if (isPlague)
			{
				cout << "���� ����." << endl;
			}

			else
			{
				cout << "���� �� ����." << endl;
			}
			cout << "������� ��������� ������: " << population << endl;
			cout << "������� ���� �������: " << wheatWasHarvested << endl;
			cout << "������� ���� �������� � ����: " << wheatFromAcre << endl;
			cout << "������� ���������� �����: " << wheatEatenByRats << endl;
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
		cout << "��� ����������, �������� �������� ����. � ���� " << numberRound << " ������ ����������� ��������� " << deadedPeopleOfHunger << " ������� ������ � ������, � "
			<< arrivedPeople << " ������� ������� � ��� ������� �����; " << endl;
		if (isPlague)
		{
			cout << "���� ���������� �������� ���������;" << endl;
		}
		cout << "��������� ������ ������ ����������: " << population << " �������; " << endl <<
			"�� ������� " << wheatWasHarvested << " ������� �������, �� " << wheatFromAcre << " ������ � ����; "
			<< endl << "����� ��������� " << wheatEatenByRats << " ������� �������, ������� " << wheat << " ������ � �������; "
			<< endl << "����� ������ �������� " << acreLand << " �����;" << endl <<
			"1 ��� ����� ����� ������ " << priceOfAcre << " ������." << endl <<
			"��� ���������, ���������� ?" << endl;
	}

	if (numberRound == 10)
	{
		cout << "���������: " << population << endl << " �������: " << wheat << endl << " ���������� �����: " << acreLand << endl;
		EndGame();
	}

	else
	{
		cout << "���������: " << population << endl << " �������: " << wheat << endl << " ���������� �����: " << acreLand << endl;
	}
}


void EndGame()
{
	cout << "���� ���������!" << endl;
	acreForPerson = acreLand / population;
	percentOfDeaded = percentOfDeaded / 10;

	if (percentOfDeaded > 33 && acreForPerson < 7)
	{
		cout << "��-�� ����� ���������������� � ����������, ����� ������� ����, � ������ ��� �� ������. " << endl <<
			"������ �� ��������� ������� ������ ������������� � ��������." << endl;
	}

	if (percentOfDeaded > 10 && acreForPerson < 9)
	{
		cout << "�� ������� �������� �����, ������� ������ � ����� ��������. " << endl <<
			"����� �������� � �����������, � ����� ������ �� ������ ������ ��� ����������." << endl;
	}

	if (percentOfDeaded > 3 && acreForPerson < 10)
	{
		cout << "�� ���������� ������ �������, � ���, �������, ���� ���������������, " << endl <<
			"�� ������ ������ �� ������� ��� �� ����� ������ �����." << endl;
	}

	else
	{
		cout << "����������! ���� �������, �������� � ���������� ������ �� ���������� �� �����. " << endl;
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