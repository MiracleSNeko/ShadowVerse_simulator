/*
 *	Judge���ʵ��
 */

#include <iostream>
#include "judge.h"

Judge::Judge() { }

Judge::~Judge() { }

bool Judge::isInTarget(char target_deck[], int target_deck_len, char card_draw) {
	/*
	 *	@ brief: �ж�һ�γ鿨�Ľ���Ƿ���Ŀ�꿨����
	 *	@ input: Ŀ�꿨�����飬 Ŀ�꿨��Ŀ������� һ�γ鿨�Ŀ���
	 */
	for (int i = 0; i < target_deck_len; i++) {
		if (card_draw == *(target_deck + i)) return true;
	}
	return false;
}

bool Judge::isDrawMeetGT() {
	/*
	 *	@ brief: �жϳ��ƿ����Ƿ����ٰ���Ŀ�꿨��
	 *	@ input: ���ƿ������飬Ŀ�꿨������
	 */
}

bool Judge::isDrawMeetEQ() {
	/*
	 *	@ brief: �жϳ��ƿ����Ƿ���������ָ��Ŀ�꿨��
	 *	@ input: ���ƿ������飬Ŀ�꿨������
	 */
}
