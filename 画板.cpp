//#include<stdio.h>
//#include<graphics.h>
//#include<math.h>
//#include<tchar.h>
//int main()
//{
//	int x, y;
//	TCHAR a[100];
//	initgraph(700, 500);
//	outtextxy(10, 10, "颜");
//	outtextxy(10, 30, "色");
//	setfillcolor(RED);
//	solidrectangle(220, 10, 260, 40);
//	setfillcolor(YELLOW);
//	solidrectangle(100, 10, 140, 40);
//	setfillcolor(BLUE);
//	solidrectangle(160, 10, 200, 40);
//	setfillcolor(WHITE);
//	solidrectangle(40, 10, 80, 40);
//
//	outtextxy(300, 10, "工");
//	outtextxy(300, 30, "具");
//	rectangle(330, 10, 390, 40);
//	outtextxy(344, 17, "画笔");
//	rectangle(410, 10, 470, 40);
//	outtextxy(424, 17, "折线");
//	rectangle(490, 10, 550, 40);
//	outtextxy(504, 17, "圆形");
//	rectangle(570, 10, 630, 40);
//	outtextxy(584, 17, "矩形");
//
//	setcolor(GREEN);
//	line(0, 48, 700, 48);
//
//	setcolor(WHITE);
//	MOUSEMSG mmsg;
//	int flag = 0, i = 1, j = 0, k = 0;
//	int x1 = 0, x2 = 0, y1 = 0, y2 = 0, x3 = 0, y3 = 0;
//	while (1)
//	{
//		mmsg = GetMouseMsg();
//		x = mmsg.x, y = mmsg.y;
//		setfillcolor(BLACK);
//		solidrectangle(0, 500, 100, 470);
//		_stprintf_s(a, _T("[%d,%d]"), x, y);
//		setcolor(WHITE);
//		outtextxy(0, 480, a);
//
//		if (mmsg.uMsg == WM_LBUTTONDOWN)
//		{
//			x = mmsg.x, y = mmsg.y;
//			if (x <= 80 && x >= 40 && y <= 40 && y >= 10)
//				i = 1;
//			else if (x >= 100 && x <= 140 && y <= 40 && y >= 10)
//				i = 2;
//			else if (x >= 160 && x <= 200 && y <= 40 && y >= 10)
//				i = 3;
//			else if (x >= 220 && x <= 260 && y <= 40 && y >= 10)
//				i = 4;
//			else if (x >= 330 && x <= 390 && y <= 40 && y >= 10)
//				j = 1;
//			else if (x >= 410 && x <= 470 && y <= 40 && y >= 10)
//				j = 2;
//			else if (x >= 490 && x <= 550 && y <= 40 && y >= 10)
//				j = 3;
//			else if (x >= 570 && x <= 630 && y <= 40 && y >= 10)
//				j = 4;
//		}
//		switch (i)
//		{
//		case 1: setcolor(WHITE); break;
//		case 2: setcolor(YELLOW); break;
//		case 3: setcolor(BLUE); break;
//		case 4: setcolor(RED); break;
//		default:break;
//		}
//		if (j == 1 && mmsg.y >= 50)
//		{
//			flag = 0;
//			while (1)
//			{
//				mmsg = GetMouseMsg();
//				x = mmsg.x, y = mmsg.y;
//				setfillcolor(BLACK);
//				solidrectangle(0, 500, 100, 470);
//				_stprintf_s(a, _T("[%d,%d]"), x, y);
//				setcolor(WHITE);
//				outtextxy(0, 480, a);
//				switch (i)
//				{
//				case 1: setcolor(WHITE); break;
//				case 2: setcolor(YELLOW); break;
//				case 3: setcolor(BLUE); break;
//				case 4: setcolor(RED); break;
//				default:break;
//				}
//				if (mmsg.y >= 0 && mmsg.y < 50)
//				{
//					break;
//				}
//				if (mmsg.uMsg == WM_LBUTTONDOWN)
//				{
//					if (flag == 0)
//					{
//						x1 = mmsg.x;
//						y1 = mmsg.y;
//						flag = 1;
//					}
//				}
//				else if (mmsg.uMsg == WM_MOUSEMOVE && flag == 1)
//				{
//					x2 = mmsg.x;
//					y2 = mmsg.y;
//					line((int)x1, (int)y1, (int)x2, (int)y2);
//					x1 = x2;
//					y1 = y2;
//				}
//				if (mmsg.uMsg == WM_LBUTTONUP)
//					flag = 0;
//			}
//		}
//		else if (j == 2 && mmsg.y >= 50)
//		{
//			while (1)
//			{
//				mmsg = GetMouseMsg();
//				x = mmsg.x, y = mmsg.y;
//				setfillcolor(BLACK);
//				solidrectangle(0, 500, 100, 470);
//				_stprintf_s(a, _T("[%d,%d]"), x, y);
//				setcolor(WHITE);
//				outtextxy(0, 480, a);
//				switch (i)
//				{
//				case 1: setcolor(WHITE); break;
//				case 2: setcolor(YELLOW); break;
//				case 3: setcolor(BLUE); break;
//				case 4: setcolor(RED); break;
//				default:break;
//				}
//				if (mmsg.y >= 0 && mmsg.y < 50)
//				{
//					break;
//				}
//				if (mmsg.uMsg == WM_LBUTTONDOWN)
//				{
//					if (flag == 0)
//					{
//						x1 = mmsg.x;
//						y1 = mmsg.y;
//						flag = 1;
//					}
//					else if (flag == 1)
//					{
//						x2 = mmsg.x;
//						y2 = mmsg.y;
//						line((int)x1, (int)y1, (int)x2, (int)y2);
//						x1 = x2;
//						y1 = y2;
//					}
//				}
//			}
//		}
//		else if (j == 3 && mmsg.y >= 50)
//		{
//			flag = 0;
//			while (1)
//			{
//				mmsg = GetMouseMsg();
//				x = mmsg.x, y = mmsg.y;
//				setfillcolor(BLACK);
//				solidrectangle(0, 500, 100, 470);
//				_stprintf_s(a, _T("[%d,%d]"), x, y);
//				setcolor(WHITE);
//				outtextxy(0, 480, a);
//				switch (i)
//				{
//				case 1: setcolor(WHITE); break;
//				case 2: setcolor(YELLOW); break;
//				case 3: setcolor(BLUE); break;
//				case 4: setcolor(RED); break;
//				default:break;
//				}
//				if (mmsg.y >= 0 && mmsg.y < 50)
//				{
//					break;
//				}
//				if (mmsg.uMsg == WM_LBUTTONDOWN)
//				{
//					if (flag == 0)
//					{
//						x1 = mmsg.x;
//						y1 = mmsg.y;
//						x3 = x1;
//						y3 = y1;
//						flag = 1;
//					}
//				}
//				else if (mmsg.uMsg == WM_MOUSEMOVE && flag == 1)
//				{
//					x2 = mmsg.x;
//					y2 = mmsg.y;
//				}
//				if (mmsg.uMsg == WM_LBUTTONUP && flag == 1)
//				{
//					flag = 0;
//					continue;
//				}
//
//				if (mmsg.uMsg == WM_MOUSEMOVE && flag == 1)
//				{
//					setfillcolor(BLACK);
//					solidcircle((x1 + x3) / 2, (y1 + y3) / 2, sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3)) / 2 + 1);
//					if ((y1 + y3) / 2 - sqrt((x1 - x2) * (x1 - x2) + (y1 - y3) * (y1 - y3)) / 2 <= 50)
//					{
//						flag = 0;
//
//						circle((x1 + x3) / 2, (y1 + y3) / 2, sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3)) / 2);
//						continue;
//					}
//					circle((x1 + x2) / 2, (y1 + y2) / 2, sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) / 2);
//					x3 = x2, y3 = y2;
//				}
//			}
//		}
//	}
//}