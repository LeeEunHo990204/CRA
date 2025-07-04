#include "AbstractQnA.h"

class EngineQnA : public AbstractQnA {
public:
	static EngineQnA& getInstance() {
		static EngineQnA qna;
		return qna;
	}
	string getSelectPrintMessage(int answer) {
		string message = typeNameMap[answer];
		message.append(" ������ �����ϼ̽��ϴ�.\n");
		return message;
	}
	string getRunPrintMessage(int type) {
		string message = "Engine : ";
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
	EngineQnA() : AbstractQnA() {
		question =
			"� ������ ž���ұ��?\n"
			"0. �ڷΰ���\n"
			"1. GM\n"
			"2. TOYOTA\n"
			"3. WIA\n"
			"4. ���峭 ����\n";

		typeNameMap[GM] = "GM";
		typeNameMap[TOYOTA] = "TOYOTA";
		typeNameMap[WIA] = "WIA";
		maxAnswer = 4;

		errorMessage = "ERROR :: ������ 1 ~ ";
		errorMessage.append(to_string(maxAnswer));
		errorMessage.append(" ������ ���� ����\n");
	}
	EngineQnA(const EngineQnA& ref) {}
	EngineQnA& operator=(const EngineQnA& ref) {}
	~EngineQnA() {}
};