/*
 *	�ж�ÿ��ģ�����Ƿ����Ҫ���ȫ������
 */

#ifndef JUDGE_H_
#define JUDGE_H_

#include <iostream>

class Judge {
private:
	bool isInTarget(char *, int, char);
public:
	Judge();
	~Judge();
	bool isDrawMeetGT();
	bool isDrawMeetEQ();	
};

#endif // !JUDGE_H_
