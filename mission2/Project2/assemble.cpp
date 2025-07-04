#ifdef _DEBUG

#include "gmock/gmock.h"

int main()
{
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}

#else

#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "AbstractQnA.h"
#include "CarTypeQnA.cpp"
#include "EngineQnA.cpp"
#include "BrakeSystemQnA.cpp"
#include "SteeringSystemQnA.cpp"
#include "RunTestQnA.cpp"

#define CLEAR_SCREEN "\033[H\033[2J"

int stack[10];

void delay(int ms);

void getInputBuffer(char buf[100]);
void removeNewlineChar(char  buf[100]);
bool isValidAnswer(char* checkNumber, AbstractQnA* qna, int answer);
void printErrorMessage(char* checkNumber, AbstractQnA* qna, int answer);
void printQ(AbstractQnA* qna);
void goPrevStep(int& step);
void select(AbstractQnA* qna, int answer);
void goNextStep(int& step);
void runTest(AbstractQnA* qnaList[Run_Test + 1], int answer);

void runProducedCar(AbstractQnA* qnaList[Run_Test + 1]);
void testProducedCar();

void delay(int ms)
{
	volatile int sum = 0;
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			for (int t = 0; t < ms; t++)
			{
				sum++;
			}
		}
	}
}

int main()
{
	char buf[100];
	AbstractQnA* qnaList[Run_Test + 1];
	qnaList[CarType_Q] = &CarTypeQnA::getInstance();
	qnaList[Engine_Q] = &EngineQnA::getInstance();
	qnaList[brakeSystem_Q] = &BrakeSystemQnA::getInstance();
	qnaList[SteeringSystem_Q] = &SteeringSystemQnA::getInstance();
	qnaList[Run_Test] = &RunTestQnA::getInstance();
	int step = CarType_Q;

	while (1)
	{
		printQ(qnaList[step]);

		getInputBuffer(buf);
		if (!strcmp(buf, "exit"))
		{
			printf("���̹���\n");
			break;
		}

		char* checkNumber;
		int answer = strtol(buf, &checkNumber, 10);
		if (isValidAnswer(checkNumber, qnaList[step], answer) == false) {
			printErrorMessage(checkNumber, qnaList[step], answer);
			continue;
		}

		if (answer == 0)
			goPrevStep(step);
		else if (step < Run_Test) {
			stack[step] = answer;
			select(qnaList[step], answer);
			goNextStep(step);
		}
		else runTest(qnaList, answer);
	}
}

void getInputBuffer(char buf[100])
{
	printf("INPUT > ");
	fgets(buf, sizeof(buf), stdin);
	removeNewlineChar(buf);
}

void removeNewlineChar(char buf[100])
{
	char* context = nullptr;
	strtok_s(buf, "\r", &context);
	strtok_s(buf, "\n", &context);
}

bool isValidAnswer(char* checkNumber, AbstractQnA* qna, int answer)
{
	if (*checkNumber != '\0')
		return false;
	if (qna->isValidAnswerRange(answer) == false) {
		return false;
	}
	return true;
}

void printErrorMessage(char* checkNumber, AbstractQnA* qna, int answer)
{
	if (*checkNumber != '\0')
		printf("ERROR :: ���ڸ� �Է� ����\n");
	if (!(qna->isValidAnswerRange(answer)))
		printf("%s", (qna->getErrorMessage()).c_str());
	else return;
	delay(800);
}

void printQ(AbstractQnA* qna)
{
	printf(CLEAR_SCREEN);
	printf("%s", (qna->getQuestion()).c_str());
	printf("===============================\n");
}

void goPrevStep(int& step)
{
	if (step == Run_Test)
		step = 0;
	else step--;
}

void select(AbstractQnA* qna, int answer)
{
	printf("%s", (qna->getSelectPrintMessage(answer)).c_str());
	delay(800);
}

void goNextStep(int& step)
{
	step++;
}

void runTest(AbstractQnA* qnaList[Run_Test + 1], int answer) {
	if (answer == 1)
		runProducedCar(qnaList);
	if (answer == 2)
	{
		printf("Test...\n");
		delay(1500);
		testProducedCar();
	}
	delay(2000);
}

int isValidCheck()
{
	if (stack[CarType_Q] == SEDAN && stack[brakeSystem_Q] == CONTINENTAL)
		return false;
	else if (stack[CarType_Q] == SUV && stack[Engine_Q] == TOYOTA)
		return false;
	else if (stack[CarType_Q] == TRUCK && stack[Engine_Q] == WIA)
		return false;
	else if (stack[CarType_Q] == TRUCK && stack[brakeSystem_Q] == MANDO)
		return false;
	else if (stack[brakeSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S)
		return false;
	return true;
}

void runProducedCar(AbstractQnA* qnaList[Run_Test + 1])
{
	if (isValidCheck() == false)
	{
		printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
		return;
	}
	if (stack[Engine_Q] == 4)
	{
		printf("������ ���峪�ֽ��ϴ�.\n");
		printf("�ڵ����� �������� �ʽ��ϴ�.\n");
		return;
	}
	for (int i = 0; i < 4; i++) {
		AbstractQnA* qna = qnaList[i];
		printf("%s", (qna->getRunPrintMessage(stack[i])).c_str());
	}
	printf("�ڵ����� ���۵˴ϴ�.\n");
}

void testProducedCar()
{
	if (stack[CarType_Q] == SEDAN && stack[brakeSystem_Q] == CONTINENTAL)
	{
		printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
		printf("Sedan���� Continental������ġ ��� �Ұ�\n");
	}
	else if (stack[CarType_Q] == SUV && stack[Engine_Q] == TOYOTA)
	{
		printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
		printf("SUV���� TOYOTA���� ��� �Ұ�\n");
	}
	else if (stack[CarType_Q] == TRUCK && stack[Engine_Q] == WIA)
	{
		printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
		printf("Truck���� WIA���� ��� �Ұ�\n");
	}
	else if (stack[CarType_Q] == TRUCK && stack[brakeSystem_Q] == MANDO)
	{
		printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
		printf("Truck���� Mando������ġ ��� �Ұ�\n");
	}
	else if (stack[brakeSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S)
	{
		printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
		printf("Bosch������ġ���� Bosch������ġ �̿� ��� �Ұ�\n");
	}
	else
	{
		printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
	}
}

#endif