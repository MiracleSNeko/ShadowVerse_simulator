/*
 *	�ж�ÿ��ģ�����Ƿ����Ҫ���ȫ������
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
