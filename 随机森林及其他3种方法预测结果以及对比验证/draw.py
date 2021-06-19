import matplotlib.pyplot as plt
import numpy as np


first=[1.00,0.76,0.87,0.82,0.88]
second=[1.00,0.72,0.86,0.82,0.88]
third=[0.00,0.08,0.62,0.38,0.59]
fourth=[1.00,0.78,0.81,0.79,0.81]
labels=["1.0","2.0","3.0","4.0","5.0"]
x =  np.linspace(1, len(first) , len(first)) #len(data个序列)
print(x)
height01 = first
height02 = second
height03 = third
height04 = fourth
width = 0.2
color01='darkgoldenrod'
color02 = 'seagreen'
color03 ='pink'
color04 ='black'
# 画柱状图
fig = plt.figure('Contrast Histogram',figsize=(15,10)) #指定了图的名称 和画布的大小
fig.tight_layout()
plt.suptitle('Contrast Histogram', fontsize=15) # 添加图标题
#画图
rects01 = plt.bar(x, height01, width = 0.2, color=color01,linewidth=1,alpha=0.8)
rects02 = plt.bar(x+0.2,height02 ,width = 0.2, color=color02,linewidth=1,alpha=0.8)
rects03 = plt.bar(x+0.4,height03 ,width = 0.2, color=color03,linewidth=1,alpha=0.8)
rects04 = plt.bar(x+0.6,height04 ,width = 0.2, color=color04,linewidth=1,alpha=0.8)
plt.xticks(x+0.25,labels, fontsize=12)  # 横坐标轴标签 rotation x轴标签旋转的角度
plt.xlabel(u'Heat rating', fontsize=15, labelpad=10)
plt.ylabel(u'f1-score', fontsize=15, labelpad=10)
fig.legend((rects01,rects02,rects03,rects04),( u'Random Forest',u'Tree',u'NB',u'SVM'), fontsize=15)  # 图例
plt.show()
