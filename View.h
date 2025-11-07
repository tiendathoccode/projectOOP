#include<iostream>
#include<string>
//
//#include "BaseQuestion.h"
//#include "AnswerRecord.h"
//#include "User.h"
//#include "Result.h"
//#include "ViewIP.h"
//#include "Timer.h"
//#include "FileManager.h"


using namespace std;

class View {
public:
	View() {}
	void displayWelcome(); //hien thi chao mung, HDSD
	void displayHeader(int current, int total, int timeLeft);//so cau ht, tong , thoi gian con lai
	void displayQuestion(const BaseQuestion& question);//hien thi ques
	void displayQuestionStatus(const AnswerRecord& record);//trang thai cau hoi hien tai

	//ket qua cuoi cung
	void displayResult(const User& user, const Result<double>& result, const std::string& startTime, const std::string& totalTime);
	void displayMenu();//hien thi chon thao tac
	void displayPrompt(const string& message);//nhac nhap ten
	void displayError(const string& error);//thong bao loi

};

