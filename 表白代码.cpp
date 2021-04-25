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
//	settextstyle(30, 0, "楷体");
//	outtextxy(200, 20, "*******,我喜欢你：");
//	outtextxy(350, 60, "  这是认识你的***天;");
//	outtextxy(350, 120, "  我不知道你的过去经历了什么;");
//	outtextxy(350, 180, "  你的过去我也来不及参与;");
//	outtextxy(350, 240, "  但你的未来我一定奉陪到底");
//	outtextxy(350, 300, "  我喜欢你，像风走了八万里，不问归期；");
//	outtextxy(350, 360, "  我喜欢你，你牵着我的手；");
//	outtextxy(350, 420, "  我保证：");
//	outtextxy(350, 480, "  闭着眼睛走路你也不会迷路；");
//	outtextxy(350, 540, "  答案很长");
//	outtextxy(350, 600, "  我准备用余生的时间来来回答；");
//	outtextxy(350, 660, "  你要准备听吗？");
//	outtextxy(700, 700, "-----爱你的*****");
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