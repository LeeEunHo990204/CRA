#pragma once
#include <string>
#include <unordered_map>
using namespace std;

enum QuestionType
{
	CarType_Q,
	Engine_Q,
	brakeSystem_Q,
	SteeringSystem_Q,
	Run_Test,
};

enum CarType
{
	SEDAN = 1,
	SUV,
	TRUCK
};

enum Engine
{
	GM = 1,
	TOYOTA,
	WIA
};

enum brakeSystem
{
	MANDO = 1,
	CONTINENTAL,
	BOSCH_B
};

enum SteeringSystem
{
	BOSCH_S = 1,
	MOBIS
};

class AbstractQnA {
public:
	virtual string getSelectPrintMessage(int answer) = 0;
	virtual string getRunPrintMessage(int type) = 0;
	virtual bool isValidAnswerRange(int answer) = 0;

	string getQuestion() {
		return question;
	}
	string getErrorMessage() {
		return errorMessage;
	}

protected:
	int maxAnswer = 0;
	unordered_map<int, string> typeNameMap;
	string question;
	string errorMessage;
};