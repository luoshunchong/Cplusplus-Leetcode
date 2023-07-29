import torch
import torch.nn as nn
import torch.optim as optim
from torch.utils.data import DataLoader
from torch.nn.utils.rnn import pad_sequence
from sklearn.model_selection import train_test_split

from sklearn.datasets import fetch_20newsgroups
from sklearn.feature_extraction.text import TfidfVectorizer

# 加载数据集
newsgroups = fetch_20newsgroups(subset='all')
X = newsgroups.data
y = newsgroups.target

# 文本预处理
vectorizer = TfidfVectorizer()
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42)
X_train = vectorizer.fit_transform(X_train)
X_test = vectorizer.transform(X_test)


# 定义模型
class TextClassifier(nn.Module):
    def __init__(self, vocab_size, embedding_dim, hidden_dim, output_dim):
        super(TextClassifier, self).__init__()
        self.embedding = nn.Embedding(vocab_size, embedding_dim)
        self.fc1 = nn.Linear(embedding_dim, hidden_dim)
        self.fc2 = nn.Linear(hidden_dim, output_dim)

    def forward(self, text):
        embedded = self.embedding(text)
        embedded = embedded.permute(1, 0, 2)
        pooled = nn.functional.max_pool1d(embedded, embedded.shape[2])
        pooled = pooled.permute(1, 0, 2)
        flattened = pooled.view(pooled.shape[0], -1)
        fc1 = torch.relu(self.fc1(flattened))
        fc2 = self.fc2(fc1)
        return fc2


# 定义超参数
vocab_size = len(vectorizer.vocabulary_)
embedding_dim = 128
hidden_dim = 256
output_dim = 20


# 定义数据集
class TextDataset(torch.utils.data.Dataset):
    def __init__(self, X, y):
        self.X = X
        self.y = y

    def __len__(self):
        return len(self.X)

    def __getitem__(self, idx):
        text = self.X[idx]
        label = self.y[idx]
        return text, label


trainset = TextDataset(X_train, y_train)
trainloader = DataLoader(trainset, batch_size=32, shuffle=True)

# 定义损失函数和优化器
criterion = nn.CrossEntropyLoss()
optimizer = optim.Adam(net.parameters())

# 训练模型
for epoch in range(10):
    running_loss = 0.0
    for i, data in enumerate(trainloader, 0):
        # 获取输入数据和标签
        inputs, labels = data
        # 将输入数据传递给模型进行前向计算
        outputs = net(inputs)
        # 计算损失函数的值
        loss = criterion(outputs, labels)
        # 执行反向传播
        optimizer.zero_grad()
        loss.backward()
        optimizer.step()
        # 统计损失函数的值
        running_loss += loss.item()
        # 每100个batch输出一次损失函数的值
        if i % 100 == 99:
            print('[%d, %5d] loss: %.3f' % (epoch + 1, i + 1, running_loss / 100))
            running_loss = 0.0

print('Finished Training')
