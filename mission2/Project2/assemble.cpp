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
			printf("바이바이\n");
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
		printf("ERROR :: 숫자만 입력 가능\n");
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
		printf("자동차가 동작되지 않습니다\n");
		return;
	}
	if (stack[Engine_Q] == 4)
	{
		printf("엔진이 고장나있습니다.\n");
		printf("자동차가 움직이지 않습니다.\n");
		return;
	}
	for (int i = 0; i < 4; i++) {
		AbstractQnA* qna = qnaList[i];
		printf("%s", (qna->getRunPrintMessage(stack[i])).c_str());
	}
	printf("자동차가 동작됩니다.\n");
}

void testProducedCar()
{
	if (stack[CarType_Q] == SEDAN && stack[brakeSystem_Q] == CONTINENTAL)
	{
		printf("자동차 부품 조합 테스트 결과 : FAIL\n");
		printf("Sedan에는 Continental제동장치 사용 불가\n");
	}
	else if (stack[CarType_Q] == SUV && stack[Engine_Q] == TOYOTA)
	{
		printf("자동차 부품 조합 테스트 결과 : FAIL\n");
		printf("SUV에는 TOYOTA엔진 사용 불가\n");
	}
	else if (stack[CarType_Q] == TRUCK && stack[Engine_Q] == WIA)
	{
		printf("자동차 부품 조합 테스트 결과 : FAIL\n");
		printf("Truck에는 WIA엔진 사용 불가\n");
	}
	else if (stack[CarType_Q] == TRUCK && stack[brakeSystem_Q] == MANDO)
	{
		printf("자동차 부품 조합 테스트 결과 : FAIL\n");
		printf("Truck에는 Mando제동장치 사용 불가\n");
	}
	else if (stack[brakeSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S)
	{
		printf("자동차 부품 조합 테스트 결과 : FAIL\n");
		printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
	}
	else
	{
		printf("자동차 부품 조합 테스트 결과 : PASS\n");
	}
}

#endif