/*
 *	Judge���ʵ��
 */

#include <iostream>
#include <string>
#include <algorithm>
#include "judge.h"

using namespace std;

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

bool Judge::isDrawMeetGT(char target_deck[], char *draw_deck) {
	/*
	 *	@ brief: �жϳ��ƿ����Ƿ����ٰ���Ŀ�꿨��
	 *	@ input: ���ƿ������飬Ŀ�꿨������
	 */
	string target_s, draw_s;
	int flag = 0;
	target_s = string(target_deck);
	draw_s = draw_deck;
	draw_s.erase(remove(draw_s.begin(), draw_s.end(), '0'), draw_s.end());
	sort(target_s.begin(), target_s.end());
	sort(draw_s.begin(), draw_s.end());
	for (int i = 0; i < draw_s.length(); ++i) {
		flag = 0;
		for (int j = 0; j < target_s.length(); ++j) {
			if (draw_s[i] == target_s[j]) {
				flag = 1;
				break;
			}
		}
		if (0 == flag) return false;
	}
	return true;
}

bool Judge::isDrawMeetEQ(char target_deck[], char *draw_deck) {
	/*
	 *	@ brief: �жϳ��ƿ����Ƿ���������ָ��Ŀ�꿨��
	 *	@ input: ���ƿ������飬Ŀ�꿨������
	 */
	string target_s, draw_s;
	target_s = string(target_deck);
	draw_s = draw_deck;
	draw_s.erase(remove(draw_s.begin(), draw_s.end(), '0'), draw_s.end());
	sort(target_s.begin(), target_s.end());
	sort(draw_s.begin(), draw_s.end());
	return (0 == draw_s.compare(target_s));
}
