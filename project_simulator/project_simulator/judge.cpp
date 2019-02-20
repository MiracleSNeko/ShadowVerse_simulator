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

bool Judge::isDrawMeetGT(string target_deck, string draw_deck) {
	/*
	 *	@ brief: �жϳ��ƿ����Ƿ����ٰ���Ŀ�꿨��
	 *	@ input: ���ƿ������飬Ŀ�꿨������
	 */
	int flag = 0;
	draw_deck.erase(remove(draw_deck.begin(), draw_deck.end(), '0'), draw_deck.end());
	sort(target_deck.begin(), target_deck.end());
	sort(draw_deck.begin(), draw_deck.end());
	for (size_t i = 0; i < target_deck.length(); ++i) {
		flag = 0;
		for (size_t j = 0; j < draw_deck.length(); ++j) {
			if (target_deck[i] == draw_deck[j]) {
				flag = 1;
				draw_deck[j] = '0';
				break;
			}
		}
		if (0 == flag) return false;
	}
	return true;
}

bool Judge::isDrawMeetEQ(string target_deck, string draw_deck) {
	/*
	 *	@ brief: �жϳ��ƿ����Ƿ���������ָ��Ŀ�꿨��
	 *	@ input: ���ƿ������飬Ŀ�꿨������
	 */
	draw_deck.erase(remove(draw_deck.begin(), draw_deck.end(), '0'), draw_deck.end());
	sort(target_deck.begin(), target_deck.end());
	sort(draw_deck.begin(), draw_deck.end());
	return (0 == draw_deck.compare(target_deck));
}
