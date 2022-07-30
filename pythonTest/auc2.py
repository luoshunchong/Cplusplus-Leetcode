# AUC的计算
import numpy as np
import matplotlib.pyplot as plt

for e in range(3):
    print("\nRound: ", e + 1)

    num = 1000
    auc1 = auc2 = auc3 = 0.

    # 准备数据
    pred_prob = list(np.random.uniform(low=0, high=1, size=[num]))
    labels = [int(prob > 0.5) for prob in list(
        np.random.uniform(low=0, high=1, size=[num]))]

    # 检查数据
    # print("pred_prob:\n", pred_prob)
    # print("labels:\n", labels)

    # 方法一，面积加和
    roc_point = []
    for i in range(num):
        i = pred_prob[i]
        TP = 0  # 真阳样本数
        FP = 0  # 假阳样本数
        TP_rate = 0.  # 真阳率
        FP_rate = 0.  # 假阳率
        pos_num = 0   # 预测真样本数

        # 计数过程
        for ind, prob in enumerate(pred_prob):
            if prob > i:
                pos_num += 1
            if prob > i and labels[ind] > 0.5:
                TP += 1
            elif prob > i and labels[ind] < 0.5:
                FP += 1
        if pos_num != 0:
            TP_rate = TP / sum(labels)
            FP_rate = FP / (num-sum(labels))
        roc_point.append([FP_rate, TP_rate])  # 记录ROC中的点
    # 画出ROC曲线
    roc_point.sort(key=lambda x: x[0])
    plt.plot(np.array(roc_point)[1:, 0], np.array(roc_point)[1:, 1])
    plt.xlabel("FPR")
    plt.ylabel("TPR")
    plt.show()

    # 计算每个小长方形的面积，求和即为auc
    lastx = 0.
    for x, y in roc_point:
        auc1 += (x - lastx) * y  # 底乘高
        lastx = x

    print("方法一 auc:", auc1)

    # 方法二，利用AUC关于排列概率的定义计算
    auc2 = 0
    P_ind = []  # 正样本下标
    F_ind = []  # 负样本下标
    P_F = 0  # 正样本分数高于负样本的数量
    F_P = 0  # 负样本分数高于正样本的数量

    #  计数过程
    for ind, val in enumerate(labels):
        if val > 0.5:
            P_ind.append(ind)
        else:
            F_ind.append(ind)
    for Pi in P_ind:
        for Fi in F_ind:
            if pred_prob[Pi] > pred_prob[Fi]:
                P_F += 1
            else:
                F_P += 1
    auc2 = P_F / (len(P_ind) * len(F_ind))
    print("方法二 auc:", auc2)

    # 方法三，方法二的改进，简化了计算，降低了时间复杂度
    new_data = [[p, l] for p, l in zip(pred_prob, labels)]
    new_data.sort(key=lambda x: x[0])

    # 求正样本rank之和
    rank_sum = 0
    for ind, [prob, label] in enumerate(new_data):
        if label > 0.5:
            rank_sum += ind
    auc3 = (rank_sum - len(P_ind) * (1 + len(P_ind)) / 2) / (len(P_ind) * len(F_ind))
    print("方法三 auc:", auc3)
