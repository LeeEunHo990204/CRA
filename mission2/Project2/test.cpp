#include "gmock/gmock.h"
#include "AbstractQnA.h"
#include "CarTypeQnA.cpp"
#include "EngineQnA.cpp"
#include "BrakeSystemQnA.cpp"
#include "SteeringSystemQnA.cpp"
#include "RunTestQnA.cpp"

TEST(CarTypeQnA, getSelectPrintMessage) {
	CarTypeQnA* qna = &CarTypeQnA::getInstance();
	EXPECT_EQ(qna->getSelectPrintMessage(1), "차량 타입으로 SEDAN을 선택하셨습니다.\n");
	EXPECT_EQ(qna->getSelectPrintMessage(2), "차량 타입으로 SUV을 선택하셨습니다.\n");
	EXPECT_EQ(qna->getSelectPrintMessage(3), "차량 타입으로 TRUCK을 선택하셨습니다.\n");
}

TEST(CarTypeQnA, getRunPrintMessage) {
	CarTypeQnA* qna = &CarTypeQnA::getInstance();
	EXPECT_EQ(qna->getRunPrintMessage(1), "Car Type : SEDAN\n");
	EXPECT_EQ(qna->getRunPrintMessage(2), "Car Type : SUV\n");
	EXPECT_EQ(qna->getRunPrintMessage(3), "Car Type : TRUCK\n");
}

TEST(CarTypeQnA, getErrorMessage) {
	CarTypeQnA* qna = &CarTypeQnA::getInstance();
	EXPECT_EQ(qna->getErrorMessage(), "ERROR :: 차량 타입은 1 ~ 3 범위만 선택 가능\n");
}

TEST(CarTypeQnA, isValidAnswerRange) {
	CarTypeQnA* qna = &CarTypeQnA::getInstance();
	EXPECT_TRUE(qna->isValidAnswerRange(1));
	EXPECT_TRUE(qna->isValidAnswerRange(3));
	EXPECT_FALSE(qna->isValidAnswerRange(0));
	EXPECT_FALSE(qna->isValidAnswerRange(4));
}

TEST(EngineQnA, getSelectPrintMessage) {
	EngineQnA* qna = &EngineQnA::getInstance();
	EXPECT_EQ(qna->getSelectPrintMessage(1), "GM 엔진을 선택하셨습니다.\n");
	EXPECT_EQ(qna->getSelectPrintMessage(2), "TOYOTA 엔진을 선택하셨습니다.\n");
	EXPECT_EQ(qna->getSelectPrintMessage(3), "WIA 엔진을 선택하셨습니다.\n");
}

TEST(EngineQnA, getRunPrintMessage) {
	EngineQnA* qna = &EngineQnA::getInstance();
	EXPECT_EQ(qna->getRunPrintMessage(1), "Engine : GM\n");
	EXPECT_EQ(qna->getRunPrintMessage(2), "Engine : TOYOTA\n");
	EXPECT_EQ(qna->getRunPrintMessage(3), "Engine : WIA\n");
}

TEST(EngineQnA, isValidAnswerRange) {
	EngineQnA* qna = &EngineQnA::getInstance();
	EXPECT_TRUE(qna->isValidAnswerRange(1));
	EXPECT_TRUE(qna->isValidAnswerRange(3));
	EXPECT_FALSE(qna->isValidAnswerRange(5));
}

TEST(EngineQnA, getErrorMessage) {
	EngineQnA* qna = &EngineQnA::getInstance();
	EXPECT_EQ(qna->getErrorMessage(), "ERROR :: 엔진은 1 ~ 4 범위만 선택 가능\n");
}

TEST(BrakeSystemQnA, getSelectPrintMessage) {
	BrakeSystemQnA* qna = &BrakeSystemQnA::getInstance();
	EXPECT_EQ(qna->getSelectPrintMessage(1), "MANDO 제동장치를 선택하셨습니다.\n");
	EXPECT_EQ(qna->getSelectPrintMessage(2), "CONTINENTAL 제동장치를 선택하셨습니다.\n");
	EXPECT_EQ(qna->getSelectPrintMessage(3), "BOSCH 제동장치를 선택하셨습니다.\n");
}

TEST(BrakeSystemQnA, getRunPrintMessage) {
	BrakeSystemQnA* qna = &BrakeSystemQnA::getInstance();
	EXPECT_EQ(qna->getRunPrintMessage(1), "Brake System : MANDO\n");
	EXPECT_EQ(qna->getRunPrintMessage(2), "Brake System : CONTINENTAL\n");
	EXPECT_EQ(qna->getRunPrintMessage(3), "Brake System : BOSCH\n");
}

TEST(BrakeSystemQnA, isValidAnswerRange) {
	BrakeSystemQnA* qna = &BrakeSystemQnA::getInstance();
	EXPECT_TRUE(qna->isValidAnswerRange(1));
	EXPECT_TRUE(qna->isValidAnswerRange(3));
	EXPECT_FALSE(qna->isValidAnswerRange(4));
}

TEST(BrakeSystemQnA, getErrorMessage) {
	BrakeSystemQnA* qna = &BrakeSystemQnA::getInstance();
	EXPECT_EQ(qna->getErrorMessage(), "ERROR :: 제동장치는 1 ~ 3 범위만 선택 가능\n");
}

TEST(SteeringSystemQnA, getSelectPrintMessage) {
	SteeringSystemQnA* qna = &SteeringSystemQnA::getInstance();
	EXPECT_EQ(qna->getSelectPrintMessage(1), "BOSCH 조향장치를 선택하셨습니다.\n");
	EXPECT_EQ(qna->getSelectPrintMessage(2), "MOBIS 조향장치를 선택하셨습니다.\n");
}

TEST(SteeringSystemQnA, getRunPrintMessage) {
	SteeringSystemQnA* qna = &SteeringSystemQnA::getInstance();
	EXPECT_EQ(qna->getRunPrintMessage(1), "SteeringSystem : BOSCH\n");
	EXPECT_EQ(qna->getRunPrintMessage(2), "SteeringSystem : MOBIS\n");
}

TEST(SteeringSystemQnA, isValidAnswerRange) {
	SteeringSystemQnA* qna = &SteeringSystemQnA::getInstance();
	EXPECT_TRUE(qna->isValidAnswerRange(1));
	EXPECT_TRUE(qna->isValidAnswerRange(2));
	EXPECT_FALSE(qna->isValidAnswerRange(3));
}

TEST(SteeringSystemQnA, getErrorMessage) {
	SteeringSystemQnA* qna = &SteeringSystemQnA::getInstance();
	EXPECT_EQ(qna->getErrorMessage(), "ERROR :: 조향장치는 1 ~ 2 범위만 선택 가능\n");
}

TEST(RunTestQnA, getSelectPrintMessage) {
	RunTestQnA* qna = &RunTestQnA::getInstance();
	EXPECT_EQ(qna->getSelectPrintMessage(1), "");
	EXPECT_EQ(qna->getSelectPrintMessage(2), "");
}

TEST(RunTestQnA, getRunPrintMessage) {
	RunTestQnA* qna = &RunTestQnA::getInstance();
	EXPECT_EQ(qna->getRunPrintMessage(1), "");
	EXPECT_EQ(qna->getRunPrintMessage(2), "");
}

TEST(RunTestQnA, isValidAnswerRange) {
	RunTestQnA* qna = &RunTestQnA::getInstance();
	EXPECT_TRUE(qna->isValidAnswerRange(1));
	EXPECT_TRUE(qna->isValidAnswerRange(2));
	EXPECT_FALSE(qna->isValidAnswerRange(3));
}

TEST(RunTestQnA, getErrorMessage) {
	RunTestQnA* qna = &RunTestQnA::getInstance();
	EXPECT_EQ(qna->getErrorMessage(), "ERROR :: Run 또는 Test 중 하나를 선택 필요\n");
}