#include "View.h"

//hien thi chao mung, HDSD
void View:: displayWelcome() {
	cout << "--------------------------------------------" << endl;
	cout << "\t CHUONG TRINH THI TRAC NGHIEM" << endl;
	cout << "--------------------------------------------" << endl;
    cout << "\t NOTE: Ban co the chon trả loi hoac skip sang cau tiep theo"<<endl;
    cout << "\t Chuc ban hoan thanh tot bai trac nghiem!" << endl;
	cout << "--------------------------------------------" << endl;
}

//current: cau hoi ht
//total: tong so cau trong bai
//tiemLeft: thoi gian con lai
void View::displayHeader(int current, int total, int timeLeft) {
	int minutes = timeLeft / 60; //phut
	int seconds = timeLeft % 60; //giay
	
	string minStr = (minutes < 10 ? "0" : "") + to_string(minutes);
	string secStr = (seconds < 10 ? "0" : "") + to_string(seconds);

	cout << "Cau " << current + 1 << "\t" << total
		<< " | \t Thời gian còn lại: "
		<< minStr << ":" << secStr << endl;
}

//hien thi ques
void View::displayQuestion(const BaseQuestion& question) {
	question.display();
}

//trang thai cau hoi hien tai
void View::displayQuestionStatus(const AnswerRecord& record) {
    //skip
    if (record.isSkipped()) {
        cout << "Trang thai: Đa skip" << std::endl;
    }
    //tra loi
    else if (record.isAnswer()) {
        char choice = 'a' + record.getAnswer();
        cout << "Trang thai: Đa tra loi (" << choice << ")" << std::endl;
    }
    //chua chon
    else {
        cout << "Trang thai: Chua tra loi" << std::endl;
    }
}

//ket qua cuoi cung
void View::displayResult(const User& user, const Result<double>& result, const string& startTime, const string& totalTime) {
    cout << "--------------------------------------------" << endl;
    cout << "\t KET QUA BAI THI" << endl;
    cout << "Ho ten: " << user.getName() << endl;
    cout << "Ma sinh vien: " << user.getID() << endl;
    cout << "Thoi gian bat đau: " << startTime << endl;
    cout << "Tong thoi gian lam bai: " << totalTime << endl;
    result.display();
    cout << "--------------------------------------------" << endl;
}

//hien thi chon thao tac
void View::displayMenu() {
    cout << "Lựa chọn: N (Next), P (Previous), S (Skip), J (Jump), a/b/c/d (Chọn đáp án), Q (Submit)" << endl;
}

//nhac nhap ten
void View::displayPrompt(const string& message) {
    cout << message;
}

//thong bao loi
void View::displayError(const string& error) {
    cout << "[31m" << error << "[0m" << endl;  
}
