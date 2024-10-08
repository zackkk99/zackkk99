
# 井字棋游戏

这是一个用C++实现的简单井字棋游戏。玩家可以与计算机对战，程序会记录胜利、失败和平局的次数，并将每局游戏的结果保存到一个文本文件中。

## 功能特性

- **玩家对战计算机**：玩家可以选择先手或让计算机先手。
- **简单的用户界面**：游戏在控制台中显示棋盘，并提示玩家输入自己的棋步。
- **结果记录**：每局游戏的结果（胜利、失败或平局）将保存到名为`TicTacToeResults.txt`的文件中。
- **游戏统计**：在每次游戏结束后，程序会显示玩家的总胜场数、计算机的胜场数以及平局次数。

## 如何玩

1. **开始游戏**：游戏开始时，会询问你是否要先手。输入`Y`表示是，输入`N`表示否。

2. **下棋**： 
   - 棋盘是一个3x3的网格，行和列的编号为0到2。
   - 你需要输入你想放置标记（`X`）的位置的行和列。
   - 例如：如果你想把标记放在左上角，输入`0 0`。

3. **赢得比赛**：
   - 如果你在横向、纵向或斜向上连续放置了三个标记（`X`），你就赢了。
   - 如果棋盘已满且无人获胜，则判定为平局。

4. **游戏结果**：游戏结果（胜利、失败或平局）会显示在屏幕上并保存到文件中。

5. **再玩一局**：游戏结束后，程序会询问你是否想再玩一局。输入`Y`表示继续，输入`N`表示退出。

## 文件输出

游戏结果会保存到`TicTacToeResults.txt`文件中，格式如下：

玩家获胜！
计算机获胜！
平局！



## 示例输出

| | | |
| | | |
| | | |
你想先手吗 (Y/N)? Y
请输入你的棋步（行和列）：0 0
| X | | |
| | | |
| | | |
计算机获胜！

--- 游戏统计 ---
玩家胜利次数: 0
计算机胜利次数: 1
平局次数: 0


## 编译和运行

要编译程序，请使用以下命令：

```bash
g++ -o TicTacToe TicTacToe.cpp
然后，运行程序：

复制代码
./TicTacToe