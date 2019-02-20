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

bool Judge::isDrawMeetGT(string target_deck, string draw_deck) {
	/*
	 *	@ brief: 判断抽牌卡组是否至少包含目标卡组
	 *	@ input: 抽牌卡组数组，目标卡组数组
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
	 *	@ brief: 判断抽牌卡组是否正好满足指定目标卡组
	 *	@ input: 抽牌卡组数组，目标卡组数组
	 */
	draw_deck.erase(remove(draw_deck.begin(), draw_deck.end(), '0'), draw_deck.end());
	sort(target_deck.begin(), target_deck.end());
	sort(draw_deck.begin(), draw_deck.end());
	return (0 == draw_deck.compare(target_deck));
}
