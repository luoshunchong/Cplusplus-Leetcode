import math

corpus = [
    "What is the weather like today",
    "what is for dinner tonight",
    "this is question worth pondering",
    "it is a beautiful day today"
]

def merge_corpus(corpus):
    """
    统计语料库，输出词表，并统计包含每个词的文档数。
    """
    vocab = {}
    num_docs = len(corpus)
    for sentence in corpus:
        words = sentence.strip().split()
        words = set(words)
        for word in words:
            vocab[word] = vocab.get(word, 0.0) + 1.0
    return num_docs, vocab

def get_tfidf(sentence, num_docs, vocab):
    tfidf = {}
    terms = sentence.strip().split()
    terms_set = set(terms)
    num_terms = len(terms)
    for term in terms_set:
        # 计算 TF 值
        tf = float(terms.count(term)) / num_terms
        # 计算 IDF 值
        idf = math.log(num_docs / (vocab.get(term, 0.0) + 1.0))
        # 计算 TF-IDF 值
        tfidf[term] = tf * idf
    return tfidf

def get_tfidf_value(corpus, num_docs, vocab):
    tfidf_list = []
    for sentence in corpus:
        tfidf_list.append(get_tfidf(sentence, num_docs, vocab))
    return tfidf_list

num_docs, vocab = merge_corpus(corpus)
tfidf_values = get_tfidf_value(corpus, num_docs, vocab)
for tfidf_value in tfidf_values:
    print(tfidf_value)
