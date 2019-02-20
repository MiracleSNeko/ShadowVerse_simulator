/*
 *	Judge类的实现
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
	 *	@ brief: 判断一次抽卡的结果是否在目标卡组中
	 *	@ input: 目标卡组数组， 目标卡组的卡牌数， 一次抽卡的卡牌
	 */
	for (int i = 0; i < target_deck_len; i++) {
		if (card_draw == *(target_deck + i)) return true;
	}
	return false;
}

bool Judge::isDrawMeetGT(char target_deck[], char *draw_deck) {
	/*
	 *	@ brief: 判断抽牌卡组是否至少包含目标卡组
	 *	@ input: 抽牌卡组数组，目标卡组数组
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
	 *	@ brief: 判断抽牌卡组是否正好满足指定目标卡组
	 *	@ input: 抽牌卡组数组，目标卡组数组
	 */
	string target_s, draw_s;
	target_s = string(target_deck);
	draw_s = draw_deck;
	draw_s.erase(remove(draw_s.begin(), draw_s.end(), '0'), draw_s.end());
	sort(target_s.begin(), target_s.end());
	sort(draw_s.begin(), draw_s.end());
	return (0 == draw_s.compare(target_s));
}
