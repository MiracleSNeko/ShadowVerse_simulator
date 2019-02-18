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
#include <fstream>
#include <string>
#include <ctime>
#include "judge.h"

using namespace std;

int main() {
	/*
	 *	��������ʱ�����ȡ����
	 *	ģ��鿨�Ľ���������ļ���C:\ProgramData\simulator_result.txt����
	 */
	char deck[41] = { 0 }; //ȫ���飬 ����ʱ��ȡ
	char target_deck[41] = { 0 }, *draw_deck = NULL; // Ŀ�꿨�飬����ʱ��ȡ��ģ��鿨���飬�������
	int draw_num = 0; // �鿨��������ʱ��ȡ
	int flag = 0; // �鿨��ʽ������ʱ��ȡ
	int Monte_Carlo = 1000; // ģ�����������ʱ��ȡ
	
	// ��ȡ�鿨����ȫ�������顢Ŀ�꿨������ͳ鿨��ʽ
	cout << "������鿨��(1-40)��\n" << endl;
	cin >> draw_num;
	if (draw_num > 40 || draw_num < 1) {
		cout << "ERROR: �Ƿ����룬�鿨������Ϊ��ֵ�����40��ֵ��\n"<< endl;
		goto exit_point;
	}
	cout << "������ȫ�������飺\n" << "(ֻ��Ҫ�����ȡʱ��Ŀ�꿨�ƣ��÷���ֵ(1-9,A-Z,a-z)���ɣ����࿨�ƻ�Ĭ�����㲹ȫ)\n" << endl;
	cout << "(һ�����ӣ��������������̷�һ�Űε�һ�Ź�ԣ�������\"AAABC\"��\"11123\"���ɡ�)\n" << endl;
	cin >> deck;
	int deck_len = strlen(deck);
	if (deck_len > 40) {
		cout << "ERROR: �Ƿ����룬ȫ���鿨�������ܶ�����ʮ�ţ�" << endl;
		goto exit_point;
	}
	for (int i = deck_len; i < 41; ++ i) deck[i] = '0';
	deck[41] = '\0';
	cout << "������Ŀ�꿨�����飺\n" << "(��������ȫ��������ʱ��Ӧ�ķ���ֵ�����������һ��Ϊ��)\n" << endl;
	cout << "(��Ӧ�����ӣ����ȡһ���̷�һ�Ź�ԣ�������\"AC\"��\"13\"���ɡ�)\n" << endl;
	cin >> target_deck;
	int target_len = strlen(target_deck);
	if (target_len > deck_len) {
		cout << "ERROR: Ŀ�꿨��Ŀ����������ܶ���ȫ������Ŀ�꿨�Ƶ�������������������Ҳ�ﲻ��Ҫ��ġ�" << endl;
		goto exit_point;
	}
	cout << "������鿨��ʽ��\n" << "(1-��ȡ������Ŀ�꿨��Ŀ��ƣ�2-��ȡǡ�õ���Ŀ�꿨��Ŀ���)" << endl;
	cin >> flag;
	if (1 != flag && 2 != flag) {
		cout << "ERROR: �Ƿ����룬��ʽֻ��1��2���֣�\n" << endl;
		goto exit_point;
	}
	cout << "������ģ�������\n" << "(Ĭ��Ϊ1000�Σ����鲻Ҫ̫�١�)\n" << endl;

	// ģ��鿨
	draw_deck = (char *)calloc(draw_num + 1, sizeof(char));
	srand((unsigned)time(NULL));
	int deck_rule[40] = {0};
	int card_draw_random = 0;
	for (int i = 0; i < draw_num; ++i) {
		card_draw_random = rand() % 40;
		if (1 != deck_rule[card_draw_random]) {
			*(draw_deck + i) = deck[card_draw_random];
			deck_rule[card_draw_random] = 1;
		} // ������δ����ȡ�����鿨��Ϊ�Ϸ�
		else {
			--i;
		} // �����ѱ���ȡ�������³�ȡ
	}
	*(draw_deck + draw_num) = '\0';

// �������
exit_point:
	cout << "�밴������˳�����\n" << endl;
	char pause = '0';
	cin.get(pause);
}