#include "AbstractQnA.h"

class EngineQnA : public AbstractQnA {
public:
	static EngineQnA& getInstance() {
		static EngineQnA qna;
		return qna;
	}
	string getSelectPrintMessage(int answer) {
		string message = typeNameMap[answer];
		message.append(" 엔진을 선택하셨습니다.\n");
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
			"어떤 엔진을 탑재할까요?\n"
			"0. 뒤로가기\n"
			"1. GM\n"
			"2. TOYOTA\n"
			"3. WIA\n"
			"4. 고장난 엔진\n";

		typeNameMap[GM] = "GM";
		typeNameMap[TOYOTA] = "TOYOTA";
		typeNameMap[WIA] = "WIA";
		maxAnswer = 4;

		errorMessage = "ERROR :: 엔진은 1 ~ ";
		errorMessage.append(to_string(maxAnswer));
		errorMessage.append(" 범위만 선택 가능\n");
	}
	EngineQnA(const EngineQnA& ref) {}
	EngineQnA& operator=(const EngineQnA& ref) {}
	~EngineQnA() {}
};