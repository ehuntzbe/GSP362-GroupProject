#pragma once
#include <string>
#include "CommandFunctions.h"
#include "InputParsing.h"
#include "World.h"
#include "Commands.h"
#include "Room.h"
using namespace std;

class Interface
{
private:
	Interface();
	~Interface();
	static Interface* m_interfaceInstance;
public:
	static Interface* GetInstance();
	static void MainGame();
};