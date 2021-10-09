# 贪心
## 论证
1. 设a < b < c, 且 b = a + k<sub>1</sub> , c = a + k<sub>2</sub> ,则有 k<sub>1</sub> < k<sub>2</sub>
2. 可求得: 
   1. (ab + 1) * c = a<sup>3</sup> + k<sub>1</sub> + k<sub>2</sub> + k<sub>1</sub> * k<sub>2</sub> * a + k<sub>2</sub> + a 
   2. (ac + 1) * b = a<sup>3</sup> + k<sub>1</sub> + k<sub>2</sub> + k<sub>1</sub> * k<sub>2</sub> * a + k<sub>1</sub> + a
   3. (ab + 1) * c = a<sup>3</sup> + k<sub>1</sub> + k<sub>2</sub> + k<sub>1</sub> * k<sub>2</sub> * a + a
3. 去掉公共部 , 比较大小得 (ab + 1) * c > (ac + 1) * b > (ab + 1) * c
4. 所以:
   1. 每次合并最小的两个数后得到的是最大的
   2. 每次合并最大的两个数后得到的是最小的