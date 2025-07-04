#include "gmock/gmock.h"
#include "AbstractQnA.h"
#include "CarTypeQnA.cpp"
#include "EngineQnA.cpp"
#include "BrakeSystemQnA.cpp"
#include "SteeringSystemQnA.cpp"
#include "RunTestQnA.cpp"

TEST(CarTypeQnA, getSelectPrintMessage) {
	CarTypeQnA* qna = &CarTypeQnA::getInstance();
	EXPECT_EQ(qna->getSelectPrintMessage(1), "���� Ÿ������ SEDAN�� �����ϼ̽��ϴ�.\n");
	EXPECT_EQ(qna->getSelectPrintMessage(2), "���� Ÿ������ SUV�� �����ϼ̽��ϴ�.\n");
	EXPECT_EQ(qna->getSelectPrintMessage(3), "���� Ÿ������ TRUCK�� �����ϼ̽��ϴ�.\n");
}

TEST(CarTypeQnA, getRunPrintMessage) {
	CarTypeQnA* qna = &CarTypeQnA::getInstance();
	EXPECT_EQ(qna->getRunPrintMessage(1), "Car Type : SEDAN\n");
	EXPECT_EQ(qna->getRunPrintMessage(2), "Car Type : SUV\n");
	EXPECT_EQ(qna->getRunPrintMessage(3), "Car Type : TRUCK\n");
}

TEST(CarTypeQnA, getErrorMessage) {
	CarTypeQnA* qna = &CarTypeQnA::getInstance();
	EXPECT_EQ(qna->getErrorMessage(), "ERROR :: ���� Ÿ���� 1 ~ 3 ������ ���� ����\n");
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
	EXPECT_EQ(qna->getSelectPrintMessage(1), "GM ������ �����ϼ̽��ϴ�.\n");
	EXPECT_EQ(qna->getSelectPrintMessage(2), "TOYOTA ������ �����ϼ̽��ϴ�.\n");
	EXPECT_EQ(qna->getSelectPrintMessage(3), "WIA ������ �����ϼ̽��ϴ�.\n");
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
	EXPECT_EQ(qna->getErrorMessage(), "ERROR :: ������ 1 ~ 4 ������ ���� ����\n");
}

TEST(BrakeSystemQnA, getSelectPrintMessage) {
	BrakeSystemQnA* qna = &BrakeSystemQnA::getInstance();
	EXPECT_EQ(qna->getSelectPrintMessage(1), "MANDO ������ġ�� �����ϼ̽��ϴ�.\n");
	EXPECT_EQ(qna->getSelectPrintMessage(2), "CONTINENTAL ������ġ�� �����ϼ̽��ϴ�.\n");
	EXPECT_EQ(qna->getSelectPrintMessage(3), "BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
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
	EXPECT_EQ(qna->getErrorMessage(), "ERROR :: ������ġ�� 1 ~ 3 ������ ���� ����\n");
}

TEST(SteeringSystemQnA, getSelectPrintMessage) {
	SteeringSystemQnA* qna = &SteeringSystemQnA::getInstance();
	EXPECT_EQ(qna->getSelectPrintMessage(1), "BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
	EXPECT_EQ(qna->getSelectPrintMessage(2), "MOBIS ������ġ�� �����ϼ̽��ϴ�.\n");
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
	EXPECT_EQ(qna->getErrorMessage(), "ERROR :: ������ġ�� 1 ~ 2 ������ ���� ����\n");
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
	EXPECT_EQ(qna->getErrorMessage(), "ERROR :: Run �Ǵ� Test �� �ϳ��� ���� �ʿ�\n");
}