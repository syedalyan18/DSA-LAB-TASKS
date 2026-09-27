#include <iostream>
#include <string>
using namespace std;

class PlayerNode
{
public:
	string name;
	PlayerNode *next;

	PlayerNode(const string &playerName)
	{
		name = playerName;
		next = nullptr;
	}
};

class RoundRobinTurnManager
{
private:
	PlayerNode *head;
	PlayerNode *tail;
	PlayerNode *current;

public:
	RoundRobinTurnManager()
	{
		head = nullptr;
		tail = nullptr;
		current = nullptr;
	}

	void addPlayer(const string &name)
	{
		PlayerNode *player = new PlayerNode(name);
		if (head == nullptr)
		{
			head = player;
			tail = player;
			current = player;
			player->next = player;
			return;
		}

		player->next = head;
		tail->next = player;
		tail = player;
	}

	string nextTurn()
	{
		if (current == nullptr)
		{
			return "No players";
		}

		current = current->next;
		return current->name;
	}

	void removePlayer(const string &name)
	{
		if (head == nullptr)
		{
			return;
		}

		PlayerNode *previous = tail;
		PlayerNode *target = head;
		do
		{
			if (target->name == name)
			{
				break;
			}
			previous = target;
			target = target->next;
		} while (target != head);

		if (target->name != name)
		{
			return;
		}

		if (target == target->next)
		{
			head = nullptr;
			tail = nullptr;
			current = nullptr;
		}
		else
		{
			previous->next = target->next;
			if (target == head)
			{
				head = target->next;
				tail->next = head;
			}
			if (target == tail)
			{
				tail = previous;
			}
			if (target == current)
			{
				current = target->next;
			}
		}

		delete target;
	}
};

int main()
{
	RoundRobinTurnManager manager;
	manager.addPlayer("Ali");
	manager.addPlayer("Beena");
	manager.addPlayer("Cara");

	for (int turn = 0; turn < 4; turn++)
	{
		cout << manager.nextTurn() << endl;
	}

	manager.removePlayer("Cara");
	cout << manager.nextTurn() << endl;

	return 0;
}