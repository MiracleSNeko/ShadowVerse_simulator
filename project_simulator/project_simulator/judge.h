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
	static bool isDrawMeetGT(char [], char *);
	static bool isDrawMeetEQ(char [], char *);	
};

#endif // !JUDGE_H_
