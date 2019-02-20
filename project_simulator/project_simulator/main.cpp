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
 *	@ version: 0.1.0
 *	@ date: 2019-2-18
 *	@ history version��0.1.0  2019-2-18  ��ʼ�汾
 *	@ TODO: 0.1.0 �޷�������ļ�����ջ���󣬿��������ڻ��������ݹ��ർ�¶�ջ�����
 */

#include <iostream>
//--#include <fstream>
#include <string>
#include <ctime>
#include <windows.h>
#include "judge.h"

int main() {
	/*
	 *	��������ʱ�����ȡ����
	 *	ģ��鿨�Ľ���������ļ���C:\ProgramData\simulator_result.txt����
	 */
	char deck[41]; //ȫ���飬 ����ʱ��ȡ
	char target_deck[41], *draw_deck = NULL; // Ŀ�꿨�飬����ʱ��ȡ��ģ��鿨���飬�������
	int draw_num = 0; // �鿨��������ʱ��ȡ
	int flag = 0; // �鿨��ʽ������ʱ��ȡ
	int Monte_Carlo = 0; // ģ�����������ʱ��ȡ
	int num_meet = 0; //  ģ�������������Ĵ���
	// --char isOpenFile; // �Ƿ��ģ�����ļ��ı�־
	size_t deck_len, target_len; // ȫ���������Ŀ�꿨������ĳ���
	// --std::ofstream fout; // �ļ������
	
	// ��ȡ�鿨��
	std::cout << "������鿨��(1-40)" << std::endl;
	std::cin >> draw_num;
	if (draw_num > 40 || draw_num < 1) {
		std::cout << "ERROR: �Ƿ����룬�鿨������Ϊ��ֵ�����40��ֵ!"<< std::endl;
		goto exit_point;
	}
	// ��ȡȫ�������顢Ŀ�꿨������ͳ鿨��ʽ
	std::cout << "������ȫ�������飺\n" << "(ֻ��Ҫ�����ȡʱ��Ŀ�꿨�ƣ��÷���ֵ(1-9,A-Z,a-z)���ɣ����࿨�ƻ�Ĭ�����㲹ȫ)" << std::endl;
	std::cout << "(һ�����ӣ��������������̷�һ�Űε�һ�Ź�ԣ�������\"AAABC\"��\"11123\"���ɡ�)" << std::endl;
	std::cin >> deck;
	deck_len = strlen(deck);
	if (deck_len > 40) {
		std::cout << "ERROR: �Ƿ����룬ȫ���鿨�������ܶ�����ʮ�ţ�" << std::endl;
		goto exit_point;
	}
	for (size_t i = deck_len; i < 41; ++ i) deck[i] = '0';
	deck[40] = '\0';
	// ��ȡĿ�꿨������
	std::cout << "������Ŀ�꿨�����飺\n" << "(��������ȫ��������ʱ��Ӧ�ķ���ֵ�����������һ��Ϊ��)" << std::endl;
	std::cout << "(��Ӧ�����ӣ����ȡһ���̷�һ�Ź�ԣ�������\"AC\"��\"13\"���ɡ�)" << std::endl;
	std::cin >> target_deck;
	target_len = strlen(target_deck);
	if (target_len > deck_len) {
		std::cout << "ERROR: Ŀ�꿨��Ŀ����������ܶ���ȫ������Ŀ�꿨�Ƶ�������������������Ҳ�ﲻ��Ҫ��ġ�" << std::endl;
		goto exit_point;
	}
	// ��ȡ�鿨��ʽ
	std::cout << "������鿨��ʽ��\n" << "(1-��ȡ������Ŀ�꿨��Ŀ��ƣ�2-��ȡǡ�õ���Ŀ�꿨��Ŀ���)" << std::endl;
	std::cin >> flag;
	if (1 != flag && 2 != flag) {
		std::cout << "ERROR: �Ƿ����룬��ʽֻ��1��2���֣�" << std::endl;
		goto exit_point;
	}
	std::cout << "������ģ�������\n" << "(Ĭ��Ϊ1000�Σ����鲻Ҫ̫�١�)" << std::endl;
	std::cin >> Monte_Carlo;

	/*-- // ���и���������ģ�⣬�������д���ļ�
	fout.open("C:\\ProgramData\\simulator_result.txt", std::ios_base::out);
	fout << "*--------------------------------------------------*" << std::endl;
	fout << "*                     ģ����                     *" << std::endl;
	fout << "*--------------------------------------------------*" << std::endl; --*/
	for (int i = 0; i < Monte_Carlo; ++i) {
		// ģ��鿨
		//draw_deck = (char *)calloc(draw_num + 1, sizeof(char));
		draw_deck = (char *)malloc((draw_num + 1) * sizeof(char));
		srand((unsigned)time(NULL));
		int deck_rule[40] = { 0 };
		int card_draw_random = 0;
		for (int j = 0; j < draw_num; ++j) {
			card_draw_random = rand() % 40;
			if (1 != deck_rule[card_draw_random]) {
				*(draw_deck + i) = deck[card_draw_random];
				deck_rule[card_draw_random] = 1;
			} // ������δ����ȡ�����鿨��Ϊ�Ϸ�
			else {
				--j;
			} // �����ѱ���ȡ�������³�ȡ
		}
		*(draw_deck + draw_num) = '\0';
		// �ж��Ƿ���ϳ鿨��ʽҪ��
		switch (flag)
		{
		case 1:
			if (Judge::isDrawMeetGT(target_deck, draw_deck)) ++num_meet;
			break;
		case 2:
			if (Judge::isDrawMeetEQ(target_deck, draw_deck)) ++num_meet;
			break;
		}
		/* --// ���ļ�д�뱾�ε�ģ����
		fout << "No. ", i+1, ":", *draw_deck, "\n"; --*/
		free(draw_deck);
		draw_deck = NULL;
	} 

	// ���㲢�������
	std::cout << "*--------------------------------------------------*\n" << std::endl;
	std::cout << "*                     ģ����                     *\n" << std::endl;
	std::cout << "*--------------------------------------------------*\n" << std::endl;
	std::cout << "���������ĸ���Ϊ:" << float(num_meet) / float(Monte_Carlo) << std::endl;

	/* --// �򿪴���ģ�������ļ�
	isOpenFile = 'Y';
	std::cout << "�Ƿ�򿪴���ģ�������ļ�?(Y/n)" << std::endl;
	std::cin >> isOpenFile;
	if ('n' != isOpenFile) ShellExecute(NULL, "open", "simulator_result.txt", NULL, "C:\\ProgramData", 0);
	--*/
// �������
exit_point:
	std::cout << "�밴������˳�����" << std::endl;
	char pause = '0';
	std::cin.get(pause);
}