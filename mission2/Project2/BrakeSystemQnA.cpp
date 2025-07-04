#include "AbstractQnA.h"

class BrakeSystemQnA : public AbstractQnA {
public:
	static BrakeSystemQnA& getInstance() {
		static BrakeSystemQnA qna;
		return qna;
	}
	string getSelectPrintMessage(int answer) {
		string message = typeNameMap[answer];
		message.append(" ������ġ�� �����ϼ̽��ϴ�.\n");
		return message;
	}
	string getRunPrintMessage(int type) {
		string message = "Brake System : ";
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
	BrakeSystemQnA() : AbstractQnA() {
		question =
			"� ������ġ�� �����ұ��?\n"
			"0. �ڷΰ���\n"
			"1. MANDO\n"
			"2. CONTINENTAL\n"
			"3. BOSCH\n";

		typeNameMap[MANDO] = "MANDO";
		typeNameMap[CONTINENTAL] = "CONTINENTAL";
		typeNameMap[BOSCH_B] = "BOSCH";
		maxAnswer = 3;
		errorMessage = "ERROR :: ������ġ�� 1 ~ ";
		errorMessage.append(to_string(maxAnswer));
		errorMessage.append(" ������ ���� ����\n");
	}
	BrakeSystemQnA(const BrakeSystemQnA& ref) {}
	BrakeSystemQnA& operator=(const BrakeSystemQnA& ref) {}
	~BrakeSystemQnA() {}
};