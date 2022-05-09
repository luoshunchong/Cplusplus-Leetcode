import numpy as np
import torch
import torch.nn as nn


def numpy_conv(inputs, myfilter):
    '''
    二维卷积,无Padding, 步长为1,
    '''

    h_ori, w_ori = inputs.shape
    h_k, w_k= myfilter.shape
    
    # 计算卷积之后的矩阵的长宽
    h_new, w_new = h_ori - h_k + 1, w_ori - w_k + 1
    result = np.zeros((h_new, w_new))
    
    for row in range(0, h_new, 1):  # 这里控制步长为1
        for col in range(0, w_new, 1):
            # 卷积核计算的区域
            cur_input = inputs[row : row + h_k, col : col + w_k]
            # 和核进行乘法计算
            cur_output = cur_input * myfilter
            # 再把所有值求和
            conv_sum = np.sum(cur_output)
            # 当前点输出值
            result[row, col] = conv_sum
    return result

inputs = np.random.rand(100, 100)
filter = np.ones((3,3))
res = numpy_conv(inputs, filter)
print(res)
