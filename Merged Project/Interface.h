#pragma once
#include <string>
#include "CommandFunctions.h"
#include "InputParsing.h"
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