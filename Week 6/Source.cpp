// Andrii Malakhovtsev
// CIS 1202 501
// October 6, 2024

#include<iostream>
#include<cstring>
#include<string>

using namespace std;

struct WinLoss
{
	int wins;
	int losses;
};

struct Team
{
	string name;
	WinLoss recordsTotal;
	WinLoss homeRecords;
	WinLoss awayRecords;
};

int menu();
WinLoss getWinLoss(string);
void displayWinLoss(WinLoss);
string getInputTeamName();
Team getTeam();
void displayTeam(Team);
void findTeam(Team[], int);
void displayAllTeams(Team[], int);
void insertTeamIntoArray(Team[], int, Team);


int main()
{
	const int MAX_TEAMS = 10;
	Team teams[MAX_TEAMS];

	int lastMenuItem = 4;
	int menuInput = menu();
	do
	{
		Team team;
		switch (menuInput)
		{
		case 1:
			team = getTeam();
			insertTeamIntoArray(teams, MAX_TEAMS, team);
			break;
		case 2:
			displayAllTeams(teams, MAX_TEAMS);
			break;
		case 3:
			findTeam(teams, MAX_TEAMS);
			break;
		}
		menuInput = menu();
	} while (menuInput != lastMenuItem);

	// End
	cout << endl << endl;
	system("pause");
	return 0;
}

int menu()
{
	const int FIRST_MENU_ITEM_NUMBER = 1;
	int lastMenuItemNumber = 4;

	cout << "1. Enter a new team\n";
	cout << "2. Display all teams\n";
	cout << "3. Display a particular team\n";
	cout << "4. Exit the program\n";
	cout << "Enter selection: ";

	int chosenOption;
	cin >> chosenOption;

	while (chosenOption < FIRST_MENU_ITEM_NUMBER || chosenOption > lastMenuItemNumber)
	{
		cout << "Invalid seleciton. Please enter a number between " << FIRST_MENU_ITEM_NUMBER << '-' << lastMenuItemNumber << ": ";
		cin >> chosenOption;
	}

	return chosenOption;
}

WinLoss getWinLoss(string location)
{
	const string LOCAL_LOCATION_NAME = "home", FOREIGN_LOCATION_NAME = "away";

	WinLoss record;

	cout << "Enter the " << location << " wins: ";
	cin >> record.wins;
	cout << "Enter the " << location << " losses: ";
	cin >> record.losses;

	if (location != LOCAL_LOCATION_NAME && location != FOREIGN_LOCATION_NAME)
	{
		cout << "Invalid location input (home/away)\n";
	}

	return record;
}

void displayWinLoss(WinLoss record)
{
	cout << record.wins << "-" << record.losses;
}

string getInputTeamName()
{
	string teamName;
	cin.ignore();
	cout << "Enter the team name: ";
	getline(cin, teamName);

	return teamName;
}

Team getTeam()
{
	Team team;

	team.name = getInputTeamName();

	team.homeRecords = getWinLoss("home");
	team.awayRecords = getWinLoss("away");

	team.recordsTotal.wins = team.homeRecords.wins + team.awayRecords.wins;
	team.recordsTotal.losses = team.homeRecords.losses + team.awayRecords.losses;

	return team;
}

void displayTeam(Team team)
{
	cout << team.name << endl;

	cout << "Total record: ";
	displayWinLoss(team.recordsTotal);
	cout << endl;

	cout << "Home record: ";
	displayWinLoss(team.homeRecords);
	cout << endl;

	cout << "Away record: ";
	displayWinLoss(team.awayRecords);
	cout << endl;
}

void findTeam(Team teams[], int teamsAmount)
{
	string teamName = getInputTeamName();

	for (int i = 0; i < teamsAmount; i++)
	{
		if (teams[i].name == teamName)
		{
			displayTeam(teams[i]);
			return;
		}
	}
	cout << "Team not found.\n";
}

void displayAllTeams(Team teams[], int teamsAmount)
{
	for (int i = 0; i < teamsAmount; i++)
	{
		if (teams[i].name != "") 
		{
			displayTeam(teams[i]);
		}
	}
}

void insertTeamIntoArray(Team teams[], int teamsAmount, Team team)
{
	for (int i = 0; i < teamsAmount; i++)
	{
		if (teams[i].name == "")
		{
			teams[i] = team;
			return;
		}
	}
}