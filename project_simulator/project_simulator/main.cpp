/*
 *	Copyright (C)， 2019， QQ group ★爱上kotomi★ (213794567), All rights reserved. (xD)
 *	
 *	a simulator of ShadowVerse draw card.
 *	why not use Monte Carlo instead of calculations? (xD)
 *	某沙雕之诗的抽卡概率模拟程序。
 *	为什么不用神奇的蒙特卡洛方法代替手算概率呢（笑）。
 *
 *	@ file: simulator.cpp
 *	@ author: Мiкo
 *	@ version: 1.0.0
 *	@ date: 2019-2-21
 *	@ history version：0.1.0  2019-2-18  初始版本
                       0.2.0  2019-2-20  将所有char *更改为std::string
					   0.3.0  2019-2-21  修复了判断函数的逻辑错误
					   1.0.0  2019-2-21  更改了文件输出格式，删去冗余代码
 *	@ TODO: 0.1.0 内存溢出，堆栈错误
			0.2.0 没有进入模拟抽卡的for循环
			0.3.0 无法写入和打开文件
			1.0.0 由于使用goto导致变量初始化较为混乱，可以修改程序结构并删去goto
 */

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <windows.h>
#include "judge.h"

int main() {
	/*
	 *	程序运行时输入抽取次数
	 *	模拟抽卡的结果储存在文件“C:\ProgramData\simulator_result.txt”中
	 */
	char deck[41]; //全卡组， 运行时获取
	std::string target_deck, draw_deck; // 目标卡组，运行时获取；模拟抽卡卡组，随机生成
	int draw_num = 0; // 抽卡数，运行时获取
	int flag = 0; // 抽卡方式，运行时获取
	int Monte_Carlo = 0; // 模拟次数，运行时获取
	int num_meet = 0; //  模拟结果满足条件的次数
	char isOpenFile; // 是否打开模拟结果文件的标志
	size_t deck_len, target_len; // 全卡组数组和目标卡组数组的长度
	std::ofstream fout; // 文件输出流
	
	std::cout << "*--------------------------------------------------*" << std::endl;
	std::cout << "*               某沙雕之诗抽卡模拟器               *" << std::endl;
	std::cout << "*--------------------------------------------------*" << std::endl;
	// 获取抽卡数
	std::cout << "请输入抽卡数(1-40)" << std::endl;
	std::cin >> draw_num;
	std::cout << std::endl;
	if (draw_num > 40 || draw_num < 1) {
		std::cout << "ERROR: 非法输入，抽卡数不能为负值或大于40的值!"<< std::endl;
		goto exit_point;
	}
	// 获取全卡组数组、目标卡组数组和抽卡方式
	std::cout << "请输入全卡组数组：\n" << "(只需要输入抽取时的目标卡牌，用非零值(1-9,A-Z,a-z)即可，其余卡牌会默认用零补全)" << std::endl;
	std::cout << "(一个例子：卡组中有三张商贩一张拔刀一张光辉，则输入\"AAABC\"或\"11123\"即可。)" << std::endl;
	std::cin >> deck;
	std::cout << std::endl;
	deck_len = strlen(deck);
	if (deck_len > 40) {
		std::cout << "ERROR: 非法输入，全卡组卡牌数不能多余四十张！" << std::endl;
		goto exit_point;
	}
	for (size_t i = deck_len; i < 41; ++ i) deck[i] = '0';
	deck[40] = '\0';
	// 获取目标卡组数组
	std::cout << "请输入目标卡组数组：\n" << "(用与输入全卡组数组时对应的非零值，否则计算结果一定为零)" << std::endl;
	std::cout << "(对应的例子：想抽取一张商贩一张光辉，则输入\"AC\"或\"13\"即可。)" << std::endl;
	std::cin >> target_deck;
	std::cout << std::endl;
	target_len = target_deck.length();
	if (target_len > deck_len) {
		std::cout << "ERROR: 目标卡组的卡牌数量不能多余全卡组中目标卡牌的数量，否则就算再神棍也达不到要求的。" << std::endl;
		goto exit_point;
	}
	// 获取抽卡方式
	std::cout << "请输入抽卡方式：\n" << "(1-抽取不少于目标卡组的卡牌，2-抽取恰好等于目标卡组的卡牌)" << std::endl;
	std::cin >> flag;
	std::cout << std::endl;
	
	if (1 != flag && 2 != flag) {
		std::cout << "ERROR: 非法输入，方式只有1或2两种！" << std::endl;
		goto exit_point;
	}
	std::cout << "请输入模拟次数：\n" << "(默认为1000次，建议不要太少。)" << std::endl;
	std::cin >> Monte_Carlo;
	std::cout << std::endl;

	// 进行给定次数的模拟，并将结果写入文件
	fout.open("C:\\ProgramData\\simulator_result.txt", std::ios_base::out);
	fout << "*--------------------------------------------------*" << std::endl;
	fout << "*                     模拟结果                                    *" << std::endl;
	fout << "*--------------------------------------------------*" << std::endl;
	srand((unsigned)time(NULL));
	for (int i = 0; i < Monte_Carlo; ++i) {
		// 模拟抽卡
		draw_deck = "\0";
		int deck_rule[40] = { 0 };
		int card_draw_random = 0;
		for (int j = 0; j < draw_num; ++j) {
			card_draw_random = rand() % 40;
			if (1 != deck_rule[card_draw_random]) {
				draw_deck.insert(j, 1, deck[card_draw_random]);
				deck_rule[card_draw_random] = 1;
			} // 卡牌尚未被抽取过，抽卡行为合法
			else {
				--j;
			} // 卡牌已被抽取过，重新抽取
		}
		// 判断是否符合抽卡方式要求
		switch (flag)
		{
		case 1:
			if (Judge::isDrawMeetGT(target_deck, draw_deck)) ++num_meet;
			break;
		case 2:
			if (Judge::isDrawMeetEQ(target_deck, draw_deck)) ++num_meet;
			break;
		}
		// 向文件写入本次的模拟结果
		fout << "No. " << (i + 1) << ": " << draw_deck << std::endl;
	} 
	fout.close();

	// 计算并输出概率
	std::cout << "*--------------------------------------------------*" << std::endl;
	std::cout << "*                     模拟结果                     *" << std::endl;
	std::cout << "*--------------------------------------------------*" << std::endl;
	std::cout << "满足条件的概率为:" << double(num_meet) / double(Monte_Carlo) << std::endl;

	// 打开储存模拟结果的文件
	isOpenFile = 'Y';
	std::cout << "是否打开储存模拟结果的文件?(Y/n)" << std::endl;
	std::cin >> isOpenFile;
	std::cout << std::endl;
	if ('n' != isOpenFile) ShellExecute(NULL, "open", "simulator_result.txt", NULL, "C:\\ProgramData", SW_SHOW);

// 程序出口
exit_point:
	system("pause");
	return 0;
}