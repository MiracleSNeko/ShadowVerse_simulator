/*
 *	Copyrigh (C)�� 2019�� QQ group �ﰮ��kotomi�� (213794567), All rights reserved. (xD)
 *	
 *	a simulator of ShadowVerse draw card.
 *	why not use Monte Carlo instead of calculations? (xD)
 *	ĳɳ��֮ʫ�ĳ鿨����ģ�����
 *	Ϊʲô������������ؿ��巽��������������أ�Ц����
 *
 *	@ file: simulator.cpp
 *	@ author: ��i��o
 *	@ version: What is that? (xD)
 *	@ date: 2019-2-18
 */

#include <iostream>
#include "judge.h"

int main() {
	/*
	 *	��������ʱ�����ȡ����
	 *	ģ��鿨�Ľ���������ļ���C:\ProgramData\simulator_result.txt����
	 */
	char deck[41]; //ȫ���飬 ���ļ��ж�ȡ
	char *target_deck = NULL, *draw_deck = NULL; // Ŀ�꿨�飬���ļ��ж�ȡ��ģ��鿨���飬�������
	int draw_num; // �鿨��������ʱ��ȡ
	char pause;
	
	std::cout << "������鿨��(1-40)��\n" << std::endl;
	std::cin >> draw_num;
	if (draw_num > 40 || draw_num < 1) {
		std::cout << "ERROR: �Ƿ�����\n"<< std::endl;
		goto exit_point;
	}
	draw_deck = (char *)calloc(draw_num, sizeof(char));


exit_point:
	std::cout << "�밴������˳�����\n" << std::endl;
	std::cin.get(pause);
}