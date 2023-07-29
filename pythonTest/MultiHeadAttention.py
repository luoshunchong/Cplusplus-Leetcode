import torch
import torch.nn as nn
import torch.nn.functional as F


# 定义多头注意力机制
class MultiHeadAttention(nn.Module):
    def __init__(self, num_heads, embedding_dim):
        super(MultiHeadAttention, self).__init__()
        self.num_heads = num_heads
        self.embedding_dim = embedding_dim
        self.head_dim = embedding_dim // num_heads
        self.q_linear = nn.Linear(embedding_dim, embedding_dim)
        self.k_linear = nn.Linear(embedding_dim, embedding_dim)
        self.v_linear = nn.Linear(embedding_dim, embedding_dim)
        self.out_linear = nn.Linear(embedding_dim, embedding_dim)

    def forward(self, q, k, v):
        batch_size = q.size(0)
        q = self.q_linear(q).view(
            batch_size, -1, self.num_heads, self.head_dim).transpose(1, 2)
        k = self.k_linear(k).view(
            batch_size, -1, self.num_heads, self.head_dim).transpose(1, 2)
        v = self.v_linear(v).view(
            batch_size, -1, self.num_heads, self.head_dim).transpose(1, 2)
        attention = torch.matmul(q, k.transpose(2, 3)) / self.head_dim**0.5
        attention = torch.softmax(attention, dim=-1)
        output = torch.matmul(attention, v).transpose(1, 2).contiguous().view(
            batch_size, -1, self.num_heads * self.head_dim)
        output = self.out_linear(output)
        return output
