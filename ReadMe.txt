一、hits 文件夹：
（1）处理 driver_and_poi_splited_1101all.txt 里的数据
二、hits&访问数验证分析文件夹：
（1）hits.c 与 hits2.c
         处理 splited1101_all_pair.txt，splited1102_all_pair.txt，splited1105_all_pair.txt 以及成都市区任意两天，三天全部约 200 万条的出租车订单数据进行 Hits 算法
（2）访问数.c
       处理 splited1101_all_pair.txt，splited1102_all_pair.txt，splited1105_all_pair.txt 以及成都市区任意两天，三天全部约 200 万条的出租车订单数据的访问数排序
（3）Hits_访问数比较.c
       处理比较 top100,top300,top500,top1000 两个输入文件中的不一样的个数
三、随机森林及其他 3 种方法预测结果以及对比验证文件夹：
（1）rf.py
        输出a：随机森林，决策树，贝叶斯，SVM 的分类预测结果及随机森林的回归结果
        输出b：分类问题中随机森林，决策树，贝叶斯，SVM 四种方法各自的准确率，混淆矩阵，及所分类别各自的精确率、召回率及 f1-score
（2）draw.py 画图精确率，召回率，f1-score 四种方法对所分五个类别各自的指标数值（画图需要修改代码中列表元素数值）


