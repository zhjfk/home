//#include<stdio.h>
//#include<graphics.h>
//#include<conio.h>
//#include<time.h>
//#define MAXSTAR 1314
//#define MAXMETOR 520
//IMAGE img1, img2;
//
//struct Star {
//	int x, y;
//	int color;
//	int step;
//}star[MAXSTAR];
//struct Metor {
//	int x, y;
//	int style;
//	int step;
//}metor[MAXMETOR];
//void printftext(void)
//{
//	settextcolor(RGB(255, 255, 255));
//	settextstyle(30, 0, "����");
//	outtextxy(200, 20, "*******,��ϲ���㣺");
//	outtextxy(350, 60, "  ������ʶ���***��;");
//	outtextxy(350, 120, "  �Ҳ�֪����Ĺ�ȥ������ʲô;");
//	outtextxy(350, 180, "  ��Ĺ�ȥ��Ҳ����������;");
//	outtextxy(350, 240, "  �����δ����һ�����㵽��");
//	outtextxy(350, 300, "  ��ϲ���㣬������˰�������ʹ��ڣ�");
//	outtextxy(350, 360, "  ��ϲ���㣬��ǣ���ҵ��֣�");
//	outtextxy(350, 420, "  �ұ�֤��");
//	outtextxy(350, 480, "  �����۾���·��Ҳ������·��");
//	outtextxy(350, 540, "  �𰸺ܳ�");
//	outtextxy(350, 600, "  ��׼����������ʱ�������ش�");
//	outtextxy(350, 660, "  ��Ҫ׼������");
//	outtextxy(700, 700, "-----�����*****");
//	_getch();
//}
//
//void initStar(int i)
//{
//
//	star[i].x = rand() % 1200;
//	star[i].y = rand() % 800;
//	star[i].color = RGB(rand() % 256, rand() % 256, rand() % 256);
//	star[i].step = rand() % 10;
//
//}
//void drawStar(int i)
//{
//	putpixel(star[i].x, star[i].y, star[i].color);
//	star[i].x += star[i].step;
//	star[i].y += star[i].step;
//	if (star[i].x >= 1200)
//	{
//		putpixel(star[i].x, star[i].y, star[i].color);
//		initStar(i);
//	}
//
//}
//void initMetor(int i)
//{
//
//	metor[i].x = rand() % 2200 - 1000;
//	metor[i].y = -100;
//	metor[i].style = rand() % 2;
//	metor[i].step = rand() % 10;
//
//}
//void drawMetor(int i)
//{
//	for (i = 0; i < MAXMETOR; i++)
//	{
//		switch (metor[i].style)
//		{
//		case 0:
//			putimage(metor[i].x, metor[i].y, &img1);
//			break;
//		case 1:
//			putimage(metor[i].x, metor[i].y, &img2);
//			break;
//		}
//	}
//}
//void move(int i)
//{
//	for (i = 0; i < MAXMETOR; i++)
//	{
//		metor[i].x += metor[i].step;
//		metor[i].y += metor[i].step;
//		if (metor[i].x >= 1200)
//			initMetor(i);
//	}
//}
//
//int main()
//{
//	srand((unsigned)time(NULL));
//	loadimage(&img1, "7.png", 20, 20);
//	loadimage(&img2, "6.png", 20, 20);
//	initgraph(1200, 800);
//	int i;
//	printftext();
//	for (i = 0; i < MAXSTAR; i++)
//	{
//		initStar(i);
//
//	}
//	for (i = 0; i < MAXMETOR; i++)
//	{
//		initMetor(i);
//
//	}
//	while (1)
//	{
//		BeginBatchDraw();
//		cleardevice();
//		for (i = 0; i < MAXSTAR; i++)
//		{
//			drawStar(i);
//		}
//		drawMetor(i);
//		move(i);
//		Sleep(100);
//		EndBatchDraw();
//	}
//	while (1);
//	closegraph();
//	return 0;
//}