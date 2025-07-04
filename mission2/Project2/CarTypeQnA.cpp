#include "AbstractQnA.h"

class CarTypeQnA : public AbstractQnA {
public:
	static CarTypeQnA& getInstance() {
		static CarTypeQnA qna;
		return qna;
	}
	string getSelectPrintMessage(int answer) {
		string message = "���� Ÿ������ ";
		message.append(typeNameMap[answer]);
		message.append("�� �����ϼ̽��ϴ�.\n");
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
			"� ���� Ÿ���� �����ұ��?\n"
			"1. Sedan\n"
			"2. SUV\n"
			"3. Truck\n";

		typeNameMap[SEDAN] = "SEDAN";
		typeNameMap[SUV] = "SUV";
		typeNameMap[TRUCK] = "TRUCK";
		maxAnswer = 3;
		errorMessage = "ERROR :: ���� Ÿ���� 1 ~ ";
		errorMessage.append(to_string(maxAnswer));
		errorMessage.append(" ������ ���� ����\n");
	}
	CarTypeQnA(const CarTypeQnA& ref) {}
	CarTypeQnA& operator=(const CarTypeQnA& ref) {}
	~CarTypeQnA() {}
};