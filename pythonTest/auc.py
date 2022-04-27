import numpy as np
from sklearn import metrics

'''
找到一对正负样本,这些样本对(pair)的数量是分母。
那么，分子是什么呢？分子是（正, 负）样本对中把正样本排在前面，加（负, 正）样本对中把正样本排在后面的数量。
'''

# 给定的真实y 和 预测pred
y = np.array([1, 0, 0, 0, 1, 0, 1, 0, 0, 1])
pred = np.array([0.9, 0.4, 0.3, 0.1, 0.35, 0.6, 0.65, 0.32, 0.8, 0.7])

numerator = 0  # 分子
denominator = 0  # 分母

for i in range(0, len(y)-1):
    for j in range(i, len(y)):
        if y[i] != y[j]:
            denominator += 1
            # 统计所有正负样本对中，模型把相对位置排序正确的数量
            if(y[i] > y[j] and pred[i] > pred[j]) or (y[i] < y[j] and pred[i] < pred[j]):
                numerator += 1

print("AUC =", numerator/denominator)


fpr, tpr, thresholds = metrics.roc_curve(y, pred, pos_label = 1)
print("调用sklearn库:", metrics.auc(fpr, tpr))
