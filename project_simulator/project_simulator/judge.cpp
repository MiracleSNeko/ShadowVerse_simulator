/*
 *	Judge类的实现
 */

#include <iostream>
#include "judge.h"

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

bool Judge::isDrawMeetGT() {
	/*
	 *	@ brief: 判断抽牌卡组是否至少包含目标卡组
	 *	@ input: 抽牌卡组数组，目标卡组数组
	 */
}

bool Judge::isDrawMeetEQ() {
	/*
	 *	@ brief: 判断抽牌卡组是否正好满足指定目标卡组
	 *	@ input: 抽牌卡组数组，目标卡组数组
	 */
}
