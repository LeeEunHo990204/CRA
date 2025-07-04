#include "AbstractQnA.h"

class CarTypeQnA : public AbstractQnA {
public:
	static CarTypeQnA& getInstance() {
		static CarTypeQnA qna;
		return qna;
	}
	string getSelectPrintMessage(int answer) {
		string message = "차량 타입으로 ";
		message.append(typeNameMap[answer]);
		message.append("을 선택하셨습니다.\n");
		return message;
	}
	string getRunPrintMessage(int type) {
		string message = "Car Type : ";
		message.append(typeNameMap[type]);
		message.append("\n");
		return message;
	}
	bool isValidAnswerRange (int answer) {
		if (answer >= 1 && answer <= maxAnswer) return true;
		return false;
	}
protected:
private:
	CarTypeQnA() : AbstractQnA() {
		question =
			"        ______________\n"
			"       /|            | \n"
			"  ____/_|_____________|____\n"
			" |                      O  |\n"
			" '-(@)----------------(@)--'\n"
			"===============================\n"
			"어떤 차량 타입을 선택할까요?\n"
			"1. Sedan\n"
			"2. SUV\n"
			"3. Truck\n";

		typeNameMap[SEDAN] = "SEDAN";
		typeNameMap[SUV] = "SUV";
		typeNameMap[TRUCK] = "TRUCK";
		maxAnswer = 3;
		errorMessage = "ERROR :: 차량 타입은 1 ~ ";
		errorMessage.append(to_string(maxAnswer));
		errorMessage.append(" 범위만 선택 가능\n");
	}
	CarTypeQnA(const CarTypeQnA& ref) {}
	CarTypeQnA& operator=(const CarTypeQnA& ref) {}
	~CarTypeQnA() {}
};