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
#include "judge.h"

int main() {
	/*
	 *	程序运行时输入抽取次数
	 *	模拟抽卡的结果储存在文件“C:\ProgramData\simulator_result.txt”中
	 */
	char deck[41]; //全卡组， 从文件中读取
	char *target_deck = NULL, *draw_deck = NULL; // 目标卡组，从文件中读取；模拟抽卡卡组，随机生成
	int draw_num; // 抽卡数，运行时获取
	char pause;
	
	std::cout << "请输入抽卡数(1-40)：\n" << std::endl;
	std::cin >> draw_num;
	if (draw_num > 40 || draw_num < 1) {
		std::cout << "ERROR: 非法输入\n"<< std::endl;
		goto exit_point;
	}
	draw_deck = (char *)calloc(draw_num, sizeof(char));


exit_point:
	std::cout << "请按任意键退出……\n" << std::endl;
	std::cin.get(pause);
}