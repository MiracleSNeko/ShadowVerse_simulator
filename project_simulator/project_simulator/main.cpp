/*
 *	Copyrigh (C)， 2019， QQ group ★爱上kotomi★ (213794567), All rights reserved. (xD)
 *	
 *	a simulator of ShadowVerse draw card.
 *	why not use Monte Carlo instead of calculations? (xD)
 *	某沙雕之诗的抽卡概率模拟程序。
 *	为什么不用神奇的蒙特卡洛方法代替手算概率呢（笑）。
 *
 *	@ file: simulator.cpp
 *	@ author: Мiкo
 *	@ version: What is that? (xD)
 *	@ date: 2019-2-18
 */

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "judge.h"

using namespace std;

int main() {
	/*
	 *	程序运行时输入抽取次数
	 *	模拟抽卡的结果储存在文件“C:\ProgramData\simulator_result.txt”中
	 */
	char deck[41] = { 0 }; //全卡组， 运行时获取
	char target_deck[41] = { 0 }, *draw_deck = NULL; // 目标卡组，运行时获取；模拟抽卡卡组，随机生成
	int draw_num = 0; // 抽卡数，运行时获取
	int flag = 0; // 抽卡方式，运行时获取
	int Monte_Carlo = 1000; // 模拟次数，运行时获取
	
	// 获取抽卡数、全卡组数组、目标卡组数组和抽卡方式
	cout << "请输入抽卡数(1-40)：\n" << endl;
	cin >> draw_num;
	if (draw_num > 40 || draw_num < 1) {
		cout << "ERROR: 非法输入，抽卡数不能为负值或大于40的值！\n"<< endl;
		goto exit_point;
	}
	cout << "请输入全卡组数组：\n" << "(只需要输入抽取时的目标卡牌，用非零值(1-9,A-Z,a-z)即可，其余卡牌会默认用零补全)\n" << endl;
	cout << "(一个例子：卡组中有三张商贩一张拔刀一张光辉，则输入\"AAABC\"或\"11123\"即可。)\n" << endl;
	cin >> deck;
	int deck_len = strlen(deck);
	if (deck_len > 40) {
		cout << "ERROR: 非法输入，全卡组卡牌数不能多余四十张！" << endl;
		goto exit_point;
	}
	for (int i = deck_len; i < 41; ++ i) deck[i] = '0';
	deck[41] = '\0';
	cout << "请输入目标卡组数组：\n" << "(用与输入全卡组数组时对应的非零值，否则计算结果一定为零)\n" << endl;
	cout << "(对应的例子：想抽取一张商贩一张光辉，则输入\"AC\"或\"13\"即可。)\n" << endl;
	cin >> target_deck;
	int target_len = strlen(target_deck);
	if (target_len > deck_len) {
		cout << "ERROR: 目标卡组的卡牌数量不能多余全卡组中目标卡牌的数量，否则就算再神棍也达不到要求的。" << endl;
		goto exit_point;
	}
	cout << "请输入抽卡方式：\n" << "(1-抽取不少于目标卡组的卡牌，2-抽取恰好等于目标卡组的卡牌)" << endl;
	cin >> flag;
	if (1 != flag && 2 != flag) {
		cout << "ERROR: 非法输入，方式只有1或2两种！\n" << endl;
		goto exit_point;
	}
	cout << "请输入模拟次数：\n" << "(默认为1000次，建议不要太少。)\n" << endl;

	// 模拟抽卡
	draw_deck = (char *)calloc(draw_num + 1, sizeof(char));
	srand((unsigned)time(NULL));
	int deck_rule[40] = {0};
	int card_draw_random = 0;
	for (int i = 0; i < draw_num; ++i) {
		card_draw_random = rand() % 40;
		if (1 != deck_rule[card_draw_random]) {
			*(draw_deck + i) = deck[card_draw_random];
			deck_rule[card_draw_random] = 1;
		} // 卡牌尚未被抽取过，抽卡行为合法
		else {
			--i;
		} // 卡牌已被抽取过，重新抽取
	}
	*(draw_deck + draw_num) = '\0';

// 程序出口
exit_point:
	cout << "请按任意键退出……\n" << endl;
	char pause = '0';
	cin.get(pause);
}