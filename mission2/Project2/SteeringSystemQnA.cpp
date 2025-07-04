#include "AbstractQnA.h"

class SteeringSystemQnA : public AbstractQnA {
public:
	static SteeringSystemQnA& getInstance() {
		static SteeringSystemQnA qna;
		return qna;
	}
	string getSelectPrintMessage(int answer) {
		string message = typeNameMap[answer];
		message.append(" 조향장치를 선택하셨습니다.\n");
		return message;
	}
	string getRunPrintMessage(int type) {
		string message = "SteeringSystem : ";
		message.append(typeNameMap[type]);
		message.append("\n");
		return message;
	}
	bool isValidAnswerRange(int answer) {
		if (answer >= 0 && answer <= maxAnswer) return true;
		return false;
	}
protected:
private:
	SteeringSystemQnA() : AbstractQnA() {
		question =
			"어떤 조향장치를 선택할까요?\n"
			"0. 뒤로가기\n"
			"1. BOSCH\n"
			"2. MOBIS\n";

		typeNameMap[BOSCH_S] = "BOSCH";
		typeNameMap[MOBIS] = "MOBIS";
		maxAnswer = 2;

		errorMessage = "ERROR :: 조향장치는 1 ~ ";
		errorMessage.append(to_string(maxAnswer));
		errorMessage.append(" 범위만 선택 가능\n");
	}
	SteeringSystemQnA(const SteeringSystemQnA& ref) {}
	SteeringSystemQnA& operator=(const SteeringSystemQnA& ref) {}
	~SteeringSystemQnA() {}
};