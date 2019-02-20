/*
 *	判断每次模拟结果是否符合要求的全部函数
 */

#ifndef JUDGE_H_
#define JUDGE_H_

#include <iostream>

class Judge {
private:
	bool isInTarget(char [], int, char);
public:
	Judge();
	~Judge();
	static bool isDrawMeetGT(std::string, std::string);
	static bool isDrawMeetEQ(std::string, std::string);	
};

#endif // !JUDGE_H_
