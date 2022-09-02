# Notes

## cin每次只读取一行，其余行之后的cin读取

## About launch.json and tasks.json

cpp文件debug的逻辑是：先根据tasks.json文件中的-g的路径(Source)读取cpp文件，然后生产exe文件输出到-o的路径(Out)中。然后launch.json读取exe存放的路径(Out), 进行debug。

tasks.json是辅助编译的模块，cpp文件的exe就是它控制产生

```json
{
    "tasks": [
        {
            "type": "shell",                       //任务执行的是shell命令
            "label": "g++.exe build active file", //和launch.josn 中的 preLaunchTask 必须一样
            "command": "C:\\Program Files\\mingw64\\bin\\g++.exe", //命令是g++，也可以直接写g++
            "args": [
                "-g",    //生成和调试有关的信息
                "-Wall", // 开启额外警告 
                "${workspaceFolder}\\source\\*.cpp",  //当前工作空间下文件夹source目录名下的所有cpp文件。 source对应工程目录下的source文件夹名字，可自行修改   
                "-I","${workspaceFolder}\\include",      // 参数-I 和工程路径 指明了项目中要引用的非标准头文件的位置。 include对应工程目录下的include文件夹名字，可自行修改                   
                "-o",                      
                "${workspaceFolder}\\out\\${fileBasenameNoExtension}.exe", //指定输出的文件名为out，默认a.exe。out对应工程目录下的out文件夹名字，可自行修改 
                "-std=c++17",                                      //使用c++17标准编译
                "-finput-charset=UTF-8",                           //输入编译器默认文本编码 默认为utf-8
                "-fexec-charset=GB18030",                          //输出exe文件编码 
            ],
            // 所以以上部分，就是在shell中执行（假设文件名为main.cpp）  等同在shell中执行  g++ main.cpp -o filename.exe 等命令
            "options": {
                "cwd": "C:\\Program Files\\mingw64\\bin"
            }
        }
    ],
    "version": "2.0.0"
}

```

launch.json 是控制run and debug的文件，内容及其意义如下：

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "g++.exe",                     
            "type": "cppdbg",                      
            "request": "launch",                   

            "program": "${workspaceFolder}\\out\\${fileBasenameNoExtension}.exe",  //需要运行/调试的是当前打开文件的目录中，名字和当前文件相同，但扩展名为exe的程序。和tasks.json中-o后面的目录一样的
            "args": [],                    
            "stopAtEntry": false,           //设为true时程序将暂停在程序入口处（即停止main函数开始），一般设置为false    
            "cwd": "${workspaceFolder}\\out", //调试程序时的工作目录 。out对应工程目录下的out文件夹
            "environment": [],              //针对调试的程序，要添加到环境中的环境变量
            "externalConsole": true,        //调试时是否显示外置控制台窗口（大黑框），一般设置为true显示控制台   
            "internalConsoleOptions": "neverOpen",   //可以没有
            "MIMode": "gdb",                // VSCode要使用的调试工具or指示VS代码将连接到的调试器
            "miDebuggerPath": "C:\\Program Files\\mingw64\\bin\\gdb.exe",   // miDebugger的路径，注意这里要与MinGw的路径对应 当未指定时，它将搜索操作系统的PATH变量来寻找调试器
            "setupCommands": [
                {
                    "description": "为 gdb 启用整齐打印",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "g++.exe build active file"  // 调试会话开始前执行的任务，一般为编译程序，c++为g++, c为gcc 这个名字一定要跟tasks.json中的任务名字大小写一致
        }
    ]
}

```
