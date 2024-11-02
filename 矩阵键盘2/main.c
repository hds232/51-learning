#include <REGX52.H>
#include "matrixkey.h"
#include "LCD1602.h"
#include "delay.h"
#include "action.h"

void main()
{
	unsigned char keynum=0, count=0, wcount=0 ;				//定义输入位数总次数，密码错误次数
	unsigned char state=0, state1=0;						//定义状态参数state，state1
	unsigned int password=0, turepassword=9999;				//定义正确密码
	LCD_Init();
	LCD_ShowString(1, 1, "Password:");
	LCD_ShowNum(2, 1, password, 4);
	while(1)												//矩阵键盘循环扫描开始
	{
		keynum=0;
		if(wcount==3)										//如果失败次数等于3，锁定程序。如果此段代码放于if(keynum)里，会造成次数为3时按键后才会锁定程序
		{
			LCD_Clear();
			LCD_ShowString(1, 1, "Locked!!!");
			while(1);
		}
		keynum=matrixkey();
		if(keynum)
		{
			if(keynum<=10)									//键入矩阵编码小于11，输入密码并使密码位次加1					
			{
				if(count==4)								//输入密码位次等于4时，跳出循环重新执行（即锁定输入）
					continue;
				password*=10;
				password+=keynum%10;
				count++;
				LCD_ShowNum(2, 1, password, 4);
			}
			if(keynum==11)									//确认密码
			{
				if(state1==1)								//若程序处于更改密码第二阶段执行
				{
					turepassword=password;
					state1=0; password=0; count=0;			//相关参数和输入位次全部置零
					LCD_ShowString(1, 14, "OK ");
					delay(250);
					LCD_Clear();
					LCD_ShowString(1, 1, "Password:");
					LCD_ShowNum(2, 1, password, 4);
					continue;
				}
				else
				{
					if(password==turepassword)
					{
						if(state==1)						//程序处于更改密码第一阶段执行
						{
							password=0; count=0; wcount=0;
							state=0; state1=1;				//更新状态参数
							LCD_Clear();
							LCD_ShowString(1, 1, "New Password:");
							LCD_ShowNum(2, 1, password, 4);
							continue;
						}
						else								//密码正确执行
						{
							LCD_ShowString(1, 14, "OK ");
							delay(250);
							LCD_Clear();
							action();						//执行操作
							continue;
						}
					}
					else
					{
						if(state==1)						//更改密码旧密码输入错误时执行
						{
							LCD_ShowString(1, 14, "ERR");
							count=0;
							wcount++;
							password=0;
							LCD_ShowNum(2, 1, password, 4);
							continue;
						}
						else								//密码错误使位次清零，失败次数加1
						{
							LCD_ShowString(1, 14, "ERR");
							count=0;
							wcount++;
							password=0;
							delay(250);
							LCD_Clear();
							LCD_ShowString(1, 1, "Try again:");
							LCD_ShowNum(1, 15, wcount, 1);	//显示失败次数
							LCD_ShowNum(2, 1, password, 4);
							continue;
						}
					}
				}
			}
			if(keynum==12)									//定义清零键
			{
				password=0;
				count=0;
				LCD_ShowNum(2, 1, password, 4);
			}
			if(keynum==16)									//定义退位键
			{
				password/=10;
				if(count==0) {}								//密码位次退为零时，锁定退位
				else
					count--;
				LCD_ShowNum(2, 1, password, 4);
			}
			if(keynum==13)									//定义更改密码键
			{
				password=0; state=1; count=0;
				LCD_Clear();
				LCD_ShowString(1, 1, "Old Password:");		//提示输入旧密码
				LCD_ShowNum(2, 1, password, 4);
			}
			if(keynum==14)									//重新锁定
			{
				password=0; count=0; wcount=0;				//操作所改变的所有状态参数清零
				state=0; state1=0;
				LCD_Clear();
				LCD_ShowString(1, 1, "Password:");
				LCD_ShowNum(2, 1, password, 4);
			}
		}
	}
}