（homework in ustb)

1.使用vscode编写，因此压缩包中.vscode文件夹为vscode的配置文件。
2.项目正文共四个文件夹，分别为custmoers（放置所有顾客的信息，每一个顾客都有一个以自己名字为文件名的txt文件，命名格式为“姓名.txt”。每一个txt文件内存放该顾客的姓名，密码，点单内容，点单时间以及点单最终的状态。）
riders（放置所有骑手的信息，每一个骑手都有一个以自己编号为文件名的txt文件，命名格式为“编号.txt”。每一个txt文件内存放该骑手的姓名，密码以及空闲状态。）
manager（放置所有该餐厅经理的信息，每一个经理都有一个以自己名字为文件名的txt文件，命名格式为“姓名.txt”。每一个txt文件内存放该经理的姓名，密码。以及菜单信息。）
src（存放所有的头文件以及源文件，所有的经理，骑手，顾客的姓名的总名单以及执行文件start）
3.只需要在Ubuntu系统中打开终端输入g++ -o start main.cpp custmoers.cpp riders.cpp manager.cpp即可编译，在输入./start即可运行。
4.采用相对路径，可直接运行代码。该文件夹中不包含任何已建立的manager，custmoers，riders的txt文本信息，启动可执行文件后请先建立riders，否则无法配送成功，因为此时没有骑手！
manager中也没有manager，可自己建立一个（在运行之后选择I am a manager输入姓名密码即可，会自动检测是注册还是登录）

ps:文件中涉及到了文件的建立，请注意代码中文件建立的路径，事先创建必要的文件，然后正常运行程序。
可以参考png文件所示例的文件层次
