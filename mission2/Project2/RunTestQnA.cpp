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
			"���� ������ �ϼ��Ǿ����ϴ�.\n"
			"� ������ �ұ��?\n"
			"0. ó�� ȭ������ ���ư���\n"
			"1. RUN\n"
			"2. Test\n";
		maxAnswer = 2;
		errorMessage = "ERROR :: Run �Ǵ� Test �� �ϳ��� ���� �ʿ�\n";
	}
	RunTestQnA(const RunTestQnA& ref) {}
	RunTestQnA& operator=(const RunTestQnA& ref) {}
	~RunTestQnA() {}
};