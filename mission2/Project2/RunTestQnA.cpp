#include "AbstractQnA.h"

class RunTestQnA : public AbstractQnA {
public:
	static RunTestQnA& getInstance() {
		static RunTestQnA qna;
		return qna;
	}
	string getSelectPrintMessage(int answer) {
		return "";
	}
	string getRunPrintMessage(int type) {
		return "";
	}
	bool isValidAnswerRange(int answer) {
		if (answer >= 0 && answer <= maxAnswer) return true;
		return false;
	}
protected:
private:
	RunTestQnA() : AbstractQnA() {
		question =
			"멋진 차량이 완성되었습니다.\n"
			"어떤 동작을 할까요?\n"
			"0. 처음 화면으로 돌아가기\n"
			"1. RUN\n"
			"2. Test\n";
		maxAnswer = 2;
		errorMessage = "ERROR :: Run 또는 Test 중 하나를 선택 필요\n";
	}
	RunTestQnA(const RunTestQnA& ref) {}
	RunTestQnA& operator=(const RunTestQnA& ref) {}
	~RunTestQnA() {}
};