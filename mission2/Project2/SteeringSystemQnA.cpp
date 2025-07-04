#include "AbstractQnA.h"

class SteeringSystemQnA : public AbstractQnA {
public:
	static SteeringSystemQnA& getInstance() {
		static SteeringSystemQnA qna;
		return qna;
	}
	string getSelectPrintMessage(int answer) {
		string message = typeNameMap[answer];
		message.append(" ������ġ�� �����ϼ̽��ϴ�.\n");
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
			"� ������ġ�� �����ұ��?\n"
			"0. �ڷΰ���\n"
			"1. BOSCH\n"
			"2. MOBIS\n";

		typeNameMap[BOSCH_S] = "BOSCH";
		typeNameMap[MOBIS] = "MOBIS";
		maxAnswer = 2;

		errorMessage = "ERROR :: ������ġ�� 1 ~ ";
		errorMessage.append(to_string(maxAnswer));
		errorMessage.append(" ������ ���� ����\n");
	}
	SteeringSystemQnA(const SteeringSystemQnA& ref) {}
	SteeringSystemQnA& operator=(const SteeringSystemQnA& ref) {}
	~SteeringSystemQnA() {}
};