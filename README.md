# Algorithm-learning
This is a repository for algorithm learning.
这里会有各个算法的简短的笔记和经典题目的代码。

## 目录
### 1. 基础算法
- 贪心算法  
- 二分与三分  
- 深搜的剪枝技巧  
- 广搜的剪枝技巧  
### 2. 字符串算法
- 哈希和哈希表  
- KMP  
- Trie字典树  
- AC自动机
### 3. 图论  
- 最小生成树  
- 最短路  
- SPFA算法的优化  
- 差分约束系统  
- 强联通分量  
- 割点和桥  
- 欧拉路径
### 4. 数据结构
- 树状数组  
- RMQ问题  
- 线段树  
- 倍增求LCA  
- 树链剖分  
- 平衡树Treap  
- 平衡树Splay  
### 5. 动态规划
- 区间DP  
- 树形DP  
- 数位DP  
- 状态压缩DP  
- 单调队列优化  
- 斜率优化  
### 6. 数学基础
- 快速幂  
- 质数  
- 约数  
- 同余问题  
- 矩阵乘法  
- 组合数学  
- 博弈论  
### 第一部分
####  贪心算法
这部分主要是数学能力了，更多的时候是一种直觉感受加严谨的推导。  
题1，2，3都是与区间有关的贪心，题4是Johnson算法的模板题。关于Johnson算法的证明我找到了远古时期的那篇Johnson的论文，放在"贪心算法/johnson.pdf"，题5是带限期和罚款的单位时间任务调度问题。第1~5题都是与区间有关的贪心，题6是一道挂着贪心算法帽子的数学推导题。

上题：

  1. [活动安排](https://www.acwing.com/problem/content/4170/)
        代码见文件：贪心算法/activity_arrange.cpp

  2. [种树](https://www.acwing.com/problem/content/description/4171/)
        代码见文件：贪心算法/plant_tree.cpp

  3. [喷水装置](https://www.acwing.com/problem/content/description/4172/)
        代码见文件：贪心算法/water_spray.cpp

  4. [加工生产调度](https://www.luogu.com.cn/problem/P1248)
        代码见文件：贪心算法/johnson.cpp  
    这一题有很多的题解都是错的，特别是洛谷上前面四篇题解有三篇都被hack掉了，关键点在于通过数学分析得到的那个表达式并不具有传递性，看原论文就知道正确的操作流程了。
  5. [智力大冲浪](https://www.luogu.com.cn/problem/P1230)  
  代码见文件：贪心算法/intellectual_storm.cpp
  6. [糖果传递](https://www.luogu.com.cn/problem/P2512)
    代码见文件：贪心算法/candy_transfer.cpp