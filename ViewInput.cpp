#include "ViewInput.h"
#include "ViewDisplay.h"
#include <iostream>
#include <cctype>
#include <limits>
char ViewInput::getUserChoice() {
	while (true) {
		std::string s;
		if (!std::getline(std::cin, s)) continue;
		if (s.empty()) continue;
		char c = std::toupper(s[0]);
		std::string valid = "NPJSQABCD";
		if (valid.find(c) != std::string::npos) return c;
		ViewDisplay::displayError("Lua chon khong hop le!");
		ViewDisplay::displayPrompt("Nhap lai: ");
	}
}
bool ViewInput::confirmSubmit() {
	while (true) {
		std::string s;
		if (!std::getline(std::cin, s)) continue;
		if (s.empty()) continue;
		char c = std::toupper(s[0]);
		if (c == 'Y') return true;
		if (c == 'N') return false;
		ViewDisplay::displayError("Nhap Y hoac N!");
		ViewDisplay::displayPrompt("Ban co chac muon nop bai? (Y/N): ");
	}
}
int ViewInput::inputQuestionNumber(int totalQuestions) {
	while (true) {
		ViewDisplay::displayPrompt("Nhap so thu tu cau (1-" +
			std::to_string(totalQuestions) + "): ");
		std::string s;
		if (!std::getline(std::cin, s)) continue;
		try {
			int v = std::stoi(s);
			if (v >= 1 && v <= totalQuestions) return v - 1;
		}
		catch (...) {}
		ViewDisplay::displayError("So khong hop le!");
	}
}
std::string ViewInput::inputName() {
	std::string s;
	if (!std::getline(std::cin, s)) s = "";
	// trim
	auto l = s.find_first_not_of(" \t\n\r\f\v");
	if (l == std::string::npos) return "";
	auto r = s.find_last_not_of(" \t\n\r\f\v");
	return s.substr(l, r - l + 1);
}
std::string ViewInput::inputStudentID() {
	std::string s;
	if (!std::getline(std::cin, s)) s = "";
	auto l = s.find_first_not_of(" \t\n\r\f\v");
	if (l == std::string::npos) return "";
	auto r = s.find_last_not_of(" \t\n\r\f\v");
	return s.substr(l, r - l + 1);
}
int ViewInput::charToOptionIndex(char choice) {
	choice = std::toupper(choice);
	if (choice >= 'A' && choice <= 'D') return choice - 'A';
	return -1;
}

