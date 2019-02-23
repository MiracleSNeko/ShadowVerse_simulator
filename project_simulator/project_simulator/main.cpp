/*
 *	Copyright (C)�� 2019�� QQ group �ﰮ��kotomi�� (213794567), All rights reserved. (xD)
 *	
 *	a simulator of ShadowVerse draw card.
 *	why not use Monte Carlo instead of calculations? (xD)
 *	ĳɳ��֮ʫ�ĳ鿨����ģ�����
 *	Ϊʲô������������ؿ��巽��������������أ�Ц����
 *
 *	@ file: simulator.cpp
 *	@ author: ��i��o
 *	@ version: 1.0.0
 *	@ date: 2019-2-21
 *	@ history version��0.1.0  2019-2-18  ��ʼ�汾
                       0.2.0  2019-2-20  ������char *����Ϊstd::string
					   0.3.0  2019-2-21  �޸����жϺ������߼�����
					   1.0.0  2019-2-21  �������ļ������ʽ��ɾȥ�������
 *	@ TODO: 0.1.0 �ڴ��������ջ����
			0.2.0 û�н���ģ��鿨��forѭ��
			0.3.0 �޷�д��ʹ��ļ�
			1.0.0 ����ʹ��goto���±�����ʼ����Ϊ���ң������޸ĳ���ṹ��ɾȥgoto
 */

#include <iostream>
#include <fstream>
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
	std::string target_deck, draw_deck; // Ŀ�꿨�飬����ʱ��ȡ��ģ��鿨���飬�������
	int draw_num = 0; // �鿨��������ʱ��ȡ
	int flag = 0; // �鿨��ʽ������ʱ��ȡ
	int Monte_Carlo = 0; // ģ�����������ʱ��ȡ
	int num_meet = 0; //  ģ�������������Ĵ���
	char isOpenFile; // �Ƿ��ģ�����ļ��ı�־
	size_t deck_len, target_len; // ȫ���������Ŀ�꿨������ĳ���
	std::ofstream fout; // �ļ������
	
	std::cout << "*--------------------------------------------------*" << std::endl;
	std::cout << "*               ĳɳ��֮ʫ�鿨ģ����               *" << std::endl;
	std::cout << "*--------------------------------------------------*" << std::endl;
	// ��ȡ�鿨��
	std::cout << "������鿨��(1-40)" << std::endl;
	std::cin >> draw_num;
	std::cout << std::endl;
	if (draw_num > 40 || draw_num < 1) {
		std::cout << "ERROR: �Ƿ����룬�鿨������Ϊ��ֵ�����40��ֵ!"<< std::endl;
		goto exit_point;
	}
	// ��ȡȫ�������顢Ŀ�꿨������ͳ鿨��ʽ
	std::cout << "������ȫ�������飺\n" << "(ֻ��Ҫ�����ȡʱ��Ŀ�꿨�ƣ��÷���ֵ(1-9,A-Z,a-z)���ɣ����࿨�ƻ�Ĭ�����㲹ȫ)" << std::endl;
	std::cout << "(һ�����ӣ��������������̷�һ�Űε�һ�Ź�ԣ�������\"AAABC\"��\"11123\"���ɡ�)" << std::endl;
	std::cin >> deck;
	std::cout << std::endl;
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
	std::cout << std::endl;
	target_len = target_deck.length();
	if (target_len > deck_len) {
		std::cout << "ERROR: Ŀ�꿨��Ŀ����������ܶ���ȫ������Ŀ�꿨�Ƶ�������������������Ҳ�ﲻ��Ҫ��ġ�" << std::endl;
		goto exit_point;
	}
	// ��ȡ�鿨��ʽ
	std::cout << "������鿨��ʽ��\n" << "(1-��ȡ������Ŀ�꿨��Ŀ��ƣ�2-��ȡǡ�õ���Ŀ�꿨��Ŀ���)" << std::endl;
	std::cin >> flag;
	std::cout << std::endl;
	
	if (1 != flag && 2 != flag) {
		std::cout << "ERROR: �Ƿ����룬��ʽֻ��1��2���֣�" << std::endl;
		goto exit_point;
	}
	std::cout << "������ģ�������\n" << "(Ĭ��Ϊ1000�Σ����鲻Ҫ̫�١�)" << std::endl;
	std::cin >> Monte_Carlo;
	std::cout << std::endl;

	// ���и���������ģ�⣬�������д���ļ�
	fout.open("C:\\ProgramData\\simulator_result.txt", std::ios_base::out);
	fout << "*--------------------------------------------------*" << std::endl;
	fout << "*                     ģ����                                    *" << std::endl;
	fout << "*--------------------------------------------------*" << std::endl;
	srand((unsigned)time(NULL));
	for (int i = 0; i < Monte_Carlo; ++i) {
		// ģ��鿨
		draw_deck = "\0";
		int deck_rule[40] = { 0 };
		int card_draw_random = 0;
		for (int j = 0; j < draw_num; ++j) {
			card_draw_random = rand() % 40;
			if (1 != deck_rule[card_draw_random]) {
				draw_deck.insert(j, 1, deck[card_draw_random]);
				deck_rule[card_draw_random] = 1;
			} // ������δ����ȡ�����鿨��Ϊ�Ϸ�
			else {
				--j;
			} // �����ѱ���ȡ�������³�ȡ
		}
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
		// ���ļ�д�뱾�ε�ģ����
		fout << "No. " << (i + 1) << ": " << draw_deck << std::endl;
	} 
	fout.close();

	// ���㲢�������
	std::cout << "*--------------------------------------------------*" << std::endl;
	std::cout << "*                     ģ����                     *" << std::endl;
	std::cout << "*--------------------------------------------------*" << std::endl;
	std::cout << "���������ĸ���Ϊ:" << double(num_meet) / double(Monte_Carlo) << std::endl;

	// �򿪴���ģ�������ļ�
	isOpenFile = 'Y';
	std::cout << "�Ƿ�򿪴���ģ�������ļ�?(Y/n)" << std::endl;
	std::cin >> isOpenFile;
	std::cout << std::endl;
	if ('n' != isOpenFile) ShellExecute(NULL, "open", "simulator_result.txt", NULL, "C:\\ProgramData", SW_SHOW);

// �������
exit_point:
	system("pause");
	return 0;
}