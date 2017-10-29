// test2.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"

#include "Smtp.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{	
	CSmtp smtp(
		25,								/*smtp端口*/
		"smtp.126.com",					/*smtp服务器地址*/
		"user@126.com",	        /*源邮箱地址*/
		"password",					/*邮箱密码*/
		"123@qq.com",	    /*目的邮箱地址*/
		"测试c/c++",							/*主题*/
		"正文测试"		/*邮件正文*/
	);
	
	// 添加附件时注意,\一定要写成\\，因为转义字符的缘故
	// Addattachment:添加附件  CSmtp::DeleteAttachment函数删除附件  
	string filePath;
	filePath = "timg.jpg";
	smtp.AddAttachment(filePath);

	int err;
	if ((err = smtp.SendEmail_Ex()) != 0)
	{
		if (err == 1)
			cout << "错误1: 由于网络不畅通，发送失败!" << endl;
		if (err == 2)
			cout << "错误2: 用户名错误,请核对!" << endl;
		if (err == 3)
			cout << "错误3: 用户密码错误，请核对!" << endl;
		if (err == 4)
			cout << "错误4: 请检查附件目录是否正确，以及文件是否存在!" << endl;
	}

	system("pause");  //VS2010 调试 console 程序比较重要
	return 0;
}

