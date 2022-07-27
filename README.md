# Basic-algorithm-exercise
 
本项目的内容是 `csp` 备考

项目使用devcpp编译，使用 c++ iso 14标准，会尽量使用 stl 中提供的方法

### install

本项目使用 cmake, 编译运行步骤如下
1. 创建 build 文件夹
2. 进入 build 文件夹
3. `cmake ../`
4. `make`

注意, 需要运行哪个程序需要在 CMakeLists.txt 中指定, 默认运行 `ex0001.cc` 即 helloworld

### CSP

<style>
button {
  background-color: #fafafa; 
  color: rgb(96,98,102);
  border: solid 1px rgb(220,223,230);
  border-radius: 4px;
}
.left {
  text-align:left;
}
table {
  width: unset !important;
}
</style>
<div>
  <div style="display:flex;align-items:center;justify-content:center;height: 100%" >
    <table class="tg" style = "text-align:center">
    <thead><tr><th>题目</th><th>名称</th><th>文件</th><th>标签</th></tr></thead>
    <tbody >
      <tr><td colspan = 4>2022 - 3</td></tr>
      <tr><td>1</td><td>测试</td><td>0001.cc</td><td class = "left">
        <button>语言基础</button> <button>网络流</button> <button>树状数组</button> <button>线段树</button> <button>tarjan </button> </td></tr>
    </tbody>
    </table>
  </div>
</div>

### practice

<div>
  <div style="display:flex !important;align-items:center !important;justify-content:center! important;height: 100%" >
    <table class="tg" style = "text-align:center">
    <thead><tr><th>文件</th><th>名称</th><th>注释</th><th>标签</th></tr></thead>
    <tbody >
      <tr><td>0001.cc</td><td>质数打表</td><td></td><td class = "left">
        <button>打表</button> <button>线性筛</button> <button>constexpr</button></td></tr>
      <tr><td>0002.cc</td><td>dijkstra</td><td>洛谷, wa</td><td class = "left">
        <button>模板</button> <button>dijkstra</button> <button>堆优化</button></td></tr>
      <tr><td>0003.cc</td><td>最大流</td><td>洛谷P3376, tle</td><td class = "left">
        <button>ff 算法</button> <button>网络流</button> </td></tr>
      <tr><td>0004.cc</td><td>图的遍历</td><td>洛谷P3916, tle</td><td class = "left">
        <button>bfs</button> <button>dfs</button> <button>链式前向星</button> </td></tr>
      <tr><td>0005.cc</td><td>字符串匹配</td><td></td><td class = "left">
        <button>正则表达式</button> </td></tr>
      <tr><td>0006.cc</td><td>组合</td><td>leetcode 组合</td><td class = "left">
        <button>模板</button> <button>迭代</button> <button>回溯</button> </td></tr>
      <tr><td>0007.cc</td><td>排列</td><td>leetcode 排列</td><td class = "left">
        <button>stl</button> </td></tr>
      <tr><td>0008.cc</td><td>硬币问题</td><td>硬币问题</td><td class = "left">
        <button>完全背包</button> <button>打表</button> <button>动态规划</button> </td></tr>
      <tr><td>0009.cc</td><td>硬币问题</td><td>硬币问题</td><td class = "left">
        <button>完全背包</button> <button>递归</button> <button>accumulate</button> <button>动态规划</button> </td></tr>
      <tr><td>0010.cc</td><td>c++ 类</td><td></td><td class = "left">
        <button>参数列表</button> <button>explicit 关键字</button> <button>运算符重载 const</button> <button>仿函数</button> </td></tr>
      <tr><td>0011.cc</td><td>io 模板</td><td></td><td class = "left">
        <button>cin</button> <button>cout</button> <button>流同步解绑</button> </td></tr>
    </tbody>
    </table>
  </div>
</div>
ex0007

```
树状数组
```

ex0008
```
lost cows 丢牛问题
线段树
segment tree
interval tree
区间染色问题
区间查询
区间会动态改变，而非静态不变（也就是染色操作）
墙长度本身不变，也就是最大的区间是固定的，区间中的元素会发生变化
```

### 题型知识点总结

字符串: 1.3|2.3|5.3|7.3|8.3|9.3|10.3
最短路径: 1.4|4.4|8.4|10.5
最小生成树: 3.4|10.4
网络流: 3.5
dp: 1.5|2.5|4.5|5.5|7.5|9.4
搜索: 2.4|5.4|6.3|6.4|7.4
排序: 3.3
模拟: 4.3
线段树: 8.5

字符串、树状数组、线段树、搜索、最短路径、生成树、网络流、dp、dp、dp