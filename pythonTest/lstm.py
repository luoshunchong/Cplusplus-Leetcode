import torch
import torch.nn as nn

lstm_seq = nn.LSTM(5, 10, 2)
lstm_input = torch.randn(6, 3, 5)
out, (h, c) = lstm_seq(lstm_input)

print("out:", out.size())
print("h:", h.size())
print("c:", c.size())