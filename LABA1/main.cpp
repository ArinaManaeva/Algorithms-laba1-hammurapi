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

bool Round();
void GetUserData();
void Start();


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
		cin >> purchasedAcres;
		while (purchasedAcres * priceOfAcre > wheat)
		{
			cout << "�� ������� ������� ��� �������. " << endl << "������� ����� ����� ����������� ������? " << endl;
			cin >> purchasedAcres;
		}
		acreLand += purchasedAcres;
		wheat -= priceOfAcre * purchasedAcres;

		cout << "������� ����� ����� ����������� �������?" << endl;
		cin >> soldedAcres;
		while (soldedAcres > acreLand) 
		{
			cout << "�� ������� ����� ��� �������. " << endl << "������� ����� ����� ����������� �������? " << endl;
			cin >> soldedAcres;
		}
		acreLand -= soldedAcres;
		wheat += priceOfAcre * soldedAcres;

		cout << "������� ������� ������� ����������� ������? " << endl;
		cin >> wheatForEat;
		while (wheatForEat > wheat)
		{
			cout << "�� ������� �������. " << endl << "������� ������� ������� ����������� ������? " << endl;
			cin >> wheatForEat;
		}
		wheat -= wheatForEat;

		cout << "������� ����� ����� ����������� �������? " << endl;
		cin >> acreForPlanted;
		while (acreForPlanted > wheat)
		{
			cout << "�� ������� �������. " << endl << "������� ����� ����� ����������� �������? " << endl;
			cin >> acreForPlanted;
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
		ratEatenPercent = (rand() % 701) / 10000;
		//cout << ratEatenPercent << endl;
		wheat -= (wheat * ratEatenPercent);
		wheatEatenByRats = wheatBeforeRatEaten - wheat;

		// Feeded people
		float feededPopulation = wheatForEat / 20;
		//cout << feededPopulation << endl;
		if (feededPopulation < population) {
			deadedPeopleOfHunger = population - feededPopulation;
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
			cout<< "��������� ������ ������ ����������: " << population << " �������; " << endl <<
			"�� ������� " << wheatWasHarvested << " ������� �������, �� " << wheatFromAcre << " ������ � ����; "
			<< endl << "����� ��������� " << wheatEatenByRats << " ������� �������, ������� " << wheat << " ������ � �������; "
			<< endl << "����� ������ �������� " << acreLand << " �����;" << endl <<
			"1 ��� ����� ����� ������ " << priceOfAcre << " ������." << endl <<
			"��� ���������, ���������� ?" << endl;
	}

	else 
	{
		cout << "���������: " << population << endl << " �������: " << wheat << endl << " ���������� �����: " << acreLand << endl;
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