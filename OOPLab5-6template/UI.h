#pragma once
#include "Controller.h"
using namespace std;

class UI
{
private:
	Controller ctrl;

public:
	UI(const Controller& ctrl) : ctrl(ctrl) {}

	void run();

private:
	static void printMenu();
	static void printRepositoryMenu();
	static void printUserMenu();

	int getSize() const { return this->ctrl.getSize(); };

	void add();
	void remove();
	void update();
	void getAll();
	//void getAllPtr();
	


};

