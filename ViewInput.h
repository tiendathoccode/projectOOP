#pragma once
#include <string>
class ViewInput {
public:
	char getUserChoice();
	bool confirmSubmit();
	int inputQuestionNumber(int totalQuestions);
	std::string inputName();
	std::string inputStudentID();
	int charToOptionIndex(char choice);
};

